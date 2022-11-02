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
const int maxn=(3e5)+10;
int T,a,b;
int tim,vis[maxn];
vector<int> ans;
void solve(int A1,int B1) {
	for (int x=0;x<=A1&&x<=a;x++) {
		int y=a-x,w=A1-x,z=b-w;
		if (0<=z&&0<=w) {
			vis[y+w]=tim;
		}
	}
}
int main() {
	read(T);
	while (T--) {
		read(a),read(b);
		tim++;
		solve((a+b)/2,(a+b)-(a+b)/2);
		solve((a+b)-(a+b)/2,(a+b)/2);
		ans.clear();
		for (int i=0;i<=a+b;i++) if (vis[i]==tim) ans.push_back(i);
		printf("%d\n",(int)ans.size());
		for (int x : ans) printf("%d ",x); puts("");
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