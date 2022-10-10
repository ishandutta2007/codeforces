#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <set>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int MAGIC = 1010;

std::vector<int> go(const std::vector<int> &a, int p) {
	int n = (int) a.size();
	std::vector<int> b(n, 0);
	for(int i = 0; i < n; i++) {
		if(i == p) {
			b[(i+1)%n] += a[i];
		} else {
			b[(i+1)%n] += (a[i] + 1) / 2;
			b[(i+n-1)%n] += a[i] / 2;
		}
	}
	return b;
}

int n, k;
std::vector<std::pair<int, int>> qries;
int debug = -1;
std::vector<std::vector<int>> hist;

int nozoku(int t, int pos, int o) {
	int delta = (o - pos) % n;
	delta = (delta + n) % n;
	if(delta < MAGIC) {
		return hist[t][delta];
	} else if(n - delta < MAGIC) {
		return hist[t][(int) hist[t].size() - (n-delta)];
	} else {
		return k;
	}
};
int qry(int x) {
	assert((int) qries.size() < 1000);
	std::cout << "? " << x+1 << std::endl;
	int y;
	if(debug == -1) {
		std::cin >> y;
	} else {
		y = nozoku((int) qries.size(), debug, x);
		std::cout << y << std::endl;
		for(int delta = -30; delta <= 30; delta++) {
			std::cout << nozoku((int) qries.size(), debug, debug + delta) << (delta == 30 ? '\n' : ' ');
		}
	}
	qries.emplace_back(x, y);
	return y;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cin >> n >> k;
	//debug = rng() % n;
	int jump = (int) sqrt(n);
	hist.assign(1, std::vector<int>(std::min(n, 3 * MAGIC), k));
	for(int i = 1; i < 1000; i++) {
		hist.push_back(go(hist.back(), 0));
	}
	int st = rng() % n;
	for(int i = 0; qry((st + i * jump) % n) == k; i++);
	assert((int) qries.size() < 2*jump + 10);
	int center = qries.back().first;
	std::set<int> cands;
	for(int i = -MAGIC; i <= MAGIC; i++) {
		if(nozoku((int) qries.size() - 1, (i%n+center+n)%n, qries.back().first) == qries.back().second) {
			cands.insert((i%n+center+n)%n);
		}
	}
	while((int) cands.size() > 1) {
		assert((int) qries.size() < 1000);
		std::set<int> nxt;

		int haha = (center - 2 * (int) qries.size() % n + rng() % std::min(n, 4 * (int) qries.size() + 1) + n) % n;
		qry(haha);
		for(auto pos : cands) {
			if(nozoku((int) qries.size() - 1, pos, qries.back().first) == qries.back().second) {
				nxt.insert(pos);
			}
		}
		nxt.swap(cands);
		nxt.clear();
	}
	assert((int) cands.size() == 1);
	std::cout << "! " << *cands.begin()+1 << std::endl;
}