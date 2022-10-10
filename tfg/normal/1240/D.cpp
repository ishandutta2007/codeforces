#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct Node {
	Node *l, *r;
	int val;
};

const int ms = 300300;

int c;
Node buffer[ms * 20];

Node* getNode() {
	return &buffer[c++];
}

Node* modify(Node* root, int l, int r, int pos, int x) {
	Node* ans = getNode();
	if(l + 1 == r) {
		ans->val = x;
	} else {
		int mid = (l + r) / 2;
		if(pos < mid) {
			ans->r = root->r;
			ans->l = modify(root->l, l, mid, pos, x);
		} else {
			ans->l = root->l;
			ans->r = modify(root->r, mid, r, pos, x);
		}
	}
	return ans;
}

int get(Node* root, int l, int r, int pos) {
	if(l + 1 == r) {
		return root->val;
	}
	int mid = (l + r) / 2;
	if(pos < mid) {
		return get(root->l, l, mid, pos);
	} else {
		return get(root->r, mid, r, pos);
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int q;
	std::cin >> q;
	while(q--) {
		int n;
		std::cin >> n;
		c = 0;
		std::vector<Node*> tree(n + 1);
		tree[n] = getNode();
		tree[n]->l = tree[n];
		tree[n]->r = tree[n];
		tree[n]->val = n + 1;
		tree[n-1] = tree[n];
		std::vector<int> a(n);
		std::vector<int> dp(n + 1, 0);
		for(int i = 0; i < n; i++) {
			std::cin >> a[i];
			a[i]--;
		}
		long long ans = 0;
		for(int i = n-2; i >= 0; i--) {
			if(a[i] == a[i+1]) {
				tree[i] = tree[i+2];
				dp[i] = 1 + dp[i+2];
				if(i + 2 < n) {
					tree[i] = modify(tree[i], 0, n, a[i+2], i+2);
				}
			} else {
				tree[i] = tree[n];
				int to = get(tree[i+1], 0, n, a[i]);
				//std::cout << "on " << i << " to " << to << '\n';
				if(to < n) {
					dp[i] = 1 + dp[to+1];
					tree[i] = tree[to+1];
					if(to + 1 < n) {
						tree[i] = modify(tree[i], 0, n, a[to+1], to+1);
					}
				}
			}
			//std::cout << "starting from " << i << " got " << dp[i] << '\n';
			ans += dp[i];
		}
		std::cout << ans << '\n';
	}
}