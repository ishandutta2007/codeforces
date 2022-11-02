#include <bits/stdc++.h>
using namespace std;

const int Z = 2e5+40;

int sL, sR, sV;
struct SegmentTree {
	int l, r, add {}, val {};
	bool s[2] {1, 0};
	SegmentTree *L, *R;
	SegmentTree(int lv, int rv) : l(lv), r(rv) {
		if(r - l > 1) {
			int m = (l + r) / 2;
			L = new SegmentTree(l, m);
			R = new SegmentTree(m, r);
		}
	}
	void insert(int v) {
		rangeAdd(v, getRange(v, 1) + 1,  1);
	}
	void erase(int v) {
		rangeAdd(v, getRange(v, 0) + 1, -1);
	}
	int getRange(int i, int p) {
		if(r <= i) return r - 1;
		if(r - l < 2)
			return p == (val & 1) ? l : l - 1;
		if(!s[!p]) return r - 1;

		int v = L->getRange(i, p ^ (add & 1));
		return v == L->r - 1 ? R->getRange(i, p ^ (add & 1)) : v;
	}
	void rangeAdd(int lv, int rv, int v) {
		sL = lv, sR = rv + 1, sV = v;
		rangeAdd();
	}
	void rangeAdd() {
		if(sL <= l && r <= sR) {
			swap(s[0], s[1]);
			add += sV;
			val += sV;
			return;
		}
		if(sR <= l || r <= sL) return;
		L->rangeAdd(), R->rangeAdd();

		for(int j : {0, 1})
			s[j] = L->s[j] || R->s[j];
		if(add & 1) swap(s[0], s[1]);

		val = add + max(L->val, R->val);
	}
	int getAnswer(int sum = 0) {
		if(r - l < 2) return l;
		sum += add;
		return (R->val + sum > 0 ? R : L)->getAnswer(sum);
	}
} s(0, Z);



int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	int n, q; cin >> n >> q;

	int a[n];

	for(int &i : a) {
		cin >> i;
		s.insert(i);
	}

	while(q--) {
		int i, v; cin >> i >> v;

		s.erase(a[--i]);
		s.insert(a[i] = v);

		cout << s.getAnswer() << '\n';
	}
}