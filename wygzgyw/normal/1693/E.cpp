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
const int maxn=(2e5)+10;
int n; ll ans;
vector<int> buc[maxn];
int tr[maxn];
void add(int x) {
	for (;x<=n;x+=x&(-x)) tr[x]++;
}
int query(int x) {
	int res=0; for (;x;x-=x&(-x)) res+=tr[x]; return res;
}
int query(int l,int r) { return query(r)-query(l-1); }
int main() {
	read(n);
	for (int i=1;i<=n;i++) {
		int x; read(x); buc[x].push_back(i);
	}
	int l=0,r=n+1;
	for (int i=n;i>=1;i--) if ((int)buc[i].size()) {
		int _l=min(r,buc[i][0]);
		int _r=max(l,buc[i].back()+1);
		l=_l,r=_r;
		for (int &x : buc[i]) add(x);
		ans+=query(l,r-1);
	}
	printf("%lld\n",ans);
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