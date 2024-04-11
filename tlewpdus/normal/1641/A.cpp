#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1000000007;

int N;
ll X;
ll A[200100];
map<ll,int> cnt;

int main() {
	int tt;

	scanf("%d",&tt);
	while(tt--) {
		scanf("%d%lld",&N,&X);
		for (int i=0;i<N;i++) {
			scanf("%lld",&A[i]);
			cnt[A[i]]++;
		}
		sort(A,A+N);
		N = unique(A,A+N)-A;
		int ans = 0;
		for (int i=0;i<N;i++) {
			while(cnt[A[i]]>0 && cnt[A[i]*X]>0) {
				cnt[A[i]]--;
				cnt[A[i]*X]--;
			}
			ans+=cnt[A[i]];
		}
		printf("%d\n",ans);
		cnt.clear();
	}

	return 0;
}