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
const int LIM=5005,MOD=1e9+7;
const ld EPS = 1e-9;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
	fastio;
	int tests;
	cin>>tests;
	
	while(tests--){

		int n; cin>>n;
		string s; cin>>s;
		v32 pos;
		string mi;
		int val = -1;
		forn(i,LIM) mi += 'z';
		forsn(i,0,n){
			int k = i;
			string f;
			if((n-k+1)%2 == 1){
				if(k<n) f = s.substr(k);
				f += s.substr(0,k);
				if(f<mi){
					mi = f;
					val = i;
				}
			}
			else{
				if(k<n) f = s.substr(k);
				string temp = s.substr(0,k);
				reverse(temp.begin(),temp.end());
				f += temp;
				if(f<mi){
					mi = f;
					val = i;
				}
			}
			// cout<<i<<" "<<f<<ln;
		}
		
		string f;
			if((n-val+1)%2 == 1){ 
				if(val<n) f = s.substr(val);
				f += s.substr(0,val);
			}
			else{
				if(val<n) f = s.substr(val);
				string temp = s.substr(0,val);
				reverse(temp.begin(),temp.end());
				f += temp;
			}
			cout<<f<<ln<<val+1<<ln;

	}

	return 0;
}