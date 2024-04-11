#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N, M;
int ans;
set<int> se[200100];

int getv(int i) {
	return (se[i].empty()||*prev(se[i].end())<i);
}

int main() {
	scanf("%d%d",&N,&M);
	for (int i=0;i<M;i++) {
		int a, b;
		scanf("%d%d",&a,&b); a--; b--;
		se[a].insert(b);
		se[b].insert(a);
	}
	for (int i=0;i<N;i++) {
		ans += getv(i);
	}
	int Q;
	scanf("%d",&Q);
	for (int i=0;i<Q;i++) {
		int t;
		scanf("%d",&t);
		if (t==1) {
			int a, b;
			scanf("%d%d",&a,&b); --a; --b;
			ans -= getv(a)+getv(b);
			se[a].insert(b);
			se[b].insert(a);
			ans += getv(a)+getv(b);
		}
		else if (t==2) {
			int a, b;
			scanf("%d%d",&a,&b); --a; --b;
			ans -= getv(a)+getv(b);
			se[a].erase(b);
			se[b].erase(a);
			ans += getv(a)+getv(b);
		}
		else {
			printf("%d\n",ans);
		}
	}

	return 0;
}