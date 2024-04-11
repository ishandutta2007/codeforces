#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(1e5)+10;
int n,q,a[maxn];
int cnt[maxn],op,k;
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(q);
	for (int i=1;i<=n;i++) read(a[i]),cnt[a[i]]++;
	while (q--) {
		read(op),read(k);
		if (op==1) cnt[a[k]]--,a[k]^=1,cnt[a[k]]++;
		else {
			if (cnt[1]>=k) puts("1");
			else puts("0");
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