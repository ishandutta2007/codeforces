#include <cstdio>
using namespace std;

const int N = 50;

bool a[N][N];
bool ch[N][N];
char buf[N + 1];

int main() 
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%s", buf);
			for (int j = 0; j < n; ++j) {
				a[i][j] = buf[j] == '1';
				ch[i][j] = false;
			}
		}
		bool ok = true;
		for (int i = n - 1; i >= 0; --i) {
			for (int j = n - 1; j >= 0; --j) if (a[i][j]) {
				if (!(i == n - 1 || j == n - 1 || a[i + 1][j] || a[i][j + 1])) ok = false;
			}
		}
		if (ok) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}