#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <utility>

typedef std::pair<int, int> ii;

struct Node {
	Node(int v = 1, int pos = 1e9) {
		min = (v == 1 ? int(1e9) : pos);
	}

	Node(Node l, Node r) {
		min = std::min(l.min, r.min);
	}

	int min;
};

template<class i_t, class e_t>
class SegmentTree {
public:
	void init(std::vector<e_t> base) {
		n = base.size();
		tree.resize(2 * n);
		for(int i = 0; i < n; i++) {
			tree[i + n] = i_t(base[i], i);
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

	void upd(int x, e_t v) {
		x += n;
		tree[x] = i_t(v, x - n);
		build(x);
	}
private:
	int n;
	std::vector<i_t> tree;

	void build(int x) {
		for(x /= 2; x > 0; x /= 2) {
			tree[x] = i_t(tree[x + x + 1], tree[x + x]);
		}
	}
};

struct Bucket {
	int n;
	SegmentTree<Node, int> tree;

	void init(int n) {
		//std::cout << "making init with size " << n << std::endl;
		this->n = n;
		tree.init(std::vector<int>(n, 0));
	}

	void erase(int pos) {
		//std::cout << "erasing in pos " << pos << std::endl;
		tree.upd(pos, 0);
	}

	int insert(int pos) {
		int x = tree.qry(pos, n).min;
		int ans = 0;
		if(x >= n) {
			x = tree.qry(0, pos).min;
			ans += n - pos + x;
		} else {
			ans += x - pos;
		}
		tree.upd(x, 1);
		return ans;
	}
};

int main() {
	//std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int h, m, n;
	std::cin >> h >> m >> n;
	int size = 1;
	for(int i = 2; i <= h; i++) {
		if(h % i == 0 && m % i == 0) {
			size = i;
		}
	}
	std::vector<Bucket> buckets(size);
	std::vector<int> hashBucket(h, 0);
	std::vector<int> posBucket(h, 0);
	std::map<int, ii> idBucket;
	for(int i = 0; i < size; i++) {
		for(int j = 0, pos = i; j < h / size; j++, pos = (pos + m) % h) {
			posBucket[pos] = j;
			hashBucket[pos] = i;
		}
		//std::cout << "trying (" << i << ", " << buckets.size() << ")\n";
		buckets[i].init(h / size);
	}
	long long ans = 0;
	//std::cout << "size is " << size << std::endl;
	for(int i = 0; i < n; i++) {
		char t;
		int id;
		//std::cin >> t >> id;
		scanf(" %c %d", &t, &id);
		//std::cout << "on query " << t << ", " << id << std::endl;
		if(t == '+') {
			int hash;
			//std::cin >> hash;
			scanf("%d", &hash);
			//std::cout << "got bucket " << hashBucket[hash] << " and position " << posBucket[hash] << std::endl;
			int got = buckets[hashBucket[hash]].insert(posBucket[hash]);
			//std::cout << "got " << got << std::endl;
			idBucket[id] = ii(hashBucket[hash], (posBucket[hash] + got) % (h / size));
			ans += got;
		} else {
			//std::cout << "erasing on (" << idBucket[id] << ", " << idPos[id] << ")\n";
			auto it = idBucket.find(id);
			buckets[it->second.first].erase(it->second.second);
			idBucket.erase(it);
		}
	}
	std::cout << ans << std::endl;
}