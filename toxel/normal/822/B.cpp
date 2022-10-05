#include<bits/stdc++.h>

const int N = 1010;

char s[N], t[N];
int n, m;
std::vector <int> vec;

int main(){
	scanf("%d%d%s%s", &n, &m, s, t);
	int ans = INT_MAX;
	for (int i = 0; i <= m - n; ++ i){
		std::vector <int> _vec;
		for (int j = 0; j < n; ++ j){
			if (s[j] != t[i + j]){
				_vec.push_back(j);
			}
		}
		if (_vec.size() < ans){
			ans = _vec.size();
			vec = _vec;
		}
	}
	printf("%d\n", ans);
	for (auto u : vec){
		printf("%d ", u + 1);
	}
	return printf("\n"), 0;
}