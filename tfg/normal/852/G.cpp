#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int c = 1;
int to[100100 * 50][5];
int freq[100100 * 50];
int step[100100 * 50], curStep = 0;

void add(const std::string &str) {
	int on = 0;
	for(auto ch : str) {
		if(to[on][ch - 'a'] == 0) {
			to[on][ch - 'a'] = c++;
		}
		on = to[on][ch - 'a'];
	}
	freq[on]++;
}

int qry(const std::string &str, int on, int i) {
	int ans = 0;
	if(i == (int) str.size()) {
		if(step[on] != curStep) {
			step[on] = curStep;
			ans += freq[on];
		}
	} else if(str[i] == '?') {
		for(int j = 0; j < 5; j++) {
			if(to[on][j]) ans += qry(str, to[on][j], i + 1);
		}
		ans += qry(str, on, i + 1);
	} else {
		if(to[on][str[i] - 'a']) ans += qry(str, to[on][str[i] - 'a'], i + 1);
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	while(n--) {
		std::string str;
		std::cin >> str;
		add(str);
	}
	while(m--) {
		std::string str;
		std::cin >> str;
		curStep++;
		std::cout << qry(str, 0, 0) << '\n';
	}
}