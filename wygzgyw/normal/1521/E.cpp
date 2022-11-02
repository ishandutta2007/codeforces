#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(1e5)+10;
int T,m,n,id[maxn],a[maxn];
bool cmp(int x,int y) { return a[x]>a[y]; }
int sz,ans[1010][1010];
int now;
int find() {
	//printf("%d\n",now);
	while (!a[id[now]]&&now<=n) now++;
	a[id[now]]--;
	return id[now];
}
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(m),read(n); int mx=0;
		for (int i=1;i<=n;i++) {
			read(a[i]),id[i]=i;
			mx=max(mx,a[i]);
		}
		sort(id+1,id+n+1,cmp); id[n+1]=0;
		for (int i=1;;i++)
			if (i*((i+1)/2)>=mx&&(i/2)*(i/2)*3+(i&1)*(i*2-1)>=m) { sz=i; break; }
		//printf("%d\n",sz);
		now=1;
		
		for (int i=1;i<=sz;i+=2)
		for (int j=2;j<=sz;j+=2) ans[i][j]=find();
		
		for (int i=1;i<=sz;i+=2)
		for (int j=1;j<=sz;j+=2) ans[i][j]=find();
		
		for (int i=2;i<=sz;i+=2)
		for (int j=1;j<=sz;j+=2) ans[i][j]=find();
		printf("%d\n",sz);
		for (int i=1;i<=sz;i++) {
			for (int j=1;j<=sz;j++) printf("%d ",ans[i][j]);
			puts("");
		}
		
	}
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