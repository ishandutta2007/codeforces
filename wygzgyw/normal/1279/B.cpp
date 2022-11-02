#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(1e5)+10;
const ll INF=1LL<<55;
int T,n,ans;
ll m,a[maxn],s[maxn];
int x,pos;
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n);
		read(m);
		for (int i=1;i<=n;i++) read(a[i]),s[i]=s[i-1]+a[i];
		ans=0,pos=0;
		for (int i=1;i<=n;i++) if (s[i]<=m) ans=i;
		s[n+1]=INF;
		for (int i=1;i<=n;i++) {
			x=upper_bound(s+1,s+n+2,m+a[i])-s-1;
			if (x>i) {
				if (ans<x-1) ans=x-1,pos=i;
			}
		}
		printf("%d\n",pos);
	}
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Interger overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/