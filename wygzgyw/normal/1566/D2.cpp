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
int T,n,m;
int d[310][310],e[310][310],ans;
pair<int,int> a[maxn],bk[maxn]; int tot;
namespace BIT {
	int tr[maxn];
	void add(int x,int y) { for (;x;x-=x&(-x)) tr[x]+=y; }
	int query(int x) { int res=0; for (;x<=n*m;x+=x&(-x)) res+=tr[x]; return res; }
}
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n),read(m);
		int tot=0; ans=0;
		for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) bk[++tot]=MP(i,j);
		for (int i=1;i<=n*m;i++) read(a[i].first),a[i].second=i;
		sort(a+1,a+n*m+1);
		for (int i=1;i<=n*m;i++) d[bk[i].first][bk[i].second]=n*m-a[i].second+1,
			e[bk[i].first][bk[i].second]=a[i].first;
		for (int i=1;i<=n;i++) {
			//for (int j=1;j<=m;j++) printf("%d ",d[i][j]); puts("");
		}
		for (int i=1;i<=n;i++) {
			int L=1,R=-1;
			for (int j=1;j<=m;j++) {
				if (j>1&&e[i][j]==e[i][j-1]) R=j;
				else {
					if (R!=-1) sort(d[i]+L,d[i]+R+1);
					L=R=j;
				}
			}
			if (R!=-1) sort(d[i]+L,d[i]+R+1);
			for (int j=1;j<=m;j++) {
				ans+=BIT::query(d[i][j]);
				BIT::add(d[i][j],1);
			}
			for (int j=1;j<=m;j++) BIT::add(d[i][j],-1);
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