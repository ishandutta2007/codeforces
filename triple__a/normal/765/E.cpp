#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;

const int maxn=1000007;
int p[maxn],cnt=0,n;
int d[maxn],par[maxn],h[maxn];
bool vis[maxn];
struct edge{
	int to,next;
}ed[maxn];
 
void init(int u,int v){
	ed[cnt].to=v;
	ed[cnt].next=p[u];
	p[u]=cnt++;
}

int bfs_farest(int u){
	bool vis[maxn];
	memset(vis,0,sizeof(vis));
	memset(d,0,sizeof(d)); 
	int ans=0;
	queue<int> q;
	while(!q.empty()){
		q.pop();
	}
	q.push(u);
	int v=0;
	while(!q.empty()){
		v=q.front();
		q.pop();
		for (int i=p[v];i!=-1;i=ed[i].next){
			if (!vis[ed[i].to]){
				vis[ed[i].to]=1;
				par[ed[i].to]=v;
				d[ed[i].to]=d[v]+1;
				q.push(ed[i].to);
			}
		}
	}
	return v;
}

void dfs_height(int u){
	vis[u]=1;
	for (int i=p[u];i!=-1;i=ed[i].next){
		int v=ed[i].to;
		if (!vis[v]){
			dfs_height(v);
			par[v]=u;
			h[u]=max(h[u],h[v]+1);
		} 
	}
}

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		p[i]=-1;
	}
	for (int i=1;i<n;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		init(u,v);
		init(v,u);
	}
	int u=bfs_farest(1);
	int v=bfs_farest(u),mid=v;
	for (int i=1;i<=d[v]/2;++i){
		mid=par[mid];
	}
	memset(h,0,sizeof(h)); 
	memset(vis,0,sizeof(vis));
	memset(par,0,sizeof(par));
	dfs_height(mid);
	int ans=0;
	for (int i=1;i<=n;++i){
		set<int> s;
		s.clear();
		for (int j=p[i];j!=-1;j=ed[j].next){
			int v=ed[j].to;
			if (par[v]==i){
				s.insert(h[v]+1);
			}
		}
		if (i!=mid){
			if (s.size()>1){
				printf("-1");
				return 0;
			}
		}
		else{
			if (s.size()>2){
				printf("-1");
				return 0;
			}
			else{
				for (set<int>::iterator it=s.begin();it!=s.end();it++){
					ans+=*it;
				}
			}
		}
	}
	while(ans%2==0){
		ans/=2;
	}
	printf("%d\n",ans);
	return 0;
}