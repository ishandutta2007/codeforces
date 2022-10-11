#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

typedef std::pair<int, int> ii;
typedef std::pair<int, ii> i3;

ii ans1(-1, -1);
ii ans2(-1, -1);

std::vector<i3> elems[200200];

std::vector<i3> solve(int l, int r) {
	if(l == r) {
		std::sort(elems[l].begin(), elems[l].end());
		return elems[l];
	}
	int mid = (l + r) / 2;
	std::vector<i3> left, right, ret;
	left = solve(l, mid);
	right = solve(mid + 1, r);
	ret.resize(left.size() + right.size());
	for(int i = 0, j = 0; i < left.size() && j < right.size();) {
		if(left[i].first == right[j].first) {
			ans1 = left[i].second;
			ans2 = right[j].second;
			break;
		}
		if(left[i] < right[j]) {
			i++;
		} else {
			j++;
		}
	}
	std::merge(left.begin(), left.end(), right.begin(), right.end(), ret.begin());
	return ret;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		int s;
		std::cin >> s;
		int sum = 0;
		elems[i].resize(s);
		for(int j = 0; j < s; j++) {
			std::cin >> elems[i][j].first;
			sum += elems[i][j].first;
			elems[i][j].second = ii(i + 1, j + 1);
		}
		for(int j = 0; j < s; j++) {
			elems[i][j].first = sum - elems[i][j].first;
		}
	}
	solve(0, n - 1);
	if(ans1 == ii(-1, -1)) {
		std::cout << "NO\n";
	} else{
		std::cout << "YES\n";
		std::cout << ans1.first << ' ' << ans1.second << '\n' << ans2.first << ' ' << ans2.second << std::endl;
	}
}