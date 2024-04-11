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
const int INF=0x7f7f7f7f;
const int maxn=(1e5)+10;
int T,n;
char s[maxn],t[maxn];
int dp[maxn],pre[maxn],mx;
int main() {
	read(T);
	while (T--) {
		read(n);
		scanf("%s",s+1);
		scanf("%s",t+1);
		int st=-1;
		pre[0]=0; mx=-INF;
		for (int i=1;i<=n;i++) {
			if (s[i]==t[i]) {
				if (st==-1||s[i-1]!=s[i]) st=i,mx=-INF;
				mx=max(mx,dp[i-1]);
				dp[i]=mx+(1-(s[i]-'0'));
				if (st-2>=0) dp[i]=max(dp[i],pre[st-2]+2);
			} else dp[i]=pre[i-1]+2;
			pre[i]=max(pre[i-1],dp[i]);
		}
		printf("%d\n",dp[n]);
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