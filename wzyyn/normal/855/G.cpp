#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=100005;
vector<int> e[N];
int sz[N],fa[N],n,Q;
int f[N],v[N],dep[N];
ll vv[N],ans;
int get(int x){
	return x==f[x]?x:f[x]=get(f[x]);
}
void dfs(int x){
	sz[x]=1;
	for (auto i:e[x])
		if (i!=fa[x]){
			fa[i]=x;
			dep[i]=dep[x]+1;
			dfs(i);
			sz[x]+=sz[i];
		}
}
void merge(int x,int y){
	f[x]=y=get(y);
	ans+=1ll*v[x]*vv[x];
	ans+=1ll*v[y]*vv[y];
	v[y]+=v[x]; vv[y]+=vv[x];
	vv[y]-=1ll*sz[x]*(sz[x]-1);
	vv[y]-=1ll*(n-sz[x])*(n-sz[x]-1);
	ans-=1ll*v[y]*vv[y];
}
int main(){
	scanf("%d",&n);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	dfs(1);
	ans=1ll*n*(n-1)*(n-2);
	For(i,1,n) f[i]=i,v[i]=1;
	For(i,1,n)
		for (auto j:e[i]){
			int m=(fa[j]==i?sz[j]:n-sz[i]);
			ans-=1ll*m*(m-1);
			vv[i]+=1ll*m*(m-1);
		}
	printf("%lld\n",ans);
	scanf("%d",&Q);
	while (Q--){
		int x,y;
		scanf("%d%d",&x,&y);
		for (;;){
			x=get(x); y=get(y);
			if (x==y) break;
			if (dep[x]<dep[y]) swap(x,y);
			merge(x,fa[x]);
		}
		printf("%lld\n",ans);
	}
}
/*
(

A-x-A 
A
 
*/