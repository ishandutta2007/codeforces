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
vector<int> lis[100100];
int A[100100];

void dfs(int here, int p, int d) {
	if (d) A[here] = lis[here].size();
	else A[here] = -((int)lis[here].size());
	for (int &there : lis[here]) {
		if (there==p) continue;
		dfs(there, here, d^1);
	}
}

int main() {
	int T;

	scanf("%d",&T);
	while(T--) {
		scanf("%d",&N);
		for (int i=0;i<N-1;i++) {
			int a, b;
			scanf("%d%d",&a,&b); --a; --b;
			lis[a].push_back(b);
			lis[b].push_back(a);
		}
		dfs(0,-1,0);
		for (int i=0;i<N;i++) printf("%d ",A[i]);
		puts("");
		for (int i=0;i<N;i++) lis[i].clear();
	}

	return 0;
}