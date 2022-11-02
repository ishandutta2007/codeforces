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
int n,k,d[1010][1010],mx;
int t[1010],tot;
void solve(int l,int r,int cnt) {
	if (l==r) return;
	if (r-l+1<=k) {
		for (int i=l;i<r;i++) for (int j=i+1;j<=r;j++) d[i][j]=cnt;
		return;
	}
	int sz=r-l+1;
	tot=k;
	if (sz%k==0) { for (int i=1;i<=k;i++) t[i]=sz/k; }
	else {
		for (int i=1;i<=sz%k;i++) t[i]=sz/k+1;
		for (int i=sz%k+1;i<=tot;i++) t[i]=sz/k;
	}
	vector<int> L,R;
	L.resize(tot+2),R.resize(tot+2);
	L[1]=l;
	for (int i=1;i<=tot;i++) {
		R[i]=L[i]+t[i]-1;
		if (i<tot) L[i+1]=R[i]+1;
	}
	assert(R[tot]==r);
	for (int i=1;i<=tot;i++) for (int j=i+1;j<=tot;j++)
	for (int x=L[i];x<=R[i];x++) for (int y=L[j];y<=R[j];y++) d[x][y]=cnt;
	for (int i=1;i<=tot;i++) solve(L[i],R[i],cnt+1);
}
int main() {
	read(n),read(k);
	solve(1,n,1);
	for (int i=1;i<=n;i++) for (int j=i+1;j<=n;j++) mx=max(mx,d[i][j]);
	printf("%d\n",mx);
	for (int i=1;i<=n;i++) for (int j=i+1;j<=n;j++) printf("%d ",d[i][j]); puts("");
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