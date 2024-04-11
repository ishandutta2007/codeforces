#include<bits/stdc++.h>

const int N = 100010;
typedef std::pair <int, int> pii;

int type[N], x[N], t[N];
pii ans[N];
std::vector <int> vec[N << 1];
int n, w, h;

int main(){
	scanf("%d%d%d", &n, &w, &h);
	for (int i = 0; i < n; ++ i){
		scanf("%d%d%d", &type[i], &x[i], &t[i]);
		-- type[i];
		vec[x[i] - t[i] + N].push_back(i);
	}
	for (int i = 0; i < N << 1; ++ i){
		if (vec[i].empty()){
			continue;
		}
		int sz = vec[i].size();
		std::vector <std::pair <pii, int>> vvec, vvvec;
		int cnt = 0;
		for (auto u : vec[i]){
			vvec.push_back({{1 ^ type[u], type[u] ? n - x[u] : x[u]}, u});
			vvvec.push_back({{type[u], type[u] ? n - x[u] : x[u]}, u});
			cnt += 1 ^ type[u];
		}
		std::sort(vvec.begin(), vvec.end());
		std::sort(vvvec.begin(), vvvec.end());
		for (int j = 0; j < sz; ++ j){
			int sit = vvvec[j].second;
			ans[vvec[j].second] = type[sit] ? std::make_pair(w, x[sit]) : std::make_pair(x[sit], h);
		}
	}
	for (int i = 0; i < n; ++ i){
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
	return 0;
}