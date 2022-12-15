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
const ll MOD = 1e9+7, LIM = 1e5+5, MAXN = 1e6+5;
const ld EPS = 1e-9;

int n, t[4*MAXN], le[4*MAXN], ri[4*MAXN],m;

void build(char a[], int v, int tl, int tr) { 

//Call this with original array a, v=1, tl=0, tr=n-1

    if (tl == tr) {
    	if(a[tl]=='('){
    	//	cout<<"yoohoo"<<ln;
    		le[v]=1;
    	}
        else{
        //	cout<<"notok"<<ln;
        	ri[v]=1;
        }
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        int z = min(le[2*v],ri[2*v+1]);
        le[v] = le[2*v]+le[2*v+1]-z;
        ri[v] = ri[2*v+1]+ri[2*v]-z;
        t[v] = z+t[2*v]+t[2*v+1];
    }
}

int sum(int v, int tl, int tr, int l, int r, int& sentl, int& sentr) {

//Call this with v=1, tl=0, tr=n-1, l and r of original query

    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
    	sentl = le[v];
    	sentr = ri[v];
        return t[v];
    }
    int tm = (tl + tr) / 2;
    int sendl1=0,sendr1=0,sendl2=0,sendr2=0;
    int answer = sum(v*2, tl, tm, l, min(r, tm),sendl1,sendr1) + sum(v*2+1, tm+1, tr, max(l, tm+1), r,sendl2,sendr2);
    int z = min(sendl1,sendr2);
    answer+=z;
    sendl1-=z;
    sendr2-=z;
    sentl = sendl1+sendl2;
    sentr = sendr1+sendr2;
    return answer;
}


int main(){
	fastio;
	string s;
	cin>>s;
	n = s.length();
	//cout<<n<<ln;
	char a[n];
	forn(i,n){
		a[i] = s[i];
	}
	forn(i,MAXN){
		le[i]=0;
		t[i]=0;
		ri[i]=0;
	}
	build(a,1,0,n-1);
//	cout<<t[1]<<" HERE "<<le[1]<<" "<<ri[1]<<ln;
	cin>>m;
	forn(i,m){
		int l,r;
		cin>>l>>r;
		l=l-1;
		r=r-1;
		int a,b;
		cout<<2*sum(1,0,n-1,l,r,a,b)<<ln;
	}

	return 0;
}