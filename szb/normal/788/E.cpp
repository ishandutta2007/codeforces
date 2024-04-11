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
#include<set>
#define ll int
#define For(i,j,k)  for(ll i=j;i<=k;++i)
#define FOr(i,j,k)  for(ll i=j;i>=k;--i)
#define rep(i,j,k)	for(ll i=j;i<k;++i)
#define ld double
#define fi first
#define se second
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void wrote(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) wrote(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){ wrote(x);   puts("");   }
const ll mod=1e9+7,N=3000010;
struct data{	ll m[3][3];	}tr[N],tmp;
ll ls[N],rs[N],pre[N],nxt[N],a[N],rt[N],c[N],q[N],ans,n,cnt;
void upd(ll &x,ll y){	x=(x+y)%mod;	}
data operator * (data a,data b){
	For(i,0,2)	For(j,0,2){
		tmp.m[i][j]=(a.m[i][j]+b.m[i][j])%mod;
		For(k,i,j-1)	upd(tmp.m[i][j],1LL*a.m[i][k]*b.m[k+1][j]%mod);
	}return tmp;
}
void add(ll x){	for(;x<=n;x+=x&-x)	c[x]++;	}
ll ask(ll x){	ll ans=0;	for(;x;x-=x&-x)	ans+=c[x];	return ans;	}
void change(ll &x,ll l,ll r,ll pos,ll v){
	if (!x)	x=++cnt;
	if (l==r){
		tr[x].m[0][0]=pre[l]*v;
		tr[x].m[1][1]=v;
		tr[x].m[2][2]=nxt[l]*v;
		return;
	}ll mid=(l+r)>>1;
	pos<=mid?change(ls[x],l,mid,pos,v):change(rs[x],mid+1,r,pos,v);
	tr[x]=tr[ls[x]]*tr[rs[x]];
}
int main(){
//	freopen("a.in","r",stdin);
	n=read();
	For(i,1,n)	a[i]=read(),q[i]=a[i];
	sort(q+1,q+n+1);
	For(i,1,n)	a[i]=lower_bound(q+1,q+n+1,a[i])-q;
	For(i,1,n)	pre[i]=ask(a[i]),add(a[i]);
	memset(c,0,sizeof c);
	FOr(i,n,1)	nxt[i]=ask(a[i]),add(a[i]);
	For(i,1,n)	change(rt[a[i]],1,n,i,1);
	For(i,1,n)	ans=(ans+tr[rt[i]].m[0][2])%mod;
	ll Q=read();
	while(Q--){
		ll opt=read(),x=read();
		ans=(ans-tr[rt[a[x]]].m[0][2])%mod;
		opt==2?change(rt[a[x]],1,n,x,1):change(rt[a[x]],1,n,x,0);
		ans=(ans+tr[rt[a[x]]].m[0][2])%mod;
		writeln((ans+mod)%mod);
	}
}
/*
n011m01531n,m<=10^5
*/