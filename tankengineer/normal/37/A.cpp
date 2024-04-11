#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;

map<int, int> tr;

int main() {
	int n, ans = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
	  int t1 = 0;
		scanf("%d", &t1);
	  tr[t1]++;
	  ans = max(ans, tr[t1]);
	}
	printf("%d %d\n", ans, tr.size());
	return 0;
}