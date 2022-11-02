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
int T,n;
ll d[110],f[110],sum[110],s[110];
ll A[110],B[110]; int tot;
ll solve(ll x) {
	ll res=0;
	for (int i=tot;i>=1;i--) {
		if (s[i-1]<x) x-=f[i],res|=(1LL<<(i-1));
	}
	assert(x==0);
	return res;
}
ll preand[110],preor[110];
ll sufand[110],sufor[110];
int main() {
	read(T); tot=55;
	f[0]=f[1]=1; for (int i=2;i<=tot;i++) f[i]=f[i-1]+f[i-2];
	for (int i=0;i<=tot;i++) sum[i]=(i==0?0:sum[i-1])+f[i];
	for (int i=1;i<=tot;i++) s[i]=s[i-1]+f[i];
	//printf("%lld\n",sum[tot]-(ll)(1e11));
	while (T--) {
		read(n); ll S=0;
		for (int i=1;i<=n;i++) read(d[i]),S+=d[i];
		sort(d+1,d+n+1);
		int pos=lower_bound(sum,sum+tot+1,S)-sum;
		if (sum[pos]!=S) { puts("NO"); continue; }
		int lst=0,flag=1;
		for (int i=pos;i>=0;i--) {
			int mx=0;
			for (int j=1;j<=n;j++) if (j!=lst&&d[j]>=d[mx]) mx=j;
			if (!mx||d[mx]<f[i]) { flag=0; break; }
			lst=mx; d[mx]-=f[i];
		}
		if (flag) puts("YES"); else puts("NO");
	}
	return 0;
}