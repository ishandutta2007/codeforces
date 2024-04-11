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
int n;
int f[255][255];
int p[255],q[255];
int mk[255],cnt,jc[255];
bool vis[255];
int cir;
int to[255],in[255];
int c[5];
int main() {
	read(n);
	for (int i=1;i<=n;i++) read(p[i]);
	for (int i=1;i<=n;i++) read(q[i]);
	for (int i=1;i<=n;i++) {
		if (!p[i]&&!q[i]) cnt++;
		else if (p[i]&&q[i]) to[p[i]]=q[i],in[q[i]]=1;
		else if (!p[i]) mk[q[i]]|=2;
		else mk[p[i]]|=1;
	}
	jc[0]=1; for (int i=1;i<=n;i++) jc[i]=(ll)jc[i-1]*i%mod;
	for (int i=1;i<=n;i++) if (!vis[i]&&!in[i]) {
		int x=i,y; while (x) vis[x]=1,y=x,x=to[x];
		c[mk[i]|mk[y]]++;
	}
	for (int i=1;i<=n;i++) if (!vis[i]) {
		cir++; int x=i; while (!vis[x]) vis[x]=1,x=to[x];
	}
	f[0][0]=1;
	int now=0;
	for (int i=1;i<=c[0]+c[1];i++) {
		for (int j=0;j<=n;j++) f[now^1][j]=((ll)f[now][j]*(i-1)+(j?f[now][j-1]:0))%mod;
		now^=1;
	}
	for (int i=1;i<=c[2];i++) {
		for (int j=0;j<=n;j++) f[now^1][j]=((ll)f[now][j]*(c[0]+i-1)+(j?f[now][j-1]:0))%mod;
		now^=1;
	}
	for (int i=1;i<=c[3];i++) {
		for (int j=0;j<=n;j++) f[now^1][j]=(ll)f[now][j]*max(0,c[0]-(i-1))%mod;
		now^=1;
	}
	for (int i=0;i<n;i++) {
		int tmp=n-i-cir;
		if (tmp>=0) printf("%lld ",(ll)jc[cnt]*f[now][tmp]%mod); else printf("0 ");
	}
	puts("");
	return 0;
}