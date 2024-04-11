#include<bits/stdc++.h>
#define ll long long

const int N = 300010;

ll n, k, l[N], r[N];
bool ans[N];
std::multiset <int> set;
std::map <ll, std::vector <int>> Hash;
std::map <ll, int> __Hash;
std::pair <std::pair <int, int>, int> p[N];

int main(){
	scanf("%I64d%I64d", &n, &k);
	for (int i = 1; i <= n; ++ i){
		scanf("%I64d%I64d", &l[i], &r[i]);
		p[i - 1].first.first = l[i];
		p[i - 1].first.second = r[i];
		p[i - 1].second = i;
	}
	if (k == 1){
		int max = 0, sit;
		for (int i = 1; i <= n; ++ i){
			if (max < r[i] - l[i] + 1){
				max = r[i] - l[i] + 1;
				sit = i;
			}
		}
		return printf("%d\n%d\n", max, sit), 0;
	}
	std::sort(p, p + n);
	for (int i = 0; i < k - 1; ++ i){
		set.insert(p[i].first.second);
	}
	int max = 0;
	for (int i = k - 1; i < n; ++ i){
		int right = std::min(p[i].first.second, *(set.begin()));
		max = std::max(max, right - p[i].first.first + 1);
		set.insert(p[i].first.second);
		set.erase(set.begin());
	}
	ll left = max, right = max;
	while (left <= right){
		ll mid = left + right + 1 >> 1;
		Hash.clear();
		memset(ans, 0, sizeof(ans));
		for (int i = 1; i <= n; ++ i){
			if (l[i] > r[i] - mid + 1){
				continue;
			}
			Hash[l[i]].push_back(i);
			Hash[r[i] - mid + 2].push_back(-i);
		}
		bool flag = false;
		int now = 0;
		for (auto u = Hash.begin(); u != Hash.end(); ++ u){
			for (auto v : u -> second){
				if (v < 0){
					-- now;
					ans[-v] = false;
				}
			}
			for (auto v : u -> second){
				if (v > 0){
					++ now;
					ans[v] = true;
					if (now >= k){
						flag = true;
						break;
					}
				}
			}
			if (flag){
				break;
			}
		}
		if (left == right){
			break;
		}
		if (flag){
			left = mid;
		}
		else{
			right = mid - 1;
		}
	}
	if (!left){
		puts("0");
		for (int i = 1; i <= k; ++ i){
			printf("%d ", i);
		}
		return printf("\n"), 0;
	}
	printf("%I64d\n", left);
	for (int i = 1; i <= n; ++ i){
		if (ans[i]){
			printf("%I64d ", i);
		}
	}
	return printf("\n"), 0;
}