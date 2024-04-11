#include<bits/stdc++.h>

const int N = 2000010;

char s[N], ans[N];
int n, k[N];
std::string str[N];
std::vector <int> vec[N];
std::set <int> set;

int main(){
	int max = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		scanf("%s", s);
		str[i] = s;
		int len = strlen(s);
		scanf("%d", &k[i]);
		for (int j = 0, x; j < k[i]; ++ j){
			scanf("%d", &x);
			-- x;
			vec[i].push_back(x);
			max = std::max(max, len + x);
		}
	}
	for (int i = 0; i < max; ++ i){
		set.insert(i);
	}
	for (int i = 0; i < n; ++ i){
		int len = str[i].size();
		for (int j = 0; j < k[i]; ++ j){
			std::vector <int> rollback;
			auto it = set.lower_bound(vec[i][j]);
			while (it != set.end() && *it < vec[i][j] + len){
				ans[*it] = str[i][*it - vec[i][j]];
				rollback.push_back(*it);
				++ it;
			}
			for (auto u : rollback){
				set.erase(u);
			}
		}
	}
	for (int i = 0; i < max; ++ i){
		if (!ans[i]){
			ans[i] = 'a';
		}
	}
	return printf("%s\n", ans), 0;
}