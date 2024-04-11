#include<bits/stdc++.h>

typedef long long ll;

int main(){
	ll begin = 1;
	int x, d;
	scanf("%d%d", &x, &d);
	std::vector <ll> ans;
	while (x){
		for (int i = 1; ; ++ i){
			if ((1ll << (i + 1)) - 1 > x){
				x -= (1 << i) - 1;
				for (int j = 0; j < i; ++ j){
					ans.push_back(begin);
				}
				begin += d;
				break;
			}
		}
	}
	int sz = ans.size();
	printf("%d\n", sz);
	for (int i = 0; i < sz; ++ i){
		printf("%I64d%c", ans[i], " \n"[i == sz - 1]);
	}
	return 0;
}