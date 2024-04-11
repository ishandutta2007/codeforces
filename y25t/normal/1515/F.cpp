#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define ll long long
#define pii std::pair<int,int>
#define mp std::make_pair
#define fir first
#define sec second
#define N 300005

int n,m,x,a[N];

int hd[N],_hd=1;
struct edge{
	int v,nxt;
}e[N<<1];
inline void addedge(int u,int v){
	e[++_hd]=(edge){v,hd[u]};
	hd[u]=_hd;
}

bool vis[N];
ll sum[N];
std::vector<pii> son[N];
inline void dfs1(int u){
	vis[u]=1;
	sum[u]=a[u];
	for(int i=hd[u];i;i=e[i].nxt){
		int v=e[i].v;
		if(vis[v])
			continue;
		dfs1(v);
		son[u].push_back(mp(v,i>>1));
		sum[u]+=sum[v];
	}
}
inline bool cmp(pii u,pii v){
	return sum[u.fir]>sum[v.fir];
}
inline void dfs2(int u){
//	printf("&%d %d\n",u,son[u].size());
	std::sort(son[u].begin(),son[u].end(),cmp);
	for(auto i:son[u]){
		int v=i.fir;
		if(sum[v]>=-x){
			dfs2(v);
			printf("%d\n",i.sec);
		}
		else{
//			a[v]+=a[u];
			printf("%d\n",i.sec);
			dfs2(v);
		}
//		a[u]+=sum[v];
	}
}

int main(){
	scanf("%d%d%d",&n,&m,&x);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]-=x;
	}
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		addedge(u,v);
		addedge(v,u);
	}
	dfs1(1);
	if(sum[1]<-x){
		puts("NO");
		return 0;
	}
	puts("YES");
	dfs2(1);
}