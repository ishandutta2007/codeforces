#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int N;
int A[100100], B[100100];

int main() {
	int tt;

	scanf("%d",&tt);
	while(tt--) {
		scanf("%d",&N);
		for (int i=0;i<N;i++) scanf("%d",&A[i]);
		for (int i=0;i<N;i++) scanf("%d",&B[i]);
		sort(A,A+N);
		sort(B,B+N);
		int K = N/4;
		int AS = 0, BS = 0;
		for (int i=K;i<N;i++) AS += A[i], BS += B[i];
		if (AS>=BS) {
			puts("0");
			continue;
		}
		int L = K-1;
		for (int M=N+1;;M++) {
			if (M%4==0) {
				AS -= A[K];
				K++;
			}
			else if (L>=0) {
				BS += B[L];
				L--;
			}
			AS += 100;
			if (AS>=BS) {
				printf("%d\n",M-N);
				break;
			}
		}
	}

	return 0;
}