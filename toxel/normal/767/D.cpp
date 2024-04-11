#include<bits/stdc++.h>

const int N = 10000010;
const int M = 1000010;

int n, m, k, f[M], cnt[N];
std::pair <int, int> p[M];
std::vector <int> ans, vec;
std::set <int> set;

bool check(int mid){
	bool ret = true;
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < n; ++ i){
		++ cnt[f[i]];
	}
	for (int i = 0; i < mid; ++ i){
		++ cnt[p[i].first];
	}
	for (int i = 0; i < vec.size(); ++ i){
		if (i){
			cnt[vec[i]] += cnt[vec[i - 1]];
		}
		if (cnt[vec[i]] > 1ll * (vec[i] + 1) * k){
			ret = false;
		}
	}
	return ret;
}

int main(){
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; ++ i){
		scanf("%d", &f[i]);
		set.insert(f[i]);
	}
	for (int i = 0, x; i < m; ++ i){
		scanf("%d", &x);
		p[i] = {x, i + 1};
		set.insert(x);
	}
	for (auto u = set.begin(); u != set.end(); ++ u){
		vec.push_back(*u);
	}
	if (!check(0)){
		return printf("-1\n"), 0;
	}
	std::sort(p, p + m, std::greater <std::pair <int, int>>());
	int left = 1, right = m;
	while (left < right){
		int mid = left + right + 1 >> 1;
		if (check(mid)){
			left = mid;
		}
		else{
			right = mid - 1;
		}
	}
	if (!check(left)){
		-- left;
	}
	printf("%d\n", left);
	for (int i = 0; i < left; ++ i){
		printf("%d ", p[i].second);
	}
	return printf("\n"), 0;
}