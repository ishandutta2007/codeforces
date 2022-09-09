#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;

int n;
ll arr[30][30];

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			if (i%2==0) arr[i][j] = (1LL<<(i+j));
			else arr[i][j] = 0;
			printf("%lld ",arr[i][j]);
		}
		puts("");
	}
	fflush(stdout);
	int q;
	scanf("%d",&q);
	for (int i=0;i<q;i++) {
		ll t;
		scanf("%lld",&t);
		printf("1 1\n");
		int x = 0, y = 0;
		for (int j=1;j<=2*n-2;j++) {
			if (t>>j&1) {
				if (x%2) x++;
				else y++;
			}
			else {
				if (x%2) y++;
				else x++;
			}
			printf("%d %d\n",x+1,y+1);
		}
		fflush(stdout);
	}

	return 0;
}