#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <queue>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<std::pair<int, int>> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i].first;
	}
	for(int i = 0; i < n; i++) {
		std::cin >> a[i].second;
	}
	std::sort(a.begin(), a.end());
	std::priority_queue<int> hp;
	long long sum = 0;
	int t = -1;
	long long ans = 0;
	for(int i = 0; !hp.empty() || i < (int) a.size(); ) {
		if(i == (int) a.size() || (!hp.empty() && t < a[i].first)) {
			sum -= hp.top();
			hp.pop();
			ans += sum;
			t++;
		} else {
			assert(i < (int) a.size() && (hp.empty() || t == a[i].first));
			t = a[i].first;
			while(i < (int) a.size() && a[i].first == t) {
				hp.push(a[i].second);
				sum += a[i].second;
				i++;
			}
			sum -= hp.top();
			hp.pop();
			ans += sum;
			t++;
		}
	}
	std::cout << ans << '\n';
}