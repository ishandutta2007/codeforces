//By TheOneYouWant
#pragma GCC optimize ("-O2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define memreset(a) memset(a,0,sizeof(a))
#define int long long int
#define testcase(t) int t;cin>>t;while(t--)
#define forstl(i,v) for(auto &i: v)
#define forn(i,e) for(int i=0;i<e;++i)
#define forsn(i,s,e) for(int i=s;i<e;++i)
#define rforn(i,s) for(int i=s;i>=0;--i)
#define rforsn(i,s,e) for(int i=s;i>=e;--i)
#define bitcount(a) __builtin_popcount(a) // set bits (add ll)
#define ln '\n'
#define getcurrtime() cerr<<"Time = "<<((double)clock()/CLOCKS_PER_SEC)<<endl
#define dbgarr(v,s,e) cerr<<#v<<" = "; forsn(i,s,e) cerr<<v[i]<<", "; cerr<<endl
#define inputfile freopen("input.txt", "r", stdin)
#define outputfile freopen("output.txt", "w", stdout)
#define dbg(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); \
stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) { cerr<<endl; }
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << "\t"; err(++it, args...);
}
template<typename T1,typename T2>
ostream& operator <<(ostream& c,pair<T1,T2> &v){
	c<<"("<<v.fi<<","<<v.se<<")"; return c;
}
template <template <class...> class TT, class ...T>
ostream& operator<<(ostream& out,TT<T...>& c){
    out<<"{ ";
    forstl(x,c) out<<x<<" ";
    out<<"}"; return out;
}
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> p64;
typedef pair<int,int> p32;
typedef pair<int,p32> p96;
typedef vector<ll> v64;
typedef vector<int> v32; 
typedef vector<v32> vv32;
typedef vector<v64> vv64;
typedef vector<p32> vp32;
typedef vector<p64> vp64;
typedef vector<vp32> vvp32;
typedef map<int,int> m32;
const int LIM=2e5+5,MOD=1e9+7;
const ld EPS = 1e-9;

int read(){
    int xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=(xx<<3)+(xx<<1)+ch-'0';ch=getchar();}
    return xx*ff;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

signed main(){
	fastio;

	ll x; cin>>x;
	vector<pair<int,p32>> v;

	set<ll> num;
	num.insert(x);
	forsn(i,2,26){
		num.insert(x * i);
		v.pb(mp(0, mp(x, (i-1) * x)));
		num.insert(x * (1<<(i-1)));
		if(x * (1<<i) <= 1e18) v.pb(mp(0, mp(x*(1<<(i-2)), x*(1<<(i-2)))));
	}
	v32 to_ins;
	forstl(k,num){
		forstl(j,num){
			to_ins.pb(k ^ j);
			v.pb(mp(1, mp(k, j)));
		}
	}
	forstl(r, to_ins) num.insert(r);

	int curr = v.size();

	p32 ansp = mp(0,0);
	p32 mul = mp(0,0);
	int addn = MOD;

	forstl(r,num){
		forstl(k,num){
			if(__gcd(r,k) == 1){
				int x0, y0, g;
				find_any_solution(r, k, 1, x0, y0, g);
				int xorig = x0, yorig = y0;
				x0 = abs(x0);
				y0 = abs(y0);
				bool p = 0;
				if(((r*x0)^(k*y0)) == 1) p = 1;
				else{
					x0 = xorig + k;
					y0 = yorig + r;
					x0 = abs(x0);
					y0 = abs(y0);
					if(((r*x0)^(k*y0)) == 1) p = 1;
				}
				if(x0 <= 1e18/r && y0 <= 1e18/k && p == 1 && x0 >= 1 && y0 >= 1 && x0 <= (1<<30) && y0 <= (1<<30)) {
					ansp = mp(r,k);
					mul = mp(x0,y0);
					break;
				} 
			}
		}
	}

	int r = ansp.fi, k = ansp.se, x0 = abs(mul.fi), y0 = abs(mul.se);

	// cerr<<r<<" "<<k<<" "<<x0<<" "<<y0<<endl;

	int xxx = x0, yyy = y0;

	assert(ansp.fi + ansp.se > 0);

	forsn(i,1,31){
		if((1ll<<i) <= 2e18 / r) v.pb(mp(0, mp((1<<(i-1))*r, (1<<(i-1))*r)));
		if((1ll<<i) <= 2e18 / k) v.pb(mp(0, mp((1<<(i-1))*k, (1<<(i-1))*k)));
	}

	int ptr = 0;
	ll last = -1;

	// cerr<<v.size()<<endl;

	while(x0){
		if(x0%2 == 1){
			if(last != -1){
				v.pb(mp(0,mp(last, (1<<ptr) * r)));
				last += (1<<ptr) * r;
			}
			else{
				last = (1<<ptr) * r;
			}
		}
		ptr++;
		x0 /= 2;
	}

	ptr = 0;
	last = -1;
	
	while(y0){
		if(y0%2 == 1){
			if(last != -1){
				v.pb(mp(0,mp(last, (1<<ptr) * k)));
				last += (1<<ptr) * k;
			}
			else{
				last = (1<<ptr) * k;
			}
		}
		ptr++;
		y0 /= 2;
	}

	v.pb(mp(1, mp(r * xxx, k * yyy)));
	assert((r*xxx) ^ (k*yyy) == 1);

	assert(v.size() <= 100000);

	cout<<v.size()<<ln;
	// int ppp = 0;
	forstl(r,v){
		cout<<r.se.fi;
		if(r.fi == 0){
			cout<<" + ";
		}
		else{
			cout<<" ^ ";
		}
		cout<<r.se.se<<endl;
		// cerr<<ppp<<endl;
		// ppp++;
		assert(r.se.fi <= 3e18);
		assert(r.se.se <= 3e18);
		assert(r.se.fi+r.se.se <= 4e18);
	}

	return 0;
}