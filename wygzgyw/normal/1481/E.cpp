#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(5e5)+10;
int n,a[maxn],dp[maxn],l[maxn],r[maxn],cnt[maxn];
int tmp;
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) {
		read(a[i]);
		if (!l[a[i]]) l[a[i]]=i;
		r[a[i]]=i;
	}
	for (int i=n;i>=1;i--) {
		cnt[a[i]]++;
		if (i==l[a[i]]) tmp=dp[r[a[i]]+1]; else tmp=0;
		dp[i]=max(dp[i+1],tmp+cnt[a[i]]);
	}
	printf("%d\n",n-dp[1]);
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