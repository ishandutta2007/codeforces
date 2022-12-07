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
const int N=3005;
struct edge{
	int to,next;
}e[N*2];
int head[N],sz[N];
int n,m,tot,a[N],b[N];
pll f[N][N],v[N];
pll min(pll a,pll b){
	if (a.fi!=b.fi)
		return a.fi<b.fi?b:a;
	return a.se<b.se?a:b;
}
pll operator +(const pll &a,const pll &b){
	return pll(a.fi+b.fi,a.se+b.se);
}
pll DDD(const pll &a){
	return pll(a.fi+(a.se<0),0);
}
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void dfs(int x,int fa){
	sz[x]=1;
	f[x][1]=pii(0,a[x]-b[x]);
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa){
			dfs(e[i].to,x);
			For(j,1,sz[x]+sz[e[i].to]) v[j]=pll(-1,1ll<<60);
			For(j,1,sz[x]) For(k,1,sz[e[i].to]){
				v[j+k]=min(v[j+k],f[x][j]+DDD(f[e[i].to][k]));
				v[j+k-1]=min(v[j+k-1],f[x][j]+f[e[i].to][k]);
			}
			sz[x]+=sz[e[i].to];
			For(j,1,sz[x]) f[x][j]=v[j];
		}
}
void solve(){
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) scanf("%d",&b[i]);
	For(i,1,n) head[i]=0;
	tot=0;
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	dfs(1,0);
	printf("%lld\n",DDD(f[1][m]).fi);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}
/*
1
5 2
3 0 1 0 3
0 2 0 2 0
1 2
2 3
3 4
4 5
*/