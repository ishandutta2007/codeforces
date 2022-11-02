#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(1e5)+10;
int n,ans[maxn],d[4],e[4];
int main() {
	//freopen("1.txt","r",stdin);
	for (int i=0;i<4;i++) read(e[i]),n+=e[i];
	for (int X=0,x;X<4;X++) {
		for (int i=0;i<4;i++) d[i]=e[i];
		bool flag=1; x=X;
		for (int i=1;i<=n;i++) {
			if (x>=4) { flag=0; break; }
			ans[i]=x; d[x]--;
			if (d[x]<0) { flag=0; break; }
			if (i==n) break;
			if (x>0&&d[x-1]) x--;
			else x++;
		}
		if (flag) {
			printf("YES\n");
			for (int i=1;i<=n;i++) printf("%d ",ans[i]);
			printf("\n");
			return 0;
		}
	}
	printf("NO\n");
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