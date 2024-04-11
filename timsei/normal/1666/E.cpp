#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int l, n, pos[maxn], rem[maxn];
pair<int, int> seg[maxn];
inline int Check1(int len) {
	int pre = 0;
	for(int i = 1; i <= n; ++ i) {
		if(pre > pos[i])
			return 0;
		pre = max(pre + len, pos[i]);
	}
	return pre <= l;
}
inline int Get(int len) {
	int pre = 0;
	for(int i = 1; i <= n; ++ i) {
		int r = pre + len;
		if(r <= pos[i])
			seg[i] = {pos[i] - len, pos[i]}, pre = pos[i];
		else
			seg[i] = {pre, pre + len}, pre = pre + len;
	}
}
struct Seg {
	int val[maxn], tr[maxn << 2], tag[maxn << 2];
	inline void Apply(int o, int d) {
		tr[o] += d, tag[o] += d;
	}
	inline void Pushdown(int o) {
		if(tag[o])
			Apply(o << 1, tag[o]), Apply(o << 1 | 1, tag[o]), tag[o] = 0;
	}
	inline void Build(int o, int l, int r) {
		tag[o] = 0;
		if(l == r) {
			tr[o] = val[l];
			return;
		}
		int mid = (l + r) >> 1;
		Build(o << 1, l, mid), Build(o << 1 | 1, mid + 1, r), tr[o] = min(tr[o << 1], tr[o << 1 | 1]);
	}
	inline int Ask(int o, int l, int r, int ql, int qr) {
		if(ql <= l && r <= qr)
			return tr[o];
		Pushdown(o);
		int mid = (l + r) >> 1, ans = 1e9;
		if(ql <= mid)
			ans = min(ans, Ask(o << 1, l, mid, ql, qr));
		if(qr > mid)
			ans = min(ans, Ask(o << 1 | 1, mid + 1, r, ql, qr));
		return ans;
	}
	inline void Update(int o, int l, int r, int ql, int qr, int d) {
		if(ql <= l && r <= qr)
			return Apply(o, d);
		Pushdown(o);
		int mid = (l + r) >> 1;
		if(ql <= mid)
			Update(o << 1, l, mid, ql, qr, d);
		if(qr > mid)
			Update(o << 1 | 1, mid + 1, r, ql, qr, d);
		tr[o] = min(tr[o << 1], tr[o << 1 | 1]);
	}
}le, ri;
struct Union {
	int fa[maxn];
	inline void Init() {
		for(int i = 0; i <= n + 1; ++ i)
			fa[i] = i;
	}
	inline int Find(int x) {
		return x == fa[x] ? x : fa[x] = Find(fa[x]);
	}
	inline void Merge(int x, int y) {
		x = Find(x), y = Find(y);
		if(x == y)
			return;
		fa[y] = x;
	}
}fle, fri;
pair<int, int> ansseg[maxn];
inline int Check2(int ex, int getans = 0) {
// cerr << "Check(" << ex << ")" << endl;
	for(int i = 1; i <= n; ++ i)
		le.val[i] = seg[i].second - pos[i], ri.val[i] = pos[i] - seg[i].first;
	le.Build(1, 1, n), ri.Build(1, 1, n);
	fle.Init(), fri.Init();
	if(seg[1].first)
		rem[0] = seg[1].first;
	else
		fle.Merge(0, 1);
	for(int i = 2; i <= n; ++ i)
		if(seg[i].first > seg[i - 1].second)
			rem[i - 1] = seg[i].first - seg[i - 1].second;
		else
			rem[i - 1] = 0, fle.Merge(i - 1, i);
	if(seg[n].second < l)
		rem[n] = l - seg[n].second;
	else
		fri.Merge(n + 1, n);
	for(int i = n - 1; i; -- i)
		if(seg[i].second == seg[i + 1].first)
			fri.Merge(i + 1, i);
	for(int i = 1; i <= n; ++ i) {
		int exl = ex;
		while(exl) {
			int p = fle.Find(i) - 1;
// cerr << p << endl;
			if(p == -1)
				break;
			int mov = 1e9;
			if(p + 1 < i)
				mov = min(mov, le.Ask(1, 1, n, p + 1, i - 1));
			if(mov < rem[p])
				return 0;
			mov = min(rem[p], exl);
			exl -= mov, rem[p] -= mov;
// cerr << p << " " << mov << " " << rem[p] << " " << exl << endl;
			if(p + 1 < i)
				le.Update(1, 1, n, p + 1, i - 1, -mov);
			ri.Update(1, 1, n, p + 1, i, mov);
			if(!rem[p])
				fri.Merge(p + 1, p), fle.Merge(p, p + 1);
		}
		while(exl) {
			int p = fri.Find(i);
// cerr << p << endl;
			if(p == n + 1)
				break;
			int mov = 1e9;
			if(i < p)
				mov = min(mov, ri.Ask(1, 1, n, i + 1, p));
			if(!mov)
				break;
			mov = min(mov, min(rem[p], exl));
			exl -= mov, rem[p] -= mov;
// cerr << p << " " << mov << " " << exl << " " << rem[p] << endl;
			if(i < p)
				ri.Update(1, 1, n, i + 1, p, -mov);
			le.Update(1, 1, n, i, p, mov);
			// if(!rem[p])
			if(!rem[p])
				fle.Merge(p, p + 1), fri.Merge(p + 1, p);
		}
// cerr << "After " << i << " op, Seg:" << endl;
// for(int j = 1; j <= n; ++ j)
// 	cerr << pos[j] - ri.Ask(1, 1, n, j, j) << ", " << pos[j] + le.Ask(1, 1, n, j, j) << endl;
// cerr << "Now have hole: " << endl;
// for(auto j = 0; j <= n; ++ j)
// 	cerr << rem[j] << " ";
// cerr << endl;
	}
// cerr << cnt << endl;
	int flg = 1;
	for(int i = 0; i <= n; ++ i)
		if(rem[i]) {
			flg = 0;
			break;
		}
	if(flg) {
		if(getans)
			for(int i = 1; i <= n; ++ i)
				ansseg[i] = {pos[i] - ri.Ask(1, 1, n, i, i), pos[i] + le.Ask(1, 1, n, i, i)};
		return 1;
	}
	return 0;
}
int main() {
	scanf("%d%d", &l, &n);
	// l = 1e9, n = 1e5;
	for(int i = 1; i <= n; ++ i)
		scanf("%d", &pos[i]);
		// pos[i] = pos[i - 1] + rand() % (l / n);
	int s = 1, t = l, ans = 0;
	while(s <= t) {
		int m = (s + t) >> 1;
		if(Check1(m))
			ans = m, s = m + 1;
		else
			t = m - 1;
	}
// cerr << "Min len = " << ans << endl;
	Get(ans);
// cerr << "!!!" << endl;
// for(int i = 1; i <= n; ++ i)
// 	cerr << seg[i].first << ", " << seg[i].second << endl;
	s = 0, t = l - ans;
	int res = l - ans;
	while(s <= t) {
		int m = (s + t) >> 1;
		if(Check2(m))
			res = m, t = m - 1;
		else
			s = m + 1;
	}
// cerr << res << endl;
// cerr << "Max len = " << ans + res << endl;
	Check2(res, 1);
	for(int i = 1; i <= n; ++ i)
		printf("%d %d\n", ansseg[i].first, ansseg[i].second);
// int ml = 0, nl = 1e9;
// for(int i = 1; i <= n; ++ i)
// 	ml = max(ml, ansseg[i].second - ansseg[i].first), nl = min(nl, ansseg[i].second - ansseg[i].first);
// assert(nl == ans && ml - nl == res);
}