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
const int mod=(1e9)+7;
const int maxn=(1e6)+10;
int n,a[maxn],jc[maxn];
vector<int> fac[maxn];
int v[maxn],c1[maxn],c2[maxn];
int X[maxn],Y[maxn];
void insert(int x,int y) {
	c2[v[x]]--;
	if ((int)fac[x].size()!=(int)fac[y].size()) { puts("0"); exit(0); }
	for (int i=0;i<fac[x].size();i++) {
		int a=fac[x][i],b=fac[y][i];
		if ((x==1?1:n/a)!=(y==1?1:n/b)) { puts("0"); exit(0); }
		if ((X[a]&&X[a]!=b)||(Y[b]&&Y[b]!=a)) { puts("0"); exit(0); }
		X[a]=b,Y[b]=a;
	}
}
int main() {
	read(n); for (int i=1;i<=n;i++) read(a[i]);
	jc[0]=1; for (int i=1;i<=n;i++) jc[i]=(ll)jc[i-1]*i%mod,v[i]=1;
	fac[1].push_back(1); c1[1]=1;
	for (int i=2;i<=n;i++) if ((int)fac[i].size()==0) {
		c1[n/i]++;
		for (int j=i;j<=n;j+=i) fac[j].push_back(i),v[j]*=i;
	}
	for (int i=1;i<=n;i++) {
		c2[v[i]]++;
		if (a[i]) insert(i,a[i]);
	}
	for (int i=1;i<=n;i++) if (X[i]) c1[i==1?1:n/i]--;
	int ans=1;
	for (int i=1;i<=n;i++) ans=(ll)ans*jc[c1[i]]%mod*jc[c2[i]]%mod;//,printf("%d %d\n",c1[i],c2[i]);
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