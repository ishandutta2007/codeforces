#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct upd{
	int pos, prev, now;
	upd() {}
	upd(int pos, int prev, int now) {
		this->pos = pos;
		this->prev = prev;
		this->now = now;
	}
};

const int K = 3500, MAX_N = 1 << 18;
vector <int> t[2 * MAX_N];
vector <upd> changes;
int a[MAX_N], b[MAX_N], whereis[MAX_N];
int n;

void relax(int pos) {
	t[pos].resize(t[2 * pos].size() + t[2 * pos + 1].size());
	merge(t[2 * pos].begin(), t[2 * pos].end(), t[2 * pos + 1].begin(), t[2 * pos + 1].end(), t[pos].begin());
}

void build(int pos, int l, int r) {
	t[pos].clear();
	if (l == r) {
		if (l <= n) t[pos].push_back(whereis[b[l]]);
		return;
	}
	int m = (l + r) / 2;
	build(2 * pos, l, m);
	build(2 * pos + 1, m + 1, r);
	relax(pos);
}

int get(int pos, int l, int r, int a, int b, int aa, int bb) {
	if (a > r || l > b) return 0;
	if (a <= l && r <= b) return upper_bound(t[pos].begin(), t[pos].end(), bb) - lower_bound(t[pos].begin(), t[pos].end(), aa);
	int m = (l + r) / 2;
	return get(2 * pos, l, m, a, b, aa, bb) + get(2 * pos + 1, m + 1, r, a, b, aa, bb);
}

int main() {
	//freopen("Desktop/input.txt", "r", stdin);
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	int m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		whereis[a[i]] = i;
	}
	for (int i = 1; i <= n; i++) cin >> b[i];
	int t, x, y, la, ra, lb, rb, ans;
	build(1, 1, MAX_N);
	for (int i = 0; i < m; i++) {
		cin >> t;
		if (t == 2) {	
			cin >> x >> y;
			changes.push_back(upd(x, whereis[b[x]], whereis[b[y]]));
			changes.push_back(upd(y, whereis[b[y]], whereis[b[x]]));
			swap(b[x], b[y]);
		} else {
			cin >> la >> ra >> lb >> rb;
			ans = get(1, 1, MAX_N, lb, rb, la, ra);
			for (upd elem : changes) {
				if (lb <= elem.pos && elem.pos <= rb) {
					if (la <= elem.prev && elem.prev <= ra) ans--;
					if (la <= elem.now && elem.now <= ra) ans++;
				}
			}
			cout << ans << '\n';
		}
		if (changes.size() >= K) {
			build(1, 1, MAX_N);
			changes.clear();
		}
	}
	return 0;
}