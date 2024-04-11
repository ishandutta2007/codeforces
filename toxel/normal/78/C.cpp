#include<bits/stdc++.h>

std::map <int, int> Hash;
int n, m, k;

void solve(int n){
	std::set <int> set;
	for (int i = 1; i * i <= n; ++ i){
		if (n % i) continue;
		if (i >= k && i != n) set.insert(Hash[i] * (n / i & 1));
		if (n / i >= k && n / i != n) set.insert(Hash[n / i] * (i & 1));
	}
	for (int i = 0; ; ++ i){
		if (!set.count(i)){
			Hash[n] = i;
			break;
		}
	}
}

int main(){
	scanf("%d%d%d", &m, &n, &k);
	if (!(m & 1) || n < k){
		puts("Marsel");
		return 0;
	}
	Hash[0] = 0;
	std::set <int> fact;
	for (int i = 1; i * i <= n; ++ i){
		if (n % i) continue;
		fact.insert(i);
		fact.insert(n / i);
	}
	for (auto u : fact){
		if (u >= k){
			solve(u);
		}
	}
	puts(Hash[n] ? "Timur" : "Marsel");
	return 0;
}