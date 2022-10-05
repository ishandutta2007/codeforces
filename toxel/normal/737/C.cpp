#include<bits/stdc++.h>

const int N = 200010;

int a[N], cnt[N];

int main(){
	int n, s;
	scanf("%d%d", &n, &s);
	-- s;
	for (int i = 0; i < n; ++ i){
		scanf("%d", &a[i]);
	}
	int ans = 0;
	if (a[s] != 0){
		++ ans;
		a[s] = 0;
	}
	int max = 0;
	for (int i = 0; i < n; ++ i){
		++ cnt[a[i]];
		max = std::max(max, a[i]);
	}
	std::set <int> set;
	for (int i = 1; i <= max; ++ i){
		if (!cnt[i]){
			set.insert(i);
		}
	}
	if (set.size() <= cnt[0] - 1){
		printf("%d\n", ans + cnt[0] - 1);
		return 0;
	}
	ans += cnt[0] - 1;
	while (cnt[0] > 1){
		int u = *(set.begin());
		set.erase(set.begin());
		++ cnt[u];
		-- cnt[0];
	}
	while (!set.empty()){
		int u = *(set.begin());
		set.erase(set.begin());
		++ cnt[u];
		-- cnt[max];
		++ ans;
		while (!cnt[max]){
			if (set.count(max)){
				set.erase(max);
			}
			-- max;
		}
	}
	printf("%d\n", ans);
	return 0;
}