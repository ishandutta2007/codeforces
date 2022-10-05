#include<bits/stdc++.h>

const int N = 500010;

int n, c, left, right, l, r;
std::vector <int> vec[N];
std::set <int> set;

void solve(int begin, int end, int sit){
	bool flag = false;
	int max = 0, min = c, first = 0;
	for (int i = begin; i <= end; ++ i){
		if (!vec[i][sit]){
			if (first){
				printf("-1\n");
				exit(0);
			}
			continue;
		}
		if (!first){
			first = vec[i][sit];
		}
		max = std::max(max, vec[i][sit]);
		min = std::min(min, vec[i][sit]);
		if (i == begin){
			continue;
		}
		if (!flag){
			if (vec[i][sit] >= vec[i - 1][sit]){
				continue;
			}
			if (vec[i][sit] >= first){
				printf("-1\n");
				exit(0);
			}
			flag = true;
			continue;
		}
		if (vec[i][sit] < vec[i - 1][sit] || vec[i][sit] >= first){
			printf("-1\n");
			exit(0);
		}
	}
	if (first && min != max){
		if (!flag){
			set.erase(set.lower_bound(c - max + 1), set.upper_bound(c - min));
		}
		else{
			set.erase(set.lower_bound(0), set.upper_bound(c - first));
			set.erase(set.lower_bound(c + 1 - vec[end][sit]), set.upper_bound(c - 1));
		}
	}
	int pre = begin;
	for (int i = begin; i < end; ++ i){
		if (vec[i][sit] != vec[i + 1][sit]){
			if (vec[i][sit] && i > pre){
				solve(pre, i, sit + 1);
			}
			pre = i + 1;
		}
	}
	if (vec[pre][sit] && end > pre){
		solve(pre, end, sit + 1);
	}
}

int main(){
	//freopen("data.txt", "r", stdin);
	scanf("%d%d", &n, &c);
	for (int i = 0; i < c; ++ i){
		set.insert(i);
	}
	for (int i = 0, l; i < n; ++ i){
		scanf("%d", &l);
		for (int j = 0, x; j < l; ++ j){
			scanf("%d", &x);
			vec[i].push_back(x);
		}
		vec[i].push_back(0);
	}
	solve(0, n - 1, 0);
	if (!set.size()){
		return printf("-1\n"), 0;
	}
	for (auto u : set){
		return printf("%d\n", u), 0;
	}
}