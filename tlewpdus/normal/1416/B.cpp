#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353; // 1000000007

int n;
int arr[10100];

struct tup {
	int a, b, c;
};
vector<tup> ans;
void que(int i, int j, int x) {
	ans.push_back({i,j,x});
//	printf("%d %d %d\n",i,j,x);
	arr[i] -= x*i;
	arr[j] += x*i;
}

int main() {
	int t;

	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		ll sum = 0;
		for (int i=1;i<=n;i++) {
			scanf("%d",&arr[i]);
			sum += arr[i];
		}
		if (sum%n!=0) {
			puts("-1");
			continue;
		}
		for (int i=2;i<=n;i++) {
			if (arr[i]%i) {
				que(1,i,i-arr[i]%i);
			}
			que(i,1,arr[i]/i);
		}
		for (int i=2;i<=n;i++) {
			que(1,i,sum/n);
		}
		printf("%d\n",ans.size());
		for (tup &t : ans) printf("%d %d %d\n",t.a,t.b,t.c);
		ans.clear();
	}

	return 0;
}