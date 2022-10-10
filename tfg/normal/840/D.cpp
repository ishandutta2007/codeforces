#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 300300;

int a[ms];
std::vector<int> pos[ms];

bool isGood(int l, int r, int x, int k) {
	int want = (r - l) / k;
	if((int) pos[x].size() <= want) return false;
	return std::lower_bound(pos[x].begin(), pos[x].end(), r) - std::lower_bound(pos[x].begin(), pos[x].end(), l) > want;
}

struct Node {
	int cand[5];
	int size = 0;
	Node* child[5] = {NULL, NULL, NULL, NULL, NULL};
};

std::vector<int> temp[22];
Node* build(int l, int r, int d) {
	Node* ans = new Node();
	if(r - l <= 5) {
		for(int i = l; i < r; i++) {
			ans->cand[ans->size++] = a[i];
		}
		std::sort(ans->cand, ans->cand + ans->size);
		ans->size = std::unique(ans->cand, ans->cand + ans->size) - ans->cand;
	} else {
		temp[d].clear();
		for(int i = 0; i < 5; i++) {
			ans->child[i] = build(l + (r - l) / 5 * i + std::min(i, (r - l) % 5), l + (r - l) / 5 * (i+1) + std::min(i+1, (r - l) % 5), d+1);
			for(int j = 0; j < ans->child[i]->size; j++) {
				temp[d].push_back(ans->child[i]->cand[j]);
			}
		}
		std::sort(temp[d].begin(), temp[d].end());
		temp[d].resize(std::unique(temp[d].begin(), temp[d].end()) - temp[d].begin());
		for(auto v : temp[d]) {
			if(isGood(l, r, v, 5)) {
				ans->cand[ans->size++] = v;
			}
		}
	}
	return ans;
}

std::vector<int> globalCand;

void go(Node *root, int l, int r, int ql, int qr) {
	if(r <= ql || l >= qr) return;
	if(ql <= l && r <= qr) {
		for(int i = 0; i < root->size; i++) {
			globalCand.push_back(root->cand[i]);
		}
	} else if(r - l <= 5) {
		for(int i = std::max(l, ql); i < r && i < qr; i++) {
			globalCand.push_back(a[i]);
		}
	} else {
		for(int i = 0; i < 5; i++) {
			go(root->child[i], l + (r - l) / 5 * i + std::min(i, (r - l) % 5), l + (r - l) / 5 * (i+1) + std::min(i+1, (r - l) % 5), ql, qr);
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, q;
	std::cin >> n >> q;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		pos[a[i]].push_back(i);
	}
	auto root = build(0, n, 0);
	while(q--) {
		int l, r, k;
		std::cin >> l >> r >> k;
		l--;
		globalCand.clear();
		go(root, 0, n, l, r);
		std::sort(globalCand.begin(), globalCand.end());
		globalCand.resize(std::unique(globalCand.begin(), globalCand.end()) - globalCand.begin());
		int ans = -1;
		for(auto v : globalCand) {
			if(isGood(l, r, v, k)) {
				ans = v;
				break;
			}
		}
		std::cout << ans << '\n';
	}
}