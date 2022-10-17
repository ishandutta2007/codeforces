#include <bits/stdc++.h>
using namespace std;
int k, n;
string s[2520], p, q;
bool same;
int dd[2520], dc;
int diff(string s, string t, bool shabi = false) {
	assert(s.size() == t.size());
	if (shabi) {
		dc = 0;
	}
	int re = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != t[i]) {
			re++;
			if (shabi) {
				dd[dc++] = i;
			}
		}
	}
	return re;
}

void check(string e) {
//	cerr << e << endl;
	for (int i = 0; i < k; i++) {
		int dif = diff(e, s[i]);
//		cerr << dif << ' ' << e << ' ' << s[i] << endl;
		if (dif == 0 && same) {
			continue;
		}
		if (dif != 2) {
			return;
		}
	}
	cout << e << endl;
	exit(0);
}

void fail() {
	printf("-1\n");
	exit(0);
}

int main() {
	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		cin >> s[i];
	}
	sort(s, s + k);
	p = s[0];
	sort(p.begin(), p.end());
	for (int i = 0; i < k; i++) {
		q = s[i];
		sort(q.begin(), q.end());
		if (p != q) {
			fail();
		}
	}
	for (int i = 1; i < p.size(); i++) {
		if (p[i] == p[i - 1]) {
			same = true;
		}
	}
	int dif = diff(s[0], s[k - 1], true);
	string fuck = s[0];
	if (dif == 0) {
		swap(fuck[0], fuck[1]);
		check(fuck);
		assert(false);
	} else if (dif == 1) {
		assert(false);
	} else if (dif == 2) {
		check(fuck);
		check(s[k - 1]);
		fail();
	} else if (dif == 3) {
		swap(fuck[dd[0]], fuck[dd[1]]);
		check(fuck);
		swap(fuck[dd[0]], fuck[dd[1]]);

		swap(fuck[dd[1]], fuck[dd[2]]);
		check(fuck);
		swap(fuck[dd[1]], fuck[dd[2]]);

		swap(fuck[dd[2]], fuck[dd[0]]);
		check(fuck);
		swap(fuck[dd[2]], fuck[dd[0]]);

		fail();
	} else if (dif == 4) {
		swap(fuck[dd[0]], fuck[dd[1]]);
		check(fuck);
		swap(fuck[dd[0]], fuck[dd[1]]);

		swap(fuck[dd[1]], fuck[dd[2]]);
		check(fuck);
		swap(fuck[dd[1]], fuck[dd[2]]);

		swap(fuck[dd[2]], fuck[dd[0]]);
		check(fuck);
		swap(fuck[dd[2]], fuck[dd[0]]);

		swap(fuck[dd[3]], fuck[dd[0]]);
		check(fuck);
		swap(fuck[dd[3]], fuck[dd[0]]);

		swap(fuck[dd[3]], fuck[dd[1]]);
		check(fuck);
		swap(fuck[dd[3]], fuck[dd[1]]);

		swap(fuck[dd[3]], fuck[dd[2]]);
		check(fuck);
		swap(fuck[dd[3]], fuck[dd[2]]);
		fail();
	} else {
		fail();
	}
	return 0;
}