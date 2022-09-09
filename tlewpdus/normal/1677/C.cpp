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
int A[100100], B[100100];
int P[100100], V[100100];

int main() {
	int T;

	scanf("%d",&T);
	while(T--) {
		scanf("%d",&N);
		for (int i=0;i<N;i++) scanf("%d",&A[i]), A[i]--;
		for (int i=0;i<N;i++) scanf("%d",&B[i]), B[i]--;
		for (int i=0;i<N;i++) P[A[i]] = B[i];
		for (int i=0;i<N;i++) V[i] = 0;
		ll d = N;
		for (int i=0;i<N;i++) {
			if (V[i]) continue;
			int p = i, c = 0;
			do {
				V[p] = 1;
				c++;
				p = P[p];
			} while(p!=i);
			if (c%2==1) d--;
		}
		if (d%2==0) {
			printf("%lld\n",2*((d/2)*(d/2)+(d/2)*(N-d)));
		}
		else {
			printf("%lld\n",2*((d/2)*(d/2+1)+(d/2)*(N-d)));
		}
	}

	return 0;
}