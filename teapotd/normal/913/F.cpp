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

ll modInv(ll a, ll m) {
	if (a == 1) return 1;
	return ((a - modInv(m%a, a))*m + 1) / a;
}

ll umod(ll a, ll m) {
	a %= m; return (a >= 0 ? a : a+m);
}

struct Zp {
	ll x;
	Zp(ll y = 0) {
		x = (y < 0 || y >= MOD ? umod(y, MOD) : y);
	}

	Zp operator+(Zp r) const { return x+r.x; }
	Zp operator-(Zp r) const { return x-r.x; }
	Zp operator*(Zp r) const { return x*r.x; }
	Zp operator/(Zp r) const {
		return x * modInv(r.x, MOD);
	}

	Zp inv() const { return modInv(x, MOD); }

	Zp pow(ll e) const {
		if (!e) return 1;
		Zp t = pow(e/2);
		return t*t * (e & 1 ? x : 1);
	}

	void print(...) { cerr << x; }

	Zp& operator+=(Zp r){ return *this=*this+r; }
	Zp& operator-=(Zp r){ return *this=*this-r; }
	Zp& operator*=(Zp r){ return *this=*this*r; }
	Zp& operator/=(Zp r){ return *this=*this/r; }
	Zp  operator-() const { return -x; }
};

// ---

int total;
Zp prob, invProb;
vector<Zp> dp, strong, prevDominating, dominating;

void run() {
	int a, b;
	cin >> total >> a >> b;
	prob = Zp(a) / Zp(b);
	invProb = Zp(1) - prob;

	dp.assign(total+1, 0);
	strong.assign(total+1, 1);
	dominating.assign(total+1, 0);
	prevDominating.assign(total+1, 0);
	prevDominating[0] = 1;

	rep(n, 1, total+1) {
		dominating[0] = 1;
		rep(m, 1, n+1) {
			dominating[m] = prevDominating[m]*prob.pow(m) + prevDominating[m-1]*invProb.pow(n-m);
		}

		rep(m, 1, n) strong[n] -= strong[m] * dominating[m];

		if (n == 1) {
			dp[n] = 0;
		} else {
			dp[n] = strong[n] * n * (n-1) / 2;

			rep(m, 1, n) {
				Zp tmp = dp[m] + dp[n-m] + Zp(m*(m-1))/2 + m*(n-m);
				dp[n] += strong[m] * dominating[m] * tmp;
			}

			dp[n] /= Zp(1) - strong[n];
		}
		prevDominating.swap(dominating);
	}

	cout << dp[total].x << endl;
}