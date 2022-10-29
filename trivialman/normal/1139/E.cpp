#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
#define PII pair<int,int>
typedef long long LL;
const LL P = 1e9+7;
const int INF = 1e9;
const int N = 5005;
const double pi = acos(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int p[N],c[N],k[N],ans[N];
bool v[N];
int n,m,d,tot=1,x;
int lnk[N],vis[N];
vector<int> g[N]; 

void add(int u,int v){ g[u].push_back(v); } 
int match(int x,int t){
	for(auto u:g[x]) if(vis[u]!=t){
		vis[u]=t;
		if(lnk[u]==-1 || match(lnk[u],t)){ lnk[u]=x; return 1; }
	}
	return 0;
}
 
int main(){
	//freopen("test.in","r",stdin);
	scanf("%d%d",&n,&m);
	rep(i,0,5000) lnk[i]=-1;
	rep(i,1,n) scanf("%d",&p[i]);
	rep(i,1,n) scanf("%d",&c[i]);
	scanf("%d",&d); int j=0;
	rep(i,1,d) scanf("%d",&k[i]),v[k[i]]=true;
	rep(i,1,n) if (!v[i]) add(p[i],c[i]);
	int tim = 0;
	rrep(i,d,1){
		int id=k[i];
		for (; j<5000; j++) if (!match(j,++tim)) break;
		ans[i]=j; add(p[id],c[id]);
	}
	rep(i,1,d) printf("%d\n",ans[i]);
	return 0;
}