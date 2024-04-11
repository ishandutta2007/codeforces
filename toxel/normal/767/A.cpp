#include<bits/stdc++.h>

const int N = 100010;

int n;
bool vis[N];

int main(){
	scanf("%d", &n);
	std::set <int> set;
	vis[n + 1] = true;
	for (int i = 0, x; i < n; ++ i){
		scanf("%d", &x);
		set.insert(-x);
		auto u = set.begin();
		while (vis[(-*u) + 1] && set.size()){
			printf("%d ", -*u);
			vis[-*u] = true;
			set.erase(u);
			u = set.begin();
		}
		putchar('\n');
	}
	return 0;
}