#include<bits/stdc++.h>

const int N = 100010;

int a[N];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		scanf("%d", &a[i]);
	}
	std::vector <int> fact;
	int nn = n;
	for (int i = 3; i <= nn; ++ i){
		if (nn % i == 0){
			fact.push_back(i);
			while (nn % i == 0){
				nn /= i;
			}
		}
	}
	for (auto u : fact){
		for (int i = 0; i < n / u; ++ i){
			bool flag = true;
			int now = i;
			for (int j = 0; j < u; ++ j){
				if (!a[now]){
					flag = false;
					break;
				}
				now += n / u;
			}
			if (flag){
				puts("YES");
				return 0;
			}
		}
	}
	puts("NO");
	return 0;
}