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

string doreverse(string k, int ptr1, int ptr2){
	// cout<<k<<" "<<" "<<ptr1<<" "<<ptr2<<" ";

	string l = k;
	forsn(i,ptr1,ptr2+1){
		l[i] = k[ptr2+ptr1-i];
	}

	// cout<<"DONE "<<l<<endl;
	return l;
}

int main(){
	fastio;
	int tests;
	cin>>tests;
	
	while(tests--){

		int n,k;
		cin>>n>>k;

		string s;
		cin>>s;

		// cout<<n<<ln;
		vp32 swaps;
		forn(i,n/2-k+1){
			if(s[i] == '(') continue;
			int ptr = i+1;
			while(s[ptr]!='(') ptr++;
			swaps.pb(mp(i+1,ptr+1));
			s = doreverse(s,i,ptr);
		}
		// cout<<swaps[0].fi<<" "<<swaps[0].se<<endl;
		// cout<<s<<endl;
		forsn(i,n/2-k+1,n-2*(k-1)){
			if(s[i] == ')') continue;
			int ptr = i+1;
			while(s[ptr]!=')') ptr++;
			swaps.pb(mp(i+1,ptr+1));
			s = doreverse(s,i,ptr);
		}
		// cout<<s<<ln;

		int offset = n-2*(k-1);
		forn(len,k-1){
			int i = offset+len*2;
			int ptr = i;
			while(s[ptr]!='(') ptr++;
			if(i!=ptr)swaps.pb(mp(i+1,ptr+1));
			s = doreverse(s,i,ptr);
			
			i = offset+len*2+1;
			ptr = i;
			while(s[ptr]!=')') ptr++;
			if(i!=ptr)swaps.pb(mp(i+1,ptr+1));
			s = doreverse(s,i,ptr);
		}

		// cout<<s<<ln;
		cout<<swaps.size()<<ln;
		forstl(r,swaps){
			cout<<r.fi<<" "<<r.se<<ln;
		}

	}

	return 0;
}