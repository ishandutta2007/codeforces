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
int T,n,r,b;
bool check(int r,int x,int i) { return r>=i&&r<=x*i; }
void print(int x,char ch) { for (int i=1;i<=x;i++) printf("%c",ch); }
void solve() {
	for (int x=1;;x++) {
		for (int i=1;i<=n;i++) for (int j=max(1,i-1);j<=min(i+1,n);j++) {
			if (check(r,x,i)&&check(b,x,j)) {
				vector<int> A,B;
				for (int k=0;k<i;k++) A.push_back(r/i+(r%i>k));
				for (int k=0;k<j;k++) B.push_back(b/j+(b%j>k));
				if (i==j) {
					for (int k=0;k<i;k++) print(A[k],'R'),print(B[k],'B');
				} else if (i>j) {
					for (int k=0;k<j;k++) print(A[k],'R'),print(B[k],'B'); print(A.back(),'R');
				} else {
					for (int k=0;k<i;k++) print(B[k],'B'),print(A[k],'R'); print(B.back(),'B');
				}
				puts("");
				return;
			}
		}
	}
}
int main() {
	read(T);
	while (T--) {
		read(n),read(r),read(b);
		solve();
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