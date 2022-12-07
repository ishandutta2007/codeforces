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
const int N=200005;
vector<int> vec[N];
int sz[N],ok[N],n;
int q[N],fa[N];
int ans[N*2][3],top;
vector<int> e[N];
void dfs(int x,int fa){
	sz[x]=1; int mx=0;
	for (auto i:e[x]) if (i!=fa)
		dfs(i,x),sz[x]+=sz[i],mx=max(mx,sz[i]);
	if (sz[x]*2>=n&&mx*2<=n) ok[x]=1;
}
void dfs2(int x,int y){
	fa[x]=y;
	for (auto i:e[x])
		if (i!=y) dfs2(i,x);
	q[++*q]=x;
}
void ins(int x,int y,int z){
	++top;
	ans[top][0]=x;
	ans[top][1]=y;
	ans[top][2]=z;
}
int main(){
	scanf("%d",&n);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	dfs(1,0);
	For(i,1,n) if (ok[i])
		for (auto j:e[i]) if (!ok[j]){
			*q=0; dfs2(j,i);
			ins(i,j,q[1]);
			For(k,1,(*q)-1)
				if (fa[q[k]]!=q[k+1])
					ins(q[k],fa[q[k]],q[k+1]);
			Rep(k,(*q)-1,2)
				ins(q[k-1],q[k],q[*q]);
			ins(i,q[1],q[*q]);
		}
	printf("%d\n",top);
	For(i,1,top) For(j,0,2)
		printf("%d%c",ans[i][j],j==2?'\n':' ');
}
/*
4-1-2-3
*/