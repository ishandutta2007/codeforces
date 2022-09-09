#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353; //1000000007

ll N, K;
int mak[100100];

int main() {
	int tt;

	scanf("%d",&tt);
	while(tt--) {
		scanf("%lld%lld",&N,&K);
		if (N<62&&(1LL<<(N-1))<K) {
			puts("-1");
			continue;
		}
		for (int i=0;i<N;i++) mak[i] = 0;
		K--;
		int c = N-2;
		while(K) {
			mak[c] = K%2;
			K/=2;
			c--;
		}
		for (int i=0;i<N;i++) {
			int j = i;
			while(mak[j]) j++;
			for (int k=j;k>=i;k--) printf("%d ",k+1);
			i = j;
		}puts("");
	}

	return 0;
}