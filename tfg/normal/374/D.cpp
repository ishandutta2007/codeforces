#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <stack>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 1001000;

int tree[ms];

void upd(int x, int v) {
	for(; x < ms; x += x & -x) {
		tree[x] += v;
	}
}

int qry(int v) {
	int x = 0;
	for(int i = 21; i >= 0; i--) {
		int nxt = x | (1 << i);
		if(nxt < ms && tree[nxt] < v) {
			x = nxt;
			v -= tree[x];
		}
	}
	return x;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<int> a(m);
	for(int i = 0; i < m; i++) {
		std::cin >> a[i];
	}
	std::vector<int> b;
	int size = 0;
	for(int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		if(x >= 0) {
			b.push_back(x);
			upd(b.size(), 1);
			size++;
		} else {
			std::vector<int> d;
			for(auto v : a) {
				if(v > size) break;
				d.push_back(qry(v));
				b[d.back()] = -1;
			}
			for(auto v : d) {
				upd(v + 1, -1);
				size--;
			}
		}
	}
	std::vector<int> c;
	for(int i = 0; i < (int) b.size(); i++) {
		if(b[i] >= 0) {
			c.push_back(b[i]);
		}
	}
	if(c.size() == 0) {
		std::cout << "Poor stack!\n";
	}
	for(int i = 0; i < (int) c.size(); i++) {
		std::cout << c[i];
		if(i + 1 == c.size()) std::cout << '\n';
	}
}