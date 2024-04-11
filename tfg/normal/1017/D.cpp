#include <iostream>
#include <cstdio>
#include <vector>

int ans[1 << 12][102];
int n, m, q;
char buffer[20];

int readVal() {
	scanf(" %s", buffer);
	int hmm = 0;
	for(int i = 0; i < n; i++) {
		hmm = (hmm << 1) + buffer[i] - '0';
	}
	return hmm;
}

int main() {
	//std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cin >> n >> m >> q;
	std::vector<int> base(n);
	for(int i = 0; i < n; i++) {
		//std::cin >> base[i];
		scanf("%d", &base[i]);
	}
	int mm = 1 << n;
	std::vector<int> cost(mm, 0);
	for(int i = 0; i < mm; i++) {
		for(int j = 0; j < n; j++) {
			if((i >> j) % 2 == 0) {
				cost[i] += base[n - j - 1];
			}
		}
		cost[i] = std::min(cost[i], 101);
	}
	std::vector<int> freq(mm, 0);
	for(int i = 0; i < m; i++) {
		int v = readVal();
		freq[v]++;
	}
	for(int i = 0; i < mm; i++) {
		for(int j = 0; j < mm; j++) {
			ans[i][cost[i ^ j]] += freq[j];
		}
		for(int j = 1; j <= 100; j++) {
			ans[i][j] += ans[i][j - 1];
		}
	}
	for(int i = 0; i < q; i++) {
		int v = readVal();
		int k;
		//std::cin >> k;
		scanf("%d", &k);
		printf("%d\n", ans[v][k]);
	}
}