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
const int maxn=(2e5)+10;
int T,n,a[maxn];
vector<int> ans;
void add(int i) { ans.push_back(i); a[i]=a[i+1]=a[i+2]=(a[i]^a[i+1]^a[i+2]); }
void solve(int l,int r) {
	for (int i=l;i<=r-2;i+=2) add(i);
	for (int i=r-4;i>=l;i-=2) add(i);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n);
		int pre=0;
		for (int i=1;i<=n;i++) read(a[i]),pre^=a[i];
		if (pre) { puts("NO"); continue; }
		ans.clear();
		if (n&1) solve(1,n);
		else {
			pre=0; int flag=0;
			for (int i=1;i<=n;i++) {
				pre^=a[i];
				if ((i&1)&&!pre) { flag=1; solve(1,i),solve(i+1,n); break; }
			}
			if (!flag) { puts("NO"); continue; }
		}
		puts("YES");
		printf("%d\n",(int)ans.size());
		for (int &x : ans) printf("%d ",x); puts("");
		for (int i=1;i<=n;i++) assert(a[i]==0);
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