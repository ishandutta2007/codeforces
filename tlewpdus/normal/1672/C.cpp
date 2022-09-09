#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N;
int A[200100];

int main() {
	int T;

	scanf("%d",&T);
	while(T--) {
		scanf("%d",&N);
		for (int i=0;i<N;i++) {
			scanf("%d",&A[i]);
		}
		int mini = N, maxi = -1;
		for (int i=0;i+1<N;i++) {
			if (A[i]==A[i+1]) {
				mini = min(mini,i);
				maxi = max(maxi,i);
			}
		}
		if (maxi==-1) {
			puts("0");
		}
		else {
			if (maxi-mini==0) puts("0");
			else if (maxi-mini<=2) puts("1");
			else printf("%d\n",maxi-mini-1);
		}
	}

	return 0;
}