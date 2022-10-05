#include<bits/stdc++.h>

std::map <int, int> Hash;
int n;

int main(){
	scanf("%d", &n);
	for (int i = 0, x; i < n; ++ i){
		scanf("%d", &x);
		++ Hash[x];
	}
	auto it = Hash.begin();
	if (it -> second >= 3){
		int x = it -> second;
		return printf("%I64d\n", 1ll * x * (x - 1) * (x - 2) / 6), 0;
	}
	if (it -> second == 2){
		++ it;
		return printf("%I64d\n", 1ll * it -> second), 0;
	}
	++ it;
	if (it -> second > 1){
		int x = it -> second;
		return printf("%I64d\n", 1ll * x * (x - 1) / 2), 0;
	}
	++ it;
	return printf("%I64d\n", 1ll * it -> second), 0;
}