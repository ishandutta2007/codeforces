#include<stdio.h>
#include<algorithm>
using namespace std;

int a[200001];
pair<int, int> b[200001];
int r[200001];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i].first);
		b[i].second = i;
	}
	sort(b + 1, b + n + 1);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		r[b[i].second] = a[n - i + 1];
	}
	for (int i = 1; i <= n; i++)printf("%d ", r[i]);
	return 0;
}