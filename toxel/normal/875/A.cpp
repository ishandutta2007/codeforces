#include<bits/stdc++.h>

int check(int n){
	int sum = n;
	while (n){
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int main(){
	int n;
	scanf("%d", &n);
	std::vector <int> ans;
	for (int i = 0; i < 100; ++ i){
		if (n < i) break;
		if (check(n - i) == n){
			ans.push_back(n - i);
		}
	}
	std::sort(ans.begin(), ans.end());
	printf("%d\n", (int) ans.size());
	for (int i = 0, sz = ans.size(); i < sz; ++ i){
		printf("%d%c", ans[i], " \n"[i == sz - 1]);
	}
	return 0;
}