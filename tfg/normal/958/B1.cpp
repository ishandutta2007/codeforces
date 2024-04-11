#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> G[1005];

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N-1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		G[a].push_back(b); G[b].push_back(a);
	}

	int cnt = 0;
	for (int i = 0; i++ < N; ) cnt += G[i].size() == 1;
	printf("%d\n", cnt);
}