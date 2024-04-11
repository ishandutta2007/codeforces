#include <stdio.h>
#include <vector>
using namespace std;
vector<int> a[100020];
int n, x, y;
double z;
void dfs(int x, int y, int d) {
	z += 1. / d;
	for (vector<int>::iterator i = a[x].begin(); i != a[x].end(); i++) {
		if (*i != y) {
			dfs(*i, x, d + 1);
		}
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1, 0, 1);
	printf("%.9f\n", z);
	return 0;
}