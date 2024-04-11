#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7; // 998244353

int t;
int N;
int A[100100];
int C[100100], D[100100];

int main() {
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&N);
		int p = 0, a = 0;
		for(int i=1;i<=N;i++) C[i] = D[i] = 0;
		for (int i=0;i<=N;i++) {
			if (i<N) {
				scanf("%d",&A[i]);
				D[A[i]]++;
			}
			if (i==N||(i&&A[i]==A[i-1])) {
				C[A[p]]++;
				C[A[i-1]]++;
				a++;
				p = i;
			}
		}
		int maxi = 0, maxd = 0;
		for (int i=1;i<=N;i++) maxi = max(maxi,C[i]);
		for (int i=1;i<=N;i++) maxd = max(maxd,D[i]);
		if (maxd>(N+1)/2) puts("-1");
		else {
			printf("%d\n",a-1+max(maxi-a-1,0));
		}
	}

	return 0;
}