#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define mp push_back
#define all(a) a.begin(), a.end()
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)

using namespace std;

typedef long long base;
typedef pair <int, int> point;

const string FILENAME = "input";
const int p = 1e9 + 7, MAXN = 1e5 + 10, MAXS = 1 << 17;
const int INF = 1e9;

int sum(int a, int b) {
	a += b;
	if (a >= p)
		return a - p;
	return a;
}

struct line {
	int L, R, H, S;
	line(){}
	line(int u, int l, int r, int s) {
		L = l, R = r, H = u, S = s;
	}
};

int w, h, n;
int rep = 0;
map <pair <int, int>, int> edge;
map <pair <int, int>, int> ans;
vector <line> arr;
int cnt[MAXN];

struct seg_tree {
	int coor[MAXS * 2];
	seg_tree() {
		for (int i = 0; i < MAXS * 2; ++i)
			coor[i] = 0;
	}
	void change(int i, int d) {
		i += MAXS;
		coor[i] = d;
		while (i > 1) {
			i >>= 1;
			coor[i] = max(coor[i * 2], coor[i * 2 + 1]);
		}
	}
	int get(int i, int L, int R, int dx, int dy) {
		if (R <= dx) return -1;
		if (R - L == 1) {
			if (coor[i] >= dy) {
				return L;
			}
			return -1;
		}
		if (coor[i] < dy) return -1;
		int M = (L + R) >> 1;
		int ans = get(i * 2, L, M, dx, dy);
		if (ans != -1) return ans;
		ans = get(i * 2 + 1, M, R, dx, dy);
		return ans;
	}
};

bool cmp(line a, line b) {
	return a.H > b.H;
}

vector <point> event;
map <int, int> num;
seg_tree box;

int main() {
	ios::sync_with_stdio(0);
	//read(FILENAME);
	cin >> h >> w >> n;
	arr.resize(n);
	for (int i = 0; i < n; ++i) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		arr[i] = line(a, b, c, d);
	}
	sort(all(arr), cmp);
	arr.insert(arr.begin(), line());
	num[h + 1] = 0;
	for (int i = 1; i <= w; ++i) {
		event.pb({i, INF + h + 1});
	}
	for (int i = 1; i <= n; ++i) {
		event.pb({arr[i].L, i});
		event.pb({arr[i].R + 1, -i});
		num[arr[i].H] = i;
		if (arr[i].R != w) {
			event.pb({arr[i].R + 1, INF + arr[i].H});
		}
		if (arr[i].L != 1) {
			event.pb({arr[i].L - 1, INF + arr[i].H});
		}
	}
	event.pb({1, n + 1});
	event.pb({w + 1, -n - 1});
	sort(all(event));
	for (auto i: event) {
		int id = abs(i.y);
		if (id >= INF) {
			id -= INF;
			edge[make_pair(id, i.x)] = box.get(1, 0, MAXS, num[id], id);
		} else if (i.y < 0) {
			box.change(id, 0);
		} else {
			if (id == n + 1)
				box.change(id, h + 1);
			else
				box.change(id, arr[id].H + arr[id].S);
		}
	}
	for (int i = 1; i <= w; ++i)
		cnt[edge[make_pair(h + 1, i)]]++;
	for (int i = 1; i <= n; ++i) {
		if (arr[i].L == 1) {
			int r = edge[make_pair(arr[i].H, arr[i].R + 1)];
			cnt[r] = sum(cnt[r], sum(cnt[i], cnt[i]));
		} else if (arr[i].R == w) {
			int r = edge[make_pair(arr[i].H, arr[i].L - 1)];
			cnt[r] = sum(cnt[r], sum(cnt[i], cnt[i]));
		} else {
			int r = edge[make_pair(arr[i].H, arr[i].R + 1)];
			cnt[r] = sum(cnt[r], cnt[i]);
			r = edge[make_pair(arr[i].H, arr[i].L - 1)];
			cnt[r] = sum(cnt[r], cnt[i]);
		}
	}
	cout << cnt[n + 1] << endl;
}