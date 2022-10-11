#include <iostream>
#include <vector>
#include <algorithm>

const int ms = 200200;

bool ans[ms];

struct Event {
	int a, b, t, idx;
	int l, r;
};

bool operator < (Event a, Event b) {
	if(a.a != b.a) {
		return a.a < b.a;
	} else {
		return a.t < b.t;
	}
}

int tree[ms + ms];

void build() {
	for(int i = 0; i < ms + ms; i++) {
		tree[i] = -1;
	}
}

void upd(int x, int v) {
	x += ms;
	tree[x] = v;
	for(x /= 2; x > 0; x /= 2) {
		tree[x] = std::min(tree[x + x], tree[x + x + 1]);
	}
}

int qry(int l, int r) {
	int ans = 1e9;
	for(l += ms, r += ms; l < r; l /= 2, r /= 2) {
		if(l&1) ans = std::min(ans, tree[l++]);
		if(r&1) ans = std::min(ans, tree[--r]);
	}
	//std::cout << "returning " << ans << std::endl;
	return ans;
}

void process(std::vector<Event> events) {
	build();
	//std::cout << "processing batch!\n";
	std::sort(events.begin(), events.end());
	std::vector<int> last(ms, -1);
	for(auto e : events) {
		//std::cout << "event in " << e.a << std::endl;
		if(e.t == 0) {
			//std::cout << "got rook on position " << e.b << std::endl;
			upd(e.b, e.a);
		} else {
			//std::cout << e.idx << ": got range in (" << e.b << ", " << e.a << ") and query is in (" << e.l << ", " << e.r << ")\n";
			ans[e.idx] = qry(e.l, e.r + 1) >= e.b || ans[e.idx];
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m, k, q;
	std::cin >> n >> m >> k >> q;
	std::vector<Event> events[2];
	for(int i = 0; i < k; i++) {
		//std::cout << "reading " << i << std::endl;
		Event cur[2];
		int x, y;
		std::cin >> x >> y;
		cur[0].a = x;
		cur[0].b = y;
		cur[1].a = y;
		cur[1].b = x;
		cur[0].t = cur[1].t = 0;
		events[0].push_back(cur[0]);
		events[1].push_back(cur[1]);
	}
	for(int i = 0; i < q; i++) {
		//std::cout << "reading " << i << std::endl;
		int x1, y1, x2, y2;
		std::cin >> x1 >> y1 >> x2 >> y2;
		Event cur[2];
		cur[0].a = x2;
		cur[0].b = x1;
		cur[0].l = y1;
		cur[0].r = y2;
		cur[0].t = 1;
		cur[1].a = y2;
		cur[1].b = y1;
		cur[1].l = x1;
		cur[1].r = x2;
		cur[1].t = 1;
		cur[0].idx = cur[1].idx = i;
		events[0].push_back(cur[0]);
		events[1].push_back(cur[1]);
	}
	process(events[0]);
	process(events[1]);
	for(int i = 0; i < q; i++) {
		std::cout << (ans[i] ? "YES\n" : "NO\n");
	}
}