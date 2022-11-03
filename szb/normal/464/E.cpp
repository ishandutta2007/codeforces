#include<queue>
#include<ctime>
#include<vector>
#include<cstdio>
#include<cstring>
#include<string>
#include<memory.h>
#include<map>
#include<ctime>
#include<algorithm>
#define ll int
#define For(i,j,k)  for(ll i=j;i<=k;++i)
#define FOr(i,j,k)  for(ll i=j;i>=k;--i)
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void wrote(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) wrote(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){ wrote(x);   puts("");   }
const ll N=101010,mod=1e9+7;
struct dt{	ll l,r,v;	}tr[N*100];
struct data{	ll v,id;	};
ll ans,S,T,n,m,bin[N],nn=101000,tot,cnt,head[N],nxt[N*2],vet[N*2],val[N*2],pre[N],dis[N];	bool vis[N];
inline void insert(ll x,ll y,ll w){	nxt[++tot]=head[x];	head[x]=tot;	vet[tot]=y;	val[tot]=w;	}
bool cmp(ll p,ll q,ll l,ll r){
	if (l==r)	return tr[p].v>tr[q].v;
	ll mid=(l+r)>>1;
	if (tr[tr[p].r].v!=tr[tr[q].r].v)	return cmp(tr[p].r,tr[q].r,mid+1,r);
	else	return cmp(tr[p].l,tr[q].l,l,mid);
}
bool jia(ll p,ll &q,ll l,ll r,ll k){
	if (!q)	q=++cnt;
	if (l==r)	return tr[q].v=tr[p].v^1,tr[p].v;
	ll mid=(l+r)>>1,re;
	if (mid<k)	tr[q].l=tr[p].l,re=jia(tr[p].r,tr[q].r,mid+1,r,k);
	else{
		ll A=jia(tr[p].l,tr[q].l,l,mid,k);
		if (!A)	tr[q].r=tr[p].r,re=0;
		else	re=jia(tr[p].r,tr[q].r,mid+1,r,mid+1);
	}
	tr[q].v=(1LL*bin[mid-l+1]*tr[tr[q].r].v+tr[tr[q].l].v)%mod;
	return re;
}
bool operator <(data a,data b){	return cmp(a.v,b.v,0,nn);	}
priority_queue<data>Q;
void dfs(ll x){
	++ans;
	if (x==S)	return printf("%d\n%d ",ans,x),void(0);
	dfs(pre[x]);	printf("%d ",x);
}
void print(ll x){
	writeln(tr[x].v);
	ans=0;	dfs(T);	exit(0);
}
void dijstra(){
	Q.push((data){dis[S]=++cnt,S});
	while(!Q.empty()){
		data now=Q.top();	Q.pop();
		if (now.id==T)	print(now.v);
		if (vis[now.id])	continue;
		vis[now.id]=1;
		for(ll i=head[now.id];i;i=nxt[i]){
			ll to=0;
			jia(now.v,to,0,nn,val[i]);
			if (!dis[vet[i]]||cmp(dis[vet[i]],to,0,nn)){
				dis[vet[i]]=to;	pre[vet[i]]=now.id;
				Q.push((data){to,vet[i]});
			}
		}
	}puts("-1");
}
int main(){
//	freopen("a.in","r",stdin);
	bin[0]=1;	For(i,1,N-1)	bin[i]=bin[i-1]*2%mod;
	n=read();	m=read();
	For(i,1,m){
		ll x=read(),y=read(),w=read();
		insert(x,y,w);	insert(y,x,w);
	}S=read();	T=read();
	dijstra();
}