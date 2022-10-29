#include <cstdio>
#include <algorithm>
#include <list>
#include <cstring>
#include <map>
#include <set>
using namespace std;
int n, ans, s[100005], a[100005];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		if (a[i] >= a[i - 1]) s[i] = s[i - 1] + 1;
		else s[i] = 1;
		if (s[i] > ans) ans = s[i];
	}
	printf("%d\n", ans);
}