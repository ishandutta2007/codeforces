#include<bits/stdc++.h>

using namespace std;

typedef long double dbl;

const dbl eps = 1e-18;
const dbl PI = 2 * acos(0);

dbl sqr(dbl x){
	return x * x;
}

struct pt{
	dbl x, y;
	pt(){}
	pt(dbl a, dbl b):x(a), y(b){}
	pt(const pt & a):x(a.x), y(a.y){}
	pt& operator = (const pt & a){x = a.x; y = a.y; return *this;}
	pt operator + (const pt & a)const{return pt(x + a.x, y + a.y);}
	pt operator - (const pt & a)const{return pt(x - a.x, y - a.y);}
	pt operator * (dbl a)const{return pt(x * a, y * a);}
	pt operator / (dbl a)const{assert(fabs(a) > eps); return pt(x / a, y / a);}
	pt& operator += (const pt & a){x += a.x; y += a.y; return *this;}
	pt& operator -= (const pt & a){x -= a.x; y -= a.y; return *this;}
	pt& operator *= (dbl a){x *= a; y *= a; return *this;}
	pt& operator /= (dbl a){assert(fabs(a) > eps); return *this;}
	bool isZero()const{return fabs(x) < eps && fabs(y) < eps;}
	bool operator == (const pt & a)const{return (*this - a).isZero();}
	dbl cross(const pt & a)const{return x * a.y - y * a.x;}
	dbl cross(pt a, pt b)const{
		a -= *this; b -= *this;
		return a.cross(b);
	}
	dbl dot(const pt & a)const{return x * a.x + y * a.y;}
	dbl dot(pt a, pt b)const{
		a -= *this; b -= *this;
		return a.dot(b);
	}
	dbl length()const{return sqrt(sqr(x) + sqr(y));}
	dbl sqrLength()const{return x * x + y * y;}
	void normalizeSelf(){*this /= length();}
	pt normalize()const{
		pt res(*this);
		res.normalizeSelf();
		return res;
	}
	dbl dist(const pt & a)const{return (*this - a).length();}
	dbl angle()const{return atan2(y, x);}
	void rotateSelf(dbl phi){
		dbl pcos = cos(phi), psin = sin(phi);
		dbl nx = x * pcos - y * psin, ny = y * pcos + x * psin;
		x = nx; y = ny;
	}
	pt rotate(dbl phi)const{
		pt res(*this);
		res.rotateSelf(phi);
		return res;
	}
};

struct Line{
	pt p[2];
	dbl a, b, c;
	Line(){}
	void recalcEquation(){
		a = p[1].y - p[0].y;
		b = p[0].x - p[1].x;
		c = -a * p[0].x - b * p[0].y;
	}
	void normalizeEquation(){
		dbl norm = sqrt(sqr(a) + sqr(b));
		a /= norm; b /= norm; c /= norm;
		if(a < -eps || (fabs(a) < eps && b < -eps)){
			a = -a; b = -b; c = -c;
		}
	}
	Line(pt l, pt r){p[0] = l; p[1] = r; recalcEquation();}
	Line(dbl pa, dbl pb, dbl pc){
		a = pa; b = pb; c = pc;
		if(fabs(b) < eps)p[0] = pt{-c/a, 0};
		else p[0] = pt{0, -c/b};
		p[1] = pt(p[0].x - b, p[0].y + a);
	}
	pt& operator [](int x){return p[x];}
	Line(const Line & l){
		p[0] = l.p[0]; p[1] = l.p[1];
		a = l.a; b = l.b; c = l.c;	
	}
	vector<dbl> getEquation()const{return vector<dbl>{a, b, c};}
	vector<dbl> getNormEquation()const{
		Line tmp(*this);
		tmp.normalizeEquation();
		return tmp.getEquation();
	}
	pt getOrth()const{
		return pt(a, b);
	}
	pt getNormOrth()const{
		Line tmp(*this);
		tmp.normalizeEquation();
		return tmp.getOrth();
	}
	int signPoint(const pt & t)const{
		dbl val = a * t.x + b * t.y + c;
		if(val < -eps)return -1;
		if(val > eps)return 1;
		return 0;
	}
	bool hasPointLine(const pt & t)const{
		return signPoint(t) == 0;
	}
	bool hasPointSeg(const pt & t)const{
		return hasPointLine(t) && p[0].dot(p[1], t) > -eps && p[1].dot(p[0], t) > -eps;
	}
	dbl distToPt(const pt & t)const{
		return fabs(a * t.x + b * t.y + c)/getOrth().length();
	}
};

