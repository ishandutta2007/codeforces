#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 50;
int a[N];

int main() 
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", a + i);
		sort(a, a + n);
		int mn = ~(1 << 31);
		for (int i = 1; i < n; ++i) mn = min(mn, a[i] - a[i - 1]);
		printf("%d\n", mn);
	}
	return 0;
}