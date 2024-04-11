#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=60;
int T,n;
ll a[maxn],b[maxn],sum,tmp;

int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n); sum=0;
		for (int i=1;i<=n;i++) read(a[i]),sum+=a[i];
		tmp=0;
		for (int i=2;i<=n;i+=2) tmp+=a[i]-1;
		if (tmp*2<=sum) {
			for (int i=1;i<=n;i++)
				if (i&1) printf("%d ",a[i]);
				else printf("1 ");
			printf("\n");
		} else {
			for (int i=1;i<=n;i++)
				if (i&1^1) printf("%d ",a[i]);
				else printf("1 ");
			printf("\n");
		}
	}
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