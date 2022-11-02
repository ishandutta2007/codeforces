#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const ll INF=1e18;
const int maxn=(1e5)+10;
int n;
ll sum,dp[maxn],mn;
priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > q;
pair<int,int> d[maxn];
int id[maxn];
bool cmp(int x,int y) {
	if (d[x].first+d[x].second!=d[y].first+d[y].second)
		return d[x].first+d[x].second<d[y].first+d[y].second;
	return x<y;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) read(d[i].first),read(d[i].second),sum+=d[i].second;
	sort(d+1,d+n+1);
	for (int i=1;i<=n;i++) dp[i]=INF,id[i]=i;
	sort(id+1,id+n+1,cmp);
	//for (int i=1;i<=n;i++) printf("%d %d\n",d[i].first,d[i].second);
	int pos=0; mn=INF;
	for (int i=1;i<=n;i++) {
		while (pos<n&&id[pos+1]<i&&d[id[pos+1]].first+d[id[pos+1]].second<=d[i].first) {
			pos++;
			//printf("HI %d\n",id[pos]);
			mn=min(mn,dp[id[pos]]-(d[id[pos]].first+d[id[pos]].second));
		}
		if (i>1) {
			dp[i]=mn+d[i].first;
			while (!q.empty()) {
				int x=q.top().second;
				if (d[x].first+d[x].second>=d[i].first) {
					dp[i]=min(dp[i],dp[x]);
					break;
				}
				q.pop();
			}
		} else dp[i]=0;
	//	printf("%lld\n",dp[i]);
		q.push(make_pair(dp[i],i));
	}
	printf("%lld\n",sum+dp[n]);
	
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