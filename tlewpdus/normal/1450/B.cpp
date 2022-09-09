#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7; // 998244353

int t;
int n, k;
pii arr[110];

int main() {
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d",&n,&k);
		for (int i=0;i<n;i++) {
			scanf("%d%d",&arr[i].first,&arr[i].second);
		}
		int d = 0;
		for (int i=0;i<n;i++) {
			int c = 1;
			for (int j=0;j<n;j++) {
				if (abs(arr[i].first-arr[j].first)+abs(arr[i].second-arr[j].second)>k) {
					c=0;
					break;
				}
			}
			if (c) {
				puts("1");
				d = 1;
				break;
			}
		}
		if (d==0) puts("-1");
	}

	return 0;
}