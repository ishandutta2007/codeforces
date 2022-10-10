#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <map>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int table[200200][22];
int pt[200200];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m, q;
	std::cin >> n >> m >> q;
	std::vector<int> a(n), r(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		a[i]--;
		r[a[i]] = i;
	}
	std::vector<int> b(m);
	for(int i = 0; i < m; i++) {
		std::cin >> b[i];
		b[i]--;
	}
	std::map<int, int> wut;
	int hue = 1e9;
	table[m][0] = m;
	for(int i = m-1; i >= 0; i--) {
		table[i][0] = m;
		if(wut.count(a[(r[b[i]]+1)%n])) {
			table[i][0] = wut[a[(r[b[i]]+1)%n]];
		}
		//std::cout << "(" << i << ", " << table[i][0] << ")\n";
		wut[b[i]] = i;
	}
	for(int i = 0; i + 1 < 22; i++) {
		for(int j = 0; j <= m; j++) {
			table[j][i+1] = table[table[j][i]][i];
		}
	}
	hue = 1e9;
	for(int i = m-1; i >= 0; i--) {
		int on = i;
		for(int j = 21; j >= 0; j--) {
			if((1 << j) & (n-1)) {
				on = table[on][j];
			}
		}
		//std::cout << "from " << i << " to " << on << "\n";
		hue = std::min(hue, on);
		pt[i] = hue;
	}
	while(q--) {
		int l, rr;
		std::cin >> l >> rr;
		std::cout << (pt[l-1] < rr ? '1' : '0');
	}
	std::cout << '\n';
}