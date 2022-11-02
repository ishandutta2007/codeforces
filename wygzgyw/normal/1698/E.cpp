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
const int mod=998244353;
const int maxn=(2e5)+10;
int T,n,a[maxn],b[maxn],s,flag,p[maxn];
int ans,pos[maxn],used[maxn];
int main() {
	read(T);
	while (T--) {
		read(n),read(s);
		flag=1;
		for (int i=1;i<=n;i++) read(a[i]),pos[a[i]]=i;
		for (int i=1;i<=n;i++) read(b[i]),used[i]=0;
		for (int i=1;i<=n;i++) if (b[i]!=-1) used[b[i]]=1,flag&=(a[i]-b[i]<=s);
		if (!flag) { puts("0"); continue; }
		p[n+1]=0;
		for (int i=n;i>=1;i--) p[i]=(p[i+1]+!used[i]);
		ans=1;
		int now=0;
		for (int i=n;i>=1;i--) {
			int x=pos[i];
			if (b[x]!=-1) continue;
			ans=(ll)ans*(p[max(1,i-s)]-now)%mod;
			now++;
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