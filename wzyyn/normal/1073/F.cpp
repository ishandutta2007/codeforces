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
struct edge{
	int to,next;
}e[N*2];
int head[N],cnt[N],n,tot;
int mx1[N],mx2[N],d[N],mx;
int ans1,ans2,ans3,ans4;
pii mxv;
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot; ++cnt[x];
}
void dfs(int x,int fa){
	mx1[x]=mx2[x]=x;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa){
			d[e[i].to]=d[x]+1;
			dfs(e[i].to,x);
			int tmp=mx1[e[i].to];
			if (d[tmp]>d[mx1[x]]) swap(mx1[x],tmp);
			if (d[tmp]>d[mx2[x]]) swap(mx2[x],tmp);
		}
	if (cnt[x]>=3){
		pii val(d[x],d[mx1[x]]+d[mx2[x]]-d[x]);
		if (val>mxv) mxv=val,mx=x;
	}
}
int main(){
	scanf("%d",&n);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	dfs(1,0);
	ans1=mx1[mx]; ans3=mx2[mx];
	mxv=pii(0,0); dfs(mx,0);
	ans2=mx1[mx]; ans4=mx2[mx];
	printf("%d %d\n%d %d\n",ans1,ans2,ans3,ans4);
}