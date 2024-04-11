#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const ll INF=5e18;
const int maxn=(1e6)+10;
int n,m,p1[maxn],p2[maxn];
ll k;
int tot;
ll M,A[maxn];
ll gcd(ll x,ll y) {
	if (!x||!y) return x+y;
	return gcd(y,x%y);
}
void exgcd(ll a,ll b,ll &x,ll &y) {
	if (b==0) { x=1,y=0; return; }
	exgcd(b,a%b,x,y);
	ll tmp=x; x=y; y=tmp-(a/b)*y;
}
ll inv(ll a,ll b) {
	ll x,y; exgcd(a,b,x,y);
	x=(x%b+b)%b;
	return x;
}
ll solve(ll mid) {
	ll res=0;
	for (int i=1;i<=tot;i++) {
		if (mid%M>=A[i]) res+=mid/M+1;
		else res+=mid/M;
	}
//	printf("%lld\n",res);
	return mid+1-res;
}
int main() {
//	freopen("1.txt","r",stdin);
	read(n),read(m);
	read(k);
	ll x,y,mx=0;
	for (int i=1;i<=n;i++) read(x),mx=max(mx,x),p1[x]=i;
	for (int i=1;i<=m;i++) read(x),mx=max(mx,x),p2[x]=i;
	ll M1=n,M2=m,T=gcd(M1,M2);
	M=(M1*M2)/T;
	for (int i=1;i<=mx;i++) if (p1[i]&&p2[i]) {
		ll C1=p1[i]-1,C2=p2[i]-1;
		//printf("%lld %lld\n",C1,C2);
		if ((C2-C1)%T!=0) continue;
		tot++;
		A[tot]=(inv(M1/T,M2/T)*(C2-C1)/T)%(M2/T)*M1+C1;
		A[tot]=(A[tot]%M+M)%M;
	//	printf("%lld %lld\n",A[tot],M);
	}
//	solve(44);
//	return 0;
	ll l=0,r=INF,mid,res;
	while (l<=r) {
		mid=(l+r)>>1;
		if (solve(mid)>=k) res=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%lld\n",res+1);
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Integer overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/