#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;

int n, a, b, da, db;
vector<int> lis[100100];
int dep[100100];

void dfs(int here, int p) {
	dep[here] = (~p?dep[p]:-1)+1;
	for (int &there : lis[here]) {
		if (there!=p) dfs(there,here);
	}
}

int main() {
	int tt;

	scanf("%d",&tt);
	while(tt--) {
		scanf("%d%d%d%d%d",&n,&a,&b,&da,&db); a--; b--;
		for (int i=0;i<n-1;i++) {
			int a, b;
			scanf("%d%d",&a,&b);
			a--; b--;
			lis[a].push_back(b);
			lis[b].push_back(a);
		}
		dfs(a,-1);
		if (dep[b]<=da) {
			puts("Alice");
			for (int i=0;i<n;i++) lis[i].clear();
			continue;
		}
		int t = 0;
		for (int i=0;i<n;i++) {
			if (dep[t]<dep[i]) t=i;
		}
		dfs(t,-1);
		t=0;
		for (int i=0;i<n;i++) {
			if (dep[t]<dep[i]) t=i;
		}
		if (da*2>=db) {
			puts("Alice");
		}
		else {
			if (dep[t]<=2*da) {
				puts("Alice");
			}
			else {
				puts("Bob");
			}
		}
		for (int i=0;i<n;i++) lis[i].clear();
	}

	return 0;
}