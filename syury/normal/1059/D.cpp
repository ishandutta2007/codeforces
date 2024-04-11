#include<bits/stdc++.h>

using namespace std;

typedef long double dbl;

constexpr dbl eps = 1e-8;
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
	Line(pt l, pt r){
		p[0] = l; p[1] = r;
		a = p[1].y - p[0].y;
		b = p[0].x - p[1].x;
		c = -a * p[0].x - b * p[0].y;
	}
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
		return eq(0, p[0].cross(p[1], t));
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
	return {c1.getByAngle(ang + cang), c1.getByAngle(ang - cang)};
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

struct Polygon{
	vector<pt> p;
	Polygon():p(vector<pt>()){}
	Polygon(vector<pt> pts):p(pts){}
	int nxt(int i)const{return (i + 1 == (int)p.size()) ? 0 : (i + 1);}
	int prv(int i)const{return (i == 0) ? ((int)p.size()-1) : (i-1);}
	int size()const{return (int)p.size();}
	pt& operator[](const int & i){return p[i];}
	const pt& operator[](const int & i)const{return p[i];}
	void push_back(pt kek){p.push_back(kek);}
	void clear(){p.clear();}
	dbl area(){
		dbl res = 0;
		for(int i = 0; i < (int)p.size(); i++)res += p[i].cross(p[nxt(i)]);
		return res/2;
	}
	void orientCCW(){
		if(area() < 0)reverse(p.begin(), p.end());
	}
};

struct Edge{
	pt origin;
	Edge * nxt = nullptr;
	Edge * prv = nullptr;
	Edge * twin = nullptr;
	int site_id = -1;
	bool alive = true;
};

inline Line get_edge(Edge* e){
	if(e->prv == nullptr)
		return Line(e->twin->origin + e->origin, e->twin->origin);
	if(e->nxt == nullptr)
		return Line(e->origin, e->origin + e->twin->origin);
	else
		return Line(e->origin, e->nxt->origin);
}

inline bool on_edge(pt p, Edge* e){
	if(e->prv == nullptr){
		return ge(e->twin->origin.dot(p, e->twin->origin + e->origin), 0);
	}
	if(e->nxt == nullptr){
		return ge(e->origin.dot(p, e->origin + e->twin->origin), 0);
	}
	else return le(p.dot(e->origin, e->twin->origin), 0);
}

struct AddedVertex{
	pt p;
	int cell;
	Edge* e;
};

inline pt trCirc(pt a, pt b, pt c){
	return interLineLine(Line((a + b)/2, (a + b)/2 + Line(a, b).getOrth()), Line((a + c)/2, (a + c)/2 + Line(a, c).getOrth()))[0];
}

void clean_prefix(Edge *start, Edge *finish, pt breakpoint, Edge *in){
	Edge *e;
	for(e = start; e != finish; e = e->prv){
		e->alive = e->twin->alive = false;
	}
	if(e->prv != nullptr && breakpoint == e->origin){
		e->alive = e->twin->alive = false;
		e = e->prv;
	}
	e->nxt = in->twin;
	in->twin->prv = e;
}

void clean_segment(Edge *start, Edge *finish, pt fbreakpoint, pt sbreakpoint, Edge *in){
	Edge *e = start->prv;
	if(start->nxt != nullptr && start->nxt->origin == fbreakpoint){
		start->alive = start->twin->alive = false;
		start->nxt->prv = in->twin;
		in->twin->nxt = start->nxt;
		e = start;
	}
	else{
		start->origin = fbreakpoint;
		start->prv = in->twin;
		in->twin->nxt = start;
	}
	for(; e != finish; e = e->prv){
		e->alive = e->twin->alive = false;
	}
	if(finish->prv != nullptr && finish->origin == sbreakpoint){
		finish->alive = finish->twin->alive =false;
		finish = finish->prv;
	}
	finish->nxt = in->twin;
	in->twin->prv = finish;
}

void clean_suffix(Edge *start, Edge *finish, pt breakpoint, Edge *in){
	Edge *e;
	for(e = start; e != finish; e = e->nxt){
		if(e->nxt != nullptr && e->nxt->origin == breakpoint)break;
		e->alive = e->twin->alive = false;
	}
	if(e->nxt != nullptr && e->nxt->origin == breakpoint){e->alive = e->twin->alive = false; e = e->nxt;}
	e->origin = breakpoint;
	e->prv = in;
	in->nxt = e;
}

