#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=5010;
int n,a[maxn],cnt[maxn],now;
int ans[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) read(a[i]);
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) cnt[j]=0;
		now=0;
		for (int j=i;j<=n;j++) {
			cnt[a[j]]++;
			if (!now) now=a[j];
			else if (cnt[a[j]]>cnt[now]||(cnt[a[j]]==cnt[now]&&a[j]<now)) now=a[j];
			ans[now]++;
		}
	}
	for (int i=1;i<=n;i++) printf("%d ",ans[i]); puts("");
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