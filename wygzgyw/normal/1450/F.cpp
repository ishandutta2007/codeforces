#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(1e5)+10;
int T,n;
int a[maxn],cnt[maxn],ans;
int mx,ed[maxn],cut;

int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n;i++) cnt[i]=ed[i]=0;
		for (int i=1;i<=n;i++) read(a[i]);
		cut=0;
		for (int i=1;i<=n;i++) {
			cnt[a[i]]++;
			if (i>1&&a[i]==a[i-1]) {
				cut++;
				ed[a[i]]++; ed[a[i-1]]++;
			}
		}
		mx=0;
		for (int i=1;i<=n;i++) mx=max(mx,cnt[i]);
		if (mx>(n+1)/2) { puts("-1"); continue; }
		ed[a[1]]++; ed[a[n]]++;
		mx=0;
		for (int i=1;i<=n;i++) mx=max(mx,ed[i]);
		printf("%d\n",cut+max(0,mx-cut-2));
	}
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