#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 500005;

int n, d[N];

long long presumd[N], sufsumdk[N], sufsumdkp[N];

#define prev PREV

long long sufv[N], prev[N], sufmin[N], premax[N];

bool prek[N], preksum[N];

void prepare() {
	presumd[0] = 0;
	for (int i = 1; i <= n; ++i) {
		presumd[i] = presumd[i - 1] + d[i];
	}
	sufsumdk[n] = 0;
	priority_queue<int> heap;
	long long heapsum = 0;
	int nonheapcnt = 0;
	for (int k = n - 1; k >= 1; --k) {
		heap.push(d[k + 1]);	
		heapsum += d[k + 1];
		while (heap.size() && heap.top() > k) {
			heapsum -= heap.top();
			heap.pop();
			nonheapcnt++;
		}
		sufsumdk[k] = heapsum + (long long)k * nonheapcnt;
	}

	sufsumdkp[n] = 0;
	while (heap.size()) {
		heap.pop();
	}
	heapsum = 0;
	nonheapcnt = 0;
	for (int k = n - 1; k >= 0; --k) {
		heap.push(d[k + 1]);	
		heapsum += d[k + 1];
		while (heap.size() && heap.top() > k + 1) {
			heapsum -= heap.top();
			heap.pop();
			nonheapcnt++;
		}
		sufsumdkp[k] = heapsum + (long long)(k + 1) * nonheapcnt;
	}

	preksum[0] = true;
	for (int k = 1; k <= n; ++k) {
		sufv[k] = (long long)k * (k + 1) + sufsumdkp[k] - presumd[k];
		prev[k] = presumd[k] - (long long)k * (k - 1) - sufsumdk[k];
		prek[k] = k >= prev[k];
		preksum[k] = prek[k] && preksum[k - 1];
	}

	sufmin[n] = sufv[n];
	for (int k = n - 1; k >= 1; --k) {
		sufmin[k] = min(sufmin[k + 1], sufv[k]);
	}

	premax[1] = prev[1];
	for (int k = 2; k <= n; ++k) {
		premax[k] = max(premax[k - 1], prev[k]);
	}
}

bool check(int dhat, int pos) {
	bool ret = true;
	if (pos == 0) {
		ret = dhat <= sufmin[1] &&
			  dhat <= sufsumdkp[0];
	} else if (pos < n) {
		ret = (dhat <= sufmin[pos]) && 
			  (dhat >= premax[pos]) && preksum[pos];
	} else {
		ret = (dhat >= premax[n]) && preksum[n] && 
				((presumd[n] + dhat) <= (long long)n * (n + 1));
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	int parity = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", d + i);
		parity ^= d[i] & 1;
	}
	sort(d + 1, d + n + 1);
	reverse(d + 1, d + n + 1);
	prepare();
	vector<int> ans;
	for (int can = parity, pos = n; can <= n; can += 2) {
		while (pos && can > d[pos]) {
			--pos;
		}
		if (check(can, pos)) {
			ans.push_back(can);
		}
	}
	if (ans.size() == 0) {
		printf("-1\n");
	} else {
		sort(ans.begin(), ans.end());
		for (int i = 0; i < (int)ans.size(); ++i) {
			printf("%d%c", ans[i], i + 1 == (int)ans.size() ? '\n' : ' ');
		}
	}
	return 0;
}