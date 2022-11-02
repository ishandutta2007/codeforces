#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int m;
vector<pair<int, pair<int, char> > > ans;

void move(int x, int y) {
	if (x != 0) {
		ans.push_back(make_pair(1, make_pair(abs(x), x > 0 ? 'R' : 'L')));
	}
	if (y != 0) {
		ans.push_back(make_pair(1, make_pair(abs(y), y > 0 ? 'U' : 'D')));
	}
}

void go(int x, int y) {
	move(x, y);
	ans.push_back(make_pair(2, make_pair(0, ' ')));
	move(-x, -y);
	ans.push_back(make_pair(3, make_pair(0, ' ')));
}

struct Bomb {
	int x, y, l;

	Bomb(int x, int y) : x(x), y(y) {
		l = abs(x) + abs(y);
	}
};

bool operator < (Bomb a, Bomb b) {
	return a.l < b.l;
}

int main() {
	scanf("%d", &m);
	vector<Bomb> v;
	for (int i = 0; i < m; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		v.push_back(Bomb(x, y));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < m; ++i) {
		go(v[i].x, v[i].y);
	}
	printf("%d\n", (int)ans.size());
	for (int i = 0; i < (int)ans.size(); ++i) {
		if (ans[i].first == 1) {
			printf("%d %d %c\n", ans[i].first, ans[i].second.first, ans[i].second.second);
		} else {
			printf("%d\n", ans[i].first);
		}
	}
	return 0;
}