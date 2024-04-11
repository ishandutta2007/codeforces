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
typedef long long ll;
const int maxn=10010;
int n,AA[maxn],k,a[maxn];
int And(int i,int j) {
	printf("and %d %d\n",i,j); fflush(stdout);
	int x; scanf("%d",&x); return x;
	//return AA[i]&AA[j];
}
int Or(int i,int j) {
	printf("or %d %d\n",i,j); fflush(stdout);
	int x; scanf("%d",&x); return x;
	//return AA[i]|AA[j];
}
int Sum(int i,int j) { return And(i,j)+Or(i,j); }
int main() {
	//freopen("1.txt","r",stdin);
	scanf("%d %d",&n,&k);
	//for (int i=1;i<=n;i++) scanf("%d",&AA[i]);
	ll xy=Sum(1,2),yz=Sum(2,3),xz=Sum(1,3),s=(xy+yz+xz)/2;
	a[1]=s-yz,a[2]=s-xz,a[3]=s-xy;
	for (int i=4;i<=n;i++) a[i]=Sum(i,1)-a[1];
	sort(a+1,a+n+1);
	printf("finish %d\n",a[k]); fflush(stdout);
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