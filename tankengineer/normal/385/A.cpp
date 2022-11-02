#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n, c;
	scanf("%d%d", &n, &c);
	int last, now;
	scanf("%d", &last);
	int ans = 0;
	while (--n) {
		scanf("%d", &now);
		ans = max(ans, last - now - c); 
		last = now;
	}
	printf("%d\n", ans);
	return 0;
}