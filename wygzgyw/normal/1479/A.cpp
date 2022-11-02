#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(1e5)+10;
int n,a[maxn],l,r,mid;
int get(int x) {
	if (a[x]) return a[x];
	printf("? %d\n",x);
	fflush(stdout);
	scanf("%d",&a[x]);
	return a[x];
}
int main() {
	scanf("%d",&n);
	l=1,r=n;
	while (l<r) {
		mid=(l+r)>>1;
		if (get(mid)<get(mid+1)) r=mid;
		else l=mid+1;
	}
	printf("! %d\n",l);
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