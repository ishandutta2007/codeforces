#include<bits/stdc++.h>

int n, h;

int main(){
	scanf("%d%d", &n, &h);
	for (int i = 1; i <= n - 1; ++ i){
		printf("%.12lf\n", std::sqrt(1.0 * i / n) * h);
	}
	return 0;
}