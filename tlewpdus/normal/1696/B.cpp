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
int A[100100];

int main() {
	int t;

	scanf("%d",&t);
	while(t--) {
		scanf("%d",&N);
		int mini = N, maxi = -1, c=0;
		for (int i=0;i<N;i++) {
			scanf("%d",&A[i]);
			if (A[i]) {
				mini = min(mini,i);
				maxi = max(maxi,i);
				c++;
			}
		}
		if (c==0) {
			puts("0");
		} else if (maxi-mini+1==c) {
			puts("1");
		} else {
			puts("2");
		}
	}

	return 0;
}