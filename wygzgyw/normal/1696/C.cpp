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
const int maxn=50010;
int T,n,m,k;
int a[maxn],b[maxn];
void init(int *a,int n,vector<pair<int,ll> > &V) {
	V.clear();
	for (int i=1;i<=n;i++) {
		int x=a[i];
		while (x%m==0) x/=m;
		pair<int,ll> tmp=MP(x,a[i]/x);
		if (V.size()&&V.back().first==tmp.first) V.back().second+=tmp.second;
		else V.push_back(tmp);
	}
}
int main() {
	read(T);
	while (T--) {
		read(n),read(m);
		for (int i=1;i<=n;i++) read(a[i]);
		read(k);
		for (int i=1;i<=k;i++) read(b[i]);
		vector<pair<int,ll> > V1,V2;
		init(a,n,V1),init(b,k,V2);
		int flag=0;
		if ((int)V1.size()==(int)V2.size()) {
			flag=1;
			for (int i=0;i<V1.size();i++) flag&=(V1[i]==V2[i]);
		}
		if (flag) puts("Yes"); else puts("No");
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