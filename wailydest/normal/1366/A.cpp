#include <cstdio>
#include <algorithm>
using namespace std;

int main() 
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (a < b) swap(a, b);
		printf("%d\n", min((a + b) / 3, min(a, b)));
	}
	return 0;
}