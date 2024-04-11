#include<bits/stdc++.h>

const int N = 100010;
typedef long long ll;

int l[N], e[N];

int check(int now, int target, int *x, int n){
	int sit1 = std::lower_bound(x, x + n, now) - x;
	int sit2 = std::lower_bound(x, x + n, target) - x;
	if (sit1 != sit2){
		return std::abs(target - now);
	}
	int min = INT_MAX;
	if (sit1){
		min = std::min(min, now + target - 2 * x[sit1 - 1]);
	}
	if (sit1 != n){
		min = std::min(min, 2 * x[sit1] - now - target);
	}
	return min;
}

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	int cl, ce;
	scanf("%d%d", &cl, &ce);
	int v;
	scanf("%d", &v);
	for (int i = 0; i < cl; ++ i){
		scanf("%d", &l[i]);
	}
	for (int i = 0; i < ce; ++ i){
		scanf("%d", &e[i]);
	}
	int q;
	scanf("%d", &q);
	while (q --){
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &y1, &x1, &y2, &x2);
		if (y1 == y2){
			printf("%d\n", std::abs(x2 - x1));
			continue;
		}
		ll min = LLONG_MAX;
		min = std::min(min, (ll) std::abs(y2 - y1) + check(x1, x2, l, cl));
		min = std::min(min, (ll) (std::abs(y2 - y1) - 1) / v + 1 + check(x1, x2, e, ce));
		printf("%I64d\n", min);
	}
	return 0;
}