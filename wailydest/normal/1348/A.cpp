#include <cstdio>
using namespace std;

void solve() 
{
	int n;
	scanf("%d", &n);
	int dif = 1 << n;
	for (int i = 1; i < n / 2; ++i) dif += 1 << i;
	for (int i = n / 2; i < n; ++i) dif -= 1 << i;
	printf("%d\n", dif);
}

int main() 
{
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}