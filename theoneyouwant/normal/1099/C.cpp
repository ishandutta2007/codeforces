//By TheOneYouWant
#pragma GCC optimize ("-O2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define memreset(a) memset(a,0,sizeof(a))
#define testcase(t) int t;cin>>t;while(t--)
#define forstl(i,v) for(auto &i: v)
#define forn(i,e) for(int i = 0; i < e; i++)
#define forsn(i,s,e) for(int i = s; i < e; i++)
#define rforn(i,s) for(int i = s; i >= 0; i--)
#define rforsn(i,s,e) for(int i = s; i >= e; i--)
#define leadzero(a) __builtin_clz(a) // count leading zeroes
#define trailzero(a) __builtin_ctz(a) // count trailing zeroes
#define bitcount(a) __builtin_popcount(a) // count set bits (add ll)
#define ln endl
#define dbg(x) cerr<<#x<<" = "<<x<<endl
#define dbg2(x,y) cerr<<#x<<" = "<<x<<" & "<<#y<<" = "<<y<<endl;
#define dbgstl32(v) cerr<<#v<<" = \n"; { int c=0; forstl(it,v) \
cerr<<"    Term "<< ++c <<" = "<<it<<ln;} cerr<<endl
#define dbgstlp32(v) cerr<<#v<<" = \n"; { int c=0; forstl(it,v) \
cerr<<"    Term "<< ++c <<" = "<<it.fi<<" , "<<it.se<<ln;} cerr<<endl
#define dbgarr(v,s,e) cerr<<#v<<" = "; forsn(i,s,e) cerr<<v[i]<<", "; cerr<<endl
#define inp freopen("input.txt", "r", stdin)
#define outp freopen("output.txt", "w", stdout)
#define dbgm(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); \
stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
typedef long long int  ll;
typedef long double  ld;
typedef pair<ll,ll> p64;
typedef pair<int,int> p32;
typedef vector<ll> v64;
typedef vector<int> v32; 
typedef vector<v32> vv32;
typedef vector<v64> vv64;
typedef vector<p32> vp32;
typedef vector<vp32> vvp32;
typedef map<int,int> m32;
const int LIM = 2e5+5, MOD = 1e9+7, EPS = 1e-9;
int t,n,m,k,x,y;
int main(){
	fastio;
	string s;
	cin>>s;
	int k;
	cin>>k;
	int count=0;
	int snowflake=0,candy=0;
	forn(i,s.length()-1){
		if(s[i+1]!='?' && s[i+1]!='*' && s[i]!='?' && s[i]!='*'){
		//	cout<<i<<" ";
			count++;
		}
		if(s[i]=='*') snowflake=1;
		if(s[i]=='?') candy++;
	}
	if(s[s.length()-1]=='*') snowflake=1;
	else if(s[s.length()-1]=='?') candy++;
	else count++;
	n = s.length();
	//cout<<count<<" "<<snowflake<<" "<<candy<<ln;
	if(count>k) cout<<"Impossible"<<ln;
	else if(snowflake==0 && candy+count<k) cout<<"Impossible"<<ln;
	else{
		if(snowflake==1){
			int r=0;
			forn(i,s.length()-1){
				if(s[i+1]!='?' && s[i+1]!='*' && s[i]!='?' && s[i]!='*') cout<<s[i];
				else if(r==0 && s[i+1] == '*'){
					r=1;
					forn(j,k-count) cout<<s[i];
				}
			}
			if(s[n-1]!='*' && s[n-1]!='?') cout<<s[n-1]<<ln;
		}
		else{
			int r=0;
			forn(i,s.length()-1){
				if(s[i+1]!='?' && s[i]!='?' && s[i]!='*') cout<<s[i];
				else if(r<k-count && s[i+1]=='?'){
					r++;
					cout<<s[i];
				}
			}
			if(s[n-1]!='?') cout<<s[n-1]<<ln;
		}
	}
	return 0;
}