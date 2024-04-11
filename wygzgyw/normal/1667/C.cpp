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
int n,m;
vector<pair<int,int> > A;
void add1(int x) {
	for (int i=x,j=1;i>=1;i--,j++) A.push_back(MP(i,j));
}
void add2(int x) {
	for (int i=n-x+1,j=n;i<=n;i++,j--) A.push_back(MP(i,j));
}
int main() {
	read(n);
	m=n/3;
	if (n%3==2) {
		add1(m+1),add2(m);
	} else if (n%3==0) {
		A.push_back(MP(n,n));
		n--;
		add1(m),add2(m-1);
	} else {
		add1(m+1),add2(m);
	}
	printf("%d\n",(int)A.size());
	for (auto [x,y] : A) printf("%d %d\n",x,y);
	return 0;
	if (n<=100) {
		for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) {
			int flag=0;
			for (auto [x,y] : A) if (x==i||y==j||x-y==i-j) { flag=1; break; }
			if (!flag) assert(0);
		}
	}
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