#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,x,m,ans;
ll p[100],q[1010];
int c1,c2;
void d(ll a) {
	for (int i=2;(ll)i*i<=a;i++)
		if (a%i==0) {
			q[++c2]=i;
			while (a%i==0) a/=i;
		}
	if (a>1) q[++c2]=a;
}
inline ll cheng(ll x,ll y,ll mod) {
	return ((x*y-(ll)( ((long double)x*y+0.5) /mod)*mod)%mod+mod)%mod;
}
inline ll phi(ll a) {
	ll res=a;
	for (int i=1;i<=c1;i++)
		if (a%p[i]==0) res=res/p[i]*(p[i]-1);
	return res;
}
ll ksm(ll a,ll b,ll mod) {
	ll res=1;
	for (a%=mod;b;b>>=1,a=cheng(a,a,mod))
		if (b&1) res=cheng(res,a,mod);
	return res;
}
ll solve(ll a) {
	ll mod=n/a,t=phi(mod),tmp=t,xd=x%mod;
	for (int i=1;i<=c2;i++) {
		while (tmp%q[i]==0&&ksm(xd,tmp/q[i],mod)==1) tmp/=q[i];
	}
	return t/tmp;
}
int main() {
	//freopen("1.txt","r",stdin);
	scanf("%lld %lld",&n,&x);
	m=n;
	for (int i=2;(ll)i*i<=m;i++)
		if (m%i==0) {
			p[++c1]=i;
			while (m%i==0) m/=i;
		}
	if (m>1) p[++c1]=m;
	for (int i=1;i<=c1;i++) {
		q[++c2]=p[i];
		d(p[i]-1);
	}
	sort(q+1,q+(c2+1));
	c2=unique(q+1,q+(c2+1))-q-1;
	for (register int i=1;(ll)i*i<=n;++i)
		if (n%i==0) {
			ans+=solve(i);
			if (n/i!=i) ans+=solve(n/i);
		}
	printf("%lld\n",ans);
	return 0;
}