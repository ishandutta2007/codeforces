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
const ll MOD = 1e9+7, LIM = 2e3+5;
const ld EPS = 1e-9;

int vert; // number of vertices
vector<int> adj[LIM]; // adjacency list of graph
vector<int> adj2[LIM];
vector<bool> visited;
vector<int> ans;

void dfs(int v) {
    visited[v] = true;
    for (int u : adj2[v]) {
        if (!visited[u])
            dfs(u);
    }
    ans.push_back(v);
}

void topological_sort() {
    visited.assign(vert, false);
    ans.clear();
    for (int i = 0; i < vert; ++i) {
        if (!visited[i])
            dfs(i);
    }
    reverse(ans.begin(), ans.end());
}


int link[LIM] = {0};
int size[LIM] = {0};

int find(int x){
	int a = x;
	while(x!=link[x]){
		x = link[x];
	}
	link[a] = x;
	return x;
}

void unite(int a, int b){
	a = find(a);
	b = find(b);
	if(size[a]<size[b]) swap(a,b);
	size[a]+=size[b];
	link[b] = a;
}

int main(){
	fastio;
	int n,m;
	cin>>n>>m;
	vert = n+m;
	
	forn(i,LIM) link[i] = i;
	forn(i,LIM) size[i] = 1;
	
	forn(i,n){
		forn(j,m){
			char x;
			cin>>x;
			if(x=='>'){
				adj[n+j].pb(i);
			}
			else if(x=='<'){
				adj[i].pb(n+j);
			}
			else{
				unite(i,n+j);
			}
		}
	}
	// forn(i,n+m){
	// 	cout<<i<<ln;
	// 	forstl(r,adj[i]) cout<<r<<" ";
	// 	cout<<ln;
	// }
	map<int,int> ma;
	int count=1;
	forn(i,n+m){
		int x = find(i);
		if(ma[x]==0){
			ma[x]=count;
			count++;
		}
	}
	forstl(r,ma) {
		//cout<<r.fi<<" "<<r.se<<ln;
		r.se--;
	}
	vert = count-1;
	int ad[n+m][n+m] = {0};
	forn(i,n+m){
		forn(j,n+m) ad[i][j]=0;
	}
	forn(i,n+m){
		int x = find(i);
		forstl(r,adj[i]){
			//cout<<i<<" "<<r<<" "<<ma[x]<<" "<<ma[find(r)]<<ln;
			int y = find(r);
			if(ad[ma[x]][ma[y]]) continue;
			//cout<<i<<" "<<r<<" "<<ma[x]<<" "<<ma[find(r)]<<ln;
			ad[ma[x]][ma[y]] = 1;
			adj2[ma[x]].pb(ma[y]);
		}
	}
	//  forn(i,vert){
	//  	cout<<i<<ln;
	//  	forstl(r,adj2[i]) cout<<r<<" ";
	//  	cout<<ln;
	// }
	topological_sort();
	int great[LIM] = {0};
	int eat[LIM] = {0};
	bool possible=1;
	forstl(r,ans){
		eat[r] = great[r]+1;
		forstl(k,adj2[r]){
			if(eat[k]!=0 && eat[k]<=eat[r]) possible=0;
			great[k] = max(great[k],eat[r]);
		}
		// cout<<r<<" "<<eat[r]<<ln;
		// eat[x1] = eat[r];
	}
	int eat2[LIM] = {0};
	forn(i,n+m){
		int x = ma[find(i)];
		eat2[i] = eat[x];
	}
	if(!possible) cout<<"No"<<ln;
	else{
		cout<<"Yes"<<ln;
		forn(i,n) cout<<eat2[i]<<" ";
		cout<<ln;
		forsn(i,n,n+m) cout<<eat2[i]<<" ";
		cout<<ln;
	}
	return 0;
}