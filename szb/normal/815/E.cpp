#include<cstdio>
#include<cstring>
#include<memory.h>
#include<algorithm>
#define ll long long
#define For(i,j,k)  for(ll i=j;i<=k;++i)
#define FOr(i,j,k)  for(ll i=j;i>=k;--i)
#define F first
#define S second
#define maxn 100010
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void wrote(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) wrote(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){ wrote(x);   puts("");   }
ll n,k;
ll get(ll now,ll to){//nowto
	if (now<=to<<1)	return 0;
	ll s1=1,s2=0,p1=now,p2=now-1,ans=0;
	while(p2>=to<<1){
		if (p2==to<<1)	return s1+ans;
		ans+=s1+s2;
		p1&1?s1=(s1<<1)+s2:s2=(s2<<1)+s1;
		p1>>=1;	p2=p1-1;
	}return ans;
}
ll solve(ll l,ll r,ll p,ll k){
	ll mid=(l+r)>>1;
	if (k==1)	return mid;
	ll tmp=get(mid-l,p),Tmp=get(r-mid,p+1);
	if (k>tmp+Tmp+1)	solve(mid+1,r,p,k-tmp-1);
	else	return solve(l,mid-1,p,k-Tmp-1);
}
int main(){
//	freopen("a.in","r",stdin);
	n=read();	k=read();
	if (k==1)	return writeln(1),0;
	if (k==2)	return writeln(n),0;
	k-=2;	n-=2;
	ll l=0,r=(n>>1)+1;
	while(r-l>1){
		ll mid=(l+r)>>1;
		if (get(n,mid)<k)	r=mid;
		else	l=mid;
	}writeln(solve(1,n,l,k)+1);
}