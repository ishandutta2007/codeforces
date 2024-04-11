#include <iostream>

typedef long long ll;

const int ms = 200200;

ll t[ms];

int main() {
	ll n, m, a, d;
	std::cin >> n >> m >> a >> d;
	ll close = 0;
	ll cur = 1;
	ll ans = 0;
	for(int i = 0; i <= m; i++) {
		if(i < m) {
			std::cin >> t[i];
		} else if(t[i - 1] < a * n) {
			t[i] = a * n;
		} else {
			continue;
		}
		if(close >= t[i]) {
			continue;
		}
		cur = std::max(cur, close / a + 1);
		//std::cout << "on time " << t[i] << ", cur is " << cur * a << ", closed on " << close << "\n";
		if(cur > n || cur * a >= t[i]) {
			//std::cout << "taking it directly\n";
			ans++;
			close = t[i] + d;
			continue;
		}
		ll get = std::min(n, t[i] / a) - cur + 1;
		ll cyc = d / a + 1;
		ll skips = get / cyc;
		ans += skips;
		cur += skips * cyc;
		close = std::max(close, (cur - cyc) * a + d);
		//std::cout << "got " << get << ", cyc is " << cyc << ", skipped " << skips << "\n";
		if(cur <= n && cur * a < t[i]) {
			ans++;
			close = cur * a + d;
			//std::cout << "taking this on " << cur * a << "\n";
		}
		if(close >= t[i]) {
			//std::cout << "skipped\n";
			continue;
		}
		//std::cout << "needed to take\n";
		ans++;
		close = t[i] + d;
	}
	std::cout << ans << '\n';
}