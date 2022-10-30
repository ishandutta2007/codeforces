#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 300005;
int n, num[N], pos[N];

struct Data {
	pair<int, int> val[2];	
	
	Data & operator += (const pair<int, int> key) {
		for (int j = 0; j < 2; ++j) {
			if (key.first == val[j].first) {
				val[j].second += key.second;
				return *this;
			}
			if (key.first < val[j].first) {
				for (int k = 1; k > j; --k) {
					val[k] = val[k - 1];
				}
				val[j] = key;
				return *this;
			}
		}
		return *this;
	}
};

Data merge(Data a, const Data b) {
	return (a += b.val[0]) += b.val[1];
}

int tag[N << 1];
Data data[N << 1];

int getID(const int l, const int r) {
	return l + r | l != r;
}

void update(const int l, const int r) {
	int k = (l + r) >> 1;
	data[getID(l, r)] = merge(data[getID(l, k)], data[getID(k + 1, r)]);
}

void segChange(const int l, const int r, const int a, const int b, const int val) ;

void pushdown(const int l, const int r) {
	int x = getID(l, r);
	if (tag[x]) {
		int k = (l + r) >> 1;
		segChange(l, k, l, r, tag[x]);
		segChange(k + 1, r, l, r, tag[x]);
		tag[x] = 0;
		update(l, r);		
	}
}

void segInit(const int l, const int r) {
	data[getID(l, r)].val[0] = make_pair(0, r - l + 1);
	data[getID(l, r)].val[1] = make_pair(1, 0);
	if (l == r) {
		return;
	}
	int k = (l + r) >> 1;
	segInit(l, k);
	segInit(k + 1, r);
}

void segChange(const int l, const int r, const int a, const int b, const int val) {
	if (b < l || r < a) {
		return;
	}
	if (a <= l && r <= b) {
		int x = getID(l, r);
		tag[x] += val;
		data[x].val[0].first += val;
		data[x].val[1].first += val;
		return;
	}
	pushdown(l, r);
	int k = (l + r) >> 1;
	segChange(l, k, a, b, val);
	segChange(k + 1, r, a, b, val);
	update(l, r);
}

Data segAsk(const int l, const int r, const int a, const int b) {
	if (a <= l && r <= b) {
		return data[getID(l, r)];	
	}
	pushdown(l, r);
	int k = (l + r) >> 1;
	if (b <= k) {
		return segAsk(l, k, a, b);
	}
	if (a > k) {
		return segAsk(k + 1, r, a, b);
	}
	return merge(segAsk(l, k, a, b), segAsk(k + 1, r, a, b));
}

int main() {
	scanf("%d", &n);
	if (n == 1) {
		printf("0\n");
		return 0;
	}
	segInit(0, n - 1);
	for (int i = 0; i < n; ++i) {
		scanf("%d", num + i);
		--num[i];
		pos[num[i]] = i;
	}
	long long ans = 0;
	for (int i = n - 1; i >= 0; --i) {
		segChange(0, n - 1, i, n - 1, 1);
		if (pos[i] > 0) {
			int tp = num[pos[i] - 1];
			if (tp > i) {
				segChange(0, n - 1, tp, n - 1, -1);
			}
		}
		if (pos[i] < n - 1) {
			int tp = num[pos[i] + 1];
			if (tp > i) {
				segChange(0, n - 1, tp, n - 1, -1);
			}
		}
		if (i < n - 1) {
			Data ret = segAsk(0, n - 1, i + 1, n - 1);
			for (int j = 0; j < 2; ++j) {
				if (ret.val[j].first <= 2) {
					ans += ret.val[j].second;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}