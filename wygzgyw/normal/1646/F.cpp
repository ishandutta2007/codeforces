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
const int maxn=210;
int n;
vector<int> V[maxn];
int cnt[maxn][maxn];
int p[maxn];
int ad(int x) {
	while (x>n) x-=n; while (x<=0) x+=n; return x;
}
int ans[100*100][110],tot,rem[maxn];
void insert() {
	tot++; for (int i=1;i<=n;i++) ans[tot][i]=p[i];
}
void shift() {
	int rem=p[n];
	for (int i=n;i>=2;i--) p[i]=p[i-1];
	p[1]=rem;
}
int main() {
	read(n);
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) {
			int x; read(x);
			cnt[i][x]++;
		}
		for (int j=1;j<=n;j++) if (cnt[i][j]>1) V[i].push_back(j);
	}
	while (1) {
		int fd=0;
		for (int i=1;i<=n;i++) if ((int)V[i].size()) { fd=i; break; }
		if (!fd) break;
		int lst;
		for (int i=1;i<=n;i++) {
			if ((int)V[fd].size()) p[fd]=V[fd].back();
			else p[fd]=lst;
			lst=p[fd];
			fd++;
			if (fd>n) fd=1;
		}
		insert();
		for (int i=1;i<=n;i++) rem[i]=cnt[i][p[ad(i-1)]];
		for (int i=1;i<=n;i++) {
			cnt[i][p[i]]--,cnt[ad(i+1)][p[i]]++;
		}
		for (int i=1;i<=n;i++) {
			if ((int)V[i].size()&&cnt[i][V[i].back()]<=1) V[i].pop_back();
			if (cnt[i][p[ad(i-1)]]>1&&rem[i]<=1) V[i].push_back(p[ad(i-1)]);
		}
	}
	for (int i=1;i<n;i++) {
		for (int j=1;j<=n;j++) p[j]=ad(j+i);
		for (int j=1;j<=i;j++) insert(),shift();
	}
	printf("%d\n",tot);
	for (int i=1;i<=tot;i++) {
		for (int j=1;j<=n;j++) printf("%d ",ans[i][j]); puts("");
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