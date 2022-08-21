#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
#include <assert.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
#define SZ 666666
const int MOD=1e9+7;
ll qp(ll a,ll b)
{
	ll x=1; a%=MOD;
	b%=(MOD-1);
	while(b<0) b+=MOD-1;
	while(b)
	{
		if(b&1) x=x*a%MOD;
		a=a*a%MOD; b>>=1;
	}
	return x;
}
int mu[SZ];
bool ip[SZ];
ll ps(ll k,ll n)
{
	if(k==1) return n+1;
	//k^0+k^1+...+k^n
	return (qp(k,n+1)-1)*qp(k-1,MOD-2)%MOD;
}
ll ps(ll k,ll l,ll r)
{
	return qp(k,l)*ps(k,r-l)%MOD;
}
ll pp(ll k,ll n)
{
	//S=k+2k^2+3k^3+nk^n
	//kS=k^2+2k^3+3k^4+...+nk^(n+1)
	//kS-S=nk^(n+1)-k^n-k^(n-1)-...-k^2-k
	return (n*qp(k,n+1)-ps(k,1,n))%MOD*qp(k-1,MOD-2)%MOD;
	ll ans=0;
	for(int i=1;i<=n;++i)
		ans+=i*qp(k,i),ans%=MOD;
	return ans;
}
ll su(ll l,ll r)
{
	l%=MOD; r%=MOD;
	return (l+r)*(r-l+1)/2%MOD;
}
int main()
{
	int n,k;
	cin>>n>>k;
	if(n==1)
	{
		puts("0");
		return 0;
	}
	if(k==1)
	{
		ll w=n-1;
		w=w*w%MOD;
		cout<<w<<"\n";
		return 0;
	}
	for(int i=1;i<=n;++i) mu[i]=1;
	for(int i=2;i<=n;++i) if(!ip[i])
	{
		for(int j=i;j<=n;j+=i)
		{
			ip[j]=1;
			if((j/i)%i==0) mu[j]=0;
			else mu[j]=-mu[j];
		}
	}
//	for(int i=1;i<=n;++i)
//		cout<<mu[i]<<",";
//	cout<<"\n";
	ll ans=0;
	for(int s=1;s<=n;++s)
	{
		//i+j<=n+s, i,j<n, gcd(i,j)=s
		int u=(n+s)/s,r=(n-1)/s;
		ll cd=0,ap=0;
		//-k^(i+j-n)
		for(int x=1;x<=r;++x)
		{
			ll ux=u/x,rx=r/x;
			ll K=qp(k,x*s);
			ll R=min(ux,rx+1);
			cd+=mu[x]*su(1,R-1);
			ap+=mu[x]*K*pp(K,R-1);
//			for(int p=2;p<=R;++p)
//			{
//				int rr=p-1;
//				cd+=mu[x]*rr;
//				ap+=mu[x]*rr*qp(K,p);
//				cd%=MOD; ap%=MOD;
//			}
			cd+=mu[x]*rx*(ux-R);
			ap+=mu[x]*rx*ps(K,R+1,ux); 
			cd%=MOD; ap%=MOD;
//			for(int p=R+1;p<=ux;++p)
//			{
//				int rr=rx;
//				cd+=mu[x]*rr;
//				ap+=mu[x]*rr*qp(K,p);
//				cd%=MOD; ap%=MOD;
//			}
//			for(int p=1;p<=r/x;++p)
//				for(int q=1;q<=r/x;++q) if(p+q<=ux)
//					cd+=mu[x],
//					ap+=mu[x]*qp(K,p+q);
					//ans-=mu[x]*qp(k,p*x*s+q*x*s-n);
		}
		cd%=MOD,ap%=MOD;
		ans+=qp(k,s)*cd;
		ans-=ap*qp(k,-n);
		ans%=MOD;
	}
	for(int i=1;i<n;++i)
		ans+=ps(k,i+1-n,i+n-1-n);
	ans=ans%MOD*qp(k,n*(ll)(MOD-2))%MOD;
	ans=(ans%MOD+MOD)%MOD;
	cout<<ans<<"\n";
}