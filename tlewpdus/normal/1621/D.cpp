#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N;
ll C[510][510];

int main() {
	int ttt;

	scanf("%d",&ttt);
	while(ttt--) {
		scanf("%d",&N);
		ll sum = 0;
		for (int i=0;i<2*N;i++) {
			for (int j=0;j<2*N;j++) {
				scanf("%lld",&C[i][j]);
				if (N<=i&&N<=j) sum += C[i][j];
			}
		}
		sum += min({
			C[0][N],C[0][2*N-1],C[N-1][N],C[N-1][2*N-1],
			C[N][0],C[N][N-1],C[2*N-1][0],C[2*N-1][N-1]
		});
		printf("%lld\n",sum);
	}

	return 0;
}