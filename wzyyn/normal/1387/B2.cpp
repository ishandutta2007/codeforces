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
int n,sz[N],rt,q[N],ans[N];
vector<int> e[N];
ll res;
void dfs(int x,int fa,int n){
	sz[x]=1;
	int mx=0;
	for (auto i:e[x])
		if (i!=fa){
			dfs(i,x,n);
			sz[x]+=sz[i];
			mx=max(mx,sz[i]);
		}
	if (sz[x]*2>n&&mx*2<=n)
		rt=x;
}
void dfs2(int x,int fa){
	q[++*q]=x;
	sz[x]=1;
	for (auto i:e[x])
		if (i!=fa){
			dfs2(i,x);
			sz[x]+=sz[i];
			res+=sz[i];
		}
}
int main(){
	scanf("%d",&n);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	dfs(1,0,n);
	dfs2(rt,0);
	For(i,1,n)
		ans[q[i]]=q[(i+n/2-1)%n+1];
	printf("%lld\n",res*2);
	For(i,1,n)
		printf("%d ",ans[i]);
}