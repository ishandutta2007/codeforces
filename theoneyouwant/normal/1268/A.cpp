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
const int LIM=1e5+5,MOD=1e9+7;
const ld EPS = 1e-9;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
	fastio;
	int tests = 1;
	// cin>>tests;
	
	while(tests--){

		ll n,k;
		cin>>n>>k;
		string s;
		cin>>s;
		string l = s; 
		forsn(i,0,k){
			l[i] = s[i];
			int j = k;
			while((i+j)<l.length()){
				l[i+j] = l[i];
				j+=k;
			} 
		}
		// cout<<"OK"<<endl;
		bool p = 1;
		bool greater = 0;
		forn(i,l.length()){
			if(l[i]>s[i]) greater = 1;
			if(greater == 0 && l[i]<s[i]){
				p = 0;
			}
		}
		// cout<<p<<endl;
		if(p){
			cout<<l.length()<<ln;
			cout<<l<<ln;
		}
		else{
			bool check = 0;
			forn(i,l.length()){
				if(s[i]!='9') check = 1;
			}
			string l;
			if(check){
				l = s;
				int ptr = k-1;
				while(ptr>=0){
					if(l[ptr]<'9'){
						l[ptr]++;
						break;
					}
					else{
						l[ptr] = '0';
					}
					ptr--;
				}
				forn(i,k){
					int j = k;
					while((i+j)<l.length()){
						l[i+j] = l[i];
						j += k;
					}
				}
			}
			else{
				forn(i,1+s.length()){
					if(i%k == 0) l += '1';
					else l += '0';
				}
			}
			cout<<l.length()<<ln;
			cout<<l<<ln;
		}

	}

	return 0;
}