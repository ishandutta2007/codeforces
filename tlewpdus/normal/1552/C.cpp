#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1000000007;

int N, K;
int C[210];
pii A[110];

int main() {
	int tt;

	scanf("%d",&tt);
	while(tt--) {
		scanf("%d%d",&N,&K);
		for (int i=0;i<2*N;i++) C[i] = 0;
		for (int i=0;i<K;i++) {
			int a, b;
			scanf("%d%d",&a,&b); --a; --b;
			if (a>b) swap(a,b);
			A[i] = {a,b};
			C[a] = C[b] = 1;
		}
		int ans = 0;
		for (int i=0;i<K;i++) {
			for (int j=i+1;j<K;j++) {
				if ((A[i].first<A[j].first&&A[j].first<A[i].second&&A[i].second<A[j].second)||
				(A[j].first<A[i].first&&A[i].first<A[j].second&&A[j].second<A[i].second)) ans++;
			}
			int c1 = 0, c2 = 0;
			for (int j=0;j<2*N;j++) {
				if (C[j]) continue;
				if (A[i].first<j&&j<A[i].second) c1++;
				else c2++;
			}
			ans += min(c1,c2);
		}
		ans += (N-K)*(N-K-1)/2;
		printf("%d\n",ans);
	}

	return 0;
}