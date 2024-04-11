#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
int n, f[110][3], a[110];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	memset(f, 63, sizeof(f));
	f[0][0] = 0;
	//0 rest 1 gym 2 contest
	for (int i = 1; i <= n; ++i) {
		if (a[i] == 2 || a[i] == 3) f[i][1] = min(f[i - 1][0], f[i - 1][2]);
		if (a[i] == 1 || a[i] == 3) f[i][2] = min(f[i - 1][0], f[i - 1][1]);
		f[i][0] = min(f[i - 1][0], min(f[i - 1][1], f[i - 1][2])) + 1;
	}
	printf("%d\n", min(f[n][0], min(f[n][1], f[n][2])));
}