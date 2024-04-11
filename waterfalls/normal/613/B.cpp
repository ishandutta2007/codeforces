#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,A,f,m;
ll b;
int a[100013];
ll sums[100013];
map<int,vector<int> > id;
int val[100013];

int main() {
	scanf("%d%d%d%d%lld",&n,&A,&f,&m,&b);
	for (int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		id[a[i]].push_back(i);
	}
	sort(a,a+n+1);
	for (int i=1;i<=n;i++) sums[i] = sums[i-1]+a[i];
	ll ans = -1;
	int which = -1, num = 0, become = 0;
	for (int i=0;i<=n;i++) {
		ll below = sums[n]-sums[i];
		below = (ll) A*(n-i)-below;
		ll res = b-below;
		if (res<0) continue;
		int low = 0;
		int high = A+1;
		while (high-low>1) {
			int mid = (low+high)/2;
			int ind = lower_bound(a,a+n+1,mid)-a-1;
			ind = min(ind,i);
			below = sums[ind];
			below = (ll) mid*ind-below;
			if (res<below) high = mid;
			else low = mid;
		}
		ll cur = (ll) f*(n-i)+(ll) m*low;
		if (cur>ans) {
			ans = cur;
			which = i;
			num = min(i,lower_bound(a,a+n+1,low)-a-1);
			become = low;
		}
	}
	printf("%lld\n",ans);
	for (int i=1;i<=n;i++) {
		int cur = a[i];
		if (i>which) cur = A;
		else if (i<=num) cur = become;
		val[id[a[i]].back()] = cur;
		id[a[i]].pop_back();
	}
	for (int i=1;i<=n;i++) printf("%d ",val[i]);
	printf("\n");

	return 0;
}