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
int A[100];

int main() {
	int ttt;
	scanf("%d",&ttt);
	while(ttt--) {
		scanf("%d",&N);
		for (int i=0;i<N;i++) scanf("%d",&A[i]);
		if (N<=2) {
			puts("0");
			continue;
		}
		int ans = N;
		for (int i=0;i<N;i++) {
			for (int j=i+1;j<N;j++) {
				int cnt = 0;
				for (int k=0;k<N;k++) {
					if ((A[k]-A[i])*(j-i)!=(A[j]-A[i])*(k-i)) cnt++;
				}
				ans = min(ans,cnt);
			}
		}
		printf("%d\n",ans);
	}

	return 0;
}