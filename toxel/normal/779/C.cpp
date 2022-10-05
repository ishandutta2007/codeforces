#include<bits/stdc++.h>

const int N = 200010;

int n, k, a[N], b[N];
std::vector <int> vec;

int main(){
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++ i){
		scanf("%d", &a[i]);
	}
	int ans = 0;
	for (int i = 0; i < n; ++ i){
		scanf("%d", &b[i]);
		if (b[i] >= a[i]){
			ans += a[i];
			-- k;
		}
		else{
			vec.push_back(a[i] - b[i]);
			ans += b[i];
		}
	}
	std::sort(vec.begin(), vec.begin() + vec.size());
	for (int i = 0; i < k; ++ i){
		ans += vec[i];
	}
	return printf("%d\n", ans), 0;
}