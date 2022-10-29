#include <bits/stdc++.h>
using namespace std;
const int maxn = 300010;
bool out[maxn];
stack<int> S;
int n, ans;
int main() {
	scanf("%d", &n);
	int ret = 0, now = 1;
	for (int i = 1; i <= n * 2; ++i) {
		char type[10]; int x;
		scanf("%s", type);
		if (type[0] == 'a') {
			scanf("%d", &x);
			S.push(x);
			++ret;
		}
		else if (type[0] == 'r') {
			while (out[S.top()]) S.pop();
			if (S.top() != now) {
				if (!ret) {
					out[now] = true;
				}
				else {
					++ans;
					ret = 0;
					out[now] = true;
				}
			}
			else {
				if (ret) --ret;
				S.pop();
			}
			++now;
		}
	}
	printf("%d\n", ans);
}