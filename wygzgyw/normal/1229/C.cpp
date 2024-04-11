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
const int maxn=(1e5)+10;
int n,out[maxn],in[maxn];
vector<int> s[maxn];
int m,x,y; ll ans;
void rev(int a,int b) {
	ans-=(ll)in[a]*out[a]+(ll)in[b]*out[b];
	s[a].push_back(b);
	out[a]--,in[a]++;
	out[b]++,in[b]--;
	ans+=(ll)in[a]*out[a]+(ll)in[b]*out[b];
}
int main() {
	read(n); read(m);
	for (int i=1;i<=m;i++) {
		read(x),read(y);
		if (x<y) swap(x,y);
		s[y].push_back(x);
		out[x]++,in[y]++;
	}
	for (int i=1;i<=n;i++) ans+=(ll)in[i]*out[i];
		printf("%lld\n",ans);
	int q; read(q);
	while (q--) {
		read(x);
		for (int &y : s[x]) rev(y,x); s[x].clear();
		printf("%lld\n",ans);
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