vector<Edge*> farthest_point(vector<pt> p){
	int n = p.size();
	mt19937 rnd(time(0));
	vector<int> what_on(n), where_is(n);
	for(int i = 0; i < n; i++){
		what_on[i] = i;
		where_is[i] = i;
		int j = rnd()%(i + 1);
		if(j < 0)j += i + 1;
		swap(p[i], p[j]);
		swap(where_is[what_on[j]], where_is[what_on[i]]);
		swap(what_on[i], what_on[j]);
	}
	if(lt(p[0].cross(p[1], p[2]), 0)){
		swap(p[2], p[1]);
		swap(where_is[what_on[2]], where_is[what_on[1]]);
		swap(what_on[2], what_on[1]);
	}
	vector<int> cw(p.size()), ccw(p.size());
	vector<int> lp(p.size()), rp(p.size());
	for(int i = 0; i < n; i++){
		rp[i] = where_is[(what_on[i] + 1) < n ? what_on[i] + 1 : 0];
		lp[i] = where_is[(what_on[i] - 1) >= 0 ? what_on[i] - 1 : (n - 1)];
	}
	for(int i = n - 1; i >= 3; i--){
		cw[i] = lp[i];
		ccw[i] = rp[i];
		rp[lp[i]] = rp[i];
		lp[rp[i]] = lp[i];
	}
	pt cc = trCirc(p[0], p[1], p[2]);
	vector<Edge*> ans;
	vector<Edge*> most_ccw(n, nullptr);
	vector<Edge*> e01, e02, e12;
	pt d01, d02, d12;
	pt m01, m02, m12;
	Edge *fe, *se;
	Line l1, l2;
	pt v1, v2;
	d01 = Line(p[0], p[1]).getOrth();
	d02 = Line(p[0], p[2]).getOrth();
	d12 = Line(p[1], p[2]).getOrth();
	//0
	fe = new Edge; se = new Edge;
	se->origin = cc;
	most_ccw[0] = se;
	if(gt(p[1].cross(p[0], p[1] + d01), 0))d01 *= -1;
	fe->origin = d01;
	fe->nxt = se;
	se->prv = fe;
	fe->site_id = se->site_id = 0;
	ans.push_back(fe); ans.push_back(se);
	//1	
	fe = new Edge; se = new Edge;
	se->origin = cc;
	most_ccw[1] = se;
	if(gt(p[2].cross(p[1], p[2] + d12), 0))d12 *= -1;
	fe->origin = d12;
	fe->nxt = se;
	se->prv = fe;
	fe->site_id = se->site_id = 1;
	ans.push_back(fe); ans.push_back(se);
	//2
	fe = new Edge; se = new Edge;
	se->origin = cc;
	most_ccw[2] = se;
	if(gt(p[0].cross(p[2], p[0] + d02), 0))d02 *= -1;
	fe->origin = d02;
	fe->nxt = se;
	se->prv = fe;
	fe->site_id = se->site_id = 2;
	ans.push_back(fe); ans.push_back(se);
	//twins
	most_ccw[0]->twin = most_ccw[2]->prv; most_ccw[2]->prv->twin = most_ccw[0];
	most_ccw[1]->twin = most_ccw[0]->prv; most_ccw[0]->prv->twin = most_ccw[1];
	most_ccw[2]->twin = most_ccw[1]->prv; most_ccw[1]->prv->twin = most_ccw[2];
	vector<Edge*> startwith(n);
	for(int i = 3; i < n; i++){
		int cell = ccw[i];
		Edge* e = most_ccw[cell];
		Edge* last = nullptr;
		Edge* last_e = nullptr;
		Line bs = Line((p[cell] + p[i])/2.0, (p[cell] + p[i])/2.0 + Line(p[i], p[cell]).getOrth());
		pt pp;
		pt edir;
		bool was = false;
		vector<AddedVertex> v;
		startwith[ccw[i]] = e;
		while(true){
			assert(e != nullptr);
			vector<pt> kek = {trCirc(p[i], p[cell], p[e->twin->site_id])};
			if(on_edge(kek[0], e)){
				v.push_back(AddedVertex{kek[0], cell, e});
				if(e->twin->site_id == cw[i]){
					startwith[cw[i]] = e->twin;
					break;
				}
				if(e->twin->prv != nullptr && e->twin->origin == kek[0])e = e->twin->prv->prv;
				else e = e->twin->prv;
				cell = e->site_id;
				startwith[cell] = e;
				if(cell == cw[i])break;
			}
			else e = e->prv;
		}
		Edge *fe, *se, *tmp;
		fe = new Edge;
		se = new Edge;
		fe->site_id = i;
		fe->twin = se;
		se->origin = v[0].p;
		se->twin = fe;
		se->site_id = ccw[i];
		Edge *keke = most_ccw[ccw[i]];
		clean_prefix(most_ccw[ccw[i]], v[0].e, v[0].p, fe);
		last = fe;
		most_ccw[ccw[i]] = se;
		ans.push_back(fe);
		ans.push_back(se);
		for(int j = 0; j + 1 < (int)v.size(); j++){
			fe = new Edge;
			se = new Edge;
			fe->site_id = i;
			fe->twin = se;
			se->origin = v[j + 1].p;
			fe->origin = v[j].p;
			se->twin = fe;
			se->site_id = v[j + 1].cell;
			fe->prv = last;
			last->nxt = fe;
			last = fe;
			clean_segment(startwith[v[j + 1].cell]->nxt, v[j + 1].e, v[j].p, v[j + 1].p, fe);
			ans.push_back(fe);
			ans.push_back(se);
		}
		fe = new Edge; se = new Edge;
		fe->site_id = i;
		fe->twin = se;
		fe->origin = v.back().p;
		se->twin = fe;
		se->site_id = cw[i];
		last->nxt = fe;
		fe->prv = last;
		most_ccw[i] = fe;
		tmp = startwith[cw[i]];
		if(tmp->nxt != nullptr && tmp->nxt->origin == v.back().p)tmp = tmp->nxt;
		clean_suffix(keke->twin, startwith[cw[i]], v[(int)v.size() - 1].p, se);
		auto ns = se->nxt;
		pt vv = Line(p[i], p[cw[i]]).getOrth();
		pt nv = (ns->nxt == nullptr) ? ns->twin->origin : (ns->twin->origin - ns->origin);
		if(lt(vv.cross(nv), 0))vv *= -1;
		se->origin = vv * -1;
		tmp = most_ccw[ccw[i]]->twin;
		ns = tmp->nxt;
		vv = Line(p[i], p[ccw[i]]).getOrth();
		nv = (ns->nxt == nullptr) ? ns->twin->origin : (ns->twin->origin - ns->origin);
		if(lt(vv.cross(nv), 0))vv *= -1;
		tmp->origin = vv * -1;
		ans.push_back(fe);
		ans.push_back(se);
	}
	vector<Edge*> out;
	for(Edge* e : ans)
		if(e->alive){e->site_id = what_on[e->site_id]; out.push_back(e);}
		else delete e;
	return out;
}

