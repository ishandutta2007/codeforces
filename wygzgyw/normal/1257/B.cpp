#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
int T;
ll x,y;
void solve() {
	int cnt=500;
	while (cnt--) {
		if (x>=y) { printf("Yes\n"); return; }
		if (x==1) break;
		if (x&1) x--;
		else x=x/2*3;
	}
	printf("No\n");
}
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(x); read(y);
		solve();
	}
	return 0;
}
/*
  REMEMBER:
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Array size? Integer overflow? Time complexity? Memory usage? Precision error?
*/