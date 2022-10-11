#include <iostream>
#include <cstdio>
#include <vector>

const int ms = 300300;

int pairs[ms];
bool in[ms];

int main() {
	int n, m;
	std::cin >> n >> m;
	//std::cin >> m; n = 3e5;
	long long got = 0;
	int inc = 1;
	while(got <= m && inc <= n) {
		//std::cout << "with " << inc << " got " << pairs[inc] << '\n';
		got += pairs[inc];
		for(int i = inc + inc; i < ms; i += inc) {
			pairs[i]++;
		}
		in[inc] = true;
		inc++;
	}
	if(got < m) {
		std::cout << "No\n";
		return 0;
	}
	//std::cout << "got " << got << '\n';
	//std::cout << "inc is " << inc << '\n';
	std::vector<int> primes;
	for(int i = inc - 1; i * 2 >= inc && got != m; i--) {
		if(got - pairs[i] == m) {
			in[i] = false;
			got -= pairs[i];
		} else if(pairs[i] == 1) {
			primes.push_back(i);
		}
	}
	for(int i = inc - 1; i * 2 >= inc && got != m; i--) {
		if(pairs[i] == 1 || !in[i]) continue;
		if(got - pairs[i] >= m) {
			in[i] = false;
			got -= pairs[i];
		}
	}
	for(int i = inc - 1; i * 2 >= inc && got != m; i--) {
		if(pairs[i] == 1 || !in[i]) continue;
		if(got - pairs[i] >= m) {
			in[i] = false;
			got -= pairs[i];
		}
	}
	while(got > m && !primes.empty()) {
		got--;
		in[primes.back()] = false;
		primes.pop_back();
	}
	if(got == m) {
		std::cout << "Yes\n";
		std::vector<int> ans;
		for(int i = 1; i < inc; i++) {
			if(in[i]) {
				ans.push_back(i);
			}
		}
		std::cout << ans.size() << '\n';
		for(int i = 0; i < ans.size(); i++) {
			printf("%i%c", ans[i], i + 1 == ans.size() ? '\n' : ' ');
		}
	} else {
		std::cout << "No\n";
	}
}