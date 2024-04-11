#include<queue>
#include<ctime>
#include<vector>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<memory.h>
#include<map>
#include<ctime>
#include<algorithm>
#include<ctime>
#define ll long long
#define For(i,j,k)  for(ll i=j;i<=k;++i)
#define FOr(i,j,k)  for(ll i=j;i>=k;--i)
#define ld double
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void wrote(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) wrote(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){ wrote(x);   puts("");   }
const ll N=600010,inf=1e9;
ll fa[N],tot,head[N],nxt[N],vet[N],c[N],v[N],pos[N],n;
struct data{
	ll l1,r1,l2,r2,dis,c1,c2;
	void New(ll x){
        dis=-inf;   c1=c2=0;
        if (v[x]==-6)   c2=1;
        if (v[x]==-9)   c1=1;
        if (v[x]>0&&c[v[x]]) l1=r1=l2=r2=0;
        else    l1=r1=l2=r2=-inf;
	}
}tr[N*4];
data operator + (data x,data y){
    data s;
    ll a=x.c1,b=x.c2,c=y.c1,d=y.c2;
    s.dis=max(max(x.dis,y.dis),max(x.r1+y.l2,x.r2+y.l1));
    s.r1=max(y.r1,max(x.r1-c+d,x.r2+c+d));
    s.l1=max(x.l1,max(y.l1-b+a,y.l2+b+a));
    s.r2=max(y.r2,x.r2+c-d);
    s.l2=max(x.l2,y.l2+b-a);
    if (b<c) s.c1=a-b+c,s.c2=d;
    else    s.c1=a,s.c2=b-c+d;
    return s;
}
void insert(ll x,ll y){	nxt[++tot]=head[x];	head[x]=tot;	vet[tot]=y;	}
void dfs(ll x){
	v[++tot]=-6;	v[++tot]=x;	pos[x]=tot;
	for(ll i=head[x];i;i=nxt[i])	dfs(vet[i]);
	v[++tot]=-9;
}
void build(ll l,ll r,ll p){
	if (l==r)	return tr[p].New(l),void(0);
	ll mid=(l+r)>>1;
	build(l,mid,p<<1);	build(mid+1,r,p<<1|1);
	tr[p]=tr[p<<1]+tr[p<<1|1];
}
void add(ll l,ll r,ll p,ll pos){
	if (l==r)	return tr[p].New(l),void(0);
	ll mid=(l+r)>>1;
	pos<=mid?add(l,mid,p<<1,pos):add(mid+1,r,p<<1|1,pos);
	tr[p]=tr[p<<1]+tr[p<<1|1];
}
int main(){
//	freopen("a.in","r",stdin);
	n=read();
	For(i,2,n)	fa[i]=read(),insert(fa[i],i);
	tot=0;	dfs(1);	c[1]=1;	build(1,tot,1);
	For(i,2,n){
		c[i]=1;
		add(1,tot,1,pos[i]);
		printf("%lld ",tr[1].dis);
	}
}
//c1,c2
//l2
//r2
//l1
//r1
//dis