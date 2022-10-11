#include <iostream>
#include <vector>

typedef long long ll;

int step[1001000];
ll get_pos(ll size, ll cyc, ll pos) {
	if(pos < size) {
		return pos;
	}
	pos -= cyc;
	pos %= size - cyc;
	pos += cyc;
	return pos;
}

int main() {
	ll m, h[2], a[2], x[2], y[2];
	ll pos[2];
	std::cin >> m;
	std::vector<ll> cyc[2];
	ll cyc_pos[2];
	for(int i = 0; i < 2; i++) {
		std::cin >> h[i] >> a[i] >> x[i] >> y[i];
	}
	for(int i = 0; i < 2; i++) {
		ll nxt = h[i];
		while(step[nxt] != i + 1) {
			step[nxt] = i + 1;
			cyc[i].push_back(nxt);
			nxt = (x[i] * nxt + y[i]) % m;
		}
		for(int j = 0; j <= cyc[i].size(); j++) {
			if(j == cyc[i].size()) {
				std::cout << "-1\n";
				return 0;
			} else if(cyc[i][j] == a[i]) {
				pos[i] = j;
				break;
			}
		}
		for(int j = 0; j < cyc[i].size(); j++) {
			if(cyc[i][j] == nxt) {
				cyc_pos[i] = j;
			}
		}
	}
	if(cyc_pos[0] > pos[0]) {
		ll cur = pos[0];
		cur = get_pos(cyc[1].size(), cyc_pos[1], cur);
		if(cyc[1][cur] == a[1]) {
			std::cout << pos[0] << '\n';
		} else {
			std::cout << "-1\n";
		}
		return 0;
	}
	for(ll i = 0; i <= 1e7; i++) {
		ll cur = pos[0] + (cyc[0].size() - cyc_pos[0]) * i;
		cur = get_pos(cyc[1].size(), cyc_pos[1], cur);
		if(cyc[1][cur] == a[1]) {
			std::cout << pos[0] + (cyc[0].size() - cyc_pos[0]) * i << '\n';
			return 0;
		}
	}
	std::cout << "-1\n";
}