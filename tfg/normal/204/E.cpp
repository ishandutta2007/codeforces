#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

template <class T>
class SuffixArray {
public:
	std::vector<int> buildSuffix(const std::vector<T> &array) {
		int n = array.size();
		std::vector<int> sa(n);
		for(int i = 0; i < n; i++) {
			sa[i] = i;
		}
		std::sort(sa.begin(), sa.end(), [&](int a, int b) { return array[a] < array[b]; });
		int cur = 0;
		std::vector<int> inv(n);
		std::vector<int> nxt(n);
		inv[sa[0]] = 0;
		for(int i = 1; i < n; i++) {
			inv[sa[i]] = (array[sa[i - 1]] != array[sa[i]] ? ++cur : cur);
		}
		cur++;
		for(int k = 0; cur < n; k++) {
			cur = 0;
			auxSort(sa, inv, 1 << k);
			for(int l = 0, r = 0; l < n; l = r, cur++) {
				while(r < n && getPair(inv, sa[l], 1 << k) == getPair(inv, sa[r], 1 << k)) {
					nxt[sa[r++]] = cur;
				}
			}
			nxt.swap(inv);
		}
		return sa;
	}

	std::vector<int> buildLCP(const std::vector<int> &sa, const std::vector<T> &array) {
		int n = sa.size();
		std::vector<int> inv(n);
		for(int i = 0; i < n; i++) {
			inv[sa[i]] = i;
		}
		std::vector<int> lcp(n, 0);
		for(int i = 0, k = 0; i < n; i++) {
			if(inv[i] + 1 == n) {
				k = 0;
				continue;
			}
			int j = sa[inv[i] + 1];
			while(i + k < n && j + k < n && array[i + k] == array[j + k]) {
				k++;
			}
			lcp[inv[i]] = k;
			if(k > 0) {
				k--;
			}
		}
		return lcp;
	}
private:
	void auxSort(std::vector<int> &sa, const std::vector<int> &inv, int offset) {
		// O(nlogn) step, O(nlog^2n) total
		std::sort(sa.begin(), sa.end(), [&](int a, int b) { return getPair(inv, a, offset) < getPair(inv, b, offset); });
		// O(n) step, O(nlogn) total -- TO DO --
	}
	std::pair<int, int> getPair(const std::vector<int> &inv, int pos, int offset) {
		return std::pair<int, int>(inv[pos], pos + offset < (int) inv.size() ? inv[pos + offset] : -1);
	}
};

struct Merger {
	int operator() (int a, int b) { return std::min(a, b); }
};

template <class T, class Merger>
class SparseTable {
public:
	void init(std::vector<T> a) {
		int e = 0;
		int n = a.size();
		while((1 << e) / 2 < (int) a.size()) {
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
		if(l < 0 || r > (int) table[0].size()) {
			return -1;
		}
		if(l == r) return 1e9;
		int e = get[r - l];
		return merge(table[e][l], table[e][r - (1 << e)]);
	}
private:
	std::vector<std::vector<T>> table;
	std::vector<int> get;
	Merger merge;
};

struct Node {
	Node *left, *right;
	int sum;

	Node(int v = 0) {
		sum = v;
		left = right = this;
	}
};

Node* upd(Node* tree, int pos, int val, int l = 0, int r = 2e5 + 1) {
	if(l + 1 == r) {
		return new Node(tree->sum + val);
	} else {
		int mid = (l + r) / 2;
		Node* ans = new Node();
		if(pos < mid) {
			ans->left = upd(tree->left, pos, val, l, mid);
			ans->right = tree->right;
		} else {
			ans->left = tree->left;
			ans->right = upd(tree->right, pos, val, mid, r);
		}
		ans->sum = ans->left->sum + ans->right->sum;
		return ans;
	}
}

int qry(Node* tree, int pos, int l = 0, int r = 2e5 + 1) {
	if(l + 1 == r) {
		return tree->sum;
	} else {
		int mid = (l + r) / 2;
		if(pos < mid) {
			return qry(tree->left, pos, l, mid);
		} else {
			return tree->left->sum + qry(tree->right, pos, mid, r);
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	std::vector<std::string> strs(n);
	std::vector<int> arr, pos, start;
	for(int i = 0; i < n; i++) {
		std::cin >> strs[i];
		start.push_back((int) arr.size());
		for(auto c : strs[i]) {
			arr.push_back(c);
			pos.push_back(i);
		}
		arr.push_back(-(i+1));
		pos.push_back(-1);
	}
	SuffixArray<int> builder;
	auto sa = builder.buildSuffix(arr);
	SparseTable<int, Merger> table;
	table.init(builder.buildLCP(sa, arr));
	Node* root = new Node(0);
	std::vector<std::vector<int>> positions(n);
	for(int i = (int) sa.size()-1; i >= 0; i--) {
		if(pos[sa[i]] != -1) {
			positions[pos[sa[i]]].push_back(i);
		}
	}
	for(int i = 0; i < n; i++) {
		root = upd(root, positions[i].back(), 1);
	}
	std::vector<Node*> roots((int) sa.size()+1, NULL);
	roots[0] = root;
	for(int i = 0; i < (int) sa.size(); i++) {
		if(pos[sa[i]] != -1) {
			int id = pos[sa[i]];
			root = upd(root, positions[id].back(), -1);
			positions[id].pop_back();
			if(!positions[id].empty()) {
				root = upd(root, positions[id].back(), 1);
			}
		}
		roots[i+1] = root;
	}
	auto getRange = [&](int &l, int &r, int x) {
		for(int i = (1 << 18); i > 0; i /= 2) {
			if(table.qry(l, r + i) >= x) {
				r += i;
			}
			if(table.qry(l - i, r) >= x) {
				l -= i;
			}
		}
	};
	auto check = [&](int x, int i) {
		int l = i, r = i;
		getRange(l, r, x);
		//std::cout << "for " << i << ", " << x << " got range [" << l << ", " << r << "]\n";
		//std::cout << "answer for query is " << qry(roots[l], r) << '\n';
		return qry(roots[l], r) >= k;
	};
	std::vector<long long> ans(n, 0);
	/*for(int i = 0; i < (int) sa.size(); i++) {
		int id = pos[sa[i]];
		if(id == -1) continue;
		int len = (start[id] + (int) strs[id].size()) - sa[i];
		//std::cout << i << ": " << strs[id].substr(sa[i] - start[id], len) << '\n';
	}*/
	for(int i = 0; i < (int) sa.size(); i++) {
		int id = pos[sa[i]];
		if(id == -1) continue;
		//if(id != 2) continue;
		int len = (start[id] + (int) strs[id].size()) - sa[i];
		//std::cout << "query for " << strs[id].substr(sa[i] - start[id], len) << '\n';
		int l = 0, r = len;
		while(l != r) {
			int mid = (l + r + 1) / 2;
			if(check(mid, i)) {
				l = mid;
			} else {
				r = mid - 1;
			}
		}
		//std::cout << "match until " << l << ", max is " << len << '\n';
		ans[id] += l;
	}
	for(int i = 0; i < n; i++) {
		std::cout << ans[i] << (i + 1 == n ? '\n' : ' ');
	}
}