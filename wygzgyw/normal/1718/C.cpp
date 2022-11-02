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
int T,n,q;
ll a[maxn];
int sz;
vector<int> V;
multiset<ll> s[maxn];
ll *sum[maxn];
ll *now;
ll rub[20000010];
void print() {
	ll ans=0;
	for (int i=0;i<sz;i++) ans=max(ans,(*--s[i].end())*V[i]);
	printf("%lld\n",ans);
}
int main() {
	read(T);
	while (T--) {
		read(n),read(q);
		for (int i=1;i<=n;i++) read(a[i%n]);
		V.clear();
		for (int i=1;i<n;i++) if (n%i==0) V.push_back(i);
		vector<int> V2;
		for (int &x : V) {
			bool flag=0; for (int &y : V) if (y!=x&&y%x==0) { flag=1; break; }
			if (!flag) V2.push_back(x);
		}
		V.swap(V2);
		sz=(int)V.size();
		for (int i=0;i<sz;i++) s[i].clear();
		now=rub;
		for (int i=0;i<sz;i++) {
			sum[i]=now,now+=V[i];
			for (int j=0;j<V[i];j++) sum[i][j]=0;
			for (int j=0;j<n;j++) sum[i][j%V[i]]+=a[j];
			for (int j=0;j<V[i];j++) s[i].insert(sum[i][j]);
		}
		print();
		while (q--) {
			int x; read(x); x%=n; ll now; read(now);
			for (int i=0;i<sz;i++) {
				int y=x%V[i];
				s[i].erase(s[i].find(sum[i][y]));
				sum[i][y]-=a[x];
				sum[i][y]+=now;
				s[i].insert(sum[i][y]);
			}
			a[x]=now;
			print();
		}
	}
	return 0;
}