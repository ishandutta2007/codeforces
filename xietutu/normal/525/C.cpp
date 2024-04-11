#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <iostream>
std::priority_queue<int> Q; 
const int maxn = 100005;
int n,last,now,a[maxn];
long long ans;
int main() {
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d",a + i);
		Q.push(a[i]);
	}
	last = 0;
	while (Q.size() >= 2)  {
		int x = Q.top(); Q.pop();
		int y = Q.top();
		if (x == y) now = x, Q.pop();
		else if (x == y + 1) now = y, Q.pop();
		else now = 0;
		if (now) {
			if (last) ans = ans + static_cast<long long>(now) * last, last = 0;
			else last = now;
		}
	}
	std::cout << ans << std::endl;
}