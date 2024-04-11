#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define N 1500005

int n,a[N],b[N];

std::vector<std::tuple<int,int,int>> E[N];
inline void build(int p,int L,int R){
	if(L==R){
		E[n+p].emplace_back(L+b[L],0,L);
		return;
	}
	int mid=(L+R)>>1;
	build(p<<1,L,mid),build(p<<1|1,mid+1,R);
	E[n+p].emplace_back(n+(p<<1),0,0),E[n+p].emplace_back(n+(p<<1|1),0,0);
}
inline void adde(int p,int L,int R,int l,int r,int x){
	if(L>r||R<l)
		return;
	if(l<=L&&R<=r)
		return E[x].emplace_back(n+p,1,0),void();
	int mid=(L+R)>>1;
	adde(p<<1,L,mid,l,r,x),adde(p<<1|1,mid+1,R,l,r,x);
}

int dis[N],pre[N],id[N];
std::priority_queue<std::pair<int,int>> q;
inline void dij(int s){
	memset(pre,-1,sizeof(pre));
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	q.emplace(0,s);
	while(q.size()){
		int u=q.top().second;
		q.pop();
		for(auto [v,w,i]:E[u])
			if(dis[v]>dis[u]+w){
				pre[v]=u;
				id[v]=i;
				dis[v]=dis[u]+w;
				q.emplace(-dis[v],v);
			}
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	build(1,0,n);
	for(int i=1;i<=n;i++)
		adde(1,0,n,i-a[i],i,i);
	dij(n);
	if(dis[0]==inf)
		return puts("-1"),0;
	printf("%d\n",dis[0]);
	std::vector<int> ans;
	for(int u=0;u!=n;u=pre[u])
		if(u<=n)
			ans.push_back(id[u]);
	std::reverse(ans.begin(),ans.end());
	for(auto x:ans)
		printf("%d ",x);
	puts("");
}