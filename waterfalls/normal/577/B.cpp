#include <cstdio>
#include <algorithm>

using namespace std;

int n,m;
int a[1000013];
bool can[2][1013];

int main() {
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	if (n>=m) return printf("YES\n"), 0;
	for (int i=1;i<=n;i++) {
		for (int j=0;j<m;j++) can[1][j] = can[0][j];
		can[1][a[i]%m] = 1;
		for (int j=0;j<m;j++) can[1][(j+a[i])%m]|=can[0][j];
		swap(can[0],can[1]);
	}
	printf("%s\n",can[0][0] ? "YES" : "NO");

	return 0;
}