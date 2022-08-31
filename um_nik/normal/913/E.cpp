#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

struct Item {
	int val;
	string s;

	Item() : val(-1), s("") {}
	Item(int _val, string _s) : val(_val), s(_s) {}

	Item Not() const {
		Item I;
		I.val = 255 ^ val;
		I.s = "!" + s;
		return I;
	}
	Item And (const Item &I2) const {
		Item I;
		I.val = val & I2.val;
		I.s = s + "&" + I2.s;
		return I;
	}
	Item Or (const Item &I2) const {
		Item I;
		I.val = val | I2.val;
		I.s = s + "|" + I2.s;
		return I;
	}
	Item bracketize() const {
		Item I;
		I.val = val;
		I.s = "(" + s + ")";
		return I;
	}

	bool operator < (const Item &I) const {
		if (val == -1) return false;
		if (I.val == -1) return true;
		if (s.length() != I.s.length())
			return s.length() < I.s.length();
		return s < I.s;
	}
};

const int D = 100;
const int N = 256;
Item a[3][N];
vector< pair<Item, int> > q[D];

void tryUpd(Item I, int t) {
	int x = I.val;
	if (x == -1) return;
	if (I < a[t][x]) {
		a[t][x] = I;
		q[I.s.length()].push_back(mp(I, t));
	}
}

void tryGo(Item I, int t) {
//	cout << I.s << endl;
	if (t == 0) {
		Item I2 = I.bracketize();
		tryUpd(I2, 2);
		for (int val2 = 0; val2 < N; val2++) {
			if (a[1][val2].val != -1) {
				I2 = I.Or(a[1][val2]);
				tryUpd(I2, 0);
			}
		}
	} else if (t == 1) {
		tryUpd(I, 0);
		for (int val2 = 0; val2 < N; val2++) {
			if (a[0][val2].val != -1) {
				Item I2 = a[0][val2].Or(I);
				tryUpd(I2, 0);
			}
			if (a[2][val2].val != -1) {
				Item I2 = I.And(a[2][val2]);
				tryUpd(I2, 1);
			}
		}
	} else {
		tryUpd(I, 1);
		Item I2 = I.Not();
		tryUpd(I2, 2);
		for (int val2 = 0; val2 < N; val2++) {
			if (a[1][val2].val != -1) {
				I2 = a[1][val2].And(I);
				tryUpd(I2, 1);
			}
		}
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	tryUpd(Item(128 + 64 + 32 + 16, "x"), 2);
	tryUpd(Item(128 + 64 + 8 + 4, "y"), 2);
	tryUpd(Item(128 + 32 + 8 + 2, "z"), 2);

	for (int d = 1; d < D; d++) {
		for (int i = 0; i < (int)q[d].size(); i++) {
			auto w = q[d][i];
			int val = w.first.val;
			if (a[w.second][val].s != w.first.s) continue;
			tryGo(w.first, w.second);
		}
	}
/*
	for (int x = 0; x < N; x++)
		cout << x << " " << a[0][x].val << " " << a[0][x].s << endl;
*/
	string s;
	
	int t;
	cin >> t;
	while(t--) {
		cin >> s;
		int val = 0;
		for (int i = 7; i >= 0; i--) {
			val *= 2;
			if (s[i] == '1') val++;
		}
		cout << a[0][val].s << "\n";
	}

	return 0;
}