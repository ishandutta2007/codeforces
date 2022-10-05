#include<bits/stdc++.h>

const int N = 200010;
typedef std::pair <int, int> pii;
const int MAX = 1 << 18;

int seg[MAX << 1];
int n, x;
std::vector <pii> vec[N];

void add(int sit, int value){
	seg[sit += MAX] = value;
	for (sit >>= 1; sit; sit >>= 1){
		seg[sit] = std::min(seg[sit << 1], seg[sit << 1 | 1]);
	}
}

int query(int l, int r){
	int ret = INT_MAX;
	for (l += MAX, r += MAX + 1; l < r; l >>= 1, r >>= 1){
		if (l & 1) ret = std::min(ret, seg[l ++]);
		if (r & 1) ret = std::min(ret, seg[-- r]);
	}
	return ret;
}

int main(){
	scanf("%d%d", &n, &x);
	for (int i = 0, l, r, c; i < n; ++ i){
		scanf("%d%d%d", &l, &r, &c);
		vec[r - l + 1].push_back({l, c});
	}
	for (int i = 0; i < MAX << 1; ++ i){
		seg[i] = INT_MAX;
	}
	int ans = INT_MAX;
	for (int i = 1; i < x; ++ i){
		for (auto u : vec[i]){
			add(u.first, std::min(seg[u.first + MAX], u.second));
		}
		for (auto u : vec[x - i]){
			int y = query(u.first + x - i, MAX - 1);
			if (y != INT_MAX){
				ans = std::min(u.second + y, ans);
			}
		}
		for (auto u : vec[i]){
			add(u.first, INT_MAX);
		}
	}
	return printf("%d\n", ans == INT_MAX ? -1 : ans), 0;
}