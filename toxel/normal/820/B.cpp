#include<bits/stdc++.h>
#define ll long long

int n, a;

int main(){
	scanf("%d%d", &n, &a);
	int k = n * a / 180;
	if (k == 0){
		k = 1;
	}
	else{
		if (std::abs(180 * k - n * a) > std::abs(180 * (k + 1) - n * a)){
			++ k;
		}
	}
	if (k >= n - 1){
		k = n - 2;
	}
	return printf("2 %d %d\n", 1, k + 2), 0;
}