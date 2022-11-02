#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
vector<pair<int, int> > blocks;

vector<pair<int, int> > now;

int search(int pos) {
	int p = lower_bound(now.begin(), now.end(), make_pair(pos, 0)) - now.begin();
	int ret = n + 1;
	if (p != (int)now.size()) {
		ret = now[p].first;
	}
	if (p != 0) {
		int l = now[p - 1].first, r = now[p - 1].second;
		if (pos <= r) {
			ret = pos;
		}
	}
	return ret;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		blocks.push_back(make_pair(x, y));
	}
	sort(blocks.begin(), blocks.end());
	int currow = 0;
	now.push_back(make_pair(1, 1));
	for (int i = 0; i < (int)blocks.size(); ++i) {
		vector<pair<int, int> > tmp;
		int j = i;
		while (j < (int)blocks.size() && blocks[j].first == blocks[i].first) {
			tmp.push_back(blocks[j]);
			++j;
		}
		i = j - 1;
		if (tmp.begin()->first != currow + 1) {
			int leftmost = now.begin()->first;
			now.clear();
			now.push_back(make_pair(leftmost, n));
			currow = tmp.begin()->first - 1;
		}
		vector<pair<int, int> > next;
		int leftmost = now.begin()->first;
		if (leftmost < tmp.begin()->second) {
			next.push_back(make_pair(leftmost, tmp.begin()->second - 1));
		}
		for (int k = 0; k < (int)tmp.size(); ++k) {
			int l = tmp[k].second, r = k == tmp.size() - 1 ? n + 1 : tmp[k + 1].second;	
			int v = search(l + 1);
			if (v < r) {
				next.push_back(make_pair(v, r - 1));
			}
		}
		now = next;
		currow = tmp.begin()->first;
		if (now.size() == 0) {
			printf("-1\n");
			return 0;
		}
	}
	if (currow < n) {
		int leftmost = now.begin()->first;
		now.clear();
		now.push_back(make_pair(leftmost, n));
		currow = n;
	}
	if (now.back().second != n) {
		printf("-1\n");
		return 0;
	}
	printf("%d\n", 2 * n - 2);
	return 0;
}