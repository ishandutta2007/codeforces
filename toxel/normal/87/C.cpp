#include<bits/stdc++.h>

const int N = 100010;

int sg[N], pre[N];
int n;

int main(){
	scanf("%d", &n);
	for (int i = 1; i < n; ++ i){
		std::set <int> set;
		for (int j = 2; j * (j + 1) <= 2 * i; ++ j){
			if (j & 1){
				if (i % j) continue;
			}
			else{
				if (2 * i % j || !(i % j)) continue;
			}
			int y = 2 * i / j - j + 1 >> 1;
			set.insert(pre[y + j - 1] ^ pre[y - 1]);
		}
		for (int j = 0; ; ++ j){
			if (!set.count(j)){
				sg[i] = j;
				break;
			}
		}
		pre[i] = pre[i - 1] ^ sg[i];
	}
	for (int i = 2; i * (i + 1) <= 2 * n; ++ i){
		if (i & 1){
			if (n % i) continue;
		}
		else{
			if (2 * n % i || !(n % i)) continue;
		}
		int x = 2 * n / i - i + 1 >> 1;
		if (!(pre[x + i - 1] ^ pre[x - 1])){
			return printf("%d\n", i), 0;
		}
	}
	return printf("-1\n"), 0;
}