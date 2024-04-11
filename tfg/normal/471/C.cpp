#include <iostream>

typedef long long ll;

const int ms = 1e6;

ll cards[ms];

int main() {
	for(int i = 1; i < ms; i++) {
		cards[i] = cards[i - 1] + (i - 1) * 3LL + 2;
	}
	ll n;
	std::cin >> n;
	int ans = 0;
	for(int i = 1; cards[i] <= n; i++) {
		//std::cout << cards[i] << '\n';
		if(cards[i] % 3 == n % 3 && (cards[i] + 3 == n || cards[i] + 5 <= n || cards[i] == n)) {
			ans++;
		}
	}
	std::cout << ans << '\n';
}