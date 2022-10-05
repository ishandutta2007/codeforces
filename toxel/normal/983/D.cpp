#include<bits/stdc++.h>

const int N = 100010;
const int MAX = 1 << 18;

struct event{
	int y1, y2;
	int id;
	bool add;
};

std::set <int> seg[MAX << 1];
int c[N << 1];
int x[N << 1], y[N << 1], min[MAX << 1], max[MAX << 1];
int x1[N], y1[N], x2[N], y2[N];
std::vector <event> vec[N << 1];
std::set <int> ans;

void compress(int *a, int n){
	for (int i = 0; i < n; ++ i){
		c[i] = a[i];
	}
	std::sort(c, c + n);
	int cnt = std::unique(c, c + n) - c;
	for (int i = 0; i < n; ++ i){
		a[i] = std::lower_bound(c, c + cnt, a[i]) - c;
	}
}

void pull(int sit){
	if (sit >= MAX){
		int x = seg[sit].empty() ? 0 : *(-- seg[sit].end());
		max[sit] = x ? (ans.count(x) ? 0 : x) : 0;
		min[sit] = x;
		return;
	}
	int maxchild = std::max(max[sit << 1], max[sit << 1 | 1]);
	int minchild = std::min(min[sit << 1], min[sit << 1 | 1]);
	int x = seg[sit].empty() ? 0 : *(-- seg[sit].end());
	if (x && x > maxchild){
		if (ans.count(x) || x < minchild){
			max[sit] = 0;
		}
		else{
			max[sit] = x;
		}
	}
	else{
		max[sit] = maxchild;
	}
	min[sit] = std::max(x, minchild);
}

void add(int sit, int l, int r, int ql, int qr, int value, int type){
	if (ql <= l && qr >= r){
		if (type == 1){
			seg[sit].erase(value);
		}
		else if (type == 0){
			seg[sit].insert(value);
		}
		pull(sit);
		return;
	}
	int mid = l + r >> 1;
	if (ql <= mid){
		add(sit << 1, l, mid, ql, qr, value, type);
	}
	if (mid < qr){
		add(sit << 1 | 1, mid + 1, r, ql, qr, value, type);
	}
	pull(sit);
}

void add(int ql, int qr, int value, int type){
	add(1, 0, MAX - 1, ql, qr, value, type);
}

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		scanf("%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i]);
	}
	for (int i = 0; i < n; ++ i){
		x[i << 1] = x1[i];
		x[i << 1 | 1] = x2[i];
		y[i << 1] = y1[i];
		y[i << 1 | 1] = y2[i];
	}
	compress(x, n << 1);
	compress(y, n << 1);
	for (int i = 0; i < n; ++ i){
		x1[i] = x[i << 1];
		x2[i] = x[i << 1 | 1];
		y1[i] = y[i << 1];
		y2[i] = y[i << 1 | 1];
		vec[x1[i]].push_back({y1[i], y2[i], i + 1, true});
		vec[x2[i]].push_back({y1[i], y2[i], i + 1, false});
	}
	for (int i = 0; i < N << 1; ++ i){
		for (auto u : vec[i]){
			add(u.y1, u.y2 - 1, u.id, u.add ? 0 : 1);
		}
		int num;
		while (num = max[1]){
			ans.insert(num);
			add(y1[num - 1], y2[num - 1] - 1, num, 2);
		}
	}
	ans.insert(0);
	printf("%d\n", (int) ans.size());
	return 0;
}