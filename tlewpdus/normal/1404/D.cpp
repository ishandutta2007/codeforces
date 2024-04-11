#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;

int N;
int p[2][1000100];
vector<int> lis[1000100];
int vis[1000100];

int main() {
	scanf("%d",&N);
	if (N%2==0) {
		puts("First");
		for (int i=0;i<2*N;i++) {
			printf("%d ",i%N+1);
		}
		puts("");
		fflush(stdout);
		return 0;
	}
	else {
		for (int i=0;i<N;i++) {
			p[0][i] = i+N;
			p[0][i+N] = i;
		}
		puts("Second"); fflush(stdout);
		for (int i=0;i<2*N;i++) {
			int a;
			scanf("%d",&a);
			lis[a-1].push_back(i);
		}
		for (int i=0;i<N;i++) {
			p[1][lis[i][0]] = lis[i][1];
			p[1][lis[i][1]] = lis[i][0];
		}
		ll sum = 0;
		int locs = 0, loce = 0;
		vector<int> ans;
		for (int i=0;i<2*N;i++) {
			if (vis[i]) continue;
			int cnt = 0;
			int q = i;
			int ts = ans.size();
			do {
				ans.push_back(q);
				sum += q+1;
				vis[q] = 1;
				q = p[0][q];
				vis[q] = 1;
				q = p[1][q];
				cnt++;
			} while(!vis[q]);
			if (cnt%2) {
				locs = ts;
				loce = ans.size();
			}
		}
		if (sum%(2*N)==N) {
			for (int i=locs;i<loce;i++) {
				ans[i] = p[0][ans[i]];
			}
		}
		for (int &v : ans) printf("%d ",v+1);
		puts("");
		fflush(stdout);
	}

	return 0;
}