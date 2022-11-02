#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(1e6)+10;
const ll INF=(1e18);
int n,prime[maxn],tot;
bool vis[maxn];
ll s[maxn],ans;
void solve(ll tmp) {
	ll res=0;
	for (int i=1;i<=n;i++)
		res+=min(s[i]%tmp,tmp-s[i]%tmp);
	ans=min(ans,res);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) read(s[i]);
	for (int i=1;i<=n;i++) s[i]+=s[i-1];
	for (int i=2,tmp;i<maxn;i++) {
		if (!vis[i]) prime[++tot]=i;
		for (int j=1;j<=tot;j++) {
			tmp=prime[j]*i;
			if (tmp>=maxn) break;
			vis[tmp]=1;
			if (i%prime[j]==0) break;
		}
	}
	ans=INF;
	ll tmp=s[n];
	for (int i=1;i<=tot;i++)
		if (tmp%prime[i]==0) {
			solve(prime[i]);
			while (tmp%prime[i]==0) tmp/=prime[i];
		}
	if (tmp>1) solve(tmp);
	if (ans==INF) ans=-1;
	printf("%lld\n",ans);
	return 0;
}
/*
  REMEMBER:
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Array size? Integer overflow? Time complexity? Memory usage? Precision error?
*/