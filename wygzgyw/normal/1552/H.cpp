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
int f[10];
int query(int d) {
	vector<pair<int,int> > A;
	for (int i=d;i<=200;i+=d) for (int j=1;j<=200;j++) A.push_back(MP(i,j));
	printf("? %d\n",(int)A.size());
	for (pair<int,int> B : A) printf("%d %d ",B.first,B.second); puts("");
	fflush(stdout);
	int x; scanf("%d",&x); return x;
}
int main() {
	f[0]=query(1);
	int l=1,r=7,mid,res=0;
	while (l<=r) {
		mid=(l+r)>>1;
		f[mid]=query(1<<mid);
		if (f[mid]*(1<<mid)==f[0]) l=mid+1,res=mid;
		else r=mid-1;
	}
	mid=res;
	int m=abs(2*f[mid+1]-(f[0]>>mid))-1;
	int n=f[0]/(m+1)-1;
	printf("! %d\n",(n+m)*2);
	fflush(stdout);
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