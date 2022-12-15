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
	int tests;
	cin>>tests;
	
	while(tests--){

		string s; cin>>s;

		int n = s.length();

		int ma = 0;
		forn(i,n/2){
			if(s[i] == s[n-1-i]) ma++; 
			else break;
		}
		
		vector<int> d1(n);
		for (int i = 0, l = 0, r = -1; i < n; i++) {
		    int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
		    while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
		        k++;
		    }
		    d1[i] = k--;
		    if (i + k > r) {
		        l = i - k;
		        r = i + k;
		    }
		}	

		int ml = 1;

		forn(i,n){
			// ml = max(ml,2*d1[i]-1);
			if(ma >= i+1-d1[i] && i < (n+1)/2) ml = max(ml,2*i+1);
			if(i+d1[i]-1+ma >= n-1 && i >= (n+1)/2) ml = max(ml,2*(n-1-i)+1);
		}

		vector<int> d2(n);
		for (int i = 0, l = 0, r = -1; i < n; i++) {
		    int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
		    while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
		        k++;
		    }
		    d2[i] = k--;
		    if (i + k > r) {
		        l = i - k - 1;
		        r = i + k ;
		    }
		}
		forn(i,n){
			// ml = max(ml, 2*d2[i]);
			if(ma >= i-d2[i] && i < (n+1)/2) ml = max(ml,2*i);
			if(i+d2[i]+ma >= n && i >= (n+1)/2) ml = max(ml,2*(n-i));
		}
		// cout<<ml<<ln;
		bool done = 0;

		forn(i,n){
			if(done) continue;
			// if(ml == 2*d1[i]-1){
			// 	// cout<<"OK1"<<" "<<ml<<ln;
			// 	cout<<s.substr(i-d1[i]+1,2*d1[i]-1)<<ln;
			// 	done = 1;
			// }
			// else if(ml == 2*d2[i]){
			// 	// cout<<"OK2"<<" "<<ml<<ln;
			// 	cout<<s.substr(i-d2[i],2*d2[i])<<ln;
			// 	done = 1;
			// }
			if(ml == 2*i+1 && ma >= i+1-d1[i] && i < (n+1)/2){
				// cout<<"OK3"<<" "<<ml<<ln;
				string z = s.substr(0,i+d1[i]);
				cout<<z;
				int f = 2*i+1-i-d1[i];
				z = s.substr(n-f,f);
				cout<<z<<ln;
				done = 1;
			}
			else if(ml == 2*(n-1-i)+1 && i+d1[i]-1+ma >= n-1 && i >= (n+1)/2){
				// cout<<"OK"<<ln;
				// cout<<"OK4"<<" "<<ml<<ln;
				string z = s.substr(0,ma);
				cout<<z;
				int f = 2*(n-1-i)+1-ma;
				z = s.substr(n-f,f);
				cout<<z<<ln;
				done = 1;
				// cout<<z<<s[i];
				// reverse(z.begin(),z.end());
				// cout<<z<<ln;
			}
			else if(ml == 2*i && ma >= i-d2[i] && i < (n+1)/2){
				// cout<<"OK5"<<" "<<ml<<ln;
				string z = s.substr(0,i+d2[i]);
				cout<<z;
				int f = 2*i-i-d2[i];
				z = s.substr(n-f,f);
				cout<<z<<ln;
				done = 1;
			}
			else if(ml == 2*(n-i) && i+d2[i]+ma >= n && i >= (n+1)/2){
				// cout<<"OK6"<<" "<<ml<<ln;
				string z = s.substr(0,ma);
				cout<<z;
				int f = 2*(n-i)-ma;
				z = s.substr(n-f,f);
				cout<<z<<ln;
				done = 1;
			}
		}

	}

	return 0;
}