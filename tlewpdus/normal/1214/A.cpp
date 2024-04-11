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

int n;
int d, e;

int main() {
	scanf("%d%d%d",&n,&d,&e);
	int mini = n;
	for (int i=0;i<=n/(5*e);i++) {
		mini = min(mini,(n-5*i*e)%d);
	}
	printf("%d\n",mini);

	return 0;
}