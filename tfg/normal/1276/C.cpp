#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

std::vector<std::pair<int, int>> generateFreq(std::vector<int> a) {
	std::sort(a.begin(), a.end());
	int n = (int) a.size();
	std::vector<std::pair<int, int>> ans;
	for(int l = 0, r = 0; l < n; l = r) {
		while(r < n && a[r] == a[l]) r++;
		ans.emplace_back(r - l, a[l]);
	}
	std::sort(ans.begin(), ans.end());
	return ans;
}

std::vector<std::pair<int, int>> generatePos(int n, int m) {
	std::vector<std::pair<int, int>> ans;
	int got = 0;
	int i = 0, j = 0;
	std::vector<bool> visit(n * m, false);
	while(got != n * m) {
		int id = i * m + j;
		if(visit[id]) {
			j = (j + 1) % m;
			id = i * m + j;
			assert(!visit[id]);
		} else {
			got++;
			visit[id] = true;
			//std::cout << "got " << i << ", " << j << std::endl;
			ans.emplace_back(i, j);
			i = (i + 1) % n;
			j = (j + 1) % m;
		}
	}
	return ans;
}

void solve(std::vector<std::pair<int, int>> freq, int n, int m) {
	std::reverse(freq.begin(), freq.end());
	std::vector<std::pair<int, int>> pos = generatePos(n, m);
	std::vector<int> a;
	for(auto p : freq) {
		int use = std::min(n, p.first);
		while(use--) {
			a.push_back(p.second);
		}
	}
	assert((int) a.size() >= n * m);
	std::vector<std::vector<int>> mat(n, std::vector<int>(m, -1));
	for(int i = 0; i < n * m; i++) {
		//std::cout << a[i] << ' ';
		mat[pos[i].first][pos[i].second] = a[i];
	}
	//std::cout << '\n';
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			std::cout << mat[i][j] << (j + 1 == m ? '\n' : ' ');
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<std::pair<int, int>> a;
	{
		std::vector<int> b(n);
		for(int i = 0; i < n; i++) {
			std::cin >> b[i];
		}
		a = generateFreq(b);
	}
	int ans = 0;
	int sizes[2] = {0, 0};
	for(int i = 1, j = 0, sum = 0; i <= n; i++) {
		while(j < (int) a.size() && a[j].first <= i) {
			sum += a[j++].first;
		}
		sum += ((int) a.size() - j) * i;
		int k = sum / i;
		if(k >= i && k * i > ans) {
			ans = k * i;
			sizes[0] = i;
			sizes[1] = k;
		}
		sum -= ((int) a.size() - j) * i;
	}
	std::cout << ans << '\n';
	std::cout << sizes[0] << ' ' << sizes[1] << '\n';
	solve(a, sizes[0], sizes[1]);
}