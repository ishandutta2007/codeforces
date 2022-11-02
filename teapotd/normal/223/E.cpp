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

struct vec2 {
	using T = ll;
	T x{0}, y{0};

	vec2() {}
	vec2(T a, T b) : x(a), y(b) {}

	vec2 operator+(vec2 r) const {
		return {x+r.x, y+r.y};
	}
	vec2 operator-(vec2 r) const {
		return {x-r.x, y-r.y};
	}
	vec2 operator*(T r) const {
		return {x*r, y*r};
	}
	vec2 operator/(T r) const {
		return {x/r, y/r};
	}

	T dot(vec2 r) const { return x*r.x+y*r.y; }
	T cross(vec2 r) const { return x*r.y-y*r.x; }
	T dist2() const { return x*x + y*y; }

	bool operator==(vec2 r) const {
		return x == r.x && y == r.y;
	}

	bool upper() const {
		return y > 0 || (y == 0 && x > 0);
	}

	bool operator<(vec2 r) const {
		if (upper() != r.upper()) return upper();
		return cross(r) > 0;
	}

	void print(...) { cerr << x << ',' << y; }
};

// ---

struct Vert {
	Vi edges, edgesPos;
	vector<ll> prefs;
	vec2 pos;
	bool visited{false};
	DBP(edges, edgesPos, prefs, pos, visited);
};

int n, m;
vector<Vert> V;

ll dfs(int i, int from = -1) {
	if (V[i].visited) return 0;
	ll sum = 0;
	V[i].visited = true;
	V[i].prefs.pb(0);

	each(e, V[i].edges) {
		if (e != from) sum += dfs(e, i);
		V[i].prefs.pb(-sum);
	}

	sum++;
	ll sub = 0;
	rep(j, 0, sz(V[i].edges)) {
		if (V[i].edges[j] == from) sub = sum;
		V[i].prefs[j+1] += sub;
	}
	return sum;
}

void query() {
	int k; cin >> k;
	Vi cycle(k);
	each(v, cycle) cin >> v;

	ll sum = 0;

	rep(i, 0, k) {
		int cur = cycle[i];
		int next = cycle[(i+1) % k];
		sum += (V[next].pos.x - V[cur].pos.x) * (V[next].pos.y + V[cur].pos.y);
	}

	if (sum > 0) reverse(all(cycle));
	ll ans = 0;

	rep(i, 0, k) {
		int prev = cycle[(i-1+k) % k];
		int next = cycle[(i+1) % k];
		int cur = cycle[i];

		auto& vert = V[cur];
		auto cmp = [&](int a, int b) { return vert.edges[a] < b; };

		int begin = *lower_bound(all(vert.edgesPos), prev, cmp);
		int end = *lower_bound(all(vert.edgesPos), next, cmp);

		if (begin < end) {
			ans += vert.prefs[end] - vert.prefs[begin+1];
		} else {
			ans += vert.prefs[sz(vert.edges)] - vert.prefs[begin+1];
			ans += vert.prefs[end];
		}
	}

	cout << ans << endl;
}

void run() {
	cin >> n >> m;
	V.resize(n+1);

	rep(i, 0, m) {
		int a, b;
		cin >> a >> b;
		V[a].edges.pb(b);
		V[b].edges.pb(a);
	}

	int leftMost = 1;

	rep(i, 1, sz(V)) {
		cin >> V[i].pos.x >> V[i].pos.y;
		if (V[i].pos.x < V[leftMost].pos.x) leftMost = i;
	}

	V[0].pos = V[leftMost].pos - vec2(10, 0);
	V[0].edges.pb(leftMost);
	V[leftMost].edges.pb(0);

	rep(i, 0, sz(V)) {
		auto& vert = V[i];

		sort(all(vert.edges), [&](int l, int r) {
			return V[l].pos-vert.pos < V[r].pos-vert.pos;
		});

		vert.edgesPos.resize(sz(vert.edges));
		iota(all(vert.edgesPos), 0);

		sort(all(vert.edgesPos), [&](int l, int r) {
			return vert.edges[l] < vert.edges[r];
		});
	}

	dfs(0);
	int q; cin >> q;
	while (q--) query();
}