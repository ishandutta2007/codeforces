#include <cstdio>
using namespace std;

int main() 
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		if (n >= 2 && m > 2 || n > 2 && m >= 2) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}