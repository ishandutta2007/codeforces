#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MP make_pair
#define A first
#define B second

int n;
int x[200013];

ll sum[200013];
ll get(int a, int b) { return sum[b]-sum[a-1]; }

pair<ll,ll> check(int i, int l) {
	ll top = get(i-l,i)+get(n+1-l,n)-(ll) (2*l+1)*x[i];
	return MP(top,2*l+1);
}

int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&x[i]);
	sort(x+1,x+n+1);
	for (int i=1;i<=n;i++) sum[i] = sum[i-1]+x[i];
	pair<ll,ll> best = MP(-1,1);
	int mid = 0;
	int len = 0;
	for (int i=1;i<=n;i++) {
		int low = 0;
		int high = min(i-1,n-i);
		while (high>low) {
			auto one = check(i,(low*2+high)/3);
			auto two = check(i,(low+high*2)/3+1);
			if (one.A*two.B>one.B*two.A) high = (low+high*2)/3;
			else low = (low*2+high)/3+1;
		}
		auto cur = check(i,low);
		if (cur.A*best.B>cur.B*best.A) {
			best = cur;
			mid = i;
			len = low;
		}
	}
	printf("%d\n",len*2+1);
	for (int i=mid-len;i<=mid;i++) printf("%d ",x[i]);
	for (int i=n+1-len;i<=n;i++) printf("%d ",x[i]);
	printf("\n");

	return 0;
}