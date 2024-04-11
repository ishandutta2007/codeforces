#include<set>
#include<vector>
#include<cstdio>
#include<climits>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 300005;
int n, m, ans[N];

int main() {
	scanf("%d%d", &n, &m);
	set<int> t;
	for (int i = 0; i < n; ++i) {
		t.insert(i);	
		ans[i] = 0;
	}
	for (int i = 0; i < m; ++i) {
		int l, r;
		int win;
		scanf("%d%d%d", &l, &r, &win);
		--l, --r, --win;
		vector<int> defeat;
		for (set<int>::iterator it = t.lower_bound(l); it != t.end() && *it <= r; ++it) {
			if (*it != win) {
				defeat.push_back(*it);
			}
		}
		for (int i = 0; i < (int)defeat.size(); ++i) {
			ans[defeat[i]] = win + 1;
			t.erase(defeat[i]);
		}
	}
	for (int i = 0; i < n; ++i) {
		printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
	}
	return 0;
}