#include<bits/stdc++.h>

const int N = 1010;

int n;
char sher[N], mori[N];

int main(){
	scanf("%d%s%s", &n, sher, mori);
	std::sort(sher, sher + n);
	std::sort(mori, mori + n);
	int ans1 = 0, ans2 = n;
	for (int i = 0, j = 0; j < n; ++ j){
		if (sher[i] < mori[j]){
			++ ans1;
			++ i;
		}
	}
	for (int i = 0, j = 0; j < n; ++ j){
		if (sher[i] <= mori[j]){
			-- ans2;
			++ i;
		}
	}
	return printf("%d\n%d\n", ans2, ans1), 0;
}