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
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void wrote(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) wrote(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){ wrote(x);   puts("");   }
const ll N=200010;
struct data{	double win,los,ans;	ll cho1,cho2;	}tr[N*4];
ll a[N],b[N],n,m,Q;	double pyop[N];
void change(ll l,ll r,ll p,ll pos){
	if (l==r){
		tr[p].ans=min(pyop[l]/2,pyop[l]*a[l]/(a[l]+b[l]));
		tr[p].win=a[l]>=b[l]?0:pyop[l]*(a[l]+1)/(a[l]+b[l]+1)-pyop[l]*a[l]/(a[l]+b[l]);
		tr[p].los=!a[l]?1e10:(a[l]>b[l])?0:pyop[l]*a[l]/(a[l]+b[l])-pyop[l]*(a[l]-1)/(a[l]+b[l]-1);
		tr[p].cho1=tr[p].cho2=l;
		return;
	}ll mid=(l+r)>>1,ls=p<<1,rs=p<<1|1;
	pos<=mid?change(l,mid,p<<1,pos):change(mid+1,r,p<<1|1,pos);
	tr[p].ans=tr[ls].ans+tr[rs].ans;
	tr[p].win=max(tr[ls].win,tr[rs].win);
	tr[p].los=min(tr[ls].los,tr[rs].los);
	tr[p].cho1=tr[p].win==tr[ls].win?tr[ls].cho1:tr[rs].cho1;
	tr[p].cho2=tr[p].los==tr[ls].los?tr[ls].cho2:tr[rs].cho2;
}
int main(){
//	freopen("a.in","r",stdin);
	n=read();	m=read();	Q=read();
	For(i,1,n)	pyop[i]=read();
	For(i,1,n)	b[i]=read(),change(1,n,1,i);
	while(m--){
		a[tr[1].cho1]++;
		change(1,n,1,tr[1].cho1);
	}
	while(Q--){
		ll x=read(),y=read();
		x==1?b[y]++:b[y]--;
		change(1,n,1,y);
		if (tr[1].win>tr[1].los){
			a[tr[1].cho1]++;			a[tr[1].cho2]--;
			change(1,n,1,tr[1].cho1);	change(1,n,1,tr[1].cho2);
		}printf("%.10lf\n",tr[1].ans);
	}
}