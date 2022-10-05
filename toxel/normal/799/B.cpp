#include<bits/stdc++.h>

const int N = 200010;

std::set <int> set[3];
int n, m;
int p[N], a[N], b[N];

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		scanf("%d", &p[i]);
	}
	for (int i = 0; i < n; ++ i){
		scanf("%d", &a[i]);
		-- a[i];
		set[a[i]].insert(p[i]);
	}
	for (int i = 0; i < n; ++ i){
		scanf("%d", &b[i]);
		-- b[i];
		set[b[i]].insert(p[i]);
	}
	scanf("%d", &m);
	for (int i = 0, x; i < m; ++ i){
		scanf("%d", &x);
		-- x;
		if (!(int) set[x].size()){
			printf("-1 ");
			continue;
		}
		int price = *(set[x].begin());
		for (int i = 0; i < 3; ++ i){
			set[i].erase(price);
		}
		printf("%d ", price);
	}
	return printf("\n"), 0;
}