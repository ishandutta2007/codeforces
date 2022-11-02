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

ll x, y, mod;
unordered_map<int, Vi> paths;

ll modInv(ll a, ll m) {
	if (a == 1) return 1;
	return ((a - modInv(m%a, a))*m + 1) / a;
}

ll add(ll a, ll b) {
	a += b;
	return a < mod ? a : a-mod;
}

ll sub(ll a, ll b) {
	a -= b;
	return a >= 0 ? a : a+mod;
}

int randomPath(Vi& out, ll i, int n, bool inv) {
	while (n--) {
		switch (rand() % (i != 0 ? 3 : 2)) {
			case 0:
				i = add(i, 1);
				out.pb(inv ? 2 : 1);
				break;
			case 1:
				i = sub(i, 1);
				out.pb(inv ? 1 : 2);
				break;
			case 2:
				i = modInv(i, mod);
				out.pb(3);
				break;
		}
	}
	return int(i);
}

void op(int i) {
	if (i == 1) x = add(x, 1);
	else if (i == 2) x = sub(x, 1);
	else if (i == 3) x = modInv(x, mod);
}

void run() {
	cin >> x >> y >> mod;

	for (int i = 0; i*i < mod; i++) {
		Vi out;
		paths[randomPath(out, x, 100, false)] = move(out);
	}

	while (true) {
		Vi sec;
		int mid = randomPath(sec, y, 100, true);

		if (paths.count(mid)) {
			Vi& begin = paths[mid];
			cout << sz(begin) + sz(sec) << endl;

			each(a, begin) {
				cout << a << ' ';
				op(a);
			}

			for (int i = sz(sec)-1; i >= 0; i--) {
				cout << sec[i] << ' ';
				op(sec[i]);
			}

			cout << endl;
			assert(x == y);
			return;
		}
	}
}