pt get(pt l, pt r){
	pt p0 = (l + r)/2;
	pt vec = Line(l, r).getOrth();
	dbl a = vec.x * vec.x;
	dbl b = -2 * l.y * vec.y + 2 * p0.x * vec.x - 2 * l.x * vec.x;
	dbl c = -2 * l.y * p0.y + l.y * l.y + p0.x * p0.x + l.x * l.x - 2 * p0.x * l.x;
	if(eq(a, 0)){
		dbl t = -c/b;
		return p0 + vec * t;
	}
	dbl D = sqrt(b * b - 4 * a * c);
	dbl lt = (-b - D)/(2 * a), rt = (-b + D)/(2 * a);
	pt lans = p0 + vec * lt, rans = p0 + vec * rt;
	return rans.x < l.x ? lans : rans;
}

const dbl hull_eps = 1e-9;

inline bool hull_lt(dbl x, dbl y){
	return x < y - hull_eps;
}

inline bool hull_eq(dbl x, dbl y){
	return fabs(x - y) < hull_eps;
}

struct comp{
	pt base;
	comp(pt _base):base(_base){}
	bool operator ()(const pt & l, const pt & r)const{
		return base.cross(l, r) > hull_eps || (fabs(base.cross(l, r)) < hull_eps && (l - base).sqrLength() < (r - base).sqrLength() - hull_eps);
	}
};

