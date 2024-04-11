#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

const int INF = 1e9;
const int ms = 100100;
const int bs = 70;
const int bss = 2200;

struct Node {
	Node() {
		// empty constructor
		right = 0;
		left = INF;
	}
	
	Node(int v) {
		// init
		right = left = v;
	}
	
	Node(Node l, Node r) {
		// merge
		left = std::min(l.left, r.left);
		right = std::max(l.right, r.right);
	}

	Node merge(int v) {
		return Node(*this, Node(v));
	}

	int dist() {
		return right - left;
	}

	// atributes
	int left, right;
};

template <class i_t, class e_t>
class SegmentTree {
public:
	void init(std::vector<e_t> base) {
		n = base.size();
		tree.resize(2 * n);
		for(int i = 0; i < n; i++) {
			tree[i + n] = i_t(base[i]);
		}
		for(int i = n - 1; i > 0; i--) {
			tree[i] = i_t(tree[i + i], tree[i + i + 1]);
		}
	}
	
	i_t qry(int l, int r) {
		i_t lp, rp;
		for(l += n, r += n; l < r; l /= 2, r /= 2) {
			if(l & 1) lp = i_t(lp, tree[l++]);
			if(r & 1) rp = i_t(tree[--r], rp);
		}
		return i_t(lp, rp);
	}
	
	void upd(int pos, e_t v) {
		pos += n;
		tree[pos] = i_t(v);
		for(pos /= 2; pos > 0; pos /= 2) {
			tree[pos] = i_t(tree[pos + pos], tree[pos + pos + 1]);
		}
	}
	
	int walk(int pos, int v) {
		//std::cout << "walking from " << pos << std::endl;
		// use only for n == 2^k
		// walk to find the first of some property
		// in this case, max - min > v
		if(qry(pos, n).dist() <= v) {
			//std::cout << "got this shit with " << qry(pos, n).dist() << "\n";
			return n;
		}
		pos += n;
		i_t cur;
		while(pos > 1) {
			//std::cout << "going up on " << pos << std::endl;
			if(pos & 1) {
				// is right child
				if(Node(cur, tree[pos]).dist() > v) {
					break;
				}
				cur = Node(cur, tree[pos++]);
			}
			pos /= 2;
		}
		while(pos < n) {
			//std::cout << "going down on " << pos << ", cur dist is " << cur.dist() << std::endl;
			pos = pos + pos;
			if(Node(cur, tree[pos]).dist() <= v) {
				cur = Node(cur, tree[pos]);
				pos++;
			}
		}
		return pos - n;
	}
private:
	int n;
	std::vector<i_t> tree;
};

bool dirty[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, w, q;
	std::cin >> n >> w >> q;
	int s = 1;
	while(s < n) {
		s += s;
	}
	std::vector<int> a(s, 0);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	SegmentTree<Node, int> tree;
	tree.init(a);
	std::vector<int> ans(q, 0);
	std::vector<std::pair<int, int>> qries;
	for(int i = 0; i < q; i++) {
		int k;
		std::cin >> k;
		k = w - k;
		//std::cout << "answering query k == " << k << std::endl;
		if(k < 0) {
			continue;
		}
		qries.emplace_back(k, i);
	}
	std::sort(qries.begin(), qries.end());
	std::vector<Node> curNode(n);
	std::vector<int> firstStep(n);
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> events;
	std::vector<std::pair<int, int>> lng(n);
	auto fix = [&](int pos, int k) {
		//std::cout << "fixing " << pos << ", " << k << std::endl;
		int &to = firstStep[pos];
		while(to < n && to - pos < bss && Node(curNode[pos], Node(a[to])).dist() <= k) {
			curNode[pos] = Node(curNode[pos], Node(a[to]));
			to++;
		}
		if(to - pos >= bss && to != n) {
			to = tree.walk(pos, k);
		}
		to = std::min(to, n);
		//std::cout << "to is " << to << std::endl;
	};
	auto getLng = [&](int pos, int k) {
		std::pair<int, int> l(pos, 0);
		for(int i = 0; i + pos < n && i < bs; ) {
			//std::cout << "on " << i + pos << std::endl;
			if(firstStep[i + pos] - pos >= bs || firstStep[i + pos] == n) {
				break;
			}
			fix(i + pos, k);
			if(firstStep[i + pos] - pos >= bs || firstStep[i + pos] == n) {
				break;
			}
			//std::cout << "to is " << firstStep[i + pos] << std::endl;
			l.first = firstStep[i + pos];
			l.second++;
			i = l.first - pos;
		}
		return l;
	};
	for(int i = 0; i < n; i++) {
		curNode[i] = Node(a[i]);
		firstStep[i] = i + 1;
		fix(i, 0);
		if(firstStep[i] < n && firstStep[i] - i < bs) {
			events.push({Node(curNode[i], Node(a[firstStep[i]])).dist(), i});
		}
	}
	for(int i = 0; i < n; i++) {
		lng[i] = getLng(i, 0);
	}
	for(auto qu : qries) {
		int k = qu.first;
		int id = qu.second;
		//std::cout << "answering query " << id << " with k == " << k << std::endl;
		while(!events.empty() && events.top().first <= k) {
			int on = events.top().second;
			events.pop();
			int &to = firstStep[on];
			fix(on, k);
			if(to - on < bs && to < n) {
				events.push({Node(curNode[on], Node(a[to])).dist(), on});
			}
			lng[on] = getLng(on, k);
			for(int i = 1; i < bs && on - i >= 0; i++) {
				if(lng[on - i].first > on) {
					dirty[on - i] = true;
				}
			}
		}
		int curAns = -1;
		for(int on = 0; on < n; ) {
			if(dirty[on]) {
				lng[on] = getLng(on, k);
				dirty[on] = false;
			}
			//std::cout << "starting from " << on << std::endl;
			curAns += lng[on].second;
			on = lng[on].first;
			//std::cout << "lng to " << on << std::endl;
			//std::cout << "now to " << firstStep[on] << std::endl;
			fix(on, k);
			//std::cout << "fixed to " << firstStep[on] << std::endl;
			curAns++;
			on = firstStep[on];
		}
		ans[id] = curAns;
	}
	for(int i = 0; i < q; i++) {
		std::cout << ans[i] << '\n';
	}
}