#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int L = 1000000 + 5;

int n, m, pos, len;
vector<int> a;

int getID(int l, int r) {
	return l + r | l != r;
}

int size[L << 1];
char ch[L << 1];

void insert(int l, int r, int pos, char c) {
	++size[getID(l, r)];
	if (l == r) {
		ch[getID(l, r)] = c;
		return;
	}
	int m = l + r >> 1;
	if (pos <= m) {
		insert(l, m, pos, c);
	} else {
		insert(m + 1, r, pos, c);
	}
}

void erase(int l, int r, int pos) {
	--size[getID(l, r)];
	if (l == r) {
		return;
	}
	int m = l + r >> 1;
	if (size[getID(l, m)] >= pos) {
		erase(l, m, pos);
	} else {
		erase(m + 1, r, pos - size[getID(l, m)]);
	}
}

void print() {
	string ans;
	for (int i = 0; i < pos; ++i) {
		if (size[getID(i, i)]) {
			ans += ch[getID(i, i)];
		}
	}
	if (ans.size() == 0) {
		printf("Poor stack!\n");
	} else {
		printf("%s\n", ans.c_str());
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int t1;
		scanf("%d", &t1);
		a.push_back(t1);
	}
	a.push_back(n + 1);
	pos = 0, len = 0;		
	for (int i = 0; i < n; ++i) {
		int e;
		scanf("%d", &e);
		if (e == -1) {
			int t = upper_bound(a.begin(), a.end(), len) - a.begin();
			for (int i = t - 1; i >= 0; --i) {
				erase(0, n, a[i]);
			}
			len -= t;
		} else if (e == 0) {
			insert(0, n, pos, '0');
			++pos;
			++len;
		} else {
			insert(0, n, pos, '1');
			++pos;
			++len;
		}
	}
	print();
	return 0;
}