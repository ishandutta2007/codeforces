#include <cstdio>
using namespace std;

int main() 
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		bool ok = true;
		for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
			int v;
			scanf("%d", &v);
			bool b1 = i == 0 || i == n - 1;
			bool b2 = j == 0 || j == m - 1;
			if (b1 && b2) {
				if (v > 2) ok = false;
			}
			else if (b1 || b2) {
				if (v > 3) ok = false;
			}
			else if (v > 4) ok = false;
		}
		if (ok) {
			printf("YES\n");
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					bool b1 = i == 0 || i == n - 1;
					bool b2 = j == 0 || j == m - 1;
					if (b1 && b2) printf("2 ");
					else if (b1 || b2) printf("3 ");
					else printf("4 ");
				}
				printf("\n");
			}
		}
		else printf("NO\n");
	}
	return 0;
}