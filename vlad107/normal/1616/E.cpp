#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

template<typename T>
struct FenwickTree {
  int size;
  vector<T> f;

  FenwickTree(int n) : size(n) {
    f.resize(n, T {});
  }

  void add(int x, T val) {
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
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		string s, t;
		cin >> s;
		cin >> t;
		string sSorted = s;
		sort(sSorted.begin(), sSorted.end());
		if (sSorted >= t) {
			cout << "-1\n";
			continue;
		}
		
		vector<queue<int>> pos(26);
		for (int i = 0; i < n; i++) pos[s[i] - 'a'].push(i);

		FenwickTree<int> fenwick(n);

		for (int i = 0; i < n; i++) fenwick.add(i, +1);

		long long curAns = 0;
		long long minAns = n * 1LL * n;
		for (int i = 0; i < n; i++) {
			int j = n + 1;
			for (int x = 0; x < t[i]-'a'; x++) {
				if (!pos[x].empty()) j = min(fenwick.sum(pos[x].front() - 1), j);
			}
			if (j != n + 1) {
				minAns = min(minAns, curAns + j);
			}
			int x = t[i] - 'a';
			if (pos[x].empty()) break;
			int realPos = fenwick.sum(pos[x].front() - 1);
			curAns += realPos;
			fenwick.add(pos[x].front(), -1);
			pos[x].pop();
		}
		cout << minAns << "\n";
	}
	return 0;
}