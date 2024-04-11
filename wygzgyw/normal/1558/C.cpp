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
const int maxn=2050;
int T,n,a[maxn];
int pos[maxn];
vector<int> ans;
void solve(int x) {
	if (x==1) return;
	assert(x%2==1&&1<=x&&x<=n);
	reverse(a+1,a+x+1); ans.push_back(x);
	for (int i=1;i<=x;i++) pos[a[i]]=i;
}
int main() {
	read(T);
	while (T--) {
		read(n); ans.clear();
		int flag=1;
		for (int i=1;i<=n;i++) read(a[i]),flag&=(a[i]%2==i%2),pos[a[i]]=i;
		if (!flag) { puts("-1"); continue; }
		for (int i=n;i>=3;i-=2) {
			solve(pos[i]);
			solve(pos[i-1]-1);
			solve(pos[i-1]+1);
			solve(3);
			solve(i);
		}
		printf("%d\n",(int)ans.size());
		for (int x : ans) printf("%d ",x); puts("");
		//for (int i=1;i<=n;i++) printf("%d ",a[i]); puts("");
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