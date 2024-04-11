#include<stdio.h>
#include<queue>
using namespace std;
int a[300001];
int main() {
	priority_queue<pair<int, int>> H;
	int n, t;
	scanf("%d", &n);
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &t);
		if (!H.empty() && -H.top().first < t){
			ans += H.top().first + t;
			int x = H.top().second;
			if (a[x] == 0) a[x] = 1;
			else if (a[x] == 2) a[x] = 0;
			if (a[x] == 1) H.pop();
			a[i] = 2;
		}
		H.emplace(-t, i);
	}
	printf("%lld\n", ans);
	return 0;
}