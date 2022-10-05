#include<bits/stdc++.h>

const int N = 200010;

int p[N], cnt[N];
bool left[N];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i){
		scanf("%d", &p[i]);
		++ cnt[p[i]];
	}
	std::set <int> set;
	memset(left, true, sizeof(left));
	for (int i = 1; i <= n; ++ i){
		if (!cnt[i]){
			set.insert(i);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++ i){
		if (cnt[p[i]] > 1){
			int x = *(set.begin());
			if (x > p[i] && left[p[i]]){
				left[p[i]] = false;
				continue;
			}
			set.erase(set.begin());
			-- cnt[p[i]];
			++ cnt[x];
			p[i] = x;
			++ ans;
		}
	}
	printf("%d\n", ans);
	for (int i = 1; i <= n; ++ i){
		printf("%d%c", p[i], " \n"[i == n]);
	}
	return 0;
}