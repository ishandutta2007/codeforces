#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <map>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

struct Merger {
	int operator() (int a, int b) { return gcd(a, b); }
};

template <class T, class Merger>
class SparseTable {
public:
	void init(std::vector<T> a) {
		int e = 0;
		int n = a.size();
		while((1 << e) / 2 < a.size()) {
			e++;
		}
		table.resize(e, std::vector<T>(n));
		get.assign(n + 1, -1);
		for(int i = 0; i < n; i++) {
			table[0][i] = a[i];
			get[i+1] = get[(i+1)/2] + 1;
		}
		for(int i = 0; i + 1 < e; i++) {
			for(int j = 0; j + (1 << i) < n; j++) {
				table[i+1][j] = merge(table[i][j], table[i][j + (1 << i)]);
			}
		}
	}
	
	T qry(int l, int r) {
		int e = get[r - l];
		return merge(table[e][l], table[e][r - (1 << e)]);
	}
private:
	std::vector<std::vector<T>> table;
	std::vector<int> get;
	Merger merge;
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	SparseTable<int, Merger> table;
	table.init(a);
	std::map<int, long long> memo;
	for(int i = 0; i < n; i++) {
		int l = i, r = n-1;
		while(l < n) {
			int start = l;
			int g = table.qry(i, l+1);
			while(l != r) {
				int mid = (l + r + 1) / 2;
				if(table.qry(i, mid+1) == g) {
					l = mid;
				} else {
					r = mid-1;
				}
			}
			memo[g] += r - start + 1;
			l = r + 1;
			r = n-1;
		}
	}
	int q;
	std::cin >> q;
	while(q--) {
		int x;
		std::cin >> x;
		std::cout << memo[x] << '\n';
	}
}