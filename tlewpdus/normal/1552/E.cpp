#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1000000007;

int N, K;
vector<int> loc[110];
int A[10100];

pii ans[110];
int C[110];
void solve(int s, int e) {
	for (int t=0;t<=e-s;t++) {
		int mini = -1;
		for (int i = s; i <= e; i++) {
			if (C[i]) continue;
			if (mini==-1||loc[mini][t+1]>loc[i][t+1]) {
				mini = i;
			}
		}
		C[mini] = 1;
		ans[mini] = {loc[mini][t],loc[mini][t+1]};
	}
}

int main() {
	scanf("%d%d",&N,&K);
	for (int i=0;i<N*K;i++) {
		scanf("%d",&A[i]); A[i]--;
		loc[A[i]].push_back(i);
	}
	for (int i=0;i<N;i+=K-1) {
		int s = i, e = min(i+K-2,N-1);
		solve(s,e);
	}
	for (int i=0;i<N;i++) {
		printf("%d %d\n",ans[i].first+1,ans[i].second+1);
	}

	return 0;
}