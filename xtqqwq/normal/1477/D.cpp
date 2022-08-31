#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,tot;
int v[1000005],nxt[1000005],h[500005],f[500005],du[500005],q[500005],ans1[500005],ans2[500005];
bool vis[500005];
vector<int> adj[500005];

int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot; du[y]++;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot; du[x]++;
}

void work(){
	n=readint(); m=readint();
	for(int i=1;i<=n+1;i++) h[i]=du[i]=vis[i]=0; tot=0;
	for(int i=1;i<=n;i++) adj[i].clear();
	for(int i=1;i<=n;i++) f[i]=i;
	int x,y;
	for(int i=1;i<=m;i++){
		x=readint(); y=readint();
		adj[x].pb(y),adj[y].pb(x);
	}
	for(int i=1;i<=n;i++){
		vis[i]=1;
		for(auto v:adj[i]) vis[v]=1;
		int pl=0;
		for(int j=1;j<=adj[i].size()+2;j++) if(!vis[j]) pl=j;
		if(pl<=n){
			int fx=getf(i),fy=getf(pl);
			if(fx!=fy) f[fx]=fy,addedge(i,pl);
		}
		vis[i]=0;
		for(auto v:adj[i]) vis[v]=0;
	}
	int front=0,rear=0,cnt=0;
	for(int i=1;i<=n;i++) if(du[i]==1) q[rear++]=i;
	for(int i=1;i<=n;i++) if(du[i]==0) ans1[i]=ans2[i]=++cnt;
	while(front<rear){
		int t=q[front++],to;
		if(vis[t]) continue;
		for(int p=h[t];p;p=nxt[p]) if(!vis[v[p]]) to=v[p];
		vis[to]=1;
		vector<int> vec(1,to);
		for(int p=h[to];p;p=nxt[p]){
			if(!vis[v[p]]&&du[v[p]]==1){
				vec.pb(v[p]);
				vis[v[p]]=1;
			}
		}
		for(int i=0;i<vec.size();i++) ans1[vec[i]]=cnt+i+1;
		for(int i=1;i<vec.size();i++) ans2[vec[i]]=cnt+i;
		ans2[to]=cnt+vec.size();
		cnt+=vec.size();
		for(int p=h[to];p;p=nxt[p]) if(!vis[v[p]]&&(--du[v[p]])==1) q[rear++]=v[p];
	}
	for(int i=1;i<=n;i++) printf("%d ",ans1[i]);
	printf("\n");
	for(int i=1;i<=n;i++) printf("%d ",ans2[i]);
	printf("\n");
}

int main(){
	int T=readint();
	while(T--) work();
	return 0;
}