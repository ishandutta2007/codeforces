#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(5e5)+10;
int n,k,a[maxn];
priority_queue<ll> q;
ll tmp,ans;
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(k);
	for (int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+n+1);
	for (int i=1;i<=k+1;i++) q.push(0);
	for (int i=n;i>=1;i--) {
		tmp=q.top(); q.pop();
		ans+=tmp;
		q.push(tmp+a[i]);
	}
	printf("%lld\n",ans);
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