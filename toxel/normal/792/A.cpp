#include<bits/stdc++.h>

const int N = 200010;

int n, a[N];
std::map <int, int> Hash;

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		scanf("%d", &a[i]);
		++ Hash[a[i]];
	}
	std::sort(a, a + n);
	int min = INT_MAX;
	for (int i = 0; i < n - 1; ++ i){
		min = std::min(min, a[i + 1] - a[i]);
	}
	long long cnt = 0;
	if (!min){
		for (auto u : Hash){
			cnt += 1ll * u.second * (u.second - 1) >> 1;
		}
	}
	else{
		for (auto u : Hash){
			if (Hash.count(u.first + min)){
				cnt += Hash[u.first + min];
			}
			if (Hash.count(u.first - min)){
				cnt +=Hash[u.first - min];
			}
		}
		cnt >>= 1;
	}
	return printf("%d %I64d\n", min, cnt), 0;
}