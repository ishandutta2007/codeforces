#include<bits/stdc++.h>

const int N = 100010;
const int MAX = 1 << 17;

int n;
int a[N], seg[2][MAX << 1];

void add(int *seg, int sit, int value){
	seg[sit += MAX] = value;
	for (sit >>= 1; sit; sit >>= 1){
		seg[sit] = std::min(seg[sit << 1], seg[sit << 1 | 1]);
	}
}

int query(int *seg, int l, int r){
	int ret = INT_MAX;
	for (l += MAX, r += MAX + 1; l < r; l >>= 1, r >>= 1){
		if (l & 1) ret = std::min(ret, seg[l ++]);
		if (r & 1) ret = std::min(ret, seg[-- r]);
	}
	return ret;
}

bool check(int mid){
	for (int i = mid; i < n - mid; ++ i){
		int x = query(seg[0], i, i + mid) - i - mid;
		int y = query(seg[1], i - mid, i) + i - mid;
		if (std::min(x, y) > 0) return false;
	}
	return true;
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		scanf("%d", &a[i]);
		add(seg[0], i, a[i] + i);
		add(seg[1], i, a[i] - i);
	}
	int left = 0, right = n + 1 >> 1;
	while (left < right){
		int mid = left + right >> 1;
		if (check(mid)){
			right = mid;
		}
		else{
			left = mid + 1;
		}
	}
	return printf("%d\n", left), 0;
}