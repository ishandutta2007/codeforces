#include<bits/stdc++.h>

const int N = 2010;

int n, k;
int a[N], b[N];
std::set <int> set;

int main(){
	scanf("%d%d", &k, &n);
	for (int i = 1; i <= k; ++ i){
		scanf("%d", &a[i]);
		a[i] += a[i - 1];
		set.insert(a[i]);
	}
	for (int i = 1; i <= n; ++ i){
		scanf("%d", &b[i]);
	}
	std::set <int> ans;
	for (int i = 1; i <= k; ++ i){
		bool flag = true;
		for (int j = 1; j <= n; ++ j){
			if (!set.count(b[j] + a[i] - b[1])){
				flag = false;
				break;
			}
		}
		if (flag){
			ans.insert(a[i] - b[0]);
		}
	}
	return printf("%d\n", (int) ans.size()), 0;
}