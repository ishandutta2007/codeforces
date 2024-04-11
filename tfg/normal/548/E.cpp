#include <iostream>
#include <vector>

typedef long long ll;

const int ms = 500500;

ll pairs[ms];
int group[ms], mob[ms];
std::vector<int> divs[ms];
int mode[ms];
int count[ms];
int a[ms];

int main() {
	for(int i = 2; i < ms; i++) {
		pairs[i] = pairs[i - 1] + i - 1;
	}
	for(int i = 1; i < ms; i++) {
		group[i] = 1;
		mob[i] = 1;
	}
	for(int i = 2; i < ms; i++) {
		if(group[i] != 1) {
			continue;
		}
		for(int j = i; j < ms; j += i) {
			group[j] *= i;
			mob[j] = -mob[j];
		}
	}
	for(int i = 1; i < ms; i++) {
		for(int j = i; j < ms; j += i) {
			if(group[j] == j) {
				divs[j].push_back(i);
			}
		}
	}
	int n, q;
	std::cin >> n >> q;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		a[i] = group[a[i]];
	}
	ll ans = 0;
	while(q--) {
		int p;
		std::cin >> p;
		p--;
		int diff = 1 - mode[p];
		mode[p] = 1 - mode[p];
		if(diff == 0) {
			diff = -1;
		}
		for(auto d : divs[a[p]]) {
			ans -= pairs[count[d]] * mob[d];
			count[d] += diff;
			ans += pairs[count[d]] * mob[d];
		}
		std::cout << ans << '\n';
	}
}