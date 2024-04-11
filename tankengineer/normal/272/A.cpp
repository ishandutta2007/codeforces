#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n, sum = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int t1;
		scanf("%d", &t1);
		sum += t1;
	}
	++n;
	int ans = 0;
	for (int i = 1; i <= 5; ++i) {
		if ((sum + i) % n != 1) {
			++ans;
		}
	}
	printf("%d\n", ans);
	return 0;
}