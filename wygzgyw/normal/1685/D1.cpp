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
int T,n,p[maxn];
int fa[maxn],pre[maxn],q[maxn],_p[maxn];
int find(int x) {
	if (fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y) { fa[find(x)]=find(y); }
int main() {
	//freopen("1.txt","r",stdin);
	read(T); while (T--) {
		read(n);
		for (int i=1;i<=n;i++) read(p[i]),fa[i]=i,_p[i]=p[i];
		for (int i=1;i<=n;i++) merge(i,p[i]),pre[p[i]]=i;
		for (int i=1;i<n;i++) if (find(i)!=find(i+1)) {
			int x=pre[i],y=pre[i+1];
			swap(p[x],p[y]);
			pre[p[x]]=x,pre[p[y]]=y;
			merge(i,i+1);
			//printf("i=%d %d %d\n",i,x,y);
		}
		q[n]=n;
		for (int i=n-1;i>=1;i--) q[i]=p[q[i+1]];
		//for (int i=1;i<=n;i++) printf("%d,%d ",p[i],_p[i]); puts("");
		for (int i=1;i<=n;i++) printf("%d ",q[i]); puts("");
		int ans=0;
		for (int i=1;i<n;i++) ans+=abs(q[i]-_p[q[i+1]]);
		ans+=abs(q[n]-_p[q[1]]);
		//printf("ans=%d\n",ans);
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