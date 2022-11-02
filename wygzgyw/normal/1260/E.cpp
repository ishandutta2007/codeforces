#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=1<<20;
int n,a[maxn];
priority_queue<ll,vector<ll>,greater<ll> > q;
ll ans;
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++)
		read(a[i]);
	q.push(a[n]);
	if (a[n]==-1) { printf("0\n"); return 0; }
	for (int t=n;t>=1;t/=2) {
		ans+=q.top(); q.pop();
		for (int i=t/2;i<t;i++) {
			if (a[i]==-1) { printf("%lld\n",ans); return 0; }
			q.push(a[i]);
		}
	}
	return 0;
}
/*
  REMEMBER:
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Array size? Integer overflow? Time complexity? Memory usage? Precision error?
*/