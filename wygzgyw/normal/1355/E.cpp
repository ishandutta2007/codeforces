#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(1e5)+10;
const int INF=1e9;
int n,a,r,m;
ll sum,tmp,ans,s1,s2,k,t1,t2,d[maxn],s[maxn];
void solve(ll h) {
	int x=lower_bound(d+1,d+n+2,h)-d;
		
	s1=(ll)h*(x-1)-s[x-1];
	s2=s[n]-s[x-1]-(ll)h*(n-x+1);
	
	if (a+r>=m) {
		k=min(s1,s2);
		tmp=k*m+(s1-k)*a+(s2-k)*r;
	} else tmp=a*s1+r*s2;
	ans=min(ans,tmp);
}
int main() {
	//freopen("1.txt","r",stdin);
	ans=2e18;
	read(n);
	read(a); read(r); read(m);
	for (int i=1;i<=n;i++) read(d[i]);
	sort(d+1,d+n+1);
	for (int i=1;i<=n;i++) sum+=d[i],s[i]=sum;
	if (a+r<=m) {
		for (int i=1;i<=n;i++) {
			s1=d[i]*i-s[i];
			s2=s[n]-s[i]-d[i]*(n-i);
			ans=min(ans,a*s1+r*s2);
		}
		printf("%lld\n",ans);
		return 0;
	}
	d[n+1]=INF;
	int l=0,r=INF,res,mid,x;
	while (l<=r) {
		mid=(l+r)/2;
		x=lower_bound(d+1,d+n+2,mid)-d;
		
		s1=(ll)mid*(x-1)-s[x-1];
		s2=s[n]-s[x-1]-(ll)mid*(n-x+1);
		
		if (s1<=s2) res=mid+1,l=mid+1;
		else r=mid-1;
		
	}
	for (ll i=max(0,res-10000);i<=min(INF,res+10000);i++) solve(i);
	for (int i=1;i<=n;i++) solve(d[i]);
	solve(0); solve(INF); 
	printf("%lld\n",ans);
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Interger overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/