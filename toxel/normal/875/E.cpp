#include<bits/stdc++.h>

const int N = 100010;
const int MAX = 1 << 17;
inline int lowbit(int n){return n & -n;}

int seg[MAX << 1], seg1, c[N];

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

void addf(int sit, int value){
	for ( ; sit < N; sit += lowbit(sit)){
		c[sit] += value;
	}
}

int queryf(int sit){
	int ret = 0;
	for ( ; sit; sit -= lowbit(sit)){
		ret += c[sit];
	}
	return ret;
}

int n, x[N], rsit[N], disc[N * 3];

int main(){
	int n, s1, s2;
	scanf("%d%d%d", &n, &s1, &s2);
	int max = std::max(s1, s2), min = std::min(s1, s2);
	for (int i = 1; i <= n; ++ i){
		scanf("%d", &x[i]);
		max = std::max(max, x[i]);
		min = std::min(min, x[i]);
	}
	int left = std::abs(s2 - s1), right = max - min;
	while (left < right){
		int mid = left + right >> 1;
		disc[0] = s1, disc[1] = s2;
		int cnt = 2;
		for (int i = 1; i <= n; ++ i){
			disc[cnt ++] = x[i];
		}
		std::sort(disc, disc + cnt);
		cnt = std::unique(disc, disc + cnt) - disc;
		memset(seg, 0x7f, sizeof(seg));
		memset(c, 0, sizeof(c));
		for (int i = n; i; -- i){
			int l = std::lower_bound(disc, disc + cnt, x[i] - mid) - disc;
			int r = std::upper_bound(disc, disc + cnt, x[i] + mid) - disc;
			rsit[i] = std::min(query(0, l - 1), query(r, cnt - 1));
			int sit = std::lower_bound(disc, disc + cnt, x[i]) - disc;
			add(sit, std::min(seg[sit + MAX], i));
		}
		int l = std::lower_bound(disc, disc + cnt, s1 - mid) - disc;
		int r = std::lower_bound(disc, disc + cnt, s1 + mid) - disc;
		int rs1 = std::min(query(0, l - 1), query(r + 1, MAX - 1));
		l = std::lower_bound(disc, disc + cnt, s2 - mid) - disc;
		r = std::lower_bound(disc, disc + cnt, s2 + mid) - disc;
		int rs2 = std::min(query(0, l - 1), query(r + 1, cnt - 1));
		addf(1, 1);
		addf(std::max(rs1, rs2), -1);
		for (int i = 1; i <= n; ++ i){
			int value = queryf(i);
			if (i < n && std::abs(x[i] - x[i + 1]) > mid){
				value = 0;
				addf(i, -value);
				addf(i + 1, value);
			}
			if (value){
				addf(i + 1, 1);
				addf(rsit[i], -1);
			}
		}
		if (queryf(n)){
			right = mid;
		}
		else{
			left = mid + 1;
		}
	}
	return printf("%d\n", left), 0;
}