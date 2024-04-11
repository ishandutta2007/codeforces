//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define pb push_back
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

constexpr dbl eps = 1e-12;
constexpr dbl PI = 2 * acos(0);

constexpr inline dbl safe_sqrt(dbl x){
	return x < 0 ? 0 : sqrt(x);
}

constexpr inline dbl safe_acos(dbl x){
	return x < -1 ? acos(-1) : (x > 1 ? acos(1) : acos(x));
}

constexpr inline dbl safe_asin(dbl x){
	return x < -1 ? asin(-1) : (x > 1 ? asin(1) : asin(x));
}

constexpr inline dbl sqr(dbl x){
	return x * x;
}

constexpr inline bool eq(dbl x, dbl y){
	return fabs(x - y) < eps;
}

constexpr inline bool gt(dbl x, dbl y){
	return x > y + eps;
}

constexpr inline bool lt(dbl x, dbl y){
	return y > x + eps;
}

constexpr inline bool ge(dbl x, dbl y){
	return !lt(x, y);
}

constexpr inline bool le(dbl x, dbl y){
	return !gt(x, y);
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
	pt& operator /= (dbl a){assert(fabs(a) > eps); x /= a; y /= a; return *this;}
	bool isZero()const{return fabs(x) < eps && fabs(y) < eps;}
	bool operator == (const pt & a)const{return (*this - a).isZero();}
	bool operator != (const pt & a)const{return !(*this == a);}
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
	void normalizeSelf(dbl len = 1.0){*this /= length(); *this *= len;}
	pt normalize(dbl len = 1.0)const{
		pt res(*this);
		res.normalizeSelf(len);
		return res;
	}
	dbl dist(const pt & a)const{return (*this - a).length();}
	dbl angle()const{return atan2(y, x);}
	void rotateSelf(dbl phi){
		dbl pcos = cos(phi), psin = sin(phi);
		dbl nx = x * pcos - y * psin, ny = y * pcos + x * psin;
		x = nx; y = ny;
	}
	void rotateSelf(dbl cosphi, dbl sinphi){
		dbl nx = x * cosphi - y * sinphi, ny = y * cosphi + x * sinphi;
		x = nx; y = ny;
	}
	pt rotate(dbl phi)const{
		pt res(*this);
		res.rotateSelf(phi);
		return res;
	}
	pt rotate(dbl cosphi, dbl sinphi)const{
		pt res(*this);
		res.rotateSelf(cosphi, sinphi);
		return res;
	}
	void out()const{
		cout << fixed << x << " " << y << '\n';
	}
	void outf()const{
		printf("%.15lf %.15lf\n", (double)x, (double)y);
	}
};

bool lexComp(const pt & l, const pt & r){
	if(fabs(l.x - r.x) > eps){
		return l.x < r.x;
	}
	else return l.y < r.y;
}

dbl angle(pt l, pt mid, pt r){
	l -= mid; r -= mid;
	return atan2(l.cross(r), l.dot(r));
}

inline pt trBary(pt a, pt b, pt c, dbl wa, dbl wb, dbl wc){
	return (a * wa + b * wb + c * wc)/(wa + wb + wc);
}

inline pt trCent(pt a, pt b, pt c){
	return trBary(a, b, c, 1, 1, 1);
}

inline pt trIncent(pt a, pt b, pt c){
	return trBary(a, b, c, (b - c).length(), (c - a).length(), (a - b).length());
}

inline pt trCirc(pt a, pt b, pt c){
	dbl la = (b - c).sqrLength(), lb = (c - a).sqrLength(), lc = (a - b).sqrLength();
	return trBary(a, b, c, la * (lb + lc - la), lb * (lc + la - lb), lc * (la + lb - lc));
}

inline pt trOrth(pt a, pt b, pt c){
	dbl la = (b - c).sqrLength(), lb = (c - a).sqrLength(), lc = (a - b).sqrLength();
	return trBary(a, b, c, (la + lb - lc) * (la + lc - lb), (lb + la - lc) * (lb + lc - la), (lc + la - lb) * (lc + lb - la));
}

