#include <iostream>
#include <vector>

typedef long long ll;

const int ms = 14;

ll cost(std::vector<ll> stones, int pos) {
	ll got = stones[pos];
	if(got == 0) return 0;
	stones[pos] = 0;
	ll ans = 0;
	ll all = got / 14;
	got %= 14;
	for(int i = 1; i <= got; i++) {
		stones[(pos + i) % 14]++;
	}
	for(int i = 0; i < 14; i++) {
		stones[i] += all;
	}
	for(int i = 0; i < 14; i++) {
		if(stones[i] % 2 == 0)
		ans += stones[i];
	}
	/*std::cout << "for pos " << pos << ", got " << ans << std::endl;
	for(int i = 0; i < 14; i++) {
		std::cout << stones[i] << ' ';
	}
	std::cout << std::endl;*/
	return ans;
}

int main() {
	std::vector<ll> stones(ms);
	for(int i = 0; i < ms; i++) {
		std::cin >> stones[i];
	}
	ll ans = 0;
	for(int i = 0; i < ms; i++) {
		ans = std::max(ans, cost(stones, i));
	}
	std::cout << ans << std::endl;
}