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
#define ll long long
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
const ll N=120010,inf=1LL<<60;
struct data{	ll m[3][3];	}tr[N],tmp,ne;
pair<ll,ll>a[N],b[N];
ll tru[N],pos[N],n,Q;
inline data operator *(data A,data B){
	For(i,0,2)	For(j,0,2){
		tmp.m[i][j]=-inf;
		For(k,0,2)	tmp.m[i][j]=max(tmp.m[i][j],A.m[i][k]+B.m[k][j]);
	}return tmp;
}
inline bool match(ll x,ll y){	return tru[a[x].se]!=b[y].se;	}
inline void upd(ll &x,ll y){	if (y>x)	x=y;	}
void change(ll l,ll r,ll p,ll pos){
	if (l==r){
		tr[p];	tr[p]=ne;
		tr[p].m[0][1]=tr[p].m[1][2]=0;
		if (match(l,l))	tr[p].m[0][0]=a[l].fi*b[l].fi;
		if (l>1&&match(l,l-1)&&match(l-1,l))	tr[p].m[1][0]=a[l-1].fi*b[l].fi+a[l].fi*b[l-1].fi;
		if (l>2&&match(l,l-2)&&match(l-2,l-1)&&match(l-1,l))	upd(tr[p].m[2][0],a[l].fi*b[l-2].fi+a[l-2].fi*b[l-1].fi+a[l-1].fi*b[l].fi);
		if (l>2&&match(l,l-1)&&match(l-1,l-2)&&match(l-2,l))	upd(tr[p].m[2][0],a[l].fi*b[l-1].fi+a[l-1].fi*b[l-2].fi+a[l-2].fi*b[l].fi);
		return;
	}ll mid=(l+r)>>1;
	if (pos<=mid)	change(l,mid,p<<1,pos);
	else	change(mid+1,r,p<<1|1,pos);
	tr[p]=tr[p<<1]*tr[p<<1|1];
}
int main(){
	For(i,0,2)	For(j,0,2)	ne.m[i][j]=-inf;
	n=read();	Q=read();
	For(i,1,n)	a[i].fi=read(),a[i].se=i;
	For(i,1,n)	b[i].fi=read(),b[i].se=i;
	sort(a+1,a+n+1,greater<pair<ll,ll> >());	sort(b+1,b+n+1,greater<pair<ll,ll> >());
	For(i,1,n)	pos[a[i].se]=i,tru[i]=i;
	For(i,1,n)	change(1,n,1,i);
	while(Q--){
		ll x=read(),y=read();
		swap(tru[x],tru[y]);
		For(i,pos[x],pos[x]+2)	if (i<=n)	change(1,n,1,i);
		For(i,pos[y],pos[y]+2)	if (i<=n)	change(1,n,1,i);
		writeln(tr[1].m[0][0]);
	}
}
/*
nnq2
*/