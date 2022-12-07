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
const int V=998244353;
struct edge{
	int to,next;
}e[N*2];
int head[N],tot,n;
ll f[N],g[N],q[N*2];
int mp[N*2],S,ans,ansv;
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void add(int x){
	if (!mp[x]) ++S;
	//else if (mp[x]==1) --S;
	++mp[x];
}
void del(int x){
	--mp[x];
	if (!mp[x]) --S;
	//else if (mp[x]==1) ++S;
}
void dfs1(int x,int fa){
	f[x]=114514;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa){
			dfs1(e[i].to,x);
			f[x]+=f[e[i].to]*(f[e[i].to]^V)+1919813;
		}
}
void dfs2(int x,int fa){
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa){
			g[e[i].to]=(x==1?0:g[x]*(g[x]^V)+1919813)+f[x];
			g[e[i].to]-=f[e[i].to]*(f[e[i].to]^V)+1919813;
			dfs2(e[i].to,x);
		}
}
void getans(int x,int fa){
	if (S>ansv) ansv=S,ans=x;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa){
			del(f[e[i].to]);
			add(g[e[i].to]);
			getans(e[i].to,x);
			del(g[e[i].to]);
			add(f[e[i].to]);
		}
}
int main(){
	scanf("%d",&n);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	dfs1(1,0);
	dfs2(1,0);
	For(i,2,n){
		q[++*q]=f[i];
		q[++*q]=g[i];
		//cout<<f[i]<<' '<<g[i]<<endl;
	}
	sort(q+1,q+*q+1);
	For(i,2,n){
		f[i]=lower_bound(q+1,q+*q+1,f[i])-q;
		g[i]=lower_bound(q+1,q+*q+1,g[i])-q;
	}
	For(i,2,n) add(f[i]);
	ansv=-1; getans(1,0);
	printf("%d\n",ans);
}