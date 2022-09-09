#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N, X;
int A[200100];

int main() {
	int TT;

	scanf("%d",&TT);
	while(TT--) {
		scanf("%d%d",&N,&X);
		for (int i=0;i<N;i++) scanf("%d",&A[i]);
		int maxi = 0, mini = INF;
		int ans = 0;
		for (int i=0;i<N;i++) {
			maxi = max(maxi, A[i]);
			mini = min(mini,A[i]);
			if (maxi-mini>2*X) {
				ans++;
				maxi = mini = A[i];
			}
		}
		printf("%d\n",ans);
	}

	return 0;
}