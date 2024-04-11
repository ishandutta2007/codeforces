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
int T,n,ans[65536],bk[65536],tim,vis[65536];
vector<int> g[65536];
void insert(int x,int y) {
	//printf("xyr %d %d\n",x,y);
	ans[x]=y;
	bk[y]=x;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n);
		int x,y;
		for (int i=0;i<(1<<n);i++) g[i].clear(),ans[i]=0,bk[i]=-1;
		for (int i=1;i<=n*(1<<n-1);i++) {
			read(x),read(y);
			g[x].push_back(y),g[y].push_back(x);
		}
		insert(0,0); int cnt=0;
		for (int i : g[0]) insert(1<<cnt,i),cnt++;
		for (int i=1;i<(1<<n);i++) if (!ans[i]) {
			int x=-1,y=-1;
			for (int j=1;j<(1<<n);j<<=1) if ((i^j)<i) {
				if (x==-1) x=ans[i^j]; else y=ans[i^j];
			}
			assert(x!=-1&&y!=-1);
			tim++;
			for (int z : g[x]) vis[z]=tim;
			for (int z : g[y]) if (vis[z]==tim) {
				if (bk[z]!=-1) continue;
				insert(i,z); break;
			}
		}
		for (int i=0;i<(1<<n);i++) printf("%d ",ans[i]); puts("");
		if (n!=1&&n!=2&&n!=4&&n!=8&&n!=16) { puts("-1"); continue; }
		if (n==1) { puts("0 0"); continue; }
		for (int i=0;i<(1<<n);i++) {
			int c=0; for (int j=0;j<n;j++) if (bk[i]>>j&1) c^=j;
			printf("%d ",c);			
		}
		puts("");
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