#include <iostream>
#include <algorithm>
#include <set>
#include <utility>

typedef std::pair<int, int> ii;

int a[200200];
int ans[200200];



int main() {
	int n;
	std::cin >> n;
	std::set<ii> pts;
	std::set<int> inc;
	inc.insert(-1);
	inc.insert(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		pts.insert(ii(a[i], i));
	}
	for(auto pt : pts) {
		int idx = pt.second;
		inc.insert(idx);
		auto it = inc.lower_bound(idx);
		it--;
		int cur_ans = -*it;
		it++;
		it++;
		cur_ans += *it - 1;
		ans[cur_ans] = std::max(ans[cur_ans], pt.first);
	}
	for(int i = n - 1; i > 0; i--) {
		ans[i] = std::max(ans[i], ans[i + 1]);
	}
	for(int i = 1; i <= n; i++) {
		std::cout << ans[i] << (i == n ? '\n' : ' ');
	}
}