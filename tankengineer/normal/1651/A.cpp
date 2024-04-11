#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int x, ans;
		scanf("%d", &x);
		ans = (1 << x) - 1;
		printf("%d\n", ans);
	}
	return 0;
}