#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int INF = 1e6;

struct Node {
	Node() {
		ans[0] = ans[1] = pref[0] = pref[1] = suf[0] = suf[1] = INF;
		size = 0;
	}
	
	Node(int v) {
		// init
		ans[0] = ans[1] = pref[0] = pref[1] = suf[0] = suf[1] = INF;
		ans[v] = pref[v] = suf[v] = 0;
		size = 1;
	}
	
	Node(Node l, Node r) {
		// merge
		for(int i = 0; i < 2; i++) {
			suf[i] = l.suf[i] >= INF ? r.suf[i] + l.size : l.suf[i];
			pref[i] = r.pref[i] >= INF ? l.pref[i] : l.size + r.pref[i];
			ans[i] = pref[i] - suf[i] + 1;
		}
		size = l.size + r.size;
	}

	// atributes
	int ans[2], pref[2], suf[2], size;
	int best() { return std::min(ans[0], ans[1]); }
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		char ch;
		std::cin >> ch;
		a[i] = ch - '0';
	}
	std::vector<Node> pref(n+1), suf(n+1);
	for(int i = 0; i < n; i++) {
		pref[i+1] = Node(pref[i], Node(a[i]));
		suf[n-i-1] = Node(Node(a[n-i-1]), suf[n-i]);
	}
	Node wtf[2];
	for(int i = 0; i < k; i++) {
		wtf[0] = Node(wtf[0], Node(0));
		wtf[1] = Node(wtf[1], Node(1));
	}
	if(pref[n].best() <= k) {
		std::cout << "tokitsukaze\n";
		return 0;
	}
	int haha = 0;
	for(int i = 0; i + k <= n; i++) {
		haha = std::max(haha, Node(pref[i], Node(wtf[0], suf[i+k])).best());
		haha = std::max(haha, Node(pref[i], Node(wtf[1], suf[i+k])).best());
	}
	if(haha <= k) {
		std::cout << "quailty\n";
		return 0;
	} else {
		std::cout << "once again\n";
		return 0;
	}
}