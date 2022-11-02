#include<vector>
#include<cstdio>
#include<cstring>
#include<climits>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1000005, M = 100005;
int n;
char s[N]; 
int l[M], r[M], ans[M], match[N];
vector<int> stack;

int tr[N];

void insert(int pos, int val) {
	while (pos <= n) {
		tr[pos] += val;
		pos += pos & -pos;
	}
}

int getsum(int pos) {
	int ret = 0;
	while (pos) {
		ret += tr[pos];
		pos -= pos & -pos;
	}
	return ret;
}

int getsum(int l, int r) {
	return getsum(r) - getsum(l - 1);
}

int main() {
	scanf("%s", s);
	n = strlen(s);
	for (int i = 0; i < n; ++i) {
		if (s[i] == '(') {
			stack.push_back(i);
		} else {
			if (stack.size()) {
				match[stack.back()] = i;
				stack.pop_back();
			}
		}
	}
	memset(tr, 0, sizeof(tr));
	vector<pair<int, pair<int, int> > > evt;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '(' && match[i]) {
			insert(match[i] + 1, 1);
			evt.push_back(make_pair(i + 1,	make_pair(INT_MAX, match[i] + 1))); 
		}
	}
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", l + i, r + i);
		evt.push_back(make_pair(l[i], make_pair(INT_MIN, i)));
	}
	sort(evt.begin(), evt.end());
	for (int i = 0; i < (int)evt.size(); ++i) {
		if (evt[i].second.first > 0) {
			insert(evt[i].second.second, -1);
		} else {
			int v = evt[i].second.second;
			ans[v] = getsum(l[v], r[v]) * 2;
		}
	}
	for (int i = 0; i < m; ++i) {
		printf("%d\n", ans[i]);
	}
	return 0;
}