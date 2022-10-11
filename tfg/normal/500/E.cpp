#include <iostream>
#include <vector>

const int me = 18;
const int ms = 200200;
const int INF = (int) 1e9 + 10;

int to[me][ms];
int cost[me][ms];

int main() {
	int n;
	std::cin >> n;
	std::vector<int> p(n + 1, INF), l(n + 1, INF);
	for(int i = 0; i < n; i++) {
		std::cin >> p[i] >> l[i];
	}
	std::vector<int> st(1, n);
	for(int i = n-1; i >= 0; i--) {
		while(p[i] + l[i] >= p[st.back()] + l[st.back()]) {
			st.pop_back();
		}
		to[0][i] = st.back();
		cost[0][i] = std::max(0, p[st.back()] - (p[i] + l[i]));
		//std::cout << "from " << i << " to " << to[0][i] << " with cost " << cost[0][i] << "\n";
		st.push_back(i);
	}
	to[0][n] = n;
	for(int i = 0; i+1 < me; i++) {
		for(int j = 0; j <= n; j++) {
			to[i+1][j] = to[i][to[i][j]];
			cost[i+1][j] = cost[i][j] + cost[i][to[i][j]];
			//std::cout << "to(" << i+1 << ", " << j << ") = " << to[i+1][j] << '\n';
		}
	}
	int m;
	std::cin >> m;
	while(m--) {
		int l, r;
		std::cin >> l >> r;
		l--;r--;
		int ans = 0;
		for(int i = me-1; i >= 0; i--) {
			if(to[i][l] <= r) {
				ans += cost[i][l];
				l = to[i][l];
			}
		}
		//std::cout << "ended in " << l << "\n";
		std::cout << ans << '\n';
	}
}