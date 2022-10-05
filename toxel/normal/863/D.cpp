#include<bits/stdc++.h>

const int N = 200010;

int type[N], l[N], r[N], a[N];

int main(){
	int n, q, m;
	scanf("%d%d%d", &n, &q, &m);
	for (int i = 1; i <= n; ++ i){
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= q; ++ i){
		scanf("%d%d%d", &type[i], &l[i], &r[i]);
	}
	for (int i = 0, x; i < m; ++ i){
		scanf("%d", &x);
		for (int j = q; j; -- j){
			if (l[j] <= x && x <= r[j]){
				if (type[j] == 1){
					-- x;
					if (x < l[j]){
						x = r[j];
					}
				}
				else{
					x = r[j] + l[j] - x;
				}
			}
		}
		printf("%d%c", a[x], " \n"[i == m]);
	}
	return 0;
}