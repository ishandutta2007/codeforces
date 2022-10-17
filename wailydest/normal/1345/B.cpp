#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 25900;

int main() 
{
	int a[N];
	a[0] = 2;
	for (int i = 1; i < N; ++i) a[i] = a[i - 1] + 3 * (i + 1) - 1;
	for (int i = 0; i < N; ++i) a[i] = -a[i];
	reverse(a, a + N);
	
	
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		int amt = 0;
		while (n > 1) {
			int cl = *lower_bound(a, a + N, -n);
			amt += n / (-cl);
			n %= (-cl);
		}
		printf("%d\n", amt);
	}
	return 0;
}