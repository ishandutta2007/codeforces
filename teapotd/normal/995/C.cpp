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

constexpr ll LIM = 1500000LL*1500000LL;

struct Point {
	ll x, y;
	int ans, plus, neg;
	DBP(x, y, ans, plus, neg);
};

ll n;
vector<Point> points;
Vi segs[8];
Vi remain;

int seg(Point& p) {
	ll a = (p.x > 0 ? p.x : -p.x), b = (p.y > 0 ? p.y : -p.y);
	if (p.x > 0) {
		if (p.y > 0) return a < b ? 0 : 1;
		else return a < b ? 2 : 3;
	} else {
		if (p.y > 0) return a < b ? 4 : 5;
		else return a < b ? 6 : 7;
	}
}

void dfs(int i, bool neg) {
	if (i < 0) return;
	points[i].ans = (neg ? -1 : 1);
	dfs(points[i].plus, neg);
	dfs(points[i].neg, !neg);
}

void run() {
	ll x = 0, y = 0;
	cin >> n;
	points.resize(n);

	rep(i, 0, n) {
		cin >> points[i].x >> points[i].y;
		points[i].ans = 1;
		points[i].plus = points[i].neg = -1;
		segs[seg(points[i])].pb(i);
	}

	bool ok = true;
	while (ok) {
		ok = false;
		rep(i, 0, 8) if (sz(segs[i]) > 1) {
			ok = true;
			int a = segs[i].rbegin()[0], b = segs[i].rbegin()[1];
			segs[i].resize(sz(segs[i])-2);

			int add = sz(points);
			points.pb({ points[a].x - points[b].x, points[a].y - points[b].y, 1, a, b });
			segs[seg(points[add])].pb(add);
		}
	}

	each(s, segs) each(t, s) remain.pb(t);

	rep(mask, 0, 1<<sz(remain)) {
		x = 0, y = 0;
		rep(i, 0, sz(remain)) {
			x += points[remain[i]].x * ((mask >> i) & 1 ? -1 : 1);
			y += points[remain[i]].y * ((mask >> i) & 1 ? -1 : 1);
		}

		if (x*x + y*y > LIM) continue;

		rep(i, 0, sz(remain)) dfs(remain[i], (mask >> i) & 1);
		rep(i, 0, n) cout << points[i].ans << ' ';
		cout << endl;
		return;
	}

	assert(0);
}