struct Circle{
	pt c;
	dbl r;
	Circle(){}
	Circle(dbl x, dbl y, dbl rr):c(x, y), r(rr){}
	Circle(const pt & p, dbl rr):c(p), r(rr){}
	Circle(const Circle & x):c(x.c), r(x.r){}
	Circle& operator = (const Circle & x){
		c = x.c; r = x.r;
		return *this;
	}
	dbl area()const{return PI * sqr(r);}
	dbl diam()const{return 2 * r;}
	dbl perim()const{return diam() * PI;}
	bool operator == (const Circle & a)const{
		return c == a.c && fabs(r - a.r) < eps;
	}
	pt getByAngle(dbl ang)const{
		return c + pt(r * cos(ang), r * sin(ang));
	}
};

pt projPtLine(pt p, Line l){
	pt vec = l[1] - l[0];
	return l[0] + vec * (vec.dot(p - l[0])/vec.dot(vec));
}

vector<pt> interLineLine(Line l1, Line l2){
	if(fabs(l1.getOrth().cross(l2.getOrth())) < eps)return {};
	pt vec = l1.p[1] - l1.p[0];
	pt norm = l2.getOrth();
	dbl s = (-l2.c - norm.dot(l1.p[0]))/norm.dot(vec);
	return {pt(l1.p[0] + vec * s)};
}

vector<pt> interSegSeg(Line l1, Line l2){
	auto cand = interLineLine(l1, l2);
	vector<pt> res;
	for(auto x : cand){if(l1.hasPointSeg(x) && l2.hasPointSeg(x))res.push_back(x);}
	return res;
}

vector<pt> interLineCircle(Line l, Circle c){
	dbl d = l.distToPt(c.c);
	if(d > c.r + eps)return {};
	if(fabs(d - c.r) < eps){
		return {projPtLine(c.c, l)};
	}
	pt p = projPtLine(c.c, l);
	dbl lol = sqrt(sqr(c.r) - sqr(d));
	lol /= (l[1] - l[0]).length();
	return {p + (l[1] - l[0])*lol, p - (l[1] - l[0])*lol};
}

int interCircleCircle(Circle c1, Circle c2, vector<pt> & kek){
	if(c1.r + eps < c2.r)swap(c1, c2);
	if(c1 == c2){
		return 3;
	}
	pt vec = c2.c - c1.c;
	dbl d = vec.length();
	dbl ang = vec.angle();
	dbl longest = max(max(c1.r, c2.r), d);
	dbl per = c1.r + c2.r + d;
	if(2 * longest > per + eps)return 0;
	if(abs(2 * longest - per) < 2 * eps){kek[0] = c1.getByAngle(ang); return 1;}
	dbl cang = acos((sqr(c1.r) + sqr(d) - sqr(c2.r))/(2*c1.r*d));
	kek[0] = c1.getByAngle(ang + cang); kek[1] = c1.getByAngle(ang - cang);
	return 2;
}

int tangentsPtCircle(pt p, Circle c, vector<pt> & kek){
	dbl d = (c.c - p).length();
	if(d < c.r - eps)return 0;
	if(fabs(d - c.r) < eps){kek[0] = p; return 1;}
	dbl ang = acos(c.r/d);
	pt l = c.c + (p - c.c).rotate(ang) * (c.r/d), r = c.c + (p - c.c).rotate(-ang) * (c.r/d);
	kek[0] = l; kek[1] = r;
	return 2;
}

vector<Line> outerTangents(Circle c1, Circle c2){
	if(c1 == c2){return {Line(0, 0, 0)};}
	if(c1.r > c2.r)swap(c1, c2);
	dbl d = (c1.c - c2.c).length();
	if(c1.r + d < c2.r - eps)return {};
	if(fabs(c1.r - c2.r) < eps){
		dbl ang = (c2.c - c1.c).angle();
		pt l = c1.getByAngle(ang + PI/2), r = c1.getByAngle(ang - PI/2);	
		return {{l, l + (c2.c - c1.c)}, {r, r + (c2.c - c1.c)}};
	}
	pt p = c2.c + (c2.c - c1.c) * (c2.r/(c2.r - c1.r));
	if(c1.r + d < c2.r + eps){
		return {{p, p + (c2.c - c1.c).rotate(PI/2)}};
	}
	dbl ang = atan((c2.r - c1.r)/d);
	return {{p, p + (c1.c - p).rotate(ang)}, {p, p + (c1.c - p).rotate(-ang)}};
}

vector<Line> innerTangents(Circle c1, Circle c2){
	if(c1 == c2){return {};}
	if(c1.r > c2.r)swap(c1, c2);
	dbl d = (c1.c - c2.c).length();
	if(d < c1.r + c2.r - eps)return {};
	pt p = c1.c + (c2.c - c1.c) * (c1.r/(c1.r + c2.r));
	if(d < c1.r + c2.r + eps){
		return {{p, p + (c1.c - p).rotate(PI/2)}};
	}
	dbl ang = acos(c1.r/(p - c1.c).length());
	dbl cang = (p - c1.c).angle();
	pt l = c1.getByAngle(cang + ang), r = c1.getByAngle(cang - ang);
	return {{p, l}, {p, r}};
}

