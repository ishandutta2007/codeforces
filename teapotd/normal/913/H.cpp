template<class T>struct _iter_wrapper{T begin_,end_;T begin(){return begin_;}T end(){return end_;}};
template<class T>_iter_wrapper<const T*>span(const T*arr, int n){return _iter_wrapper<const T*>{arr,
arr+n};} template<class T, int N>_iter_wrapper<const T*>span(const T(&arr)[N]) {return span(arr,N);}
#define _deb(...)(_printDebug/*                               */(__LINE__,#__VA_ARGS__,__VA_ARGS__))
#define rep(i,b,e)/*                                                      */for(int i=(b);i<(e);i++)
#define sz(x)/*                                                                    */int((x).size())
#define mp/*                                                                             */make_pair
#include/*                                                                         */<bits/stdc++.h>
#ifdef/*                                                                                       */LOC
#define/*                                                                                 */deb _deb
#elif/*                                                                                       */true
#define/*                                                                                 */deb(...)
#endif/*                                                                                          */
#define/*                                                                                  */x first
#define/*                             ("`-''-/").___..--''"`-._                           */y second
#define pb/*                          `6_ 6  )   `-.  (     ).`-.__.`)                   */push_back
#define each(a,x/*                    (_Y_.)'  ._   )  `._ `. ``-..-`             */)for(auto&a:(x))
#define all(x)(x)/*                  _..`--'_..-_/  /--'_.' ,'                  */.begin(),(x).end()
#define DBP(...)void print(/*      (il),-''  (li),'  ((!.-'    */...){DD(#__VA_ARGS__,__VA_ARGS__);}
using namespace std;using namespace rel_ops;using ll=long long;using ull=unsigned long long;using Vi
=vector<int>;using Vll=vector<ll>;using Vull=vector<ull>; using Pii=pair<int,int>; template<class T,
class V> auto operator<<(T& out,V val)->decltype(val.print(0),out){out<<"{";val.print();return out<<
"}";}template<class T, class V>auto operator<<(T&out,V val)->decltype(get<1>(val), out){return out<<
"("<<val.x<<", "<<val.y<<")";} template<class T,class V>auto operator<<(T &out,V val)->decltype(all(
val),out){out << "[";bool comma=false;for(auto elem:val){if(comma)out << ", ";out<<elem;comma=true;}
return out<<"]";}void DD(...){}template<class T,class...S>void DD(const char*format,T elem,S...rest)
{int braces=0;while(*format&&(braces>0||*format!=',')){if(*format=='('||*format=='['||*format=='{'||
*format=='<'){braces++;}if (*format==')'||*format==']'||*format=='}'||*format=='>') braces--;cerr<<*
format++;} cerr<<": "<<elem<<*format++;DD(format, rest...);} template<class...T>void _printDebug(int
line,const char*format, T...elems){cerr<<'<';if(line<10)cerr<<'0';if(line<100)cerr<<'0';cerr<<line<<
"> ";DD(format,elems...);cerr<<endl;}void run();int main(){cin.sync_with_stdio(0); cin.tie(0);cout<<
fixed<<setprecision(/**********************> by teapotd <**********************/10);run();return 0;}
//------------------------------------------------------------------------------------------------//

constexpr ll MOD = 998244353;

struct Zp {
	ll x;
	Zp(ll a = 0) { x=a%MOD; if (x<0) x+=MOD; }
	static Zp wrap(ll a){Zp t; t.x=a; return t;}

	Zp operator+(Zp r) const {
		ll a = x+r.x;
		return wrap(a >= MOD ? a-MOD : a);
	}

	Zp operator-(Zp r) const {
		ll a = x-r.x;
		return wrap(a < 0 ? a+MOD : a);
	}

	Zp operator*(Zp r) const {
		return wrap(x*r.x % MOD);
	}

	Zp operator/(Zp r) const {
		return wrap(x*r.inv().x % MOD);
	}

	Zp inv() const { return pow(MOD-2); }

	Zp pow(ll e) const {
		Zp t = wrap(1), m = *this;
		while (e) {
			if (e & 1) t *= m;
			e >>= 1;
			m *= m;
		}
		return t;
	}

	Zp& operator+=(Zp r){ return *this=*this+r; }
	Zp& operator-=(Zp r){ return *this=*this-r; }
	Zp& operator*=(Zp r){ return *this=*this*r; }
	Zp& operator/=(Zp r){ return *this=*this/r; }
	Zp operator-() const { return wrap(MOD-x); }

