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
int n,m;
set<int> s[maxn];
set<int>::iterator it;
int ans;
int ST(int x) {
	if (s[x].empty()) return 1;
	it=s[x].end(); it--;
	if ((*it)<x) return 1;
	return 0;
}
void del(int x) {
	ans-=ST(x);
}
void add(int x) { ans+=ST(x); }
void add(int x,int y) {
	del(x),del(y);
	s[x].insert(y);
	s[y].insert(x);
	add(x),add(y);
}
void del(int x,int y) {
	del(x),del(y);
	s[x].erase(y);
	s[y].erase(x);
	add(x),add(y);
}
int main() {
	read(n),read(m);
	for (int i=1;i<=n;i++) add(i);
	int op,x,y;
	while (m--) read(x),read(y),add(x,y);
	int q; read(q); while (q--) {
		read(op);
		if (op==3) printf("%d\n",ans);
		else {
			read(x),read(y);
			if (op==1) add(x,y); else del(x,y);
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