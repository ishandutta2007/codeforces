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
const int maxn=(1e5)+10;
int T,n,k,mx[maxn],a[maxn];
int block=300;
void chkmax(int &x,int y) { if (x<y) x=y; }
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n),read(k);
		for (int i=1;i<=n;i++) read(a[i]);
		n=unique(a+1,a+n+1)-a-1;
		int ans=1e9;
		for (int mn=a[1]/k;mn<=block&&mn<=a[1];mn++) {
			int mx=0;
			for (int i=1;i<=n;i++) {
				int p=min(k,mn==0?k:a[i]/mn);
				mx=max(mx,a[i]/p);
			//	if (mn==16) printf("%d %d %d\n",a[i],p,a[i]/p);
			}
			ans=min(ans,mx-mn);
		}
		for (int i=1;i<=a[n];i++) mx[i]=0;
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=k&&a[i]/j>block;j++) {
				//a[i]/(j+1)...a[i]/j
				chkmax(mx[a[i]/(j+1)+1],a[i]/j);
			//	printf("[%d,%d]\n",a[i]/(j+1),a[i]/j);
			}
			chkmax(mx[1],a[i]/k);
		}
		for (int i=1;i<=a[n];i++) chkmax(mx[i],mx[i-1]);
		for (int mn=max(block+1,a[1]/k);mn<=a[1];mn++) {
			ans=min(ans,mx[mn]-mn);
		//	if (mx[mn]==mn) printf("%d\n",mn);
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