#include <cstdio>
using namespace std;

const int N = 1024;
int n;
int a[N];

bool c(int k) 
{
	int be[N] = {0};
	int aft[N] = {0};
	for (int i = 0; i < n; ++i) {
		++be[a[i]];
		++aft[a[i] ^ k];
	}
	for (int i = 0; i < N; ++i) if (be[i] != aft[i]) return false;
	return true;
}

int main() 
{
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", a + i);
		bool ok = false;
		int k;
		for (k = 1; k < N && !ok; ++k) {
			if (c(k)) {
				ok = true;
			}
		}
		if (ok) printf("%d\n", k - 1);
		else printf("-1\n");
	}
	return 0;
}