int hull(pt *from, pt *to){
	pt *pos = from;
	for(pt *i = from + 1; i != to; i++){
		if(hull_lt((*i).x, (*pos).x) || (hull_eq((*i).x, (*pos).x) && hull_lt((*i).y, (*pos).y)))pos = i;
	}
	rotate(from, pos, to);
	sort(from + 1, to, comp(*from));
	int n = to - from;
	pt *stk = new pt[n];
	int sz = 1;
	*stk = *from;
	for(pt *i = from + 1; i != to; i++){
		if(sz < 2){*(stk + sz) = *i; ++sz; continue;}
		while(sz >= 2 && !hull_lt((*(stk + (sz - 2))).cross(*i, *(stk + (sz - 1))), 0))--sz;
		*(stk + sz) = *i;
		++sz;
	}
	memcpy(from, stk, sz * sizeof(pt));
	return sz;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<pt> p;
	pt *tmp = new pt[n];
	bool wn = false, wp = false;
	for(int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		if(y > 0)wp = true;
		else wn = true;
		tmp[i] = pt(x, y);
	}
	if(wn && wp){cout << -1; return 0;}
	if(wn)
		for(int i = 0; i < n; i++)tmp[i].y = -tmp[i].y;
	cout.precision(16);
	n = hull(tmp, tmp + n);
	dbl ans = 1e18;
	for(int i = 0; i < n; i++){
		p.push_back(tmp[i]);
	}
	delete[] tmp;
	if(n < 3){
		for(int j = 0; j < n; j++){
			pt start = pt(p[j].x, p[j].y/2);
			bool good = true;
			for(int i = 0; i < n; i++){
				if(gt(start.dist(p[i]), start.y)){
					good = false;
					break;
				}
			}
			if(good)
				ans = min(ans, start.y);
			pt tmp = start;
			for(int i = 0; i < n; i++){
				if(i == j)continue;
				pt cand = get(p[j], p[i]);
				bool kek = true;
				for(int k = 0; k < n; k++){
					if(k == i || k == j)continue;
					if(gt(cand.dist(p[k]), cand.y))kek = false;
				}
				if(kek)ans = min(ans, cand.y);
			}
		}
		cout << fixed << ans;
		return 0;
	}
	auto kek = farthest_point(p);
	vector<Edge*> start(n, nullptr);
	for(auto e : kek){
		if(e->prv == nullptr){
			start[e->site_id] = e;
		}
	}
	for(int i = 0; i < n; i++){
		if(start[i] == nullptr)
			assert(false);
		int g = 2;
		pt cand = pt(p[i].x, p[i].y/2);
		for(Edge* e = start[i]; e != nullptr; e = e->nxt){
			if(get_edge(e).hasPointLine(cand)){
				if(on_edge(cand, e))g = 1;
				else g = 0;
			}
		}
		if(g == 0){
			continue;
		}
		if(g == 1){
			ans = min(ans, cand.y);
			continue;
		}
		g = 1;
		if(gt(start[i]->origin.cross(cand - start[i]->twin->origin), 0))g = 0;
		Edge* e = start[i]->nxt;
		for(; e != nullptr; e = e->nxt){
			if(e->nxt == nullptr){
				if(lt(e->twin->origin.cross(cand - e->origin), 0))g = 0;
				break;
			}
			if(lt(e->origin.cross(e->nxt->origin, cand), 0))g = 0;
		}
		if(g == 1)
			ans = min(ans, cand.y);
	}
	for(auto e : kek){
		int i = e->site_id, j = e->twin->site_id;
		auto cand = get(p[i], p[j]);
		Line l((p[i] + p[j])/2.0, (p[i] + p[j])/2.0 + Line(p[i], p[j]).getOrth());
		if(fabs(l[0].cross(l[1], cand)) > 1e-4)continue;
		if(on_edge(cand, e)){
			ans = min(ans, cand.y);
		}
	}
	cout << fixed << (long double)ans;
	return 0;
}