#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <stack>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	long long ans = 0;
	std::stack<std::pair<int, int>> st;
	auto getCost = [&](int f, int id) {
		if(f <= 0) return 0LL;
		id -= f - 1;
		if(st.empty()) return (long long) f * (f + 1) / 2 + (long long) f * id;
		assert(st.top().first > f && st.top().second < id);
		int id2 = st.top().second - (f - 1);
		return (long long) f * (id - id2);
	};
	long long sum = 0;
	int f = 0;
	int n;
	std::string str;
	std::cin >> n >> str;
	int id = 0;
	for(auto ch : str) {
		if(ch == '0') {
			f = 0;
		} else {
			f++;
			while(!st.empty() && st.top().first <= f) {
				auto got = st.top();
				//std::cout << "popping " << st.top().first << ", " << st.top().second << "\n";
				st.pop();
				sum -= getCost(got.first, got.second);
			}
			sum += getCost(f, id);
			st.push({f, id});
			//std::cout << "pushing " << st.top().first << ", " << st.top().second << "\n";
		}
		//std::cout << "at " << id << " got sum " << sum << '\n';
		ans += sum;
		id++;
	}
	std::cout << ans << '\n';
}