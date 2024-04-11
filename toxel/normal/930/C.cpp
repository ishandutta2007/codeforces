#include<bits/stdc++.h>

const int N = 100010;
const int MAX = 1 << 17;

int n, m;
int cnt[N], ans[N], tmp[N];
int seg[MAX << 1];

void add(int sit, int value){
	seg[sit += MAX] = value;
	for (sit >>= 1; sit; sit >>= 1){
		seg[sit] = std::max(seg[sit << 1], seg[sit << 1 | 1]);
	}
}

int query(int l, int r){
	int ret = 0;
	for (l += MAX, r += MAX + 1; l < r; l >>= 1, r >>= 1){
		if (l & 1) ret = std::max(ret, seg[l ++]);
		if (r & 1) ret = std::max(ret, seg[-- r]);
	}
	return ret;
}

void solve(int n, int *a){
	memset(seg, 0, sizeof(seg));
	memset(ans, 0, sizeof(ans));
	for (int i = 1; i <= n; ++ i){
		ans[i] = query(0, a[i]) + 1;
		add(a[i], ans[i]);
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 0, l, r; i < n; ++ i){
		scanf("%d%d", &l, &r);
		++ cnt[l];
		-- cnt[r + 1];
	}
	for (int i = 1; i <= m + 1; ++ i){
		cnt[i] += cnt[i - 1];
	}
	solve(m, cnt);
	for (int i = 1; i <= m; ++ i){
		tmp[i] = ans[i];
	}
	std::reverse(cnt + 1, cnt + m + 1);
	solve(m, cnt);
	std::reverse(ans + 1, ans + m + 1);
	int ret = 0;
	for (int i = 1; i <= m; ++ i){
		ret = std::max(ret, ans[i] + tmp[i] - 1);
	}
	printf("%d\n", ret);
	return 0;
}