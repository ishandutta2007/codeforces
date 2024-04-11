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
ll x[maxn],y[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	if (n&1) { printf("NO\n"); return 0; }
	for (int i=1;i<=n;i++) read(x[i]),read(y[i]);
	x[n+1]=x[1],y[n+1]=y[1];
	for (int i=1;i<=n/2;i++) {
		if (x[i]-x[i+1]==x[i+n/2+1]-x[i+n/2]&&y[i]-y[i+1]==y[i+n/2+1]-y[i+n/2]);
		else { printf("NO\n"); return 0; }
	}
	printf("YES\n");
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