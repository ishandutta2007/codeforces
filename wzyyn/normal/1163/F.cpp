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
	int to,next,v;
}e[N*2];
int head[N],tot,n,m,QQ;
int vis[N],spe[N*2];
int q[N],id1[N],id2[N];
ll d[N],dS[N],dT[N];
pii from[N];
priority_queue<pll> Q;
void add(int x,int y,int v){
	e[++tot]=(edge){y,head[x],v};
	head[x]=tot;
} 
void SSSP(int S){	
	For(i,1,n) d[i]=1ll<<60,vis[i]=0;
	Q.push(pll(d[S]=0,S));
	from[S]=pii(0,0);
	while (!Q.empty()){
		int x=Q.top().se; Q.pop();
		if (vis[x]) continue;
		vis[x]=1;
		for (int i=head[x];i;i=e[i].next)
			if (d[e[i].to]>d[x]+e[i].v){
				d[e[i].to]=d[x]+e[i].v;
				from[e[i].to]=pii(i,x);
				Q.push(pll(-d[e[i].to],e[i].to));
			}
	}
}
int getid(int x){
	return vis[x]?vis[x]:vis[x]=getid(from[x].se);
}
ll t[N*4];
void build(int k,int l,int r){
	t[k]=1ll<<60;
	if (l==r) return;
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
}
void change(int k,int l,int r,int x,int y,ll v){
	//if (l==1&&r==*q) cout<<x<<' '<<y<<' '<<v<<endl;
	if (x>y) return;
	if (x<=l&&r<=y){
		t[k]=min(t[k],v);
		return;
	}
	int mid=(l+r)/2;
	if (x<=mid) change(k*2,l,mid,x,y,v);
	if (y>mid) change(k*2+1,mid+1,r,x,y,v);
}
ll ask(int k,int l,int r,int x){
	if (l==r) return t[k];
	int mid=(l+r)/2;
	if (x<=mid) return min(t[k],ask(k*2,l,mid,x));
	return min(t[k],ask(k*2+1,mid+1,r,x));
}
int x[N],y[N],v[N];
int main(){
	//freopen("1.in","r",stdin);
	scanf("%d%d%d",&n,&m,&QQ);
	For(i,1,m){
		scanf("%d%d%d",&x[i],&y[i],&v[i]);
		add(x[i],y[i],v[i]);
		add(y[i],x[i],v[i]);
	}
	vis[0]=-1;
	SSSP(1);
	For(i,1,n) dS[i]=d[i],vis[i]=0;
	for (int i=n;i;i=from[i].se) q[++*q]=i;
	reverse(q+1,q+*q+1);
	//For(i,1,*q) cout<<q[i]<<' '; cout<<endl;
	For(i,1,*q) vis[q[i]]=i;
	For(i,2,*q) spe[from[q[i]].fi]=i;
	For(i,1,m) spe[i*2]=spe[i*2-1]=spe[i*2]+spe[i*2-1];
	//cout<<233<<endl;
	For(i,1,n) id1[i]=getid(i);
	//cout<<233<<endl;
	SSSP(n);
	For(i,1,n) dT[i]=d[i],vis[i]=0;
	For(i,1,*q) vis[q[i]]=i;
	For(i,1,n) id2[i]=getid(i);
	//For(i,1,n) cout<<id1[i]<<' '<<id2[i]<<' '<<dS[i]<<' '<<dT[i]<<endl;
	build(1,1,*q);
	For(i,1,m) if (!spe[i*2]&&!spe[i*2-1]){
		//cout<<i<<endl;
		change(1,1,*q,id1[x[i]]+1,id2[y[i]],dS[x[i]]+dT[y[i]]+v[i]);
		change(1,1,*q,id1[y[i]]+1,id2[x[i]],dS[y[i]]+dT[x[i]]+v[i]);
	}
	//cout<<spe[4]<<endl;
	while (QQ--){
		int id,v;
		scanf("%d%d",&id,&v);
		if (!spe[id*2]) printf("%lld\n",min(dS[n],min(dS[x[id]]+dT[y[id]],dS[y[id]]+dT[x[id]])+v));
		else printf("%lld\n",min(dS[n]+v-::v[id],ask(1,1,*q,spe[id*2])));
	}
}