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

constexpr ll MOD = 1e9+7;

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

Vi masks;
Vi elems;
vector<Zp> dp0, dp1, counts0, counts1;

int computeMasks() {
	vector<bool> prime(sz(masks), true);
	int bit = 1;

	rep(i, 2, sz(masks)) if (prime[i]) {
		for (int j = i; j < sz(masks); j += i) {
			prime[j] = false;
		}
		for (int j = i; j < sz(masks); j *= i) {
			for (int k = j; k < sz(masks); k += j) {
				masks[k] ^= bit;
			}
		}
		bit <<= 1;
	}

	return bit;
}

void run() {
	int n; cin >> n;
	int limit = 0;

	elems.resize(n);
	each(e, elems) {
		cin >> e;
		limit = max(limit, e);
	}

	masks.resize(limit+1);
	int nMasks = computeMasks();

	counts0.resize(limit+1, 1);
	counts1.resize(limit+1, 0);
	dp0.resize(nMasks);
	dp1.resize(nMasks);

	each(e, elems) {
		Zp a = counts0[e], b = counts1[e];
		counts1[e] += a;
		counts0[e] += b;
	}

	dp0[0] = 1;
	rep(i, 1, limit+1) {
		rep(j, 0, nMasks) {
			dp1[j] += dp0[j] * counts0[i];
			dp1[j] += dp0[j ^ masks[i]] * counts1[i];
		}

		dp0.swap(dp1);
		dp1.assign(nMasks, 0);
	}

	cout << dp0[0].x-1 << endl;
}