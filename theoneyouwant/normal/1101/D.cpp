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
	v32 adj[LIM];
		int a[LIM];
int t,n,k,x,y;
map<int,int> m[LIM];
int visited[LIM];
int primes[LIM];
int ans=0;

void calc(int x, int p){
	v32 div;
	forsn(i,2,sqrt(a[x])+1e-9){
		if(a[x]%i==0 && primes[i]==0){
			div.pb(i);
		}
	}
	// cout<<"our number is "<<x<<" "<<a[x]<<ln;
	// forstl(r,div) cout<<r<<" ";
	// cout<<ln;
	if(primes[a[x]]==0) div.pb(a[x]);
	int qw = div.size();
	int m1[qw+1]={0},m2[qw+1]={0};
	forstl(r,adj[x]){
		if(r!=p){
			forn(i,div.size()){
				int w = div[i];
				m[x][w]=max(m[x][w],m[r][w]);
				if(m[r][w]>=m1[i]){
					m2[i] =  m1[i];
					m1[i] = m[r][w];

				}
				else if(m[r][w]>=m2[i]){
					m2[i] = m[r][w];
				}
				//cout<<w<<" "<<x<<" "<<r<<" "<<"OH"<<ln;
			}
		}
	}
	forn(i,qw){
		if(m1[i]!=0 && m2[i]!=0) ans = max(ans,m1[i]+m2[i]+1);
	}
	forstl(w,div) m[x][w]+=1; 	
}

void dfs(int x, int p){
	forstl(r,adj[x]){
		if(!visited[r]){
			visited[r]=1;
			dfs(r,x);
			//cout<<"OK"<<" "<<x<<" "<<r<<edl;
		}
	}
	calc(x,p);
}

int main(){
	fastio;
	cin>>n;
	forn(i,LIM) primes[i]=0;
	primes[0] = 1;
	primes[1] = 1;
	forsn(i,2,LIM){
		if(primes[i]) continue;
		int j=2;
		while(i*j<LIM){
			primes[i*j]=1;
			j++;
		}
	}
	forn(i,n+1) visited[i]= 0;
	forn(i,n) cin>>a[i+1];
	forn(i,n-1){
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	visited[1]=1;
	//cout<<"OK"<<ln;
	dfs(1,0);
	forn(i,LIM){
		forstl(r,m[i]) ans = max(ans,r.se);
	}
	cout<<ans<<ln;
	return 0;
}