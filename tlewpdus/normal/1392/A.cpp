#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;

int n;
int arr[200100];

int main() {
	int tt;

	scanf("%d",&tt);
	while(tt--) {
		scanf("%d",&n);
		int mang = 0;
		for (int i=0;i<n;i++) {
			scanf("%d",&arr[i]);
			if (arr[i]!=arr[0]) mang = 1;
		}
		if (mang) puts("1");
		else printf("%d\n",n);
	}

	return 0;
}