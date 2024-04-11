#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100005;
int n, m, s, c[N];
vector<pair<int, int> > stu, bug;
int ans[N];

bool check(int d) {
	int left = s;
	priority_queue<pair<int, int> > heap;
	int i = m - 1, j = n - 1;
	while (i >= 0) {
		//now solve i
		while (j >= 0 && stu[j].first >= bug[i].first) {
			heap.push(make_pair(-c[stu[j].second], stu[j].second));
			--j;
		}
		if (heap.size() == 0 || left < -heap.top().first) {
			return false;
		}
		int now = heap.top().second;
		heap.pop();
		left -= c[now];
		for (int k = 0; k < d && i >= 0; ++k, --i) {
			ans[bug[i].second] = now;
		}
	}
	return true;
}

int main() {
	scanf("%d%d%d", &n, &m, &s);
	for (int i = 0; i < m; ++i) {
		int a;
		scanf("%d", &a);
		bug.push_back(make_pair(a, i));
	}
	sort(bug.begin(), bug.end());
	for (int i = 0; i < n; ++i) {
		int b;
		scanf("%d", &b);
		stu.push_back(make_pair(b, i));
	}
	sort(stu.begin(), stu.end());
	for (int i = 0; i < n; ++i) {
		scanf("%d", c + i);
	}
	int l = 0, r = n + 1, mid;
	if (!check(r)) {
		printf("NO\n");
		return 0;
	}
	while (l < r) {
		mid = l + r >> 1;	
		if (check(mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	check(r);
	puts("YES");
	for (int i = 0; i < m; ++i) {
		printf("%d%c", ans[i] + 1, " \n"[i == m - 1]);
	}
	return 0;
}