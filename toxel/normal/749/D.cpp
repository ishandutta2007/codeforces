#include<bits/stdc++.h>

const int N = 200010;

std::vector <int> vec[N], del;
std::set <std::pair <int, int>> set;
int n, q, a[N], b[N], max[N];

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		scanf("%d%d", &a[i], &b[i]);
		vec[a[i]].push_back(b[i]);
		max[a[i]] = std::max(max[a[i]], b[i]);
	}
	for (int i = 1; i <= n; ++ i){
		if (max[i]){
			set.insert({-max[i], i});
		}
	}
	scanf("%d", &q);
	while (q --){
		del.clear();
		int sz;
		scanf("%d", &sz);
		for (int i = 0, x; i < sz; ++ i){
			scanf("%d", &x);
			del.push_back(x);
			set.erase({-max[x], x});
		}
		if (set.empty()){
			printf("0 0\n");
		}
		else if ((int) set.size() == 1){
			auto u = set.begin();
			int x = (*u).second;
			printf("%d %d\n", x, vec[x][0]);
		}
		else{
			auto u = set.begin();
			++ u;
			int x = -((*u).first);
			-- u;
			int sit = (*u).second;
			printf("%d %d\n", sit, vec[sit][std::lower_bound(vec[sit].begin(), vec[sit].end(), x) - vec[sit].begin()]);
		}
		for (auto u : del){
			if (max[u]){
				set.insert({-max[u], u});
			}
		}
	}
	return 0;
}