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
const int mo=1000000007;
const int N=100005;
struct edge{
	int to,next,v;
}e[N*2];
int head[N],tot;
int deg[N],n;
int f[N],g[N];
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
void add(int x,int y,int v){
	e[++tot]=(edge){y,head[x],v};
	head[x]=tot;
}
void dfs(int x,int fa){
	int sz=deg[x]-(fa!=0);
	if (!sz) return;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa){
			dfs(e[i].to,x);
			g[x]=(g[x]+g[e[i].to])%mo;
			g[x]=(g[x]+e[i].v+1ll*f[e[i].to]*e[i].v)%mo;
			f[x]=(f[x]+f[e[i].to])%mo;
		}
	//cout
	g[x]=1ll*g[x]*power(deg[x],mo-2)%mo;
	f[x]=1ll*f[x]*power(deg[x],mo-2)%mo;
	int p1=(fa?power(deg[x],mo-2):0);
	int p2=(1ll*sz*power(deg[x],mo-2)+mo-f[x])%mo;
	//cout<<p1<<' '<<p2<<' '<<g[x]<<' '<<x<<endl;
	f[x]=1ll*p1*power(p1+p2,mo-2)%mo;
	g[x]=1ll*g[x]*power(p1+p2,mo-2)%mo;
	//cout<<f[x]<<' '<<g[x]<<' '<<x<<' '<<p2<<' '<<p1<<endl;
}
/*
1/3  
1/3 40,
1/6 32,
1/6 24, 
*/
int main(){
	scanf("%d",&n);
	For(i,1,n-1){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		++deg[++x]; ++deg[++y];
		add(x,y,v); add(y,x,v);
	}
	dfs(1,0);
	printf("%d\n",g[1]);
	//printf("%d\n")
}
/*
f[i]:i
g[i]:i 
*/