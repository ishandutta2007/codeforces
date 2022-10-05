#include<bits/stdc++.h>

int n, k;
typedef long long ll;
const int N = 14;

ll fac[N];
int a[N];
std::vector <int> lucky[10];

bool check(int n){
	while (n){
		int x = n % 10;
		if (x != 4 && x != 7) return false;
		n /= 10;
	}
	return true;
}

int main(){
	fac[0] = 1;
	for (int i = 1; i < N; ++ i){
		fac[i] = fac[i - 1] * i;
	}
	scanf("%d%d", &n, &k);
	if (n < N && k > fac[n]) return printf("-1\n"), 0;
	std::set <int> left;
	if (n < N){
		for (int i = 1; i <= n; ++ i){
			left.insert(i);
		}
	}
	else{
		for (int i = n - 13; i <= n; ++ i){
			left.insert(i);
		}
	}
	int now = n < N ? n - 1 : 13;
	-- k;
	int ans = 0;
	int dif = n - std::min(n, N);
	for (int i = 0, sz = std::min(n, N); i < sz; ++ i, -- now){
		ll x = k / fac[now];
		int cnt = 0, y;
		for (auto u : left){
			if (cnt == x){
				y = u;
				break;
			}
			++ cnt;
		}
		a[i] = y;
		ans += check(y) && check(i + 1 + dif);
		left.erase(y);
		k -= x * fac[now];
	}
	lucky[1] = {4, 7};
	for (int i = 1; i < 9; ++ i){
		for (auto u : lucky[i]){
			lucky[i + 1].push_back(u * 10 + 4);
			lucky[i + 1].push_back(u * 10 + 7);
		}
	}
	for (int i = 1; i <= 9; ++ i){
		for (auto u : lucky[i]){
			ans += u <= dif;
		}
	}
	return printf("%d\n",ans), 0;
}