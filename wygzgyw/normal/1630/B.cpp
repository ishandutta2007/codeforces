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
const int maxn=(2e5)+10;
int T;
int n,k,cnt[maxn],sum[maxn];
int x,y,mn,a[maxn];
int d[maxn],tot;
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n),read(k);
		for (int i=1;i<=n;i++) cnt[i]=0;
		for (int i=1;i<=n;i++) read(a[i]),cnt[a[i]]++;
		mn=1e9;
		int now=-n;
		for (int i=1,j=0;i<=n;i++) {
			while (now<k&&j<n) {
				j++;
				now+=cnt[j]*2;
			}
			if (now>=k&&j-i<mn) mn=j-i,x=i,y=j;//,printf("? %d %d\n",i,j);
			now-=cnt[i]*2;
		}
		printf("%d %d\n",x,y);
		for (int i=1;i<=n;i++) sum[i]=sum[i-1]+(x<=a[i]&&a[i]<=y?1:-1);
		now=tot=0;
		for (int i=1;i<=n;i++) {
			if (sum[i]==now+1&&sum[i]<sum[n]) now++,d[++tot]=i;
		}
		assert(now+1==sum[n]);
		d[++tot]=n;
		//printf(": ");
		//for (int i=1;i<=tot;i++) printf("%d ",d[i]); puts("");
		d[tot-k]=0;
		for (int i=tot-k+1;i<=tot;i++) printf("%d %d\n",d[i-1]+1,d[i]);
		
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