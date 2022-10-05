#include<bits/stdc++.h>
#define ll long long

const int N = 100010;

std::map <int, int> Hash;
int n, k;

int main(){
	scanf("%d%d", &n, &k);
	for (int i = 0, x; i < n; ++ i){
		scanf("%d", &x);
		if (Hash.count(x))
			Hash[x] ++;
		else
			Hash[x] = 1;
	}
	ll ans = 0;
	for (int i = 1; i <= 100000; ++ i){
		int x = i ^ k;
		if (!Hash.count(i) || !Hash.count(x))
			continue;
		if (i == x){
			if (Hash[i] > 1)
				ans += 1ll * Hash[i] * (Hash[i] - 1);
			continue;
		}
		ans += 1ll * Hash[i] * Hash[x];
	}
	printf("%I64d\n", ans / 2);
	return 0;
}