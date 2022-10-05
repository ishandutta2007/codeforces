#include<bits/stdc++.h>

int power_mod(int a, int index, int moder){
	int ans = 1;
	while (index){
		if (index & 1)
			ans = 1ll * ans * a % moder;
		a = 1ll * a * a % moder;
		index >>= 1;
	}
	return ans;
}

int main(){
	int n;
	scanf("%d", &n);
	printf("%d\n", power_mod(1378, n, 10));
	return 0;
}