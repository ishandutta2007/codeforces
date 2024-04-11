#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
int T,n,q;
ll tmp;
int main() {
	scanf("%d",&n);
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=n;j++) {
				if (i&1) printf("0 ");
				else printf("%lld ",1LL<<(i+j));
			}
			puts("");
		}
		fflush(stdout);
		scanf("%d",&q);
		while (q--) {
			scanf("%lld",&tmp);
			printf("1 1\n");
			int x=1,y=1;
			for (int i=3;i<=n+n;i++) {
				if ((x&1)==(tmp>>i&1)) x++; else y++;
				printf("%d %d\n",x,y);
			}
			fflush(stdout);
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