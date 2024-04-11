#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

typedef long long ll;

const int me = 64;

ll shifts[me], values[me];

int get_height(ll x) {
	if(x <= 1) return 0;
	else return 1 + get_height(x / 2);
}

int main() {
	int q;
	std::cin >> q;
	while(q--) {
		int t;
		ll x;
		scanf("%d %lld", &t, &x);
		int h = get_height(x);
		if(t == 2) {
			ll s;
			scanf("%lld", &s);
			s = -s;
			s %= (1LL << h);
			s += (1LL << h);
			s %= (1LL << h);
			for(; h < me; h++, s = s + s) {
				s = (s % (1LL << h) + (1LL << h)) % (1LL << h);
				shifts[h] = (shifts[h] + s) % (1LL << h);
			}
		} else if(t == 1) {
			ll s;
			scanf("%lld", &s);
			s = -s;
			s %= (1LL << h);
			s += (1LL << h);
			s %= (1LL << h);
			s = (s % (1LL << h) + (1LL << h)) % (1LL << h);
			shifts[h] = (shifts[h] + s) % (1LL << h);
		} else {
			std::vector<ll> ans;
			x = (1LL << h) + (x - shifts[h] + (1LL << h)) % (1LL << h);
			do {
				ans.push_back((x + shifts[h]) % (1LL << h) + (1LL << h));
				h--;
				x /= 2;
			} while(x > 0);
			for(int i = 0; i < ans.size(); i++) {
				printf("%lld%c", ans[i], i + 1 == ans.size() ? '\n' : ' ');
			}
		}
		/*for(int i = 1; i < 50; i++) {
			int he = get_height(i);
			if(he != get_height(i - 1)) std::cout << '\n';
			std::cout << (1 << he) + (i + shifts[he]) % (1 << he) << ' ';
		}
		std::cout << '\n';*/
	}
}