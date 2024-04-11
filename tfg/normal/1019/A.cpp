#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

const int ms = 3030;

int size[ms];
int n, m;
int val[ms], id[ms][ms];
int perm[ms];
int inv[ms];

template <class T>
class FenwickTree {
public:
	void init(int n) {
		this->n = n;
		bit.assign(n + 1, 0);
	}

	void init(const std::vector<T> &a) {
		n = a.size();
		bit.assign(n + 1, 0);
		for(int i = 1; i <= n; i++) {
			bit[i] += a[i - 1];
			if(i + (i & -i) <= n) {
				bit[i + (i & -i)] += bit[i];
			}
		}
	}

	T qry(int x) {
		x = std::min(x, (int)bit.size() - 1);
		T ans = 0;
		for(; x > 0; x -= x & -x) {
			ans += bit[x];
		}
		return ans;
	}

	void upd(int x, T v) {
		if(x <= 0) return;
		for(; x <= n; x += x & -x) {
			bit[x] += v;
		}
	}

	int search(int f) {
		int ans = 0;
		for(int i = 18; i >= 0; i--) {
			int nxt = ans | (1 << i);
			if(nxt < bit.size() && f - bit[nxt] > 0) {
				ans = nxt;
				f -= bit[nxt];
			}
		}
		return ans + 1;
	}
private:
	int n;
	std::vector<T> bit;
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cin >> n >> m;
	for(int i = 0; i < n; i++) {
		int p, c;
		std::cin >> p >> c;
		p--;
		if(p == 0) {
			size[0]++;
			n--;
			i--;
			continue;
		}
		id[p][size[p]++] = i;
		val[i] = c;
		perm[i] = i;
	}
	std::sort(perm, perm + n, [](int a, int b) { return val[a] < val[b]; });
	for(int i = 1; i < m; i++) {
		std::sort(id[i], id[i] + size[i], [](int a, int b) { return val[a] > val[b]; });
	}
	for(int i = 0; i < n; i++) {
		inv[perm[i]] = i;
	}
	FenwickTree<long long> tree;
	FenwickTree<int> freq;
	tree.init(n);
	freq.init(n);
	for(int i = 0; i < n; i++) {
		tree.upd(i + 1, val[perm[i]]);
		freq.upd(i + 1, 1);
	}
	long long all = 0;
	int got = size[0];
	long long ans = 1e18;
	for(int i = n; i >= 0; i--) {
		for(int j = 1; j < m; j++) {
			if(i < size[j]) {
				//std::cout << "on " << i << ", adding value " << val[id[j][i]] << std::endl;
				all += val[id[j][i]];
				tree.upd(inv[id[j][i]] + 1, -val[id[j][i]]);
				freq.upd(inv[id[j][i]] + 1, -1);
				got++;
			}
		}
		if(got > i) {
			ans = std::min(ans, all);
			break;
		}
		int idx = freq.search(i - got + 1);
		//std::cout << "on " << i << ", got is " << got << " idx is " << idx << std::endl;
		ans = std::min(ans, all + tree.qry(idx));
		//std::cout << "all is " << all << ", rest is " << tree.qry(idx) << std::endl;
	}
	std::cout << ans << std::endl;
}