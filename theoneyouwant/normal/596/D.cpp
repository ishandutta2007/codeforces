//By TheOneYouWant
#pragma GCC optimize ("-O2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define memreset(a) memset(a,0,sizeof(a))
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
const int LIM=1e5+5,MOD=1e9+7;
const ld EPS = 1e-9;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
	fastio;

	cout<<setprecision(10)<<fixed;

	ll n;
	ld h;
	 cin>>n>>h;
	ld p; cin>>p;
	ld x[n];
	forn(i,n) cin>>x[i];
	sort(x, x+n);

	ll left[n] = {0};
	ll right[n] = {0};

	forsn(i,1,n){
		if(x[i]-x[i-1] >= h-EPS) left[i] = i;
		else left[i] = left[i-1];
	}
	right[n-1] = n-1;
	rforn(i,n-2){
		if(x[i+1] - x[i] >= h-EPS) right[i] = i;
		else right[i] = right[i+1];
	}

	ld dp[n][n][2][2];
	forn(i,n) forn(j,n) forn(k,2) forn(l,2) dp[i][j][k][l] = 0;

	forn(k,n){
		forn(i,n){
			if(i+k >= n) continue;
			int j = i+k;

			forn(a,2){
				forn(b,2){
					if(i == j){
						if(i == 0) dp[i][j][a][b] += p * h;
						else if(a == 1) dp[i][j][a][b] += p * min(h, (x[i] - x[i-1] - h));
						else dp[i][j][a][b] += p * min(h, (x[i] - x[i-1]));

						if(j == n-1) dp[i][j][a][b] += (1-p) * h;
						else if(b == 1) dp[i][j][a][b] += (1-p) * min(h, (x[j+1] - x[j]));
						else dp[i][j][a][b] += (1-p) * min(h, (x[j+1] - x[j] - h));

						continue;
					}

					ld q = 0;
					if(a == 1) q = -h;

					if(i == 0) dp[i][j][a][b] += 0.5 * p * (h + dp[i+1][j][0][b]);
					else dp[i][j][a][b] += 0.5 * p * (min(h, x[i] - x[i-1] + q) + dp[i+1][j][0][b]);

					// if(i == 0 && j == 1) cout<<"what is "<<a<<" "<<b<<" "<<dp[i][j][a][b]<<" "<<dp[i+1][j][0][b]<<ln;

					q = 0;
					if(b == 0) q = -h;

					if(j == n-1) dp[i][j][a][b] += 0.5 * (1-p) * (h + dp[i][j-1][a][1]);
					else dp[i][j][a][b] += 0.5 * (1-p) * (min(h, x[j+1] - x[j] + q) + dp[i][j-1][a][1]);

					// if(i == 1 && j == 2) cout<<a<<" "<<b<<" "<<dp[i][j][a][b]<<ln;

					if(right[i] >= j) {
						ld xx = x[j] + h - x[i];
						ld y = 0;
						if(b == 0) y = -h;
						if(j != n-1) xx = min(xx, x[j+1] + y - x[i]);
						dp[i][j][a][b] += 0.5 * (1-p) * xx;
					}
					else{
						dp[i][j][a][b] += 0.5 * (1-p) * (x[right[i]]+h-x[i] + dp[right[i]+1][j][1][b]);
					}
					// if(i == 1 && j == 2) cout<<"whatt "<<a<<" "<<b<<" "<<dp[i][j][a][b]<<ln;

					if(left[j] <= i){
						ld xx = x[j] + h - x[i];
						ld y = 0;
						if(a == 1) y = -h;
						if(i != 0) xx = min(xx, x[j] - x[i-1] + y);
						dp[i][j][a][b] += 0.5 * p * xx;
					}
					else{
						dp[i][j][a][b] += 0.5 * p * (x[j] - x[left[j]] + h + dp[i][left[j]-1][a][0]);
					}
					// if(i == 1 && j == 2) cout<<a<<" "<<b<<" "<<dp[i][j][a][b]<<" "<<i<<" "<<j<<" "<<left[j]<<ln;
				}
			}
		}
	}

	cout<<dp[0][n-1][0][1]<<ln;

	return 0;
}