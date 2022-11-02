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
typedef unsigned long long ull;
const int maxn=(1e6)+10;
int n;
ull Rand[maxn],pre[maxn];
bool vis[maxn];
int tot,prime[maxn];
ull GET() {
	ull res=0;
	for (int i=0;i<64;i++) if (rand()&1) res|=(ull)1<<i;
	return res;
}
int mx;
map<ull,int> M;
void solve(int n) {
	ull all=0;
	for (int i=1;i<=n;i++) all^=Rand[i];
	for (int i=1;i<=n;i++) M[Rand[i]^all]=i;
	for (int i=1;i<=n;i++) if (M[Rand[i]]) {
		int j=M[Rand[i]];
		printf("%d\n",n-2);
		for (int k=1;k<=n;k++) if (i!=k&&j!=k) printf("%d ",k); puts("");
		exit(0);
	}
}
int main() {
	for (int i=2;i<maxn;i++) {
		if (!vis[i]) {
			prime[++tot]=i,Rand[i]=GET();
		}
		for (int j=1;j<=tot;j++) {
			if (prime[j]*i>=maxn) break;
			vis[i*prime[j]]=1;
			Rand[i*prime[j]]=(Rand[i]^Rand[prime[j]]);
			if (i%prime[j]==0) break;
		}
	}
	for (int i=2;i<maxn;i++) Rand[i]^=Rand[i-1];
	read(n);
	ull all=0;
	for (int i=1;i<=n;i++) all^=Rand[i];
	if (!all) { printf("%d\n",n); for (int i=1;i<=n;i++) printf("%d ",i); puts(""); return 0; }
	for (int i=1;i<=n;i++) if (Rand[i]==all) {
		printf("%d\n",n-1);
		for (int j=1;j<=n;j++) if (i!=j) printf("%d ",j); puts(""); return 0;
	}
	solve(n);
	solve(n-1);
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