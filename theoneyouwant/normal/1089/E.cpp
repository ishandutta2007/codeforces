//By Tushar Gautam
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
#define ln "\n"
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
const int LIM = 1e5+5, MOD = 1e9+7;
int t,n,m,k,x,y;
string s="abcdefgh";
void output(int x,int f=0,int u=0){
	if(x<=0) return;
	bool dir=0;
	forsn(i,u,8){
		if(!dir){
			forn(j,x){
				cout<<s[j+f]<<i+1<<" ";
			}
		}else{
			rforn(j,x-1){
				cout<<s[j+f]<<i+1<<" ";
			}
		}
		dir=!dir;
	}
}
int main(){
	fastio;
	cin>>n; // a1 h1 h8
	if(n<=15){
		cout<<"a1 a8 "; --n;
	}else if(n<=55){
		output((n-8)/8);
		if(n>=8) n-=8*((n-8)/8)-1;
	}else if(n>=48) output(5),n-=39;
	if(n>17){
		cout<<"f8 "; 
		n-=17;
		forn(i,n-1){
			cout<<"f"<<7-i<<" ";
		}
		cout<<"f1 ";
		bool dir=1;
		forn(i,8){
			if(!dir){
				forn(j,2){
					cout<<s[j+6]<<i+1<<" ";
				}
			}else{
				rforn(j,1){
					cout<<s[j+6]<<i+1<<" ";
				}
			}
			dir=!dir;
		}
	}else if(n>9){
		cout<<"f8 "; 
		n-=9;
		forn(i,n-1){
			cout<<"f"<<7-i<<" ";
		}
		if(n!=8) cout<<"f1 ";
		else cout<<"g1 ";
		output(1,7);
	}else if(n>=4){
		cout<<"f8 ";
		cout<<"f"<<11-n<<" ";
		output(1,7,10-n);
	}else if(n==1){
		cout<<"h8 ";
	}else{
		cout<<"f8 ";
		if(n==3) cout<<"g8 ";
		cout<<"h8 ";
	}
	return 0;
}