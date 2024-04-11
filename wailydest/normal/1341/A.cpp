#include <cstdio>
using namespace std;

int main() 
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, a, b, c, d;
		scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
		if ((a - b) * n > c + d || (b + a) * n < c - d) printf("No\n");
		else printf("Yes\n");
	}
}