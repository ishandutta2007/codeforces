#include <iostream>
#include <vector>

typedef long long ll;

struct Node {
	ll sum, pref, suf, ans;

	Node(int v = -1e9) {
		sum = v = pref = suf = ans = v;
	}

	Node(Node l, Node r) {
		sum = l.sum + r.sum;
		pref = std::max(l.pref, l.sum + r.pref);
		suf = std::max(r.suf, r.sum + l.suf);
		ans = std::max(std::max(l.ans, r.ans), l.suf + r.pref);
	}
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<Node> all(n);
	for(int i = 0; i < n; i++) {
		int s;
		std::cin >> s;
		s--;
		int wtf;
		std::cin >> wtf;
		all[i] = Node(wtf);
		while(s--) {
			int v;
			std::cin >> v;
			all[i] = Node(all[i], Node(v));
		}
		//std::cout << all[i].pref << ", " << all[i].suf << std::endl;
		//std::cout << all[i].ans << " and " << all[i].sum << std::endl;
	}
	Node tot;
	for(int i = 0; i < m; i++) {
		int idx;
		std::cin >> idx;
		tot = Node(tot, all[idx - 1]);
	}
	std::cout << tot.ans << std::endl;
}