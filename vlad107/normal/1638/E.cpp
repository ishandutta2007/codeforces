#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <chrono>
#include <random>
#include <bitset>
#include <functional>
#include <numeric>
#include <array>
#include <limits>
#include <stack>

using namespace std;

template<typename T>
struct FenwickTree {
  int size;
  vector<T> f;

  FenwickTree(int n) : size(n) {
    f.resize(n, T {});
  }

  void modify(int x, T val) {
    while (x < size) {
      f[x] += val;
      x |= x + 1;
    }
  }

  T sum(int x) {
    T res {};
    while (x >= 0) {
      res += f[x];
      x = (x & (x + 1)) - 1;
    }
    return res;
  }
};


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	
	vector<long long> totalAdd(n);

	map<int, int> pts;
	pts[0] = pts[n] = 0;
	FenwickTree<long long> fenw(n + 1);

	auto recolor = [&](int l, int r, int newCol) {
		auto it = pts.lower_bound(r);
		if (it->first != r) {
			pts[r] = prev(it)->second;
		}
		
		it = pts.lower_bound(l);
		if (it->first != l) {
			pts[l] = prev(it)->second;
		}

		it = pts.lower_bound(l);
		while (it->first < r) {
			int L = it->first;
			int oldCol = it->second;
			it = pts.erase(it);
			int R = it->first;

			fenw.modify(L, totalAdd[oldCol] - totalAdd[newCol]);
			fenw.modify(R, -(totalAdd[oldCol] - totalAdd[newCol]));
		}

		pts[l] = newCol;
	};

	for (int i = 0; i < q; i++) {
		string query;
		cin >> query;
		if (query == "Add") {
			int col, x;
			cin >> col >> x;
			--col;
			totalAdd[col] += x;
		} else if (query == "Color") {
			int l, r, col;
			cin >> l >> r >> col;
			--l; --r; --col;
			recolor(l, r + 1, col);
		} else if (query == "Query") {
			int x;
			cin >> x;
			--x;
			auto it = prev(pts.upper_bound(x));
			int col = it->second;
			long long res = fenw.sum(x) + totalAdd[col];
			cout << res << "\n";
		}
	}
	return 0;
}