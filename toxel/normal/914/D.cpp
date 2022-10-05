#include<bits/stdc++.h>

const int MAX = 1 << 19;

int seg[MAX << 1];

void add(int sit, int value){
	seg[sit += MAX] = value;
	for (sit >>= 1; sit; sit >>= 1){
		seg[sit] = std::__gcd(seg[sit << 1], seg[sit << 1 | 1]);
	}
}

int query(int l, int r){
	int ret = seg[l + MAX];
	for (l += MAX, r += MAX + 1; l < r; l >>= 1, r >>= 1){
		if (l & 1) ret = std::__gcd(ret, seg[l ++]);
		if (r & 1) ret = std::__gcd(ret, seg[-- r]);
	}
	return ret;
}

int a[MAX];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		scanf("%d", &a[i]);
		add(i, a[i]);
	}
	int q;
	scanf("%d", &q);
	while (q --){
		int type;
		scanf("%d", &type);
		if (type == 1){
			int l, r, x;
			scanf("%d%d%d", &l, &r, &x);
			-- l, -- r;
			bool flag = true;
			while (l < r){
				int mid = l + r >> 1;
				int y = query(l, mid);
				int z = query(mid + 1, r);
				if (y % x && z % x){
					flag = false;
					break;
				}
				if (y % x){
					r = mid;
					continue;
				}
				if (z % x){
					l = mid + 1;
					continue;
				}
				break;
			}
			puts(flag ? "YES" : "NO");
		}
		else{
			int sit, y;
			scanf("%d%d", &sit, &y);
			add(sit - 1, y);
		}
	}
	return 0;
}