// wygzgyw
#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
template <typename T> void write(T t) {
	if (t<0) { putchar('-'); write(-t); return; }
	if (t>9) write(t/10);
	putchar('0'+t%10);
}
template <typename T> void writeln(T t) { write(t); puts(""); }
#define MP make_pair
typedef long long ll;
const int maxn=(5e6)+10;
int T,n,m;
int dp[maxn],buc[maxn];
bool mk[maxn];
int main() {
	read(T);
	while (T--) {
		read(n),read(m);
		for (int i=1;i<=m;i++) mk[i]=buc[i]=0;
		int mn=m+1;
		for (int i=1;i<=n;i++) {
			int x; read(x); mk[x]=1; mn=min(mn,x);
		}
		for (int i=1;i<=m;i++) dp[i]=i;
		int mx=m,ans=m+1;
		for (int i=1;i<=m;i++) if (mk[i]) buc[dp[i]]++;
		for (int mid=m;mid>=1;mid--) {
			if ((ll)mid*mid<=m) {
				for (int i=mid*mid;i<=m;i+=mid) {
					if (mk[i]) buc[dp[i]]--;
					dp[i]=min(dp[i],dp[i/mid]);
					if (mk[i]) buc[dp[i]]++;
				}
			}
			while (!buc[mx]) mx--;
			if (mid<=mn) ans=min(ans,mx-mid);
		}
		printf("%d\n",ans);
	}
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