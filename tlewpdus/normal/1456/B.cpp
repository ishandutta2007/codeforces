#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7; // 998244353

int N;
int A[100100];
int L[100100];

int len(int x) {
	int c = 0;
	while(x) {
		x>>=1;
		c++;
	}
	return c;
}

int main() {
	scanf("%d",&N);
	for (int i=0;i<N;i++) scanf("%d",&A[i]);
	for (int i=0;i<N;i++) {
		L[i] = len(A[i]);
	}
	for (int i=0;i+2<N;i++) {
		if (L[i]==L[i+1]&&L[i+1]==L[i+2]) {
			puts("1");
			return 0;
		}
	}
	int ans = -1;
	for (int s=0;s<=N;s++) {
		for (int m=s+1;m<=N;m++) {
			for (int e=m+1;e<=N;e++) {
				int x = 0, y = 0;
				for (int i=s;i<m;i++) x ^= A[i];
				for (int i=m;i<e;i++) y ^= A[i];
				if (x>y) {
					if (ans==-1||ans>e-s-2) {
						ans=e-s-2;
					}
				}
			}
		}
	}
	printf("%d\n",ans);

	return 0;
}