#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(2e5)+10;
int T;
ll n,m,a,b,s[maxn];
bool solve(ll mid) {
	if (mid>=b-a) return 0;
	ll mx=0;
	for (int i=mid;i>=1;i--) {
		mx=max(mx,(mid-i)+s[i]);
	}
	return b-1>mx;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	ll l,r,mid,res;
	while (T--) {
		read(n),read(m),read(a),read(b);
		if (a>b) a=n-a+1,b=n-b+1;
		for (int i=1;i<=m;i++) read(s[i]);
		sort(s+1,s+m+1);
		l=1,r=m,res=0;
		while (l<=r) {
			mid=(l+r)/2;
			if (solve(mid)) l=mid+1,res=mid;
			else r=mid-1;
		}
		printf("%lld\n",res);
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