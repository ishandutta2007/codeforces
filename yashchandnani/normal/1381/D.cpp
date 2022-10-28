#include <bits/stdc++.h>
using namespace std;


void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void pre(){


}
int h1[100009],h2[100009],h3[100009],h4[100009],h5[100009];
int fg[100009];
int gg[100009];
vector<vi> g;
void dfs(int u,int p){
	h1[u]=h2[u]=h3[u]=0;
	trav(i,g[u]){
		if(i!=p){
			h4[i] = h4[u]+1;
			dfs(i,u);
			if(fg[i]) fg[u] = i;
			if(h1[i]+1>h1[u]){
				swap(h2[u],h3[u]);
				swap(h1[u],h2[u]);
				h1[u] = h1[i]+1;
			}
			else if(h1[i]+1>h2[u])
			{
				swap(h2[u],h3[u]);
				h2[u] = h1[i]+1;
			}
			else if(h1[i]+1>h3[u]){
				h3[u] = h1[i]+1;
			}

		}
	}
}
void dfs2(int u,int p){
	trav(i,g[u]){
		if(i!=p){
			h5[i] = h5[u]+1;
			if(h1[i]+1==h1[u]){
				h5[i] = max(h5[i],h2[u]+1);
			}
			else h5[i] = max(h5[i],h1[u]+1);
			dfs2(i,u);
		}
	}
}

void dfs3(int u,int p){
	gg[u]=1;
	trav(i,g[u]){
		if(i!=p&&fg[i]!=u){
			dfs3(i,u);
		}
	}
}
void solve(){
	int n,a,b;cin>>n>>a>>b;
	g.clear();
	g.resize(n+1);
	rep(i,n-1){
		int u,v;cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
		fg[i+1]=0;
		gg[i+1]=0;
	}
	gg[n] = 0;
	fg[n] = 0;
	fg[b] = a;
	h4[a] = 0;
	dfs(a,-1);
	int l = h4[b];
	if(h2[b]>=l){
		cout<<"YES\n";
		return ;
	}
	fg[b] = 0;
	h5[a] = 0;
	dfs2(a,-1);
	deque<int> q;
	q.push_back(a);
	while(q.back()!=b){
		q.push_back(fg[q.back()]);
	}
	while(sz(q)>2){
		int cl = sz(q)-1;
		int a1 = h5[q.front()];
		int a2 = h1[q.back()];
		if(h1[q.front()]==h1[fg[q.front()]]+1) a1 = max(a1,h2[q.front()]);
		else a1 = max(a1,h1[q.front()]);
		if(a1+cl==l&&a2+cl==l) break;
		rep(i,a1+cl-l){
			if(sz(q)) q.pop_back();
			else break;
		}
		rep(i,a2+cl-l){
			if(sz(q)) q.pop_front();
			else break;
		}
	}
	if(sz(q)>2){
		q.pop_front();
		q.pop_back();
		while(sz(q)){
			int z = q.back();
			dfs3(z,fg[z]);
			q.pop_back();
		}
	}
	repA(i,1,n){
		if(!gg[i]&&(h3[i]>=l||(h2[i]>=l&&h5[i]>=l))){
			cout<<"YES\n";
			return ;
			
		}
	}
	cout<<"NO\n";
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	rep(i,n) solve();
	return 0;
}