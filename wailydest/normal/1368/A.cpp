#include <cstdio>
#include <utility>
using namespace std;

int main() 
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int a, b, n;
		scanf("%d%d%d", &a, &b, &n);
		if (a > b) swap(a, b);
		int c = 0;
		while (b <= n) {
			a += b;
			swap(a, b);
			++c;
		}
		printf("%d\n", c);
	}
	return 0;
}