#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(2e5)+10;
int n,m,a[maxn];
int ans,tmp,s[maxn];
int q,f[20][maxn];
int S(int l,int r) {
	if (r>m) r=m+1;
	if (l>r) return 0;
	return s[r]^s[l-1];
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(m); int x,y;
	for (int i=1;i<=n;i++) read(x),a[x]^=1;
	for (int i=1;i<=m+1;i++) s[i]=(s[i-1]^a[i]);
	for (int k=0;k<=19;k++) {
		for (int i=m,j;i>=1;i--) {
			j=(i+(1<<(k+1)));
			f[k][i]=(S(i+(1<<k),i+(1<<(k+1))-1)^f[k][min(j,m+1)]);
		}
	}
	read(q); int l,r;
	while (q--) {
		read(l),read(r); ans=1;
		for (int k=0;k<=19;k++) {
			tmp=f[k][l];
			x=(r-l)/(1<<(k+1));
			y=l+(1<<(k+1))*(x+1);
			tmp^=f[k][min(y,m+1)];
			tmp^=S(max(y-(1<<k),r+1),y-1);
			//if (l==2&&r==4&&k==4) printf("%d %d %d\n",y,tmp,S(4,5));
			if (tmp) { ans=0; break; }
		}
		if (!ans) putchar('A');
		else putchar('B');
	}
	puts("");
	return 0;
}
/*
  REMEMBER:
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Array size? Integer overflow? Time complexity? Memory usage? Precision error?
*/