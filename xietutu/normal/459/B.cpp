#include <cstdio>
#include <algorithm>
#include <iostream>
int n,min,max,mincnt,maxcnt;
int main() {
	scanf("%d",&n);
	min = 1000000001; max = 0;
	for (int i = 1; i <= n; ++i) {
		int x;
		scanf("%d",&x); 
		if (x > max) {
			max = x;
			maxcnt = 1;
		}
		else if (x == max) ++maxcnt;
		if (x < min) {
			min = x;
			mincnt = 1;
		}
		else if (x == min) ++mincnt;
	}
	if (max - min) std::cout << max - min << ' ' << static_cast<long long>(mincnt) * maxcnt;
	else std::cout << max - min << ' ' << static_cast<long long>(n) * (n-1) / 2;
}