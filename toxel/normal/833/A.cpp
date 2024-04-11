#include<bits/stdc++.h>

typedef long long ll;
const int N = 1000010;

int n;
int a, b;
int min[N], mu[N];
std::vector <int> prime;

ll sqrt(ll n){
	ll left = 0, right = 1e6;
	while (left < right){
		ll mid = left + right + 1 >> 1;
		if (mid * mid * mid <= n){
			left = mid;
		}
		else{
			right = mid - 1;
		}
	}
	return left;
}

int main(){
	mu[1] = 1;
	for(int i = 2; i < N; ++ i){
		if(!min[i]){
			prime.push_back(i);
			mu[i] = -1;
			min[i] = i;
		}
		for(int j = 0, k, sz = (int) prime.size(); j < sz && i * prime[j] < N; ++ j){
			min[k = i * prime[j]] = prime[j];
			if(i % prime[j] == 0){
				mu[k] = 0;
				break;
			}
			mu[k] = mu[i] * -1;
		}
	}
	scanf("%d", &n);
	while (n --){
		scanf("%d%d", &a, &b);
		ll x = 1ll * a * b;
		ll ans = sqrt(x);
		if (ans * ans * ans != x){
			printf("No\n");
			continue;
		}
		std::set <int> fact;
		while (ans > 1){
			fact.insert(min[ans]);
			ans /= min[ans];
		}
		bool flag = true;
		for (auto u : fact){
			int cnta = 0, cntb = 0;
			while (!(a % u)){
				a /= u;
				++ cnta;
			}
			while (!(b % u)){
				b /= u;
				++ cntb;
			}
			int x = (2 * cnta - cntb) / 3, y = (2 * cntb - cnta) / 3;
			if (x < 0 || y < 0){
				flag = false;
				break;
			}
		}
		printf(flag ? "Yes\n" : "No\n");
	}
	return 0;
}