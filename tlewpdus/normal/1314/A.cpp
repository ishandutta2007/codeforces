#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 998244353;

int n;
pll arr[200100];

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%lld",&arr[i].first);
	for (int i=0;i<n;i++) scanf("%lld",&arr[i].second);
	sort(arr,arr+n);
	int tar = -1;
	ll ans = 0;
	for (int i=0;i<n;) {
		priority_queue<pll> pq;
		int p = i;
		for (int k=arr[i].first;;k++) {
			while(p<n&&arr[p].first<=k) {
				pq.push({arr[p].second,p});
				p++;
			}
			if (pq.empty()) break;
			pll tmp = pq.top(); pq.pop();
			ans += tmp.first*(k-arr[tmp.second].first);
		}
		i = p;
	}
	printf("%lld\n",ans);

	return 0;
}