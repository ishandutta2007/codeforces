#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
struct arr {
	char s[1005];
} now,ans;
int n;
bool operator<(const arr& lhs,const arr& rhs) {
	for (int i = 1; i <= n; ++i)
		if (lhs.s[i] != rhs.s[i])
		return lhs.s[i] < rhs.s[i];
	return false;
}
void work() {
	for (int i = 1; i <= n; ++i) {
		if (now < ans) ans = now;
		char tmp = now.s[1];
		for (int j = 1; j < n; ++j)
			now.s[j] = now.s[j + 1];
		now.s[n] = tmp;
	}
}
int main() {
	scanf("%d",&n);
	scanf("%s",now.s + 1);
	ans = now;
	for (int i = 1; i <= 10; ++i) {
		work();
		for (int j = 1; j <= n; ++j)
			now.s[j] = (now.s[j] - '0' + 1) % 10 + '0';
	}
	printf("%s",ans.s + 1);
}