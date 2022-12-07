#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int N=100005;
struct edge{
	int to,next,v;
}e[N*2];
int head[N],q[N],tot,n,Q;
int f[N],fa[N],fr[N],id[N];
ll dS[N],dT[N],a[N];
int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
bool cmp(int x,int y){
	return a[x]<a[y];
}
void add(int x,int y,int v){
	e[++tot]=(edge){y,head[x],v};
	head[x]=tot;
}
int find(int S,ll *d){
	For(i,1,n) d[i]=-1;
	int h=0,t=1; q[1]=S; d[S]=0;
	while (h!=t){
		int x=q[++h];
		for (int i=head[x];i;i=e[i].next)
			if (d[e[i].to]==-1){
				d[e[i].to]=d[x]+e[i].v;
				q[++t]=e[i].to;
			}
	}
	int id=1;
	For(i,2,n)
		if (d[i]>d[id]) id=i;
	return id;
}
void dfs(int x){
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fr[x]){	
			fr[e[i].to]=x;
			dfs(e[i].to);
		}
}
int main(){
	scanf("%d",&n);
	For(i,1,n-1){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		add(x,y,v); add(y,x,v);
	}
	int S=find(1,dS);
	int T=find(S,dS);
	find(T,dT);
	For(i,1,n) a[i]=max(dS[i],dT[i]);
	For(i,1,n) id[i]=i;
	sort(id+1,id+n+1,cmp);
	dfs(id[1]);
	scanf("%d",&Q);
	//cerr<<233<<' '<<id[1]<<endl;
	while (Q--){
		ll v;
		scanf("%lld",&v);
		For(i,1,n) f[i]=1,fa[i]=i;
		int ans=0,p=n;
		Rep(i,n,1){
			int x=id[i];
			for (int j=head[x];j;j=e[j].next)
				if (e[j].to!=fr[x]){
					fa[e[j].to]=x;
					f[x]+=f[e[j].to];
				}
			for (;a[id[p]]-a[x]>v;--p)
				--f[get(id[p])];
			ans=max(ans,f[x]);
		}
		printf("%d\n",ans);
	}
}