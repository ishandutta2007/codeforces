#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n;

struct Seq {
	int val, st, ed;
	
	Seq(const int val = 0, const int st = 0, const int ed = 0) : val(val), st(st), ed(ed) {}
};

bool operator < (const Seq a, const Seq b) {
	return a.val < b.val;
}

Seq operator + (const Seq a, const Seq b) {
	return Seq(a.val + b.val, a.st, b.ed);
}

struct Data {
	int tag;
	Seq sum, left, right, best;
	
	Data(const int pos = 0, const int val = 0, const int tag = 0) : tag(tag) {
		sum = Seq(val, pos, pos);
		if ((val >= 0) ^ tag) {
			left = right = best = sum;
		} else {
			left = Seq(0, pos, pos - 1);
			right = Seq(0, pos + 1, pos);
			best = Seq(0, pos, pos - 1);	
		}
	}

	void reverse() {
		tag = 1 ^ tag;
		sum.val = -sum.val;
		left.val = -left.val;
		right.val = -right.val;
		best.val = -best.val;
	}
};

Data merge(const Data a, const Data b) {
	Data ret;
	ret.tag = a.tag;
	ret.sum = a.sum + b.sum;
	if (!ret.tag) {
		ret.left = max(a.left, a.sum + b.left);
		ret.right = max(a.right + b.sum, b.right);
		ret.best = max(a.right + b.left, max(a.best, b.best));	
	} else {
		ret.left = min(a.left, a.sum + b.left);
		ret.right = min(a.right + b.sum, b.right);
		ret.best = min(a.right + b.left, min(a.best, b.best));	
	}
	return ret;
}

const int N = 100005;

Data data[N << 1][2];

int getID(const int l, const int r) {
	return l + r | l != r;
}

void update(const int l, const int r) {
	int k = (l + r) >> 1;
	int x = getID(l, r), lc = getID(l, k), rc = getID(k + 1, r);
	data[x][0] = merge(data[lc][0], data[rc][0]);
	data[x][1] = merge(data[lc][1], data[rc][1]);
}

void segChange(const int l, const int r, const int pos, const int val) {
	if (pos < l || r < pos) {
		return;
	}
	if (l == r) {
		int x = getID(l, r);
		data[x][0] = Data(l, val, 0);
		data[x][1] = Data(l, val, 1);
	} else {
		int k = (l + r) >> 1;
		segChange(l, k, pos, val);
		segChange(k + 1, r, pos, val);
		update(l, r);
	}
}

int tag[N << 1];

void segReverse(const int l, const int r, const int a, const int b);

void pushdown(const int l, const int r) {
	int x = getID(l, r);
	if (tag[x]) {
		int k = (l + r) >> 1;
		tag[x] ^= 1;
		segReverse(l, k, l, r);
		segReverse(k + 1, r, l, r);
		update(l, r);
	}
}

void segReverse(const int l, const int r, const int a, const int b) {
	if (b < l || r < a) {
		return;
	}
	if (a <= l && r <= b) {
		int x = getID(l, r);
		tag[x] ^= 1;
		swap(data[x][0], data[x][1]);
		data[x][0].reverse();
		data[x][1].reverse();
		return;
	}
	pushdown(l, r);
	int k = (l + r) >> 1;
	segReverse(l, k, a, b);
	segReverse(k + 1, r, a, b);	
	update(l, r);
}

Data segAsk(const int l, const int r, const int a, const int b) {
	if (a <= l && r <= b) {
		return data[getID(l, r)][0];
	}
	pushdown(l, r);
	int k = (l + r) >> 1;
	if (b <= k) {
		return segAsk(l, k, a, b);
	}
	if (k < a) {
		return segAsk(k + 1, r, a, b);
	}
	return merge(segAsk(l, k, a, b), segAsk(k + 1, r, a, b));
}


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i) {
		int t1;
		scanf("%d", &t1);
		segChange(0, n - 1, i, t1);
	}
	int m;
	scanf("%d", &m);
	while (m--) {
		int type;
		scanf("%d", &type);
		if (type) {
			int l, r, k;
			scanf("%d%d%d", &l, &r, &k);
			--l, --r;
			int ans = 0;
			vector<pair<int, int> > v;
			for (int i = 0; i < k; ++i) {
				Seq tmp = segAsk(0, n - 1, l, r).best;
				if (tmp.val > 0) {
					ans += tmp.val;
					segReverse(0, n - 1, tmp.st, tmp.ed);
					v.push_back(make_pair(tmp.st, tmp.ed));
				}
			}
			printf("%d\n", ans);
			for (int i = 0; i < (int)v.size(); ++i) {
				segReverse(0, n - 1, v[i].first, v[i].second);
			}
		} else {
			int tpos, tval;
			scanf("%d%d", &tpos, &tval);
			--tpos;
			segChange(0, n - 1, tpos, tval);
		}
	}
	return 0;
}