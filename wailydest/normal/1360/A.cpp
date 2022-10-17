#include <cstdio>
#include <algorithm>
using namespace std;

int main() 
{
	int t;
	scanf("%d", &t);
	int a, b;
	while (t--) {
		scanf("%d%d", &a, &b);
		if (a < b) swap(a, b);
		printf("%d\n", a >= b * 2 ? a * a : b * b * 4);
	}
	return 0;
}