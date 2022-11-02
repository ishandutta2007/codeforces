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

int n, k;
int V[4][50];
vector<pair<Pii, Pii>> rot;
vector<pair<int, Pii>> moves;

void initRotate() {
	rep(x, 1, n) rot.pb(mp(mp(1, x), mp(1, x-1)));
	rot.pb(mp(mp(2, n-1), mp(1, n-1)));
	for (int x = n-2; x >= 0; x--) rot.pb(mp(mp(2, x), mp(2, x+1)));
	rot.pb(mp(mp(1, 0), mp(2, 0)));
}

bool rotate() {
	rep(i, 0, sz(rot)) {
		Pii from = rot[i].x, to = rot[i].y;
		if (!V[to.x][to.y]) {
			rep(j, 0, sz(rot)-1) {
				from = rot[(i+j)%sz(rot)].x, to = rot[(i+j)%sz(rot)].y;
				if (V[from.x][from.y]) {
					moves.pb(mp(V[from.x][from.y], to));
					swap(V[from.x][from.y], V[to.x][to.y]);
				}
			}
			return true;
		}
	}
	return false;
}

void run() {
	cin >> n >> k;
	rep(i, 0, 4) rep(j, 0, n) cin >> V[i][j];

	initRotate();

	rep(r, 0, 2*n) {
		if (r > 0 && !rotate()) break;

		rep(i, 1, 3) rep(j, 0, n) {
			if (V[i][j] && V[i][j] == V[i^1][j]) {
				moves.pb(mp(V[i][j], mp(i^1, j)));
				V[i][j] = 0;
			}
		}
	}

	rep(i, 1, 3) rep(j, 0, n) if (V[i][j]) {
		cout << "-1\n";
		return;
	}

	cout << sz(moves) << '\n';
	each(m, moves) cout << m.x << ' ' << m.y.x+1 << ' ' << m.y.y+1 << '\n';
}