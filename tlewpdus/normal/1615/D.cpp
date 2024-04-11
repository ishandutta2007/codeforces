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
int col[200100];
vector<pii> lis[200100];
vector<pii> tis[200100];

int parity(int k) {
	return __builtin_popcount(k)%2;
}

bool dfs(int here) {
	for (pii &e : tis[here]) {
		int there = e.second;
		if (col[there]==-1) {
			col[there] = (col[here]^e.first);
			if (!dfs(there)) return false;
		}
		else if (col[there]!=(col[here]^e.first)) return false;
	}
	return true;
}

int main() {
	int t;
	scanf("%d",&t);

	while(t--) {
		scanf("%d%d",&N,&M);
		for (int i=0;i<N-1;i++) {
			int a, b, c;
			scanf("%d%d%d",&a,&b,&c); a--; b--;
			lis[a].emplace_back(c,b);
			lis[b].emplace_back(c,a);
			if (c>=0) {
				tis[a].emplace_back(parity(c),b);
				tis[b].emplace_back(parity(c),a);
			}
		}
		for (int i=0;i<M;i++) {
			int a, b, c;
			scanf("%d%d%d",&a,&b,&c); a--; b--;
			tis[a].emplace_back(parity(c),b);
			tis[b].emplace_back(parity(c),a);
		}
		for (int i=0;i<N;i++) col[i] = -1;
		bool mang = false;
		for (int i=0;i<N;i++) {
			if (col[i]!=-1) continue;
			col[i] = 0;
			if (!dfs(i)) {
				mang = true;
				break;
			}
		}
		if (mang) puts("NO");
		else {
			puts("YES");
			for (int i=0;i<N;i++) {
				for (pii &e : lis[i]) {
					if (e.first==-1) {
						e.first = (col[i]^col[e.second]);
					}
					if (i<e.second) {
						printf("%d %d %d\n",i+1,e.second+1,e.first);
					}
				}
			}
		}
		for (int i=0;i<N;i++) {
			lis[i].clear();
			tis[i].clear();
		}
	}

	return 0;
}