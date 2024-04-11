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
const int maxn=(3e5)+10;
char s[maxn];
int n,op,dp[2][64];
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
int main() {
	scanf("%s",s+1);
	n=strlen(s+1);
	dp[0][63]=1; op=0;
	for (int i=1;i<=n;i++) {
		memset(dp[op^1],0,sizeof(dp[op^1]));
		for (int t=0;t<64;t++) if (dp[op][t]) {
			for (int a=0;a<2;a++) for (int b=0;b<2;b++) for (int c=0;c<2;c++) {
				int x=(a^b),y=(b^c),z=(c^a);
				if (s[i]=='0') {
					if ((a&&t>>0&1)||(b&&t>>1&1)||(c&&t>>2&1)) continue;
				}
				int t2=0;
				if (t>>0&1) t2|=(s[i]-'0'==a)<<0;
				if (t>>1&1) t2|=(s[i]-'0'==b)<<1;
				if (t>>2&1) t2|=(s[i]-'0'==c)<<2;
				if (t>>3&1) t2|=(x+y==z)<<3;
				if (t>>4&1) t2|=(y+z==x)<<4;
				if (t>>5&1) t2|=(z+x==y)<<5;
				update(dp[op^1][t2],dp[op][t]);
			}
		} op^=1;
	}
	int ans=0;
	for (int t=0;t<8;t++) update(ans,dp[op][t]);
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