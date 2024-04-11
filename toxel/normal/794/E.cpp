#include<bits/stdc++.h>

const int N = 300010;
const int MAX = 1 << 19;

int segodd[MAX << 1], segeven[MAX << 1];

void add(int *seg, int sit, int value){
	for (sit += MAX, seg[sit] = std::max(value, seg[sit]), sit >>= 1; sit; seg[sit] = std::max(seg[sit << 1], seg[sit << 1 | 1]), sit >>= 1);
}

int query(int *seg, int l, int r){
	int ret = 0;
	for (l += MAX, r += MAX + 1; l < r; l >>= 1, r >>= 1){
		if (l & 1){
			ret = std::max(ret, seg[l ++]);
		}
		if (r & 1){
			ret = std::max(ret, seg[-- r]);
		}
	}
	return ret;
}

int a[N];
int n;

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n - 1; ++ i){
		add(segeven, i, std::max(a[i], a[i + 1]));
	}
	for (int i = 1; i < n - 1; ++ i){
		add(segodd, i, std::min(a[i], std::max(a[i - 1], a[i + 1])));
	}
	for (int i = 0; i < n; ++ i){
		if (n - i == 1){
			int max = 0;
			for (int j = 0; j < n; ++ j){
				max = std::max(max, a[j]);
			}
			return printf("%d\n", max), 0;
		}
		int left = n - i - 1 >> 1, right = i + (n - i - 1 >> 1);
		if (n - i & 1){
			printf("%d\n", query(segodd, left, right));
		}
		else{
			printf("%d\n", query(segeven, left, right));
		}
	}
}