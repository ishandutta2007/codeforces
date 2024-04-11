#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(1e5)+10;
int n;
ll d[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) read(d[i]);
	for (int i=31;i>=0;i--) {
		int cnt=0,pos=0;
		for (int j=1;j<=n;j++)
			if (d[j]&(1LL<<i)) cnt++,pos=j;
		if (cnt==1) {
			printf("%d ",d[pos]);
			for (int j=1;j<=n;j++)
				if (j!=pos) printf("%d ",d[j]);
			printf("\n");
			return 0;
		}
	}
	for (int i=1;i<=n;i++) printf("%d ",d[i]); printf("\n");
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Interger overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/