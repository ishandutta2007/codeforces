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
int T,n,m;
char t[410][410];
int v[410],h[410];
int sum[410][410],s[410];
int c0(int x,int l,int r) {
	return (r-l+1)-(sum[x][r]-sum[x][l-1]);
}
int c1(int x,int l,int r) {
	return sum[x][r]-sum[x][l-1];
}
int main() {
//	freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n),read(m);
		for (int i=1;i<=n;i++) scanf("%s",t[i]+1);
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=m;j++) {
				sum[i][j]=sum[i][j-1]+t[i][j]-'0';
			}
		}
		int ans=1e9;
		for (int l=2;l<=m;l++) for (int r=l+1;r<m;r++) {
			for (int i=2;i<n;i++) {
				v[i]=c0(i-1,l,r);
				h[i]=c0(i+1,l,r);
			//	printf("%d %d\n",v[i],h[i]);
			}
			for (int i=1;i<=n;i++) s[i]=s[i-1]+c1(i,l,r)+(t[i][l-1]=='0')+(t[i][r+1]=='0');
			int mn=1e9;
			int pos=n-1;
			for (int a=n-1;a>=2;a--) {
				while (pos>=a+2) {
					mn=min(mn,h[pos]+s[pos]);
					pos--;
				}
				ans=min(ans,mn+v[a]-s[a-1]);
			}
		}
			printf("%d\n",ans);
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