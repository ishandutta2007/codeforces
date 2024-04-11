#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

const int N = 3 * 1000000 + 1, M = 5000 + 1;
int l[M], r[M], needed[M];
string s[M];

struct Block {
	int num, st, len;

	Block(int num = 0, int st = 0, int len = 0) : num(num), st(st), len(len) {}
};

vector<Block> v;

struct MyIterator {
	int pb, bpos, spos, pos;
	char ch;

	MyIterator(int p = 0) {
		pos = bpos = 0;
		while(bpos < v.size() && pos + v[bpos].len <= p) {
			pos += v[bpos++].len;
		}
		if (bpos < v.size()) {
			spos = p - pos;
			pos = p;
			pb = v[bpos].num;
			ch = s[pb][v[bpos].st + spos];
		}
	}

	void next() {
		++pos;
		++spos;
		if (bpos < v.size() && spos == v[bpos].len) {
			spos = 0;
			++bpos;
		}
		if (bpos < v.size()) {
			pb = v[bpos].num;
			ch = s[pb][v[bpos].st + spos];
		}
	}

	void next2() {
		next();
		next();
	}

};


int main() {
	ios::sync_with_stdio(false);
	int m, k;
	cin >> s[0] >> k >> m;
	for (int i = 0; i < m; ++i) {
		cin >> l[i] >> r[i];
		--l[i], --r[i];
	}
	needed[m] = k;
	for (int i = m - 1; i >= 0; --i) {
		if (r[i] >= k - 1) {
		} else {
			if (r[i] + r[i] - l[i] + 1 >= k - 1) {
				k = r[i] + 1;
			} else {
				k -= r[i] - l[i] + 1;
			}
		}
		needed[i] = k;
	}
	v.push_back(Block(0, 0, needed[0]));
	for (int i = 0; i < m; ++i) {
		if (needed[i + 1] == needed[i]) {
			continue;
		}
		int len = needed[i + 1] - needed[i];
		MyIterator it(l[i] + 1);
		while (it.pos <= r[i] && s[i + 1].size() < len) {
			s[i + 1] += it.ch;
			it.next2();
		}
		it = MyIterator(l[i]);
		while (it.pos <= r[i] && s[i + 1].size() < len) {
			s[i + 1] += it.ch;
			it.next2();
		}
		it = MyIterator(r[i]);
		vector<Block> tmp;
		for (int j = v.size() - 1; j > it.bpos; --j) {
			tmp.push_back(v.back());
			v.pop_back();
		}
		if (it.spos != v[it.bpos].len - 1) {
			Block bleft = Block(it.pb, v[it.bpos].st, it.spos + 1),
				  bright = Block(it.pb, v[it.bpos].st + it.spos + 1, v[it.bpos].len - it.spos - 1);
			v.pop_back();
			v.push_back(bleft);
			tmp.push_back(bright);
		}
		tmp.push_back(Block(i + 1, 0, len));
		for (int j = tmp.size() - 1; j >= 0; --j) {
			v.push_back(tmp[j]);
		}
	}

	string ans;
	for (MyIterator it(0); it.bpos < (int)v.size(); it.next()) {
		ans += it.ch;
	}
	cout << ans << endl;
	return 0;
}