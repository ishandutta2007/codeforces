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
int T,n,a[maxn];
int cnt[2];
ll ans,tmp;
int p[maxn],b[maxn];
vector<int> g[maxn];
namespace BIT {
int tr[maxn];
void clear() { for (int i=1;i<=n;i++) tr[i]=0; }
int query(int x) {
	int res=0; for (;x<=n;x+=x&(-x)) res+=tr[x]; return res;
}
void add(int x) {
	for (;x;x-=x&(-x)) tr[x]++;
}
};
void solve() {
	tmp=0;
	g[0].clear(),g[1].clear();
	for (int i=1;i<=n;i++) {
		g[b[i]].push_back(i);
	}
	int P[2]; P[0]=P[1]=0;
	for (int i=1;i<=n;i++) p[i]=g[a[i]][P[a[i]]++];
	BIT::clear();
	for (int i=1;i<=n;i++) tmp+=BIT::query(p[i]),BIT::add(p[i]);
	ans=min(ans,tmp);
}
int main() {
	read(T);
	while (T--) {
		read(n);
		cnt[0]=cnt[1]=0;
		for (int i=1;i<=n;i++) read(a[i]),a[i]%=2,cnt[a[i]]++;
		ans=1e18;
		if (cnt[0]==cnt[1]) {
			for (int i=1;i<=n;i+=2) b[i]=0;
			for (int i=2;i<=n;i+=2) b[i]=1;
			solve();
			for (int i=1;i<=n;i+=2) b[i]=1;
			for (int i=2;i<=n;i+=2) b[i]=0;
			solve();
			printf("%lld\n",ans);
		} else if (abs(cnt[0]-cnt[1])==1) {
			int op=(cnt[0]>cnt[1]?0:1);
			for (int i=1;i<=n;i+=2) b[i]=op;
			for (int i=2;i<=n;i+=2) b[i]=1-op;
			solve();
			printf("%lld\n",ans);
		} else puts("-1");
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