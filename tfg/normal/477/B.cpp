#include <iostream>
#include <vector>
#include <set>

const int ms = 100100;

int gcd(int a, int b) {
	if(!b) {
		return a;
	} else {
		return gcd(b, a % b);
	}
}

int everything;

bool got[ms];

bool test(int x, std::vector<int> cur) {
	for(auto a : cur) {
		if(gcd(x, a) != 1) {
			return false;
		}
	}
	return true;
}

std::vector<std::vector<int> > solve(int n) {
	std::vector<std::vector<int> > ans, partial;
	/*for(int i = 1; ans.size() < n; i++) {
		bool got = false;
		if(!(i % 2 == 0 && i != 2)) {
			for(int j = 0; j < partial.size(); j++) {
				bool can = true;
				for(int k = 0; k < partial[j].size(); k++) {
					can = can && gcd(i, partial[j][k]) == 1;
				}
				if(can) {
					partial[j].push_back(i);
					got = true;
					if(partial[j].size() == 4) {
						ans.push_back(partial[j]);
						partial.back().swap(partial[j]);
						partial.pop_back();
					}
					break;
				}
			}
		}
		if(!got) {
			partial.emplace_back(1, i);
		}
		// std::cout << partial.size() << '\n';
		everything = i;
	}*/
	/*std::set<int> nums;
	for(int i = 1; i < ms; i++) {
		nums.insert(i);
	}
	for(int i = 1; ans.size() < n;) {
		while(got[i]) {
			i = *nums.lower_bound(i);
		}
		std::vector<int> cur;
		int j = i;
		while(cur.size() != 4) {
			while(got[j]) {
				j = *nums.lower_bound(j);
			}
			if(test(j, cur)) {
				cur.emplace_back(j);
				got[j] = true;
				everything = j;
				nums.erase(j);
			}
			j++;
		}
		ans.push_back(cur);
	}*/
	for(int i = 0; ans.size() < n; i += 6) {
		std::vector<int> cur;
		cur.push_back(i + 1);
		cur.push_back(i + 2);
		cur.push_back(i + 3);
		cur.push_back(i + 5);
		ans.push_back(cur);
		everything = i + 5;
	}
	return ans;
}

int main() {
	int n, k;
	std::cin >> n >> k;
	auto v = solve(n);
	std::cout << everything * k << '\n';
	for(int i = 0; i < n; i++) {
		for(int j = 0;  j < 4; j++) {
			std::cout << v[i][j] * k << (j == 3 ? '\n' : ' ');
		}
	}
}