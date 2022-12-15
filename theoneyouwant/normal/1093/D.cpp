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
const int LIM = 2e5+5, MOD = 998244353, EPS = 1e-9;
		int color[(int)(4*1e5)];
		int visited[(int)(4*1e5)];
int t,n,m,k,x,y;

ll poo(ll p){
	if(p==0) return 1;
	ll x = poo(p/2);
	if(p%2==0){
		return (x*x)%MOD;
	}
	else{
		return (2*x*x)%MOD;
	}
}

int find(int x, int*link) {
	int a= x;
	while (x != link[x]) x = link[x];
	link[a]  =x;
	return x;
}

void unite(int a, int b,int* size,int* link) {
	a = find(a,link);
	b = find(b,link);
	if(a==b) return;
	if (size[a] < size[b]) swap(a,b);
	size[a] += size[b];
	link[b] = a;
}

ll solve(vector<int>* v, int n,int start, bool& possible){
	queue<int> q;
		q.push(start);
		int red = 0,blue = 0,neither=0;
		//cout<<"ok"<<ln;
		visited[start] = 1;
		color[start] = 1;
		while(!q.empty()){
			int t = q.front();
			//cout<<"going"<<" "<<t<<ln;
			if(color[t]==1) red++;
			else if(color[t]==2) blue++;
			q.pop();
			forstl(r,v[t]){
				if(!visited[r]){
					visited[r] = 1;
					q.push(r);
					color[r] = 3-color[t];
				}
				else{
					if(color[r]!=3-color[t]){
						possible=0;
					}
				}
			}
		}
		//cout<<"ok"<<ln;
		ll ans = 0;
		//cout<<red<<" "<<blue<<" "<<neither<<ln;
		//if(start==0) cout<<"here "<<red<<" "<<blue<<ln;
		ans+=poo(red);
		//cout<<"ok"<<ln;
		ans%=MOD;
		ans+=poo(blue);
		ans%=MOD;
		return ans;
}

int main(){
	fastio;
	int tests;cin>>tests;
	while(tests--)
	{	
		cin>>n>>m;
		forn(i,n) color[i] = 0;
		forn(i,n) visited[i] = 0;
		int link[n] = {0};
		int size[n] = {0};
		for (int i = 0; i <= n-1; i++) link[i] = i;
		for (int i = 0; i <= n-1; i++) size[i] = 1;
		set<pair<int,int> > prs;
		vector<int> v[n];
		forn(i,m){
			cin>>x>>y;
			x--;
			y--;
			//cout<<x<<" "<<y<<ln;
			prs.insert(mp(x,y));
			unite(x,y,size,link);
		}
		forstl(r,prs){
			v[r.first].pb(r.second);
			v[r.second].pb(r.first);
		}
		bool possible = 1;
		ll ans = 1;
		vector<int> sol;
		forn(i,n) sol.pb(find(i,link));
		forstl(r,sol){
			if(!visited[r]){
				//cout<<r<<" "<<solve(v,n,r,possible)<<ln;
				ans*=solve(v,n,r,possible);
			}
			ans%=MOD;
		}
		if(possible) cout<<ans<<ln;
		else cout<<0<<ln;	
	}

	return 0;
}