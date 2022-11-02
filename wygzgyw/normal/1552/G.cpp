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
int n,k;
void Yes() { puts("ACCEPTED"); exit(0); }
void No() { puts("REJECTED"); exit(0); }
ll msk[11][50],rem[11]; int cnt[11],bit[1<<16];
int Pop(ll x) {
	return bit[x&65535]+bit[(x>>16)&65535]+bit[(x>>32)&65535];
}
void dfs(int x,ll s) {
	if (x>k) {
		s++;
		if (s!=(s&(-s))) No();
		return;
	}
	int tmp=Pop(s&rem[x]);
	s&=(1LL<<n)-1-rem[x];
	for (int i=0;i<=cnt[x];i++) dfs(x+1,s|msk[x][i+tmp]);
}
int main() {
	for (int i=1;i<65536;i++) bit[i]=bit[i-(i&(-i))]+1;
	read(n),read(k);
	if (n==1) Yes();
	int x,y;
	ll all=0;
	for (int i=1;i<=k;i++) {
		read(x); ll s=0;
		for (int j=1;j<=x;j++) read(y),y--,s|=(1LL<<y),msk[i][j]=s;
		ll t=s-(s&all);
		while (t) cnt[i]++,t-=t&(-t);
		all|=s; rem[i]=s;
	}
	if (all!=(1LL<<n)-1) No();
	dfs(1,0);
	Yes();
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