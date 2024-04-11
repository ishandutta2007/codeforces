#include<cstdio>
#include<algorithm>
#include<vector>
#define N 500005

int n,b[N],c[N];

std::vector<int> e[N];

int t[N<<2];
inline void build(int p,int L,int R){
	if(L==R){
		t[p]=c[L];
		return;
	}
	int mid=(L+R)>>1;
	build(p<<1,L,mid);
	build(p<<1|1,mid+1,R);
	t[p]=std::max(t[p<<1],t[p<<1|1]);
}
inline int sch(int p,int L,int R,int l,int r,int x){
//	printf("*%d %d %d %d %d %d %d\n",p,L,R,l,r,x,t[p]);
	if(t[p]<=x||L>r||R<l)
		return -1;
	if(L==R)
		return L;
	int mid=(L+R)>>1;
	if(t[p<<1]>x)
		return sch(p<<1,L,mid,l,r,x);
	else
		return sch(p<<1|1,mid+1,R,l,r,x);
}
inline void del(int p,int L,int R,int x){
	if(L==R){
		t[p]=-1;
		return;
	}
	int mid=(L+R)>>1;
	if(x<=mid)
		del(p<<1,L,mid,x);
	else
		del(p<<1|1,mid+1,R,x);
	t[p]=std::max(t[p<<1],t[p<<1|1]);
}

int A[N],tot;
bool vis[N];
inline void dfs(int u){
	if(vis[u])
		return;
	vis[u]=1;
	while(e[u].size()){
//		printf("^%d %d\n",u,e[u].back());
		dfs(e[u].back());
		e[u].pop_back();
	}
	while(1){
		int v=sch(1,1,n,1,b[u]-1,u);
//		printf("&%d %d\n",u,v);
		if(v!=-1){
			del(1,1,n,v);
			if(!vis[v])
				dfs(v);
		}
		else
			break;
	}
	A[++tot]=u;
}

int a[N];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		c[i]=n+1;
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		if(b[i]==-1)
			b[i]=n+1;
		if(b[i]<=n)
			e[b[i]].push_back(i);
		c[b[i]]=i;
	}
	build(1,1,n);
	for(int i=1;i<=n;i++)
		dfs(i);
//	for(int i=1;i<=n;i++)
//		printf("%d ",A[i]);
//	puts("");
	for(int i=1;i<=n;i++)
		a[A[i]]=i;
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
	puts("");
}