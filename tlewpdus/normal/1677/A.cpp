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
int A[5010];
int R[5010][5010];
int L[5010][5010];

int main() {
	int T;

	scanf("%d",&T);
	while(T--) {
		scanf("%d",&N);
		for (int i=1;i<=N;i++) {
			scanf("%d",&A[i]);
		}
		for (int i=1;i<=N;i++) {
			for (int j=1;j<=N;j++) {
				L[i][j] = L[i-1][j]+(A[i]<j);
			}
		}
		for (int i=N;i;i--) {
			for (int j=1;j<=N;j++) {
				R[i][j] = R[i+1][j]+(A[i]<j);
			}
		}
		ll ans = 0;
		for (int i=1;i<=N;i++) {
			for (int j=i+1;j<=N;j++) {
				ans += L[i-1][A[j]]*R[j+1][A[i]];
			}
		}
		printf("%lld\n",ans);
		for (int i=1;i<=N;i++) {
			for (int j=1;j<=N;j++) L[i][j] = R[i][j] = 0;
		}
	}

	return 0;
}