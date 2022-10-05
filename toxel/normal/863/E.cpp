#include<bits/stdc++.h>

const int MAX = 1 << 19;

int seg[MAX << 1], l[MAX], r[MAX];
int n;
std::map <int, int> Hash;

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
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		scanf("%d%d", &l[i], &r[i]);
		++ Hash[l[i]];
		-- Hash[r[i] + 1];
	}
	int now = 0, cnt = 0;
	for (auto &u : Hash){
		now += u.second;
		add(cnt, now);
		u.second = cnt ++;
	}
	for (int i = 0; i < n; ++ i){
		int sit1 = Hash[l[i]], sit2 = Hash[r[i] + 1];
		if (query(sit1, sit2 - 1) >= 2){
			return printf("%d\n", i + 1), 0;
		}
	}
	return printf("-1\n"), 0;
}