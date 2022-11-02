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
const int mod=998244353;
const int maxn=150010;
int n,x,mi[maxn];
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
int calc(vector<int> &A,vector<int> &B,int i,int x) {
	if ((int)A.size()==0||(int)B.size()==0||i<0) return mi[(int)A.size()+(int)B.size()]-1;
	vector<int> A0,A1,B0,B1;
	for (int &x : A) if (x>>i&1) A1.push_back(x); else A0.push_back(x);
	for (int &x : B) if (x>>i&1) B1.push_back(x); else B0.push_back(x);
	if (x>>i&1) {
		x^=1<<i;
		int t1=calc(A0,B1,i-1,x)+1;
		int t2=calc(A1,B0,i-1,x)+1;
		return ((ll)t1*t2-1)%mod;
	}
	int t1=calc(A0,B0,i-1,x),t2=calc(A1,B1,i-1,x);
	int res=(t1+t2)%mod;
	update(res,(ll)(mi[(int)A0.size()]-1)*(mi[(int)A1.size()]-1)%mod);
	update(res,(ll)(mi[(int)B0.size()]-1)*(mi[(int)B1.size()]-1)%mod);
	return res;
}
int solve(vector<int> &A,int i) {
	if (!(int)A.size()||i<0) return mi[(int)A.size()]-1;
	vector<int> L,R;
	for (int &x : A) if (x>>i&1) R.push_back(x); else L.push_back(x);
	if (x>>i&1) return calc(L,R,i-1,x);
	return (solve(L,i-1)+solve(R,i-1))%mod;
}
int main() {
	read(n),read(x);
	mi[0]=1; for (int i=1;i<maxn;i++) mi[i]=(ll)mi[i-1]*2%mod;
	vector<int> a;
	for (int i=0;i<n;i++) { int X; read(X); a.push_back(X); }
	printf("%d\n",solve(a,29));
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