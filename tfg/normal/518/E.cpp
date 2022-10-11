#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

const int doubt = 0x3f3f3f3f;
const int INF = 2e9;

int readInt() {
	//if(rand() % 2 == 0) return doubt;
	//else return -1000 + rand() % 2000;
	std::string str;
	std::cin >> str;
	if(str == "?") {
		return doubt;
	}
	int ans = 0;
	for(int i = (str[0] == '-' ? 1 : 0); i < str.size(); i++) {
		ans = ans * 10 + str[i] - '0';
	}
	if(str[0] == '-') {
		ans = -ans;
	}
	return ans;
}

void solve(std::vector<int> &v) {
	for(int l = -1, r = -1; r < (int)v.size(); l = r) {
		//std::cout << "hallo\n";
		r++;
		while(r < v.size() && doubt == v[r]) {
			r++;
		}
		//std::cout << "trying range " << l << ", " << r << std::endl;
		if(r == l + 1) {
			if(r < v.size() && l >= 0 && v[l] >= v[r]) {
				v[l] = doubt;
				return;
			}
			continue;
		}
		long long left = (l == -1 ? -INF : v[l] + 1);
		long long right = (r == v.size() ? INF : v[r] - 1);
		if(right - left + 1 < r - l - 1) {
			return;
		}
		//std::cout << "on range (" << l << ", " << r << ") got (" << left << ", " << right << ")\n";
		right -= r - l - 2;
		long long perfect = -((r - l - 1) / 2);
		//std::cout << "on range (" << l << ", " << r << ") got (" << left << ", " << right << ")\n";
		//std::cout << "perfect is " << perfect << std::endl;
		if(left <= perfect && perfect <= right) {
			left = perfect;
		} else if(right < perfect) {
			left = right;
		}
		//left = right;
		for(int j = l + 1; j < r; j++) {
			v[j] = left + (j - l - 1);
		}
	}
}

int main() {
	srand(time(0));
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	std::vector<std::vector<int>> sequences(k);
	for(int i = 0; i < n; i++) {
		sequences[i % k].push_back(readInt());
		//std::cout << sequences[i % k][i / k] << (i + 1 == n ? '\n' : ' ');
	}
	long long sum = 0;
	for(int i = 0; i < k; i++) {
		//std::cout << "calling for sequence " << i << std::endl;
		solve(sequences[i]);
		for(auto v : sequences[i]) {
			if(v == doubt) {
				std::cout << "Incorrect sequence\n";
				return 0;
			}
		}
	}
	for(int i = 0; i < n; i++) {
		std::cout << sequences[i % k][i / k] << (i + 1 == n ? '\n' : ' ');
	}
}