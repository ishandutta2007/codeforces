// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <deque>
#include <cassert>
#define For(i, a, b) for (int i = a; i < b; ++i)
#define Out(i, a, b) for (int i = a - 1; i >= b; --i)
#define pb push_back
#define x first
#define y second
#define files(FileName) read(FileName); write(FileName)
#define read(FileName) freopen((FileName + ".in").c_str(), "r", stdin)
#define write(FileName) freopen((FileName + ".out").c_str(), "w", stdout)
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }

using namespace std;
const int MAXN = 1 << 18;
const long long INF = 1e18;
const string FILENAME = "input";

typedef pair <int, int> point;

vector <pair <point, long long>> f;
long long rep[MAXN];

struct seg_tree {
	long long tree[MAXN * 2];
	long long mod[MAXN * 2];
	int len[MAXN * 2];
	vector <int> func[MAXN * 2];
	seg_tree() {
		for (int i = 0; i < MAXN * 2; ++i) tree[i] = INF;
		for (int i = 0; i < MAXN; ++i) len[i + MAXN] = 1;
		for (int i = MAXN; i--;) len[i] = len[i * 2] * 2;
		for (int i = 0; i < MAXN * 2; ++i) mod[i] = INF;
	}
	void push(int i) {
		if (len[i] == 0) {
			tree[i] = INF;
			return;
		}
		if (mod[i] == INF) return;
		chkmin(tree[i], mod[i]);
		if (i < MAXN) {
			chkmin(mod[i * 2], mod[i]);
			chkmin(mod[i * 2 + 1], mod[i]);
		}
		mod[i] = INF;
	}
	void updatef(int i, int L, int R, int Ln, int Rn, int id) {
		if (R <= Ln || Rn <= L) return;
		if (Ln <= L && R <= Rn) {
			func[i].pb(id);
			return;
		}
		int M = (L + R) >> 1;
		updatef(i * 2, L, M, Ln, Rn, id);
		updatef(i * 2 + 1, M, R, Ln, Rn, id);
	}
	void update(int i, int L, int R, int Ln, int Rn, long long d) {
		push(i);
		if (R <= Ln || Rn <= L) return;
		if (Ln <= L && R <= Rn) {
			//cout << L << ' ' << R << endl;
			chkmin(mod[i], d);
			push(i);
			return;
		}
		int M = (L + R) >> 1;
		update(i * 2, L, M, Ln, Rn, d);
		update(i * 2 + 1, M, R, Ln, Rn, d);
		chkmin(tree[i], tree[i * 2 + 1]);
		chkmin(tree[i], tree[i * 2]);
		//cout << '?' << i << endl;
	}
	int take_min(int i) {
		if (tree[i] == INF) return -1;
		push(i);
		if (i >= MAXN) return i - MAXN;
		push(i * 2);
		push(i * 2 + 1);
		//cout << i << '?' << tree[i] << ' ' << tree[i * 2] << ' ' << tree[i * 2 + 1] << endl;
		if (tree[i * 2] < tree[i * 2 + 1])
			return take_min(i * 2);
		return take_min(i * 2 + 1);
	}
	void kill(int i) {
		long long ans = tree[i + MAXN];
		rep[i] = ans;
		i += MAXN;
		len[i]--;
		tree[i] = INF;
		mod[i] = INF;
		vector <int> res;
		for (int j: func[i]) res.pb(j);
		func[i].clear();
		while (i > 1) {
			i >>= 1;
			--len[i];
			for (int j: func[i]) res.pb(j);
			func[i].clear();
			if (len[i] == 0) {
				tree[i] = INF;
			} else {
				tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
			}
		}
		for (int j: res) {
			update(1, 0, MAXN, f[j].x.x, f[j].x.y, ans + f[j].y);
		}
	}
};

int n, q, s;
set <pair <int, int>> used;
seg_tree box;

int main() {
	srand(time(0));
	//write(FILENAME);
	//read(FILENAME);
	ios::sync_with_stdio(0);
	cin >> n >> q >> s;
	for (int i = 0; i < q; ++i) {
		int t, L, R, v, c;
		cin >> t;
		if (t == 1) {
			cin >> L >> R >> c;
			--L, --R;
			box.updatef(1, 0, MAXN, L, L + 1, i);
			f.pb({{R, R + 1}, c});
		} else if (t == 2) {
			cin >> v >> L >> R >> c;
			--v, --L, --R;
			box.updatef(1, 0, MAXN, v, v + 1, i);
			f.pb({{L, R + 1}, c});
		} else {
			cin >> v >> L >> R >> c;
			--v, --L, --R;
			box.updatef(1, 0, MAXN, L, R + 1, i);
			f.pb({{v, v + 1}, c});
		}
	}
	for (int i = 0; i < n; ++i) rep[i] = -1;
	box.update(1, 0, MAXN, s - 1, s, 0);
	while (true) {
		int v = box.take_min(1);
		//cout << v << endl;
		//break;
		if (v == -1 || box.tree[v + MAXN] == INF) break;
		box.kill(v);
	}
	for (int i = 0; i < n; ++i) {
		cout << rep[i] << ' ';
	}
}