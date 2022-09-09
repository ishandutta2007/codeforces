#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int query(int x) {
	printf("? %d\n",x+1);
	fflush(stdout);
	int y;
	scanf("%d",&y);
	return y-1;
}

int N;
int p[10100];
int vis[10100];

int main() {
	int ttt;

	scanf("%d",&ttt);
	while(ttt--) {
		scanf("%d",&N);
		for (int i=0;i<N;i++) vis[i] = 0;
		for (int i=0;i<N;i++) {
			if (vis[i]) continue;
			vector<int> cyc;
			while(1) {
				int x = query(i);
				cyc.push_back(x);
				if (vis[x]) break;
				vis[x] = 1;
			}
			for (int j=0;j+1<cyc.size();j++) {
				p[cyc[j]] = cyc[j+1];
			}
		}
		printf("! ");
		for (int i=0;i<N;i++) {
			printf("%d ",p[i]+1);
		}
		puts("");
		fflush(stdout);
	}

	return 0;
}