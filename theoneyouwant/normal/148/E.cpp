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
const int LIM = 2e5+5, MOD = 1e9+7;
int t,n,m,k,x,y;
int main(){
	cin>>n>>m;
	int size;
	int pre[n][max(m+1,100)];
	forn(i,n){
		forn(j,max(m+1,100)){
			pre[i][j] = 0;
		}
	}
	forn(i,n){
		cin>>size;
		int c[size]={0};
		int prec[size] = {0};
		forn(j,size){
			cin>>c[j];
			if(j==0) prec[j] = c[j];
			else prec[j] = prec[j-1] + c[j];
		}
		forsn(j,1,min(m+1,size+1)){
			forn(k,j){
		//		if(pre[i][j]>1000) cout<<"Error before "<<ln;
				pre[i][j] = max(pre[i][j],prec[k] + prec[size-1]-prec[size-j+k]);
		//		if(pre[i][j]>1000) cout<<"Error here "<<i<<" "<<j<<" k is "<<k<<ln;
			}
			pre[i][j] = max(pre[i][j], prec[size-1]-prec[size-1-j]);
		//	if(pre[i][j]>1000) cout<<"Error here "<<i<<" "<<j<<" NOT k "<<ln;
			//	cout<<"HERE "<<pre[1][0]<<ln;
		}
	}
	forn(i,n){
		forn(j,m+1){
		//	cout<<pre[i][j]<<" i is "<<i<<" j is "<<j<<ln;
		}
	}
	ll answer[n][m+1]={0};
		forn(i,n){
		forn(j,m+1){
			answer[i][j] = 0;
		}
	}
	forn(i,n){
		if(i==0){
			forn(j,m+1){
				answer[i][j] = pre[i][j];
			}
		}
		else{
			forn(j,m+1){
				forn(k,min(j+1,101)){
					answer[i][j] = max(answer[i][j],pre[i][k] + answer[i-1][j-k]);
				}
			}
		}
	}
	cout<<answer[n-1][m]<<ln;
	fastio;
	return 0;
}