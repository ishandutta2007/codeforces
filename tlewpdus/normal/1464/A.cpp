#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N, M;
int A[100100];
int vis[100100];

int main() {
	int tt;
	scanf("%d",&tt);
	while(tt--) {
		scanf("%d%d",&N,&M);
		for (int i=0;i<N;i++) A[i] = -1, vis[i] = 0;
		int ans = M;
		for (int i=0;i<M;i++) {
			int a, b;
			scanf("%d%d",&a,&b);
			if (a!=b) A[a-1] = b-1;
			else ans--;
		}
		for (int i=0;i<N;i++) {
			if (vis[i]) continue;
			int cur = i;
			do {
				vis[cur] = 1;
				cur = A[cur];
			} while(cur!=-1&&!vis[cur]);
			if (cur==i) ans++;
		}
		printf("%d\n",ans);
	}

	return 0;
}