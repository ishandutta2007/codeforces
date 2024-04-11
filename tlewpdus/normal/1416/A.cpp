#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353; // 1000000007

int n;
int arr[300100];
int ans[300100];
vector<int> loc[300100];

int main() {
	int t;

	scanf("%d",&t);
	while(t--) {
		scanf("%d", &n);
		for (int i=0;i<n;i++) {
			scanf("%d",&arr[i]);
			ans[i+1] = INF;
			loc[arr[i]].push_back(i);
		}
		ans[n+1] = INF;
		for (int i=1;i<=n;i++) {
			int pre = -1;
			int maxi = 0;
			for (int &v : loc[i]) {
				maxi = max(maxi,v-pre);
				pre = v;
			}
			maxi = max(maxi,n-pre);
			ans[maxi] = min(ans[maxi],i);
		}
		int cur = INF;
		for (int i=1;i<=n;i++) {
			cur = min(cur,ans[i]);
			printf("%d ",(cur>n+123?-1:cur));
		}
		puts("");
		for (int i=1;i<=n;i++) loc[i].clear();
	}

	return 0;
}