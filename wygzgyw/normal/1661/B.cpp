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
const int mod=32768;
int dis[mod];
vector<int> g[mod];
int n,q[mod+10],hd,tl;
int main() {
	for (int i=0;i<mod;i++) dis[i]=1e9;
	dis[0]=0,q[hd=tl=1]=0;
	for (int i=1;i<mod;i++) g[(i+1)%mod].push_back(i),g[(i*2)%mod].push_back(i);
	while (hd<=tl) {
		int x=q[hd]; hd++;
		for (int &y : g[x]) if (dis[y]>dis[x]+1) dis[y]=dis[x]+1,q[++tl]=y;
	}
	read(n);
	while (n--) { int x; read(x); printf("%d ",dis[x]); } puts("");
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