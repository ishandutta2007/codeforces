#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define y1 fdhjksa
using namespace std;
const int N=500005;
struct edge{
	int to,next,v;
}e[N*2];
int head[N],tot,n,k;
ll f[N][2],q[N];
void add(int x,int y,int v){
	e[++tot]=(edge){y,head[x],v};
	head[x]=tot;
}
void dfs(int x,int fa){
	f[x][0]=f[x][1]=0;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa){
			dfs(e[i].to,x);
			f[x][1]+=f[e[i].to][0];
		}
	*q=0;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa) q[++*q]=max(0ll,f[e[i].to][1]+e[i].v-f[e[i].to][0]);
	sort(q+1,q+*q+1,greater<ll>());
	For(i,1,*q) if (i<k) f[x][1]+=q[i];
	f[x][0]=f[x][1]+(*q>=k?q[k]:0);
}
void solve(){
	scanf("%d%d",&n,&k);
	tot=0;
	For(i,1,n) head[i]=0;
	For(i,1,n-1){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		add(x,y,v); add(y,x,v);
	}
	dfs(1,0);
	printf("%lld\n",f[1][0]);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}