#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(1e5)+10;
int n,k,now[maxn],a[maxn];
ll ans;
priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > q;
ll F(ll x,ll y) {
	if (x%y==0) return (x/y)*(x/y)*y;
	return (x/y)*(x/y)*(y-x%y)+(x/y+1)*(x/y+1)*(x%y);
}
int main() {
//	freopen("1.txt","r",stdin);
	read(n),read(k);
	for (int i=1;i<=n;i++) {
		read(a[i]);
		now[i]=1;
		ans+=(ll)a[i]*a[i];
		q.push(make_pair(F(a[i],2)-F(a[i],1),i));
	} k-=n;
//	printf("%lld\n",F(5,4));
	while (!q.empty()&&k) {
		int x=q.top().second; if (q.top().first>=0) break;
		ans+=q.top().first; k--;
		q.pop();
		now[x]++;
		if (now[x]<a[x]) q.push(make_pair(F(a[x],now[x]+1)-F(a[x],now[x]),x));
	}
//	for (int i=1;i<=n;i++) printf("%d ",now[i]); puts("");
	printf("%lld\n",ans);
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