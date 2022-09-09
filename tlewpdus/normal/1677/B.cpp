#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N, M;
char S[1000100];
int R[1000100], C[1000100];

int main() {
	int T;

	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&N,&M);
		scanf(" %s",S);
		for (int i=0;i<N*M;i++) {
			S[i] -= '0';
		}
		for (int j=0;j<M;j++) {
			for (int i=0;i<N;i++) {
				if (S[i*M+j]) {
					C[i*M+j]++;
					break;
				}
			}
		}
		for (int i=0;i<N*M;i++) C[i] += (i?C[i-1]:0);
		int past = -INF;
		for (int i=0;i<N*M;i++) {
			if (!S[i]) continue;
			int l = min(i-past,M);
			if (i+M-l<N*M) {
				R[i + M - l]++;
			}
			if (i+M<N*M) {
				R[i + M]--;
			}
			past = i;
		}
		for (int i=0;i<N*M;i++) R[i] += (i?R[i-1]:0);
		for (int j=0;j<M;j++) {
			for (int i=0;i<N;i++) R[i*M+j] += (i?R[(i-1)*M+j]:0);
		}
		for (int i=0;i<N*M;i++) {
			printf("%d ",R[i]+C[i]);
		}
		puts("");
		for (int i=0;i<N*M;i++) R[i] = C[i] = 0;
	}

	return 0;
}