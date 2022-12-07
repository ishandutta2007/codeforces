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
vector<int> e[N],f[N];
int vfa[N],n,ans,p[N],q[N],vis[N];
void dfs1(int x,int fa){
	for (auto i:e[x])
		if (i!=fa)
			dfs1(i,x);
	if (!vis[x]){
		if (fa){
			f[x].PB(fa);
			f[fa].PB(x);
			vis[x]=vis[fa]=1;
		}
		else{
			f[e[x][0]].PB(x);
			f[x].PB(e[x][0]); 
		}
		++ans;
	}
} 
void dfs2(int x){
	q[++*q]=x;
	vis[x]=1;
	for (auto i:f[x])
		if (!vis[i])
			dfs2(i);
}
int main(){
	scanf("%d",&n);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	dfs1(1,0);
	memset(vis,0,sizeof(vis));
	For(i,1,n) if (!vis[i]){
		*q=0; dfs2(i);
		For(j,1,*q) p[q[j]]=q[j%(*q)+1];
	}
	printf("%d\n",ans*2);
	For(i,1,n) printf("%d ",p[i]);
}