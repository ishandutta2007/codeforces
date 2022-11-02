#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(1e6)+10;
const int mod=(1e9)+7;
int n,k,ans,dp[maxn],a[maxn],s[maxn];
ll len;
pair<int,int> p[maxn];
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
int main() {
//	freopen("1.txt","r",stdin);
	read(n),read(len),read(k);
	for (int i=0;i<n;i++) read(a[i]);
	for (int i=0;i<n*k;i++) p[i]=make_pair(a[i%n],i);
	sort(p,p+n*k);
	for (int i=0;i<n*k;i++) {
		if (p[i].second<n) dp[p[i].second]=1;
		else dp[p[i].second]=s[p[i].second/n-1];
		update(s[p[i].second/n],dp[p[i].second]);
		if (p[i].second<len) update(ans,((len-p[i].second-1)/n+1)%mod*dp[p[i].second]%mod);
	}
	printf("%d\n",ans);
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