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

int n,m;
int du[200005],vis[200005],q[200005];
vector<int> adj[200005],adj2[200005];

int main(){
	int T=readint();
	while(T--){
		n=readint(); m=readint();
		for(int i=1;i<=n;i++) du[i]=vis[i]=0,adj[i].clear(),adj2[i].clear();
		int x,y;
		for(int i=1;i<=m;i++){
			x=readint(); y=readint();
			adj[x].pb(y),adj2[y].pb(x); du[y]++;
		}
		int front=0,rear=0;
		for(int i=1;i<=n;i++) if(!du[i]) q[rear++]=i;
		while(front<rear){
			int t=q[front++];
			for(auto v:adj[t])
				if(!(--du[v]))
					q[rear++]=v;
		}
		for(int i=0;i<rear;i++){
			int u=q[i];
			if(vis[u]) continue;
			for(auto v:adj2[u]){
				if(vis[v]) continue;
				for(auto r:adj2[v]) if(!vis[r]) vis[u]=1;
			}
		}
		vector<int> ans(0);
		for(int i=1;i<=n;i++) if(vis[i]) ans.pb(i);
		printf("%d\n",ans.size());
		for(auto x:ans) printf("%d ",x);
		printf("\n");
	}
	return 0;
}