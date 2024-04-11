#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N, K;
int A[200100];

int main() {
	int T;

	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&N,&K);
		for (int i=0;i<N;i++) scanf("%d",&A[i]);
		sort(A,A+N);
		bool good = false;
		for (int i=0;i<N;i++) {
			int t = lower_bound(A,A+N,A[i]+K)-A;
			if (t<N && A[t]==A[i]+K) {
				good = true;
				break;
			}
		}
		if (good) puts("YES");
		else puts("NO");
	}

	return 0;
}