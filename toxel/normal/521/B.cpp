#include<bits/stdc++.h>

const int N = 100010;
const int moder = 1e9 + 9;
typedef std::pair <int, int> pii;

int x[N], y[N];
std::map <pii, int> Hash;
std::set <int> move;
std::vector <int> ans;

bool check(int x, int y){
	for (int i = -1; i <= 1; ++ i){
		int xx = x + i, yy = y + 1;
		if (Hash.count({xx, yy}) && Hash[{xx, yy}] != -1){
			int cnt = 0;
			for (int j = -1; j <= 1; ++ j){
				cnt += Hash.count({xx + j, y}) && Hash[{xx + j, y}] != -1;
			}
			if (cnt == 1) return false;
		}
	}
	return true;
}

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		scanf("%d%d", &x[i], &y[i]);
		Hash[{x[i], y[i]}] = i;
	}
	for (int i = 0; i < n; ++ i){
		if (check(x[i], y[i])){
			move.insert(i);
		}
	}
	int cnt = 0;
	while (!move.empty()){
		++ cnt;
		int x;
		if (cnt & 1){
			x = *(-- move.end());
		}
		else{
			x = *(move.begin());
		}
		move.erase(x);
		ans.push_back(x);
		Hash[{::x[x], y[x]}] = -1;
		for (int i = -2; i <= 2; ++ i){
			if (Hash.count({::x[x] + i, y[x]}) && Hash[{::x[x] + i, y[x]}] != -1){
				if (!check(::x[x] + i, y[x])) move.erase(Hash[{::x[x] + i, y[x]}]);
			}
		}
		if (!y[x]) continue;
		for (int i = -1; i <= 1; ++ i){
			if (Hash.count({::x[x] + i, y[x] - 1}) && Hash[{::x[x] + i, y[x] - 1}] != -1 && check(::x[x] + i, y[x] - 1)){
				move.insert(Hash[{::x[x] + i, y[x] - 1}]);
			}
		}
	}
	std::reverse(ans.begin(), ans.end());
	int ret = 0, now = 1;
	for (int i = 0; i < n; ++ i){
		ret = (ret + 1ll * now * ans[i]) % moder;
		now = 1ll * now * n % moder;
	}
	return printf("%d\n", ret), 0;
}