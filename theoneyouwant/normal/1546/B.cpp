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
#define testcase(t) int t;cin>>t;while(t--)
#define forstl(i,v) for(auto &i: v)
#define forn(i,e) for(int i=0;i<e;++i)
#define forsn(i,s,e) for(int i=s;i<e;++i)
#define rforn(i,s) for(int i=s;i>=0;--i)
#define rforsn(i,s,e) for(int i=s;i>=e;--i)
#define bitcount(a) __builtin_popcount(a) // set bits (add ll)
#define ln endl
#define getcurrtime() cerr<<"Time = "<<((double)clock()/CLOCKS_PER_SEC)<<endl
#define dbgarr(v,s,e) cerr<<#v<<" = "; forsn(i,s,e) cerr<<v[i]<<", "; cerr<<endl
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

int read(){
    int xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=(xx<<3)+(xx<<1)+ch-'0';ch=getchar();}
    return xx*ff;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
	fastio;
	int tests = 1;
	cin>>tests;

	int MX = 26;

	int tot[LIM][MX];
	
	while(tests--){

		int n, m;
		cin >> n >> m;
		string s[n];

		forn(i,m){
			forn(j,MX){
				tot[i][j] = 0;
			}
		}

		forn(i,n){
			cin >> s[i];
			forn(j,m){
				int c = s[i][j]-'a';
				tot[j][c]++;
			}
		}

		string ans;
		forn(i,n-1){
			cin >> ans;
			forn(j,m){
				int c = ans[j]-'a';
				tot[j][c]--;
			}
		}
		bool done = 0;
		forn(i,n){
			if(done) break;
			bool p = 1;
			forn(j,m){	
				int c = s[i][j]-'a';
				if(tot[j][c]==0){
					p = 0;
					break;
				}
			}
			if(!p) continue;
			done = 1;
			cout << s[i] << ln;
		}

	}

	return 0;
}