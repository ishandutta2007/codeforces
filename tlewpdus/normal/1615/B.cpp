#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int D[200100][20];

int main() {
	int t;
	scanf("%d",&t);

	for (int i=0;i<=200010;i++) {
		for (int j=0;j<20;j++) {
			if ((i>>j)&1) D[i][j]++;
		}
	}
	for (int i=1;i<=200010;i++) {
		for (int j=0;j<20;j++) {
			D[i][j] += D[i-1][j];
		}
	}

	while(t--) {
		int l, r;
		scanf("%d%d",&l,&r);
		int maxi = 0;
		for (int i=0;i<20;i++) {
			maxi = max(maxi, D[r][i]-D[l-1][i]);
		}
		printf("%d\n",r-l+1-maxi);
	}

	return 0;
}