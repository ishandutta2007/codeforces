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
fixed<<setprecision(/*<**************************><**************************>*/10);run();return 0;}
//------------------------------------------------------------------------------------------------//

struct SAT2 {
	vector<Vi> G;
	Vi values, order;
	vector<bool> flags;

	SAT2(int n) { G.resize(n*2); }

	bool solve() {
		values.assign(sz(G)/2+1, -1);
		flags.assign(sz(G), 0);
		rep(i, 0, sz(G)) dfs1(i);
		while (!order.empty()) {
			if (!dfs2(order.back()^1, 1)) return 0;
			order.pop_back();
		}
		return 1;
	}

	void dfs1(int i) {
		if (flags[i]) return;
		flags[i] = 1;
		each(e, G[i]) dfs1(e);
		order.pb(i);
	}

	bool dfs2(int i, bool first) {
		if (!flags[i]) return 1;
		flags[i] = 0;
		if (values[i/2+1] >= 0) return first;
		values[i/2+1] = i&1;
		each(e, G[i]) if (!dfs2(e, 0)) return 0;
		return 1;
	}

	void imply(int i, int j) {
		i = max(i*2-1, -i*2-2);
		j = max(j*2-1, -j*2-2);
		G[i].pb(j);
		G[i^1].pb(j^1);
	}

	void or_(int i, int j) { imply(-i, j); }

	int addVar() {
		G.resize(sz(G)+2); return sz(G)/2;
	}

	void atMostOne(Vi& vars) {
		int x = addVar();
		each(i, vars) {
			int y = addVar();
			imply(x, y);
			imply(i, -x);
			imply(i, x);
			x = y;
		}
	}
};

void run() {
	int n, m; cin >> n >> m;
	SAT2 sat(n);

	while (m--) {
		int a, b, c; cin >> a >> b >> c;
		c = (c ? 1 : -1);
		sat.imply(a*c, b);
		sat.imply(b*c, a);
	}

	if (!sat.solve()) {
		cout << "Impossible\n";
		return;
	}

	Vi ans;
	rep(i, 1, n+1) if (sat.values[i] == 1) ans.pb(i);

	cout << sz(ans) << '\n';
	each(x, ans) cout << x << ' ';
	cout << '\n';
}