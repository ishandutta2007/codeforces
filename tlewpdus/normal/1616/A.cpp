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
int cnt[110];

int main() {
	int ttt;
	scanf("%d",&ttt);
	while(ttt--) {
		scanf("%d",&N);
		for (int i=0;i<N;i++) {
			int a;
			scanf("%d",&a);
			cnt[abs(a)]++;
		}
		int ans = min(cnt[0],1);
		for (int i=1;i<=100;i++) ans += min(cnt[i],2);
		printf("%d\n",ans);
		for (int i=0;i<=100;i++) cnt[i] = 0;
	}

	return 0;
}