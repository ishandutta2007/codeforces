#include<cstdio>
#include<cstring>
#include<algorithm>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
const int N=200005;
int n,a[N],ans[N],id[N],L[N],R[N];bool vis[N];
bool cmp(int a,int b){return ::a[a]>::a[b];}
int getl(int u){
	return !vis[u]?u:L[u]=getl(L[u]);
}
int getr(int u){
	return !vis[u]?u:R[u]=getr(R[u]);
}
int main(){
//	memset(ans,63,sizeof(ans));
	scanf("%d",&n);
	for(int i=1;i<=n;++i)L[i]=i-1,R[i]=i+1,scanf("%d",a+i),id[i]=i;
	std::sort(id+1,id+1+n,cmp);
	for(int i=1;i<=n;++i){
		int u=id[i];
		vis[u]=1;
		int l=getl(u);
		int r=getr(u);
		ans[r-l-1]=std::max(a[u],ans[r-l-1]);
	}
	for(int i=n;i>=1;--i)ans[i]=std::max(ans[i+1],ans[i]);
	for(int i=1;i<=n;++i)printf("%d ",ans[i]);
	return 0;
}