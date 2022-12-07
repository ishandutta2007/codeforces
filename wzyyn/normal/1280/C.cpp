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
const int N=1000005;
int n,tot,sz[N],head[N];
struct edge{
	int to,next,v;
}e[N*2];
ll S1,S2;
void add(int x,int y,int v){
	e[++tot]=(edge){y,head[x],v};
	head[x]=tot;
}
void dfs(int x,int fa){
	sz[x]=1;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa){
			dfs(e[i].to,x);
			S1+=1ll*(sz[e[i].to]&1)*e[i].v;
			S2+=1ll*min(2*n-sz[e[i].to],sz[e[i].to])*e[i].v;
			sz[x]+=sz[e[i].to];
		}
}
void solve(){
	scanf("%d",&n);
	For(i,1,2*n) head[i]=0;
	S1=0,S2=0;
	For(i,1,2*n-1){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		add(x,y,v); add(y,x,v);
	}
	dfs(1,0);
	printf("%lld %lld\n",S1,S2);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}