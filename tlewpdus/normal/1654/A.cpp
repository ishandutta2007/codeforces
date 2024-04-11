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
int A[1111];

int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&N);
		for (int i=0;i<N;i++) {
			scanf("%d",&A[i]);
		}
		sort(A,A+N);
		printf("%d\n",A[N-2]+A[N-1]);
	}

	return 0;
}