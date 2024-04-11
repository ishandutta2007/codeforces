#include<bits/stdc++.h>

const int N = 100010;

int n, c, d;
std::pair <int, int> founc[N], found[N];
std::multiset <int> set;
char s[N];

int main(){
	scanf("%d%d%d", &n, &c, &d);
	int cntc = 0, cntd = 0;
	for (int i = 0, cost, beauty; i < n; ++ i){
		scanf("%d%d%s", &beauty, &cost, s);
		s[0] == 'C' ? founc[cntc ++] = {cost, beauty} : found[cntd ++] = {cost, beauty};
	}
	std::sort(founc, founc + cntc);
	std::sort(found, found + cntd);
	int ans = 0, max1 = 0, max2 = 0;
	for (int i = 0; i < cntc; ++ i){
		if (founc[i].first <= c){
			max1 = std::max(max1, founc[i].second);
		}
	}
	for (int i = 0; i < cntd; ++ i){
		if (found[i].first <= d){
			max2 = std::max(max2, found[i].second);
		}
	}
	if (max1 > 0 && max2 > 0){
		ans = max1 + max2;
	}
	if (cntc > 1){
		for (int i = 0; i < cntc; ++ i){
			set.insert(-founc[i].second);
		}
		for (int i = 0, j = cntc - 1; i < cntc; ++ i){
			if (j >= i){
				set.erase(set.find(-founc[i].second));
			}
			while (j >= 0 && founc[i].first + founc[j].first > c){
				if (j != i){
					set.erase(set.find(-founc[j].second));
				}
				-- j;
			}
			if (set.size() > 0){
				ans = std::max(ans, -*(set.begin()) + founc[i].second);
			}
			if (j >= i){
				set.insert(-founc[i].second);
			}
		}
	}
	set.clear();
	if (cntd > 1){
		for (int i = 0; i < cntd; ++ i){
			set.insert(-found[i].second);
		}
		for (int i = 0, j = cntd - 1; i < cntd; ++ i){
			if (j >= i){
				set.erase(set.find(-found[i].second));
			}
			while (j >= 0 && found[i].first + found[j].first > d){
				if (j != i){
					set.erase(set.find(-found[j].second));
				}
				-- j;
			}
			if (set.size() > 0){
				ans = std::max(ans, -*(set.begin()) + found[i].second);
			}
			if (j >= i){
				set.insert(-found[i].second);
			}
		}
	}
	return printf("%d\n", ans), 0;
}