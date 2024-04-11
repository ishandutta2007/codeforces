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
const ll MOD = 1e9+7, LIM = 3e5+5;
const ld EPS = 1e-9;

void z_func(string &s, v32 &z){
	int L=0;
	int R=0;
	int sz = s.size();
	z.assign(sz,0);
	forsn(i,1,sz){
		if(i>R){
			L = R = i;
			while(R<sz && s[R-L] == s[R]) R++;
			z[i] = R-L; R--;
		}
		else{
			int k = i-L;
			if(z[k]<R-i+1) z[i] = z[k];
			else{
				L = i;
				while(R<sz && s[R-L]==s[R]) R++;
				z[i] = R-L;
				R--;
			}
		}
	}
}

int main(){
	fastio;

	string s;
	cin>>s;
		
	int n = s.length();
	int l[n] = {0};
	forn(i,n) l[i] = LIM;
	int num;
	cin>>num;
	forn(i,num){
		string b;
		cin>>b;
		string f;
		f = b;
		f += s;
		v32 v;
		z_func(f,v);
		forsn(j,b.size(),f.size()){
			if(v[j] >= b.size()){
				l[j-b.size()] = min(l[j-b.size()],(int)b.size());
			}
		}
	}	

	// forn(i,n) cout<<i<<" "<<l[i]<<ln;

	int minp = LIM;
	rforn(i,n-1){
		minp = min(minp,i+l[i]);
		l[i] = minp-i;
	}

	// forn(i,n) cout<<i<<" "<<l[i]<<ln;

	int m = 0, pos = -1;
	int curr = 0, currp = -1;

	forn(i,n){
		if(l[i] > 1e5){
			if(currp == -1){
				currp = i;
				curr = 1;
			}
			else curr++;
		} 
		else{
			if(currp == -1) currp = i;
			curr += l[i]-1;
			if(curr > m){
				// cout<<i<<" HERE"<<ln;
				m = curr;
				pos = currp;
			}
			currp = -1;
			curr = 0;
		}
	}
	if(curr > m){
		m = curr;
		pos = currp;
	}

	if(m!=0) cout<<m<<" "<<pos<<ln;
	else cout<<0<<" "<<0<<ln;

	return 0;
}