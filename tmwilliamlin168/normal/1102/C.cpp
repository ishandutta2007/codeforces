#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, x, y; scanf("%d%d%d", &n, &x, &y);
	if(x > y) printf("%d\n", n);
	else {
		int cnt = 0;
		while(n--) {
			int t; scanf("%d", &t);
			if(t <= x) cnt++;
		}
		printf("%d\n", cnt+1 >> 1);
	}
	return 0;
}