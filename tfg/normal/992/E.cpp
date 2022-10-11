#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,sse3,sse4,popcnt,abm,mmx")

#include <iostream>
#include <cstdio>
#include <vector>
#include <set>

int read() {
	int x = 0;
	int sign = 0;
	int c = getchar();
	for (; !isdigit(c); c = getchar()) {
		sign |= c == '-';
	}
	for (; isdigit(c); c = getchar()) {
		x = x * 10 + c - '0';
	}
	return sign ? -x : x;
}
void write(int x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x / 10) {
		write(x / 10);
	}
	putchar(x % 10 + '0');
}

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
private:
	int n;
	std::vector<T> bit;
};

int getGroup(int x) {
	return x == 0 ? 0 : 1 + getGroup(x / 2);
}

const int ms = 200200;
const int me = 33;
std::set<int> groups[me];
int base[ms];
int cands[me][2];
long long sum[me][2];
FenwickTree<long long> tree;

void reconstruct(int idx) {
	int i = 0;
	for(auto it = groups[idx].begin(); i < std::min(2, (int)groups[idx].size()); i++, it++) {
		cands[idx][i] = *it;
		sum[idx][i] = tree.qry(*it);
	}
};

int getAnswer(int idx) {
	for(int i = 0; i < std::min(2, (int)groups[idx].size()); i++) {
		if(base[cands[idx][i]] == sum[idx][i]) {
			return cands[idx][i] + 1;
		}
	}
	return -1;
};

int main() {
	//std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, q;
	std::cin >> n >> q;
	tree.init(n);
	for(int i = 0; i < n; i++) {
		//std::cin >> base[i];
		base[i] = read();
		tree.upd(i + 1, base[i]);
		groups[getGroup(base[i])].insert(i);
	}
	for(int i = 0; i < me; i++) {
		reconstruct(i);
	}
	while(q--) {
		int pos, v;
		//std::cin >> pos >> v;
		pos = read();
		v = read();
		pos--;
		int diff = v - base[pos];
		int a = getGroup(base[pos]);
		int b = getGroup(v);
		groups[a].erase(pos);
		base[pos] = v;
		groups[b].insert(pos);
		for(int i = 0; i < me; i++) {
			for(int j = 0; j < std::min(2, (int)groups[i].size()); j++) {
				if(pos < cands[i][j]) {
					sum[i][j] += diff;
				}
			}
		}
		tree.upd(pos + 1, diff);
		reconstruct(a);
		reconstruct(b);
		int ans = -1;
		for(int i = 0; i < me && ans == -1; i++) {
			ans = getAnswer(i);
		}
		write(ans);
		putchar('\n');
	}
}