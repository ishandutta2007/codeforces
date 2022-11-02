#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(1e6)+10;
int n,s,d[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(s);
	if (s<2*n) printf("No\n");
	else {
		printf("Yes\n");
		for (int i=1;i<n;i++) d[i]=2;
		d[n]=s-(n-1)*2;
		for (int i=1;i<=n;i++) printf("%d ",d[i]); printf("\n");
		printf("1\n");
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