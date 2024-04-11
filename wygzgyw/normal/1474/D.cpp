#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(2e5)+10;
int T,n;
ll a[maxn],L[maxn],R[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	ll x,y;
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n;i++) read(a[i]);
		L[0]=R[n+1]=0;
		for (int i=1;i<=n;i++) {
			if (L[i-1]==-1) L[i]=-1;
			else if (a[i]<L[i-1]) L[i]=-1;
			else L[i]=a[i]-L[i-1];
		}
		if (L[n]==0) { puts("YES"); continue; }
		for (int i=n;i>=1;i--) {
			if (R[i+1]==-1) R[i]=-1;
			else if (a[i]<R[i+1]) R[i]=-1;
			else R[i]=a[i]-R[i+1];
		}
		int flag=0;
		for (int i=1;i<n;i++) {
			if (L[i-1]!=-1&&R[i+2]!=-1) {
				x=a[i+1]-L[i-1],y=a[i]-R[i+2];
				if (x>=0&&y>=0&&x==y) { flag=1; break; }
			}
		}
		if (flag) puts("YES");
		else puts("NO");
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