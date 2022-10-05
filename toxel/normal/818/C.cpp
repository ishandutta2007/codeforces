#include<bits/stdc++.h>

const int N = 100010;

int up[N], down[N], left[N], right[N], x1[N], x2[N], y1[N], y2[N];
int d, n, m, cntu, cntd, cntl, cntr;

int main(){
	scanf("%d%d%d", &d, &n, &m);
	for (int i = 0; i < d; ++ i){
		scanf("%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i]);
		if (x1[i] > x2[i]){
			std::swap(x1[i], x2[i]);
		}
		if (y1[i] > y2[i]){
			std::swap(y1[i], y2[i]);
		}
		++ left[x1[i]];
		++ right[x2[i]];
		++ up[y1[i]];
		++ down[y2[i]];
	}
	for (int i = 1; i <= n; ++ i){
		left[i] += left[i - 1];
	}
	for (int i = n; i; -- i){
		right[i] += right[i + 1];
	}
	for (int i = 1; i <= m; ++ i){
		up[i] += up[i - 1];
	}
	for (int i = m; i; -- i){
		down[i] += down[i + 1];
	}
	scanf("%d%d%d%d", &cntl, &cntr, &cntu, &cntd);
	for (int i = 0; i < d; ++ i){
		if (x1[i] < x2[i]){
			if (left[x2[i] - 1] - 1 == cntl && right[x1[i] + 1] - 1 == cntr && up[y2[i] - 1] == cntu && down[y1[i] + 1] == cntd){
				return printf("%d\n", i + 1), 0;
			}
		}
		else{
			if (left[x2[i] - 1] == cntl && right[x1[i] + 1] == cntr && up[y2[i] - 1] - 1 == cntu && down[y1[i] + 1] - 1 == cntd){
				return printf("%d\n", i + 1), 0;
			}
		}
	}
	return printf("-1\n"), 0;
}