	void print(...) {
		if (x < 1000) cerr << x;
		else if (x > MOD-1000) cerr << -MOD+x;
		else if (inv().x < 1000) cerr << "1/" << inv().x;
		else if (inv().x > MOD-1000) cerr << "1/" << -MOD+inv().x;
		else cerr << x;
	}
};

// ---

constexpr ll SCALE = 1e6;
using Poly = vector<Zp>;

struct Segment {
	ll a, b;
	Poly poly;
	DBP(a, b, poly);
};

struct Event {
	int seg, type;
	ll pos;

	bool operator<(const Event& r) const {
		return pos < r.pos;
	}
};

vector<Segment> segs;

void polyAdd(Poly& dst, const Poly& src) {
	dst.resize(max(sz(dst), sz(src)));
	rep(i, 0, min(sz(dst), sz(src))) dst[i] += src[i];
}

void polySub(Poly& dst, const Poly& src) {
	dst.resize(max(sz(dst), sz(src)));
	rep(i, 0, min(sz(dst), sz(src))) dst[i] -= src[i];
}

void integrate(Poly& p) {
	p.pb(0);
	for (int i = sz(p)-1; i > 0; i--) p[i] = p[i-1] / i;
	p[0] = 0;
}

Poly subst1(const Poly& p) {
	Poly ret(sz(p));

	rep(n, 0, sz(p)) {
		Zp factor = p[n];
		rep(i, 0, n+1) {
			ret[i] += factor * ((n-i)&1 ? -1 : 1);
			factor *= Zp(n-i) / (i+1);
		}
	}
	return ret;
}

Zp polyEval(const Poly& p, Zp x) {
	Zp a = 1, ret = 0;
	each(b, p) {
		ret += a*b;
		a *= x;
	}
	return ret;
}

ll getAns() {
	Zp ans = 0;
	each(seg, segs) {
		Segment tmp = seg;
		integrate(tmp.poly);
		ans += polyEval(tmp.poly, Zp(tmp.b)/SCALE) - polyEval(tmp.poly, Zp(tmp.a)/SCALE);
	}
	return ans.x;
}

void applyStep() {
	double limit; cin >> limit;
	ll scaled = ll(limit*SCALE+0.5);

	vector<Event> events;
	vector<Poly> integrated, integrated1;
	vector<Zp> whole;
	
	rep(i, 0, sz(segs)) {
		events.pb({ i, 0, segs[i].a });
		events.pb({ i, 1, segs[i].b });
		events.pb({ i, 2, segs[i].a+SCALE });
		events.pb({ i, 3, segs[i].b+SCALE });

		integrated.pb(segs[i].poly);
		integrated1.pb(segs[i].poly);
		auto &poly0 = integrated.back(), &poly1 = integrated1.back();

		integrate(poly0);
		integrate(poly1);
		poly1 = subst1(poly1);

		Zp val0 = polyEval(poly0, Zp(segs[i].a) / SCALE);
		Zp val1 = polyEval(poly0, Zp(segs[i].b) / SCALE);

		whole.pb(val1-val0);
		poly0[0] -= val0;
		poly1[0] -= val1;
		each(x, poly1) x = -x;
	}

	sort(all(events));

	Segment built{0, 0, {}};
	vector<Segment> newSegs;

	each(e, events) {
		if (e.pos >= scaled) break;

		if (e.pos != built.a) {
			built.b = e.pos;
			newSegs.pb(built);
			built.a = e.pos;
		}

		if (e.type == 0) {
			polyAdd(built.poly, integrated[e.seg]);
		} else if (e.type == 1) {
			polySub(built.poly, integrated[e.seg]);
			built.poly[0] += whole[e.seg];
		} else if (e.type == 2) {
			built.poly[0] -= whole[e.seg];
			polyAdd(built.poly, integrated1[e.seg]);
		} else {
			polySub(built.poly, integrated1[e.seg]);
		}
	}

	if (built.a < scaled) {
		built.b = scaled;
		newSegs.pb(built);
	}

	segs = move(newSegs);
	deb(segs, getAns());
	cerr << endl;
}

void run() {
	int n; cin >> n;
	double limit; cin >> limit;
	ll scaled = ll(limit*SCALE+0.5);

	segs.pb({ 0, min(scaled, SCALE), {1} });
	deb(segs, getAns());
	rep(i, 1, n) applyStep();

	cout << getAns() << endl;
}