inline pt trExc(pt a, pt b, pt c){
	dbl la = (b - c).length(), lb = (c - a).length(), lc = (a - b).length();
	return trBary(a, b, c, -la, lb, lc);
}

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
	pt& operator [](const int & i){return p[i];}
	const pt& operator[](const int & i)const{return p[i];}
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
		return hasPointLine(t) && t.dot(p[0], p[1]) < eps;
	}
	dbl distToPt(const pt & t)const{
		return fabs(a * t.x + b * t.y + c)/getOrth().length();
	}
	dbl distToPtSeg(const pt & t)const{
		if(le(p[0].dot(t, p[1]), 0))return p[0].dist(t);
		if(le(p[1].dot(t, p[0]), 0))return p[1].dist(t);
		return distToPt(t);
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
	bool hasPointCircle(const pt & p){return c.dist(p) < r + eps;}
	bool onPointCircle(const pt & p){return eq(c.dist(p), r);}
	bool inPointCircle(const pt & p){return hasPointCircle(p) && !onPointCircle(p);}
};

pt projPtLine(pt p, Line l){
	pt vec = l[1] - l[0];
	return l[0] + vec * (vec.dot(p - l[0])/vec.dot(vec));
}

pt reflectPtLine(pt p, Line l){
	pt q = projPtLine(p, l);
	return p + (q - p) * 2;
}

vector<pt> interLineLine(Line l1, Line l2){
	if(fabs(l1.getOrth().cross(l2.getOrth())) < eps){
		if(l1.hasPointLine(l2[0]))return {l1[0], l1[1]};
		else return {};
	}
	pt u = l2[1] - l2[0];
	pt v = l1[1] - l1[0];
	dbl s = u.cross(l2[0] - l1[0])/u.cross(v);
	return {pt(l1[0] + v * s)};
}

vector<pt> interSegSeg(Line l1, Line l2){
	if(l1[0] == l1[1]){
		if(l2[0] == l2[1]){
			if(l1[0] == l2[0])return {l1[0]};
			else return {};
		}
		else{
			if(l2.hasPointSeg(l1[0]))return {l1[0]};
			else return {};
		}
	}
	if(l2[0] == l2[1]){
		if(l1.hasPointSeg(l2[0]))return {l2[0]};
		else return {};
	}
	auto li = interLineLine(l1, l2);
	if(li.empty())return li;
	if(li.size() == 2){
		if(!lexComp(l1[0], l1[1]))swap(l1[0], l1[1]);
		if(!lexComp(l2[0], l2[1]))swap(l2[0], l2[1]);
		vector<pt> res(2);
		if(lexComp(l1[0], l2[0]))res[0] = l2[0]; else res[0] = l1[0];
		if(lexComp(l1[1], l2[1]))res[1] = l1[1]; else res[1] = l2[1];
		if(res[0] == res[1])res.pop_back();
		if((int)res.size() == 2 && lexComp(res[1], res[0]))return {};
		else return res;
	}
	pt cand = li[0];
	if(l1.hasPointSeg(cand) && l2.hasPointSeg(cand))return {cand};
	else return {};
}

vector<pt> interLineSeg(Line l1, Line l2){
	if(abs((l1[0] - l1[1]).cross(l2[0] - l2[1])) < eps){
		if(l1.hasPointLine(l2[0])){if(lexComp(l2[1], l2[0])) return {l2[1], l2[0]}; else return {l2[0], l2[1]};}
		else return {};
	}
	pt cand = interLineLine(l1, l2)[0];
	if(l2.hasPointSeg(cand))return {cand};
	else return {};
}

vector<pt> interLineCircle(Line l, Circle c){
	dbl d = l.distToPt(c.c);
	if(d > c.r + eps)return {};
	if(fabs(d - c.r) < eps){
		return {projPtLine(c.c, l)};
	}
	pt p = projPtLine(c.c, l);
	dbl lol = safe_sqrt(sqr(c.r) - sqr(d));
	lol /= (l[1] - l[0]).length();
	return {p + (l[1] - l[0])*lol, p - (l[1] - l[0])*lol};
}

vector<pt> interSegCircle(Line l, Circle c){
	auto cand = interLineCircle(l, c);
	vector<pt> res;
	for(pt p : cand)if(l.hasPointSeg(p))res.push_back(p);
	return res;
}

