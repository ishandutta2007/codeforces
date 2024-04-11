#include<map>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 25;

int x[N], y[N], z[N];

int n;

map<pair<int, int>, pair<int, int> > mem;

#define left LEFT
#define right RIGHT

int left, right;

int ans = -1000000000;

long long ansWay1, ansWay2;

void go(int i, int ab, int ac, int a, int way) {
	if (i == left) {
		pair<int, int> p = make_pair(ab, ac);
		if (!mem.count(p)) {
			mem[p] = make_pair(a, way);
		} else {
			mem[p] = max(mem[p], make_pair(a, way));
		}
		return;
	}
	go(i + 1, ab + x[i] - y[i], ac + x[i], a + x[i], way * 3 + 0);
	go(i + 1, ab + x[i], ac + x[i] - z[i], a + x[i], way * 3 + 1);
	go(i + 1, ab - y[i], ac - z[i], a, way * 3 + 2);
}

void go2(int i, int ab, int ac, int a, long long way) {
	if (i == n) {
		pair<int, int> p = make_pair(-ab, -ac);
		if (mem.count(p)) {
			if (mem[p].first + a > ans) {
				ans = mem[p].first + a;
				ansWay1 = mem[p].second;
				ansWay2 = way;
			}
		}
		return;
	}
	go2(i + 1, ab + x[i] - y[i], ac + x[i], a + x[i], way * 3 + 0);
	go2(i + 1, ab + x[i], ac + x[i] - z[i], a + x[i], way * 3 + 1);
	go2(i + 1, ab - y[i], ac - z[i], a, way * 3 + 2);
}

void printAns(long long way, int n) {
	vector<pair<char, char> > ans;
	for (int i = 0; i < n; ++i) {
		if (way % 3 == 0) {
			ans.push_back(make_pair('L', 'M'));
		} else if (way % 3 == 1) {
			ans.push_back(make_pair('L', 'W'));
		} else if (way % 3 == 2) {
			ans.push_back(make_pair('M', 'W'));
		}
		way /= 3;
	}
	for (int i = n - 1; i >= 0; --i) {
		printf("%c%c\n", ans[i].first, ans[i].second);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d%d", x + i, y + i, z + i);
	}
	left = n / 2, right = n - left;
	go(0, 0, 0, 0, 0);
	go2(left, 0, 0, 0, 0);
	if (ans != -1000000000) {
		printAns(ansWay1, left);
		printAns(ansWay2, right);
	} else {
		puts("Impossible");
	}
	return 0;
}