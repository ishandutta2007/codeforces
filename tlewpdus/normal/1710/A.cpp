#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

ll N, M, K;
ll A[100100];

int main() {
	int T;

	scanf("%d",&T);
	while(T--) {
		scanf("%lld%lld%lld",&N,&M,&K);
		for (int i=0;i<K;i++) {
			scanf("%lld",&A[i]);
		}
		bool good = false;
		{
			ll sum = 0;
			bool all2 = true;
			for (int i = 0; i < K; i++) {
				if (A[i] >= 2 * N) {
					ll v = A[i] / N;
					sum += v;
					if (v!=2) all2 = false;
				}
			}
			if (sum>=M) {
				if (all2 && M%2) {

				}
				else good = true;
			}
		}
		{
			ll sum = 0;
			bool all2 = true;
			for (int i = 0; i < K; i++) {
				if (A[i] >= 2 * M) {
					ll v = A[i] / M;
					sum += v;
					if (v!=2) all2 = false;
				}
			}
			if (sum>=N) {
				if (all2 && N%2) {

				}
				else good = true;
			}
		}
		puts(good?"Yes":"No");
	}

	return 0;
}