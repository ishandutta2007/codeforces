#include<bits/stdc++.h>

const int N = 200010;
typedef std::pair <int, int> pii;

int a[N], t[N];
pii p[N];

int main(){
	int n, T;
	scanf("%d%d", &n, &T);
	for (int i = 0; i < n; ++ i){
		scanf("%d%d", &a[i], &t[i]);
		p[i] = {a[i], i};
	}
	std::sort(p, p + n, std::greater <pii>());
	std::multiset <int> set;
	int ans = -1;
	int sum = 0;
	for (int i = n, j = 0; i >= 0; -- i){
		while (j < n && p[j].first >= i){
			set.insert(t[p[j].second]);
			sum += t[p[j].second];
			++ j;
		}
		while (sum > T){
			auto u = -- set.end();
			sum -= *u;
			set.erase(u);
		}
		while ((int) set.size() > i){
			auto u = -- set.end();
			sum -= *u;
			set.erase(u);
		}
		if (ans < (int) set.size()){
			ans = set.size();
		}
	}
	std::multiset <pii> sset;
	std::vector <int> vec;
	for (int i = 0; i < n; ++ i){
		if (p[i].first >= ans){
			sset.insert({t[p[i].second], p[i].second});
		}
	}
	sum = 0;
	for (auto u : sset){
		if ((int) vec.size() == ans) break;
		if (sum + u.first <= T){
			vec.push_back(u.second);
			sum += u.first;
		}
		else break;
	}
	printf("%d\n%d\n", ans, (int) vec.size());
	for (int i = 0; i < (int) vec.size(); ++ i){
		printf("%d%c", vec[i] + 1, " \n"[i == (int) vec.size() - 1]);
	}
	if (!vec.size()){
		putchar('\n');
	}
	return 0;
}