#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N, M, K;
int A[100100], B[100100];

vector<pll> process(int N, int A[]) {
	vector<pll> res;
	for (int i=0;i<N;i++) {
		int x = A[i];
		while(x%K==0) {
			x/=K;
		}
		if (res.empty() || res.back().first!=x) {
			res.push_back({x,A[i]});
		} else {
			res.back().second += A[i];
		}
	}
	return res;
}

int main() {
	int t;

	scanf("%d",&t);
	while(t--) {
		scanf("%d%d",&N,&K);
		for (int i=0;i<N;i++) scanf("%d",&A[i]);
		scanf("%d",&M);
		for (int i=0;i<M;i++) scanf("%d",&B[i]);
		vector<pll> C = process(N,A), D = process(M,B);
		if (C==D) puts("Yes");
		else puts("No");
	}

	return 0;
}