vector<pt> interCircleCircle(Circle c1, Circle c2){
	if(c1.r + eps < c2.r)swap(c1, c2);
	if(c1 == c2){
		return {c1.getByAngle(0), c1.getByAngle(PI/2), c1.getByAngle(PI)};
	}
	pt vec = c2.c - c1.c;
	dbl d = vec.length();
	dbl ang = vec.angle();
	dbl longest = max(max(c1.r, c2.r), d);
	dbl per = c1.r + c2.r + d;
	if(2 * longest > per + eps)return {};
	if(abs(2 * longest - per) < 2 * eps)return {c1.getByAngle(ang)};
	dbl cang = safe_acos((sqr(c1.r) + sqr(d) - sqr(c2.r))/(2*c1.r*d));
	return {c1.getByAngle(ang - cang), c1.getByAngle(ang + cang)};
}

vector<pt> tangentsPtCircle(pt p, Circle c){
	dbl d = (c.c - p).length();
	if(d < c.r - eps)return {};
	if(fabs(d - c.r) < eps)return {p};
	dbl ang = safe_acos(c.r/d);
	dbl cang = (p - c.c).angle();
	return {c.getByAngle(cang - ang), c.getByAngle(cang + ang)};
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
	pt p = c2.c + (c1.c - c2.c) * (c2.r/(c2.r - c1.r));
	if(c1.r + d < c2.r + eps){
		return {{p, p + (c1.c - c2.c).rotate(PI/2)}};
	}
	dbl ang = safe_asin((c2.r - c1.r)/d);
	return {{p, p + (c1.c - p).rotate(ang)}, {p, p + (c1.c - p).rotate(-ang)}};
}

vector<Line> innerTangents(Circle c1, Circle c2){
	if(c1 == c2){return {};}
	if(c1.r < c2.r)swap(c1, c2);
	dbl d = (c1.c - c2.c).length();
	if(d < c1.r + c2.r - eps)return {};
	pt p = c1.c + (c2.c - c1.c) * (c1.r/(c1.r + c2.r));
	if(d < c1.r + c2.r + eps){
		return {{p, p + (c1.c - p).rotate(PI/2)}};
	}
	dbl ang = safe_acos(c1.r/(p - c1.c).length());
	dbl cang = (p - c1.c).angle();
	pt l = c1.getByAngle(cang + ang), r = c1.getByAngle(cang - ang);
	return {{p, l}, {p, r}};
}

vector<Line> allTangents(Circle c1, Circle c2){
	auto kek = outerTangents(c1, c2), bishkek = innerTangents(c1, c2);
	for(auto lol : kek)bishkek.push_back(lol);
	return bishkek;
}

int p[3];

int get(int v){
    return v == p[v] ? v : p[v] = get(p[v]);
}

void unite(int v, int u){
    v = get(v); u = get(u);
    p[v] = u;
}

void solve(){
    iota(p, p + 3, 0);
    int chr = 0;
    Circle c[3];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> c[i].c.x >> c[i].c.y >> c[i].r;
    }
    set<pt, function<bool(pt, pt)> > pts([](const pt & l, const pt & r){return lt(l.x, r.x) || (eq(l.x, r.x) && lt(l.y, r.y));});
    for(int i = 0; i < n; i++){
        set<pt, function<bool(pt, pt)> > cpts([](const pt & l, const pt & r){return lt(l.x, r.x) || (eq(l.x, r.x) && lt(l.y, r.y));});
        for(int j = 0; j < n; j++){
            if(i == j)continue;
            auto inter = interCircleCircle(c[i], c[j]);
            if(!inter.empty()){
                unite(i, j);
            }
            for(auto cu: inter){
                cpts.insert(cu);
                if(i < j)
                    pts.insert(cu);
            }
        }
        chr += cpts.size();
    }
    chr -= (int)pts.size();
    ++chr;
    set<int> gavno;
    for(int i = 0; i < n; i++){
        int j = get(i);
        if(!gavno.count(j))
            ++chr;
        gavno.insert(j);
    }
    cout << chr << endl;
}

signed main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(15);
    cerr.precision(15);
    int T = 1;
    while(T--)
        solve();
    return 0;
}