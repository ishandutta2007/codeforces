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
void GG(){
	puts("-1");
	exit(0);
}
ll gcd(ll x,ll y){
	return y?gcd(y,x%y):x;
}
void exgcd(ll x,ll y,ll &a,ll &b){
	if (!y){
		a=1; b=0;
		return;
	}
	exgcd(y,x%y,b,a);
	b-=(x/y)*a;
}
ll getinv(ll x,ll y){
	ll a,b;
	exgcd(x,y,a,b);
	return (a%y+y)%y;
}
ll mul(ll x,ll y,ll mod){
	ll s=0;
	for (;y;y/=2,x=(x+x)%mod)
		if (y&1) s=(s+x)%mod;
	return s;
}
pll operator /(pll a,pll b){
	assert(a.fi%b.fi==0);
	assert(a.se>=b.se);
	a.se-=b.se;
	assert(a.se%b.fi==0);
	return pll(a.fi/b.fi,a.se/b.fi);
}
pll operator *(pll a,pll b){
	return pll(a.fi*b.fi,a.fi*b.se+a.se);
}
/*
(ax+b)c+d
axcy+axd+bcy+bd
*/
void equation(pll x,pll y,pll &v1,pll &v2){
	bool fl=(x<y);
	if (fl) swap(x,y);
	if (x==y){
		if (!x.fi) v1=v2=pll(-1,0);
		else v1=v2=pll(1,0);
	}
	else if (!x.fi) GG();
	else if (!y.fi){
		if (x.se>y.se||(y.se-x.se)%x.fi) GG();
		v1=pll(0,(y.se-x.se)/x.fi); v2=pll(1,0);
	}
	else if (x.fi==y.fi){
		if ((x.se-y.se)%x.fi) GG();
		v1=pll(1,0);
		v2=pll(1,(x.se-y.se)/x.fi);
	}
	else{
		ll G=gcd(x.fi,y.fi);
		if (x.se%G!=y.se%G) GG();
		ll rem=x.se%G;
		pll X=x,Y=y;
		x.fi/=G; y.fi/=G;
		x.se/=G; y.se/=G;
		ll mod=x.fi*y.fi;
		ll val=(mul(x.se%x.fi,mul(y.fi,getinv(y.fi,x.fi),mod),mod)+
				mul(y.se%y.fi,mul(x.fi,getinv(x.fi,y.fi),mod),mod))%mod;
		if (val<x.se) val+=((x.se-val-1)/mod+1)*mod;
		if (val<y.se) val+=((y.se-val-1)/mod+1)*mod;
		pll res(mod*G,val*G+rem);
		//printf("%lld %lld %lld %lld %lld %lld %lld %lld %lld\n",res.fi,res.se,X.fi,X.se,Y.fi,Y.se,mod,G,rem);
		v1=res/X; v2=res/Y;
	}
	if (fl) swap(v1,v2);
}
void equationeq(pll x,pll y,pll &v1,pll &v2){
	if (x==y)
		v1=v2=pll(1,0);
	else{
		if (x.fi==y.fi) GG();
		ll T=(x.se-y.se)/(y.fi-x.fi);
		if (x.fi*T+x.se!=y.fi*T+y.se||T<0) GG();
		v1=v2=pll(0,T);
	}
}
void merge(pll &v1,pll &v2,pll l1,pll l2){
	if (v1.fi==-1){
		v1=l1; v2=l2;
		return;
	}
	if (l1.fi==-1)
		return;
	pll i1,i2;
	equation(v1,l1,i1,i2);
	//printf("%lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld\n",v1.fi,v1.se,v2.fi,v2.se,l1.fi,l1.se,l2.fi,l2.se,i1.fi,i1.se,i2.fi,i2.se);
	if (i1.fi!=-1) v1=v1*i1,l1=l1*i2,v2=v2*i1,l2=l2*i2;
	equationeq(v2,l2,i1,i2);
	//printf("%lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld\n",v1.fi,v1.se,v2.fi,v2.se,l1.fi,l1.se,l2.fi,l2.se,i1.fi,i1.se,i2.fi,i2.se);
	v1=v1*i1; l1=l1*i2; v2=v2*i1; l2=l2*i2;
	//printf("%lld %lld %lld %lld\n",v1.fi,v1.se,v2.fi,v2.se);
}
map<int,pll> tmp,ans;
void input(map<int,pll> &mp){
	int x;
	mp.clear();
	scanf("%d",&x);
	for (int i=2;i*i<=x;i++)
		if (x%i==0){
			int cnt=0;
			for (;x%i==0;x/=i,++cnt);
			mp[i].se=cnt;
		}
	if (x!=1)
		mp[x].se++; 
	scanf("%d",&x);
	for (int i=2;i*i<=x;i++)
		if (x%i==0){
			int cnt=0;
			for (;x%i==0;x/=i,++cnt);
			mp[i].fi=cnt;
		}
	if (x!=1)
		mp[x].fi++; 
}
map<int,pll> merge(map<int,pll> x,map<int,pll> y){
	for (auto i:y) x[i.fi].fi+=0;
	pll lim1(-1,0),lim2(-1,0);
	for (auto i:x){
		pll v1=i.se,v2=y[i.fi],l1,l2;
		equation(v1,v2,l1,l2);
		//printf("%d %lld %lld %lld %lld %lld %lld %lld %lld\n",i.fi,v1.fi,v1.se,v2.fi,v2.se,l1.fi,l1.se,l2.fi,l2.se);
		merge(lim1,lim2,l1,l2);
	}
	//puts("233");
	if (lim1!=pll(-1,0)){
		for (auto &i:x)
			i.se=i.se*lim1;
	}
	return x;
}
const int mo=1000000007;
int power(int x,ll y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int main(){
	int n;
	scanf("%d",&n);
	For(i,1,n){
		input(tmp);
		if (i!=1) ans=merge(ans,tmp);
		else ans=tmp; 
	}
	int res=1;
	for (auto i:ans)
		res=1ll*res*power(i.fi,i.se.se)%mo;
	printf("%d\n",res);
} 
/*
2
6 30
2 3

*/