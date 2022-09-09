#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;



int main() {
	int ttt;

	scanf("%d",&ttt);
	while(ttt--) {
		int N, K;

		scanf("%d%d",&N,&K);
		if (N<2*K-1) {
			puts("-1");
		}
		else {
			for (int i=0;i<N;i++) {
				for (int j=0;j<N;j++) {
					if (i==j && i%2==0 && i/2 < K) printf("R");
					else printf(".");
				}
				puts("");
			}
		}
	}

	return 0;
}