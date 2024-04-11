#include<bits/stdc++.h>

const int N = 17;

int n, a, b;
std::vector <int> life, ans;
std::map <std::vector <int>, std::vector <int>> Hash;

std::vector <int> solve(){
	if (Hash.count(life))
		return Hash[life];
	bool flag = true;
	for (int i = 0; i < life.size(); ++ i)
		if (life[i] >= 0)
			flag = false;
	if (flag)
		return {};
	std::vector <int> ans;
	flag = true;
	for (int i = 1; i < n - 1; ++ i){
		int x1 = std::min(life[i - 1] + 1, b), x2 = std::min(life[i] + 1, a), x3 = std::min(life[i + 1] + 1, b);
		if (!x1 && !x2 || !x2 && !x3)
			continue;
		life[i - 1] -= x1;
		life[i] -= x2;
		life[i + 1] -= x3;
		std::vector <int> vec = {i + 1}, vvec = solve();
		for (auto u : vvec){
			vec.push_back(u);
		}
		if (flag || ans.size() > vec.size()){
			flag = false;
			ans = vec;
		}
		life[i - 1] += x1;
		life[i] += x2;
		life[i + 1] += x3;
	}
	return Hash[life] = ans;
}

int main(){
	scanf("%d%d%d", &n, &a, &b);
	for (int i = 0, x; i < n; ++ i){
		scanf("%d", &x);
		life.push_back(x);
	}
	while (life[0] > -1){
		int x1 = std::min(life[0] + 1, b), x2 = std::min(life[1] + 1, a), x3 = std::min(life[2] + 1, b);
		life[0] -= x1;
		life[1] -= x2;
		life[2] -= x3;
		ans.push_back(2);
	}
	while (life[n - 1] > -1){
		int x1 = std::min(life[n - 3] + 1, b), x2 = std::min(life[n - 2] + 1, a), x3 = std::min(life[n - 1] + 1, b);
		life[n - 3] -= x1;
		life[n - 2] -= x2;
		life[n - 1] -= x3;
		ans.push_back(n - 1);
	}
	std::vector <int> vec = solve();
	for (auto u : vec){
		ans.push_back(u);
	}
	printf("%d\n", (int) ans.size());
	for (auto u : ans){
		printf("%d ", u);
	}
	return printf("\n"), 0;
}