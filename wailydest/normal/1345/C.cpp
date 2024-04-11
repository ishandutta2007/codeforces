#include <cstdio>
#include <cstring>
using namespace std;

const int N = 200000;

int main() 
{
	int t;
	scanf("%d", &t);
	while (t--) {
		bool ch[N] = {0};
		int n;
		scanf("%d", &n);
		int x;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &x);
			ch[((i + x) % n + n) % n] = true;
		}
		bool ok = true;
		for (int i = 0; i < n; ++i) ok = ok && ch[i];
		if (ok) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}