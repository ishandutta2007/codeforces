#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int MAX = N * 10;
const int mx = 4e5;

int n, m, id1[N], id2[N], ch[MAX][2], S[MAX], rt[N], sz;

struct P {
	int x, y;
	void input() {
		scanf("%d%d", &x, &y);
		int X = x + y, Y = x - y + 2e5;
		x = X, y = Y;
	}
}All[N];

bool cmp1(int a, int b) {
	return All[a].x < All[b].x;
}

int nw(int x) {
	++ sz;
	ch[sz][0] = ch[x][0];
	ch[sz][1] = ch[x][1];
	S[sz] = S[x];
	return sz;
}

void add(int &rt, int l, int r, int wh) {
	int now = nw(rt);
	++ S[now];
	if(l == r) {
		rt = now;
		return;
	}
	int mid = (l + r) >> 1;
	if(wh > mid) {
		add(ch[now][1], mid + 1, r, wh);
	} else add(ch[now][0], l, mid, wh);
	rt = now;
}

int ask(int rt, int l, int r, int L, int R) {
	if(l == L && R == r) {
		return S[rt];
	}
	if(!rt) return 0;
	int mid = (l + r) >> 1;
	if(L > mid) return ask(ch[rt][1], mid + 1, r, L, R);
	else if(R <= mid) return ask(ch[rt][0], l, mid, L, R);
	else return ask(ch[rt][0], l, mid, L, mid) + ask(ch[rt][1], mid + 1, r, mid + 1, R);
}

int calc(int l, int r, int L, int R) {
	L = max(L, 1);
	R = min(R, mx);
	if(L > R) return 0;
	r = min(r, mx);
	l = max(l, 1);
	if(l > r) return 0;
	return ask(rt[r], 1, mx, L, R) - ask(rt[l - 1], 1, mx, L, R);
}

map <int, int> Map[N];

int get(int x, int y) {
	int nx = x + y, ny = x - y + 2e5;
	return Map[nx].count(ny);
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++ i) All[i].input(), id1[i] = i, id2[i] = i, Map[All[i].x][All[i].y] = 1;
	sort(id1 + 1, id1 + n + 1, cmp1);
	int who = 1;
	for(int i = 1; i <= mx; ++ i) {
		rt[i] = nw(rt[i - 1]);
		while(All[id1[who]].x == i && who <= n) {
			add(rt[i], 1, mx, All[id1[who]].y);
			++ who;
		}
	}
	for(int i = 1; i <= n; ++ i) {
		int l = 0, r = 500, res = 0;
		while(l <= r) {
			int mid = (l + r) >> 1;
			int now = calc(All[i].x - mid, All[i].x + mid, All[i].y - mid, All[i].y + mid);
			if(now == mid * mid + (mid + 1) * (mid + 1)) {
				res = mid;
				l = mid + 1;
			} else r = mid - 1;
		}
		int nx = (All[i].x + All[i].y - 2e5) / 2, ny = (All[i].x - All[i].y + 2e5) / 2;
		bool ok = 0;
		int x = nx, y = ny, k = res + 1;
		for(int i = x - k; i <= x; ++ i) {
			if(!get(i, x + y - k - i)) {
				ok = 1;
				printf("%d %d\n", i, x + y - k - i);
				break;
			}
		}
		if(ok) continue;
		for(int i = x; i <= x + k; ++ i) {
			if(!get(i, x + y + k - i)) {
				ok = 1;
				printf("%d %d\n", i, x + y + k - i);
				break;
			}
		}
		if(ok) continue;
		for(int i = x - k; i <= x; ++ i) {
			if(!get(i, i + (y + k) - x)) {
				ok = 1;
				printf("%d %d\n", i, i + y + k - x);
				break;
			}
		}
		if(ok) continue;
		for(int i = x; i <= x + k; ++ i) {
			if(!get(i, i + (y - k - x))) {
				ok = 1;
				printf("%d %d\n", i, i + y - k - x);
				break;
			}
		}
	}
}