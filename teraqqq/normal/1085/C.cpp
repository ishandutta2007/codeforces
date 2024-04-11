#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const long long INF = 1e8;

const int N = 1001;

struct S {
	int mx, my;
} s[3];

int mny=INF, mxy;
bool d[N][N];
vector<S> ans;

void addp(int x, int y) {
	if(!d[x][y]) {
		d[x][y] = true;
		ans.push_back({ x, y });
	}
}

int main() {
	for(int i = 0; i < 3; ++i) {
		cin >> s[i].mx >> s[i].my;
		mny = min(mny, s[i].my);
		mxy = max(mxy, s[i].my);
	}

	sort(s, s + 3, [](S& a, S& b) {
		return a.mx < b.mx;
	});

	for(int i = mny; i <= mxy; ++i)
		addp(s[1].mx, i);
	for(int k = 0; k < 3; ++k) {
		for(int j = s[k].mx; j != s[1].mx; j > s[1].mx ? --j : ++j)
			addp(j, s[k].my);
	}

	cout << ans.size() << endl;
	for(S s : ans) {
		cout << s.mx << ' ' << s.my << endl;
	}
}