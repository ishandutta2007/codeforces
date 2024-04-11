#include<bits/stdc++.h>

int readin(){
	char ch;
	ch = getchar();
	while (ch < '0' || ch > '9'){
		ch = getchar();
	}
	int ret = 0;
	while (ch >= '0' && ch <= '9'){
		ret = ret * 10 + ch - '0';
		ch = getchar();
	}
	return ret;
}

void write(int x){
	if (x >= 10){
		write(x / 10);
	}
	putchar(x % 10 + '0');
}

const int N = 200010;
const int MAX = 1 << 18;

std::pair <int, int> seg[2][MAX << 1], p[N];
int n;
int a[N], ans[N];

void pull(int type, int sit){
	seg[type][sit] = type ? std::max(seg[type][sit << 1], seg[type][sit << 1 | 1]) : std::min(seg[type][sit << 1], seg[type][sit << 1 | 1]);
}

void build(int type){
	for (int i = 0; i <= n + 1; ++ i){
		seg[type][i + MAX] = {0, i};
	}
	for (int i = MAX - 1; i; -- i){
		pull(type, i);
	}
}

void add(int type, int sit, int value){
	for (sit += MAX, seg[type][sit].first = value, sit >>= 1; sit; sit >>= 1){
		pull(type, sit);
	}
}

int query(int type, int l, int r){
	std::pair <int, int> ret = type ? std::make_pair(-INT_MAX, INT_MAX) : std::make_pair(INT_MAX, INT_MAX);
	for (l += MAX, r += MAX + 1; l < r; l >>= 1, r >>= 1){
		if (l & 1){
			if (type){
				ret = std::max(seg[type][l ++], ret);
			}
			else{
				ret = std::min(seg[type][l ++], ret);
			}
		}
		if (r & 1){
			if (type){
				ret = std::max(seg[type][-- r], ret);
			}
			else{
				ret = std::min(seg[type][-- r], ret);
			}
		}
	}
	return ret.second;
}

int main(){
	n = readin();
	for (int i = 1; i <= n; ++ i){
		a[i] = readin();
		p[i] = {a[i], i};
	}
	std::sort(p + 1, p + n + 1, std::greater <std::pair <int, int>>());
	build(0);
	build(1);
	for (int i = 1; i <= n; ++ i){
		int x1 = query(1, 0, p[i].second - 1), x2 = query(0, p[i].second + 1, n + 1);
		ans[i] = x2 - x1 - 1;
		add(0, p[i].second, p[i].first);
		add(1, p[i].second, -p[i].first);
	}
	for (int i = 1, j = 1; i <= n; ++ i){
		while (ans[j] < i){
			++ j;
		}
		write(p[j].first);
		putchar(' ');
	}
	return printf("\n"), 0;
}