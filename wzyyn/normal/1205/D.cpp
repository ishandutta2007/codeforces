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
using namespace std;
const int N=1005;
struct edge{
	int to,next;
}e[N*2];
int head[N],tot,n;
int sz[N],mxv,mxrt;
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void dfs(int x,int fa,int n){
	int mx=0; sz[x]=1;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa){
			dfs(e[i].to,x,n);
			sz[x]+=sz[e[i].to];
			mx=max(mx,sz[e[i].to]);
		}
	mx=max(mx,n-sz[x]);
	if (mx<mxv) mxv=mx,mxrt=x;
}
pii q[N];
int f[N][N];
int top,be[N],mnv,mnid,dif;
void insert(int x,int y){
	q[++top]=pii(x,y);
	For(i,0,n) f[top][i]=f[top-1][i];
	For(i,y,n) f[top][i]|=f[top-1][i-y];
}
int s1,s2,dep[N];
void getans(int x,int fa,int type){
	dep[x]=(type==1?(s1+=1):(s2+=dif));
	//printf("
	printf("%d %d %d\n",x,fa,dep[x]-dep[fa]);
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa)
			getans(e[i].to,x,type);
}
int main(){
	scanf("%d",&n);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	mxv=1<<30; dfs(1,0,n);
	f[0][0]=1;
	for (int i=head[mxrt];i;i=e[i].next)
		insert(e[i].to,sz[e[i].to]>sz[mxrt]?n-sz[mxrt]:sz[e[i].to]);
	insert(mxrt,1);
	mnv=1<<30;
	For(i,0,n)
		if (abs(n-2*i)<mnv&&f[top][i])
			mnv=n-2*i,mnid=i;
	dif=mnid;
	Rep(i,top,1){
		if (mnid>=q[i].se&&f[i-1][mnid-q[i].se])
			be[i]=1,mnid-=q[i].se;
		else be[i]=0;
	}
	For(i,1,top-1)
		getans(q[i].fi,mxrt,be[i]);
}