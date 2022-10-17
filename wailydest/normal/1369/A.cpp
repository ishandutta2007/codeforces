#include <cstdio>
using namespace std;

int main() 
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		if (!(n % 4)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}