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
const int INF=0x7f7f7f7f;
const int maxn=150010;
int T,n,a[maxn],ans;
int fL[2][maxn],fR[2][maxn];
namespace BIT1 {
	int tr[maxn];
	void init() { for (int i=1;i<=n;i++) tr[i]=INF; }
	void add(int x,int delta) {
		for (;x;x-=x&(-x)) tr[x]=min(tr[x],delta);
	}
	int query(int x) {
		int res=INF; for (;x<=n;x+=x&(-x)) res=min(res,tr[x]); return res;
	}
};
namespace BIT2 {
	int tr[maxn];
	void init() { for (int i=1;i<=n;i++) tr[i]=-INF; }
	void add(int x,int delta) {
		for (;x<=n;x+=x&(-x)) tr[x]=max(tr[x],delta);
	}
	int query(int x) {
		int res=-INF; for (;x;x-=x&(-x)) res=max(res,tr[x]); return res;
	}
};
int main() {
	read(T); while (T--) {
		read(n);
		for (int i=1;i<=n;i++) read(a[i]);
		reverse(a+1,a+n+1); ans=1;
		for (int op=0;op<=1;op++) {
			fL[1][1]=fR[1][1]=a[1];
			for (int i=2;i<=n;i++) {
				if (!op) fL[1][i]=INF,fR[1][i]=-INF;
				else fL[1][i]=fR[1][i]=a[i];
			}
			for (int k=2,now=op+2;k<=n;k++,now++) {
				BIT1::init(),BIT2::init(); bool flag=0;
				for (int i=1;i<=n;i++) {
					if (i-now+1>=1&&fR[k&1^1][i-now+1]!=-INF) BIT1::add(fR[k&1^1][i-now+1],a[i-now+1]);
					if (i-now+1>=1&&fL[k&1^1][i-now+1]!=INF) BIT2::add(fL[k&1^1][i-now+1],a[i-now+1]);
					fL[k&1][i]=BIT1::query(a[i]);
					fR[k&1][i]=BIT2::query(a[i]);
					if (fL[k&1][i]!=INF||fR[k&1][i]!=-INF) flag=1;
					BIT1::add(a[i],fL[k&1^1][i]);
					BIT2::add(a[i],fR[k&1^1][i]);
				}
				if (flag) ans=max(ans,k); else break;
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