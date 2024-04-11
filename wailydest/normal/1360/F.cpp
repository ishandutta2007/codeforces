#include <cstdio>
#include <utility>
using namespace std;

const int N = 10;
char s[N][N + 1];

int main() 
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) {
			scanf("%s", s[i]);
		}
		bool ok = false;
		for (int k = 0; k < m && !ok; ++k) {
			for (char let = 'a'; let <= 'z' && !ok; ++let) {
				bool th = true;
				for (int i = 1; i < n; ++i) {
					bool put = false;
					for (int j = 0; j < m; ++j) if (s[i][j] != (j == k ? let : s[0][j])) {
						if (!put) put = true;
						else th = false;
					}
				}
				if (th && !ok) {
					ok = true;
					s[0][k] = let;
					printf("%s\n", s[0]);
				}
			}
		}
		if (!ok) printf("-1\n");
	}
	return 0;
}