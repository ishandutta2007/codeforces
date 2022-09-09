#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N, Z;
int A[2010];

int main() {
	int t;

	scanf("%d",&t);
	while(t--) {
		scanf("%d%d",&N,&Z);
		for (int i=0;i<N;i++) scanf("%d",&A[i]);
		int maxi = A[0];
		for (int i=0;i<N;i++) {
			maxi = max(maxi,A[i]|Z);
		}
		printf("%d\n",maxi);
	}

	return 0;
}