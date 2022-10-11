#include <iostream>
#include <set>

typedef long long ll;

const int ms = 100100;
const ll MOD = 1e9 + 7;

ll n, d, x;

ll getNext() {
	x = (x * 37 + 10007) % MOD;
	return x;
}

int a[ms];
int b[ms];
int c[ms];
int ans[ms];

void init() {
	std::cin >> n >> d >> x;
	for(int i = 0; i < n; i++) {
		a[i] = i + 1;
	}
	for(int i = 0; i < n; i++) {
		std::swap(a[i], a[getNext() % (i + 1)]);
	}
	for(int i = 0; i < n; i++) {
		if(i < d) {
			b[i] = 1;
		} else {
			b[i] = 0;
		}
	}
	for(int i = 0; i < n; i++) {
		std::swap(b[i], b[getNext() % (i + 1)]);
	}
}

int main() {
	init();
	/*for(int i = 0; i < n; i++) {
		std::cout << a[i] << (i + 1 == n ? '\n' : ' ');
	}
	for(int i = 0; i < n; i++) {
		std::cout << b[i] << (i + 1 == n ? '\n' : ' ');
	}*/
	std::set<int> pos, gaps;
	for(int i = 0; i < n; i++) {
		pos.insert(i);
	}
	for(int i = 0; i < n; i++) {
		c[a[i]] = i;
	}
	for(int i = 0; i < n; i++) {
		if(b[i]) {
			gaps.insert(i);
		}
	}
	for(int i = n; i > 0; i--) {
		auto it = gaps.begin();
		while(it != gaps.end()) {
			auto it2 = pos.lower_bound(c[i] + *it);
			if(it2 == pos.end()) {
				break;
			}
			it = gaps.lower_bound(*it2 - c[i]);
			if(it == gaps.end()) {
				break;
			}
			if(*it + c[i] != *it2) {
				continue;
			}
			ans[*it2] = i;
			pos.erase(it2);
		}
	}
	for(int i = 0; i < n; i++) {
		printf("%i\n", ans[i]);
	}
}