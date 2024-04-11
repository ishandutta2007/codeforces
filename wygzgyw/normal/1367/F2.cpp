#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; int f=1; char ch=getchar();
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(2e5)+10;
int T,n,a[maxn],b[maxn],f[maxn],ans,lst[maxn];
int dp[maxn],L[maxn],R[maxn],cnt[maxn];
int main() {
//	freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n;i++) dp[i]=cnt[i]=L[i]=R[i]=lst[i]=f[i]=0;
		for (int i=1;i<=n;i++) read(a[i]),b[i]=a[i];
		sort(b+1,b+n+1);
		int N=unique(b+1,b+n+1)-b-1;
		for (int i=1;i<=n;i++) a[i]=lower_bound(b+1,b+N+1,a[i])-b;
		for (int i=1;i<=n;i++) R[a[i]]=i;
		for (int i=n;i>=1;i--) L[a[i]]=i;
		for (int i=1;i<=n;i++) {
			dp[i]=max(dp[lst[a[i]]],cnt[a[i]-1])+1;
			if (i>R[a[i]-1]) dp[i]=max(dp[i],f[a[i]-1]+1);
			lst[a[i]]=i;
			cnt[a[i]]++;
			if (i==R[a[i]]) f[a[i]]=dp[L[a[i]]]+cnt[a[i]]-1;
		}
		ans=0;
		for (int i=1;i<=n;i++) ans=max(ans,dp[i]);
		printf("%d\n",n-ans);
	}
	return 0;
}