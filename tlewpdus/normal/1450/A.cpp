#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7; // 998244353

int t;
int n;
char str[210];

int main() {
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		scanf(" %s",str);
		sort(str,str+n);
		str[n] = 0;
		printf("%s\n",str);
	}

	return 0;
}