#include<bits/stdc++.h>

const int N = 200010;
typedef std::pair <int, int> pii;

int a[N], b[N];
pii p[N];
int ans[N];

int main(){
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; ++ i){
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < m; ++ i){
		scanf("%d", &b[i]);
		p[i] = {-b[i], i};
	}
	std::sort(p, p + m);
	std::sort(a, a + m);
	for (int i = 0; i < m; ++ i){
		ans[p[i].second] = a[i];
	}
	for (int i = 0; i < m; ++ i){
		printf("%d%c", ans[i], " \n"[i == m - 1]);
	}
	return 0;
}