#include<bits/stdc++.h>

const int N = 100010;

int n, m, a[N];
std::map <int, int> Hash, __orz;
std::vector <int> orz;

int power_mod(int a, int index, int moder){
	int ret = 1;
	while (index){
		if (index & 1){
			ret = 1ll * ret * a % moder;
		}
		a = 1ll * a * a % moder;
		index >>= 1;
	}
	return ret;
}

int main(){
	//std::cout << 2ll * power_mod(162, 241 - 2, 241) % 241 << std::endl;
	//freopen("data.txt", "r", stdin);
	scanf("%d%d", &m, &n);
	bool flag = true;
	for (int i = 0; i < n; ++ i){
		scanf("%d", &a[i]);
		++ Hash[a[i]];
		if (i && a[i] != a[i - 1]){
			flag = false;
		}
	}
	if (flag){
		return printf("%d %d\n", a[0], 0), 0;
	}
	if (n >= m){
		int x = n / m;
		for (int i = 0; i < m; ++ i){
			Hash[i] -= x;
		}
	}
	for (auto u = Hash.begin(); u != Hash.end(); ++ u){
		if (!u -> second){
			orz.push_back(u -> first);
		}
		else if (u -> second != 1){
			return printf("-1\n"), 0;
		}
	}
	for (auto u : orz){
		Hash.erase(u);
	}
	if (!Hash.size()){
		return printf("0 1\n"), 0;
	}
	if (m == 2 || Hash.size() == 1){
		return printf("%d 1\n", (Hash.begin()) -> first), 0;
	}
	if (Hash.size() > m / 2){
		flag = true;
		for (int i = 0; i < m; ++ i){
			if (!Hash.count(i)){
				__orz[i] = 1;
			}
		}
		n = m - n;
		Hash = __orz;
	}
	auto u = Hash.begin();
	int x = u -> first, y = (++ u) -> first, dif = (y - x + m) % m, cnt = 0;
	for (auto u = Hash.begin(); u != Hash.end(); ++ u){
		if (Hash.count((u -> first + dif) % m)){
			++ cnt;
		}
	}
	int d = 1ll * dif * power_mod(n - cnt, m - 2, m) % m, cnt1 = 0, cnt2 = 0;
	y = x;
	while (Hash.count(x)){
		x = (x + d) % m;
		++ cnt1;
	}
	x = y;
	while (Hash.count(x)){
		x = (x - d + m) % m;
		++ cnt2;
	}
	if (cnt1 + cnt2 - 1 == n){
		if (flag){
			return printf("%d %d\n", x, m - d), 0;
		}
		return printf("%d %d\n", (x + d) % m, d), 0;
	}
	return printf("-1\n"), 0;
}