#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int b, g, n;

int main() {
	scanf("%d%d%d",&b,&g,&n);
	int cnt = 0;
	for (int i=0;i<=n;i++) {
		if (i<=b&&n-i<=g) cnt++;
	}
	printf("%d\n",cnt);

	return 0;
}