#include<bits/stdc++.h>

const int N = 3010;
typedef std::pair <int, int> pii;

pii a[N];
int n;
int aans[N];

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		scanf("%d", &a[i].first);
		a[i].second = i;
	}
	std::sort(a, a + n, std::greater <pii>());
	std::pair <pii, int> ans = {{-1, -1}, -1}, sit;
	for (int i = 1; i <= n; ++ i){
		for (int j = i + 1 >> 1, szj = std::min(i << 1, n - i); j <= szj; ++ j){
			for (int k = std::max(i + 1 >> 1, j + 1 >> 1), szk = std::min(std::min(i << 1, j << 1), n - i - j); k <= szk; ++ k){
				std::pair <pii, int> p = {{a[i - 1].first - a[i].first, a[i + j - 1].first - a[i + j].first}, i + j + k == n ? a[n - 1].first : a[i + j + k - 1].first - a[i + j + k].first};
				if (p > ans){
					ans = p;
					sit = {{i, j}, k};
				}
			}
		}
	}
	for (int i = 0; i < sit.first.first; ++ i){
		aans[a[i].second] = 1;
	}
	for (int i = sit.first.first; i < sit.first.first + sit.first.second; ++ i){
		aans[a[i].second] = 2;
	}
	for (int i = sit.first.first + sit.first.second; i < sit.first.first + sit.first.second + sit.second; ++ i){
		aans[a[i].second] = 3;
	}
	for (int i = sit.first.first + sit.first.second + sit.second; i < n; ++ i){
		aans[a[i].second] = -1;
	}
	for (int i = 0; i < n; ++ i){
		printf("%d%c", aans[i], " \n"[i == n - 1]);
	}
	return 0;
}