#include<bits/stdc++.h>

int main(){
	int n;
	scanf("%d", &n);
	for (int i = n - 1 >> 1; i >= 1; -- i){
		if (std::__gcd(i, n - i) == 1){
			return printf("%d %d\n", i, n - i), 0;
		}
	}
}