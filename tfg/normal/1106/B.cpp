#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	const int ms = 1001000;
	std::vector<int> a(n), c(n);
	std::vector<std::vector<int> > hmm(ms);
	int pt1 = 0, pt2 = 0;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for(int i = 0; i < n; i++) {
		std::cin >> c[i];
		hmm[c[i]].push_back(i);
		//std::cout << i << " has (" << a[i] << ", " << c[i] << ")\n";
	}
	while(m--) {
		int t, d;
		std::cin >> t >> d;
		t--;
		int use = std::min(d, a[t]);
		a[t] -= use;
		d -= use;
		//std::cout << "using " << use << " from " << t << '\n';
		long long tot = (long long) use * c[t];
		while(d > 0 && pt1 < ms) {
			if(pt2 == hmm[pt1].size()) {
				pt2 = 0;
				pt1++;
				continue;
			}
			int use = std::min(a[hmm[pt1][pt2]], d);
			a[hmm[pt1][pt2]] -= use;
			d -= use;
			tot += (long long) use * pt1;
			if(d == 0) {
				break;
			}
			pt2++;
		}
		if(d > 0) tot = 0;
		std::cout << tot << '\n';
	}
}