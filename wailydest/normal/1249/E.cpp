#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 200000;

int a[N];
pair<int, int> ans[N];

int main() 
{
	int n, c;
	scanf("%d%d", &n, &c);
	ans[0] = make_pair(0, 100000000);
	printf("%d ", 0);
	for (int i = 1; i < n; ++i) scanf("%d", a + i);
	int b;
	for (int i = 1; i < n; ++i) {
		scanf("%d", &b);
		ans[i].first = min(ans[i - 1].first + a[i], ans[i - 1].second + a[i]);
		ans[i].second = min(ans[i - 1].first + c + b, ans[i - 1].second + b);
		printf("%d ", min(ans[i].first, ans[i].second));
	}
	printf("\n");
	return 0;
}