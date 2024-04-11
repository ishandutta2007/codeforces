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
const int maxn=2010;
int T,n,ans;
ll a[maxn];
int fa[maxn];
int find(int x) { if (fa[x]==x) return x; return fa[x]=find(fa[x]); }
bool check() {
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=0;i<=30;i++) {
		vector<int> V;
		for (int j=1;j<=n;j++) if (a[j]>>i&1) V.push_back(j);
		for (int j=0;j<V.size();j++) fa[find(V[j])]=find(V[0]);
	}
	for (int i=1;i<=n;i++) if (find(i)!=find(1)) return 0;
	return 1;
}
void print() {
	printf("%d\n",ans);
	for (int i=1;i<=n;i++) printf("%lld ",a[i]); puts("");
}
int main() {
	read(T);
	while (T--) {
		read(n);
		ans=0;
		for (int i=1;i<=n;i++) {
			read(a[i]);
			if (a[i]==0) a[i]++,ans++;
		}
		if (check()) { print(); continue; }
		ans++; bool flag=0;
		for (int i=1;i<=n;i++) {
			if (a[i]>1) {
				a[i]--; if (check()) { flag=1; break; }
				a[i]++;
			}
			a[i]++;
			if (check()) { flag=1; break; }
			a[i]--;
		}
		if (flag) { print(); continue; }
		ans++;
		vector<int> V; ll mx=0;
		for (int i=1;i<=n;i++) {
			ll t=(a[i]&(-a[i]));
			if (t>mx) mx=t,V.clear(),V.push_back(i);
			else if (mx==t) V.push_back(i);
		}
		a[V[0]]--,a[V[1]]++;
		print();
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