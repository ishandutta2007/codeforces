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
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair<ll,ll> p64;
typedef pair<int,int> p32;
typedef pair<int,p32> p96;
typedef vector<ll> v64;
typedef vector<int> v32; 
typedef vector<v32> vv32;
typedef vector<v64> vv64;
typedef vector<p32> vp32;
typedef vector<vp32> vvp32;
typedef map<int,int> m32;
const ll MOD = 1e9+7, LIM = 1e5+5;
const ld EPS = 1e-9;

int chartoint (char* c){
	int r = 0;
	r+=c[0]-'a';
	r+=26*(c[1]-'a');
	r+=26*26*(c[2]-'a');
	return r;
}

void inttochar (int a, char* c){
	c[2] = a/(26*26) + 'a';
	a%=(26*26);
	c[1] = a/26 + 'a';
	a%=26;
	c[0] = a+'a';
}

int main(){
	//fastio;
	string s;
	cin>>s;
	int n = s.length();
	map<int,int> mapping;
	char cha[n][3];
	forn(i,n){
		inttochar(i,cha[i]);
	}
	//cout<<"OK"<<ln;
	string a,b,z;
	cout<<"? ";
	forn(i,n) cout<<cha[i][0];
	cout<<ln;
	cin>>a;
	cout<<"? ";
	forn(i,n) cout<<cha[i][1];
	cout<<ln;
	cin>>b;
	cout<<"? ";
	forn(i,n) cout<<cha[i][2];
	cout<<ln;
	cin>>z;
	char ans[n];
	//cout<<a<<" "<<b<<" "<<c<<ln;
	forn(i,n){
		char c[3];
		c[0] = a[i];
		c[1] = b[i];
		c[2] = z[i];
		//cout<<i<<" "<<a[i]<<" "<<b[i]<<" "<<z[i]<<ln;
		int mapped = chartoint(c);
		//cout<<i<<" "<<mapped<<ln;
		ans[mapped] = s[i];
	}
	cout<<"!"<<" ";forn(i,n) cout<<ans[i];
	cout<<ln;
	return 0;
}