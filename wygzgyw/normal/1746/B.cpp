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
const int maxn=(1e6)+10;
int T,n,a[maxn];
int suf[maxn][2],pre[maxn][2];
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n);
		int ans=0;
		for (int i=1;i<=n;i++) read(a[i]),ans+=(a[i]==0);
		suf[n+1][0]=suf[n+1][1]=0;
		for (int i=n;i>=1;i--) {
			suf[i][0]=suf[i+1][0],suf[i][1]=suf[i+1][1];
			suf[i][a[i]]++;
		}
		for (int i=1;i<=n;i++) pre[i][0]=pre[i-1][0],pre[i][1]=pre[i-1][1],pre[i][a[i]]++;
		for (int i=1;i<=n;i++) if (a[i]) {
			int tmp=pre[i-1][0],v=pre[i-1][1];
			int c1=suf[i+1][1],c0=suf[i+1][0];
			int l=0,r=min(c1,c1-c0+v);
			if (l<=r) ans=max(ans,r+c0+tmp+1);
			l=r+1,r=c1;
			if (l<=r) ans=max(ans,c1+v+tmp+1);
//			for (int j=0;j<=c1;j++) ans=max(ans,tmp+1+j+min(c0,c1-j+v));
		}
		printf("%d\n",n-ans);
	}
	return 0;
}