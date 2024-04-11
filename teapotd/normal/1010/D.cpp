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

constexpr char AND = 'A';
constexpr char OR = 'O';
constexpr char XOR = 'X';
constexpr char NOT = 'N';
constexpr char IN = 'I';

struct Vertex {
	int edge1{-1}, edge2{-1};
	bool val{false}, changes{true};
	char type;
	DBP(edge1+1, edge2+1, val, changes, type);
};

vector<Vertex> G;

bool op(char type, bool a, bool b) {
	if (type == AND) return a && b;
	if (type == OR) return a || b;
	if (type == XOR) return a != b;
	if (type == NOT) return !a;
	if (type == IN) return a;
	assert(0);
}

void dfs(int i) {
	if (G[i].type == IN) return;

	if (G[i].type == NOT) {
		dfs(G[i].edge1);
		G[i].val = !G[G[i].edge1].val;
	} else {
		dfs(G[i].edge1);
		dfs(G[i].edge2);
		G[i].val = op(G[i].type, G[G[i].edge1].val, G[G[i].edge2].val);
	}
}

void dfs2(int i) {
	if (G[i].type == IN) return;

	int a = G[i].edge1, b = G[i].edge2;

	if (!G[i].changes) {
		G[a].changes = false;
		if (G[i].type != NOT) G[b].changes = false;
	}if (G[i].type == AND) {
		if (!G[a].val) G[b].changes = false;
		if (!G[b].val) G[a].changes = false;
	} else if (G[i].type == OR) {
		if (G[a].val) G[b].changes = false;
		if (G[b].val) G[a].changes = false;
	}

	dfs2(a);
	if (G[i].type != NOT) dfs2(b);
}

void run() {
	int n; cin >> n;
	G.resize(n);

	each(vert, G) {
		char tmp[8]; cin >> tmp;
		vert.type = tmp[0];

		if (vert.type == IN) {
			cin >> vert.val;
		} else if (vert.type == NOT) {
			cin >> vert.edge1;
			vert.edge1--;
		} else {
			cin >> vert.edge1 >> vert.edge2;
			vert.edge1--;
			vert.edge2--;
		}
	}

	dfs(0);
	dfs2(0);

	rep(i, 0, n) deb(i+1, G[i]);

	rep(i, 0, n) if (G[i].type == IN) {
		cout << (G[i].changes != G[0].val);
	}
	cout << endl;
}