vector<Line> allTangents(Circle c1, Circle c2){
	auto kek = outerTangents(c1, c2), bishkek = innerTangents(c1, c2);
	for(auto lol : kek)bishkek.push_back(lol);
	return bishkek;
}

dbl angle(pt l, pt mid, pt r){
	l -= mid; r -= mid;
	return atan2(l.cross(r), l.dot(r));
}

struct Polygon{
	vector<pt> p;
	Polygon():p(vector<pt>()){}
	Polygon(vector<pt> pts):p(pts){}
	int nxt(int i){return (i + 1 == (int)p.size()) ? 0 : (i + 1);}
	dbl area(){
		dbl res = 0;
		for(int i = 0; i < (int)p.size(); i++)res += p[i].cross(p[nxt(i)]);
		return res/2;
	}
	void orientCCW(){
		if(area() < 0)reverse(p.begin(), p.end());
	}
	bool insidePt(pt a){
		for(int i = 0; i < (int)p.size(); i++){
			if(Line(p[i], p[nxt(i)]).hasPointSeg(a))return true;
		}
		int wn = 0;
		for(int i = 0; i < (int)p.size(); i++){
			int j = nxt(i);
			if(p[i].y < a.y + eps){
				if(a.y + eps < p[j].y){
					if(p[i].cross(p[j], a) > eps)++wn;
				}
			}
			else{
				if(p[j].y < a.y + eps){
					if(p[i].cross(p[j], a) < -eps)--wn;
				}
			}
		}
		return wn != 0;
	}
};

struct item{
	dbl ang;
	int w;
	item(){}
	item(dbl _ang, int _w):ang(_ang), w(_w){}
};

bool operator < (const item & l, const item & r){
	return (r.ang - l.ang > eps) || (fabs(r.ang - l.ang) < eps && l.w > r.w);
}

vector<item> lol;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	pt start;
	int huy_x, huy_y;
	long long v, t;
	cin >> huy_x >> huy_y >> v >> t;
	start = {huy_x, huy_y};
	v *= t;
	Circle kek(0, 0, v);
	int n;
	int bal = 0;
	cin >> n;
	lol.resize(2*n);
	int sooqa = 0;
	vector<pt> curr(3);
	for(int i = 0; i < n; i++){
		Circle tmp;
		int x, y, r;
		cin >> x >> y >> r;
		tmp.c.x = x; tmp.c.y = y; tmp.r = r;
		tmp.c.x -= start.x; tmp.c.y -= start.y;
		if((x - huy_x) * 1ll * (x - huy_x) + (y - huy_y) * 1ll * (y - huy_y) <= r * 1ll * r){cout << 1; return 0;}
		if(fabs(tmp.r) < eps)continue;
		//if((tmp.c - pt(0, 0)).length() < kek.r + eps){
		    
			int sz = tangentsPtCircle({0, 0}, tmp, curr);
			if(curr[0].length() < v + eps){
			dbl angl = curr[0].angle(), angr = curr[1].angle();
			if(angl < 0)angl += 2 * PI;
			if(angr < 0)angr += 2 * PI;
			if(angl > angr)swap(angl, angr);
			if(angr - angl > PI - eps){lol[sooqa++] = item(angr, 1); lol[sooqa++] = item(angl, -1); bal++;}
			else {lol[sooqa++] = item(angr, -1); lol[sooqa++] = item(angl, 1);}
			continue;}
        //}
		sz = interCircleCircle(kek, tmp, curr);
		if(sz < 2)continue;
		dbl angl = curr[0].angle(), angr = curr[1].angle();
		if(angl < 0)angl += 2 * PI;
		if(angr < 0)angr += 2 * PI;
		if(angl > angr)swap(angl, angr);
		if(angr - angl > PI - eps){lol[sooqa++] = item(angr, 1); lol[sooqa++] = item(angl, -1); bal++;}
		else {lol[sooqa++] = item(angr, -1); lol[sooqa++] = item(angl, 1);}
	}
	if(sooqa == 0){
		cout << 0;
		return 0;
	}
	sort(lol.begin(), lol.begin() + sooqa);
	dbl no = 0;
	dbl prv = lol[sooqa - 1].ang;
	for(int i = 0; i < sooqa; i++){
		if(bal == 0){
			if(prv < lol[i].ang)no += lol[i].ang - prv;
			else no += lol[i].ang + (2 * PI - prv);
		}
		bal += lol[i].w;
		prv = lol[i].ang;
	}
	cout.precision(12);
	cout << fixed << 1 - no/(2*PI);
	return 0;
}