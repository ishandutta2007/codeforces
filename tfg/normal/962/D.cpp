#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

const int ms = 200200;

bool del[ms];
long long val[ms];

int main() {
	std::map<long long, std::vector<int> > m;
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		int v;
		std::cin >> v;
		m[v].push_back(i);
	}
	for(auto a : m) {
		//std::cout << "on " << a.first << ", size is " << a.second.size() << '\n';
		auto v = a.second;
		std::sort(v.begin(), v.end());
		if(v.size() % 2 == 1) {
			val[v.back()] = a.first;
			v.pop_back();
		}
		for(int i = 0; i < v.size(); i += 2) {
			del[v[i]] = true;
			m[2 * a.first].push_back(v[i + 1]);
		}
	}
	std::vector<long long> ans;
	for(int i = 0; i < n; i++) {
		if(!del[i]) {
			ans.push_back(val[i]);
		}
	}
	std::cout << ans.size() << '\n';
	for(int i = 0; i < ans.size(); i++) {
		std::cout << ans[i] << (i + 1 == ans.size() ? '\n' : ' ');
	}
}