#include <stdio.h>
#include <assert.h>
#include <vector>

using namespace std;

int n, a, b;

bool ok(vector< vector<int> > &u, int x0, int y0, int x1, int y1) {
	if ((x1 < 0) || (x1 >= a) || (y1 < 0) || (y1 >= b)) return true;
	if ((u[x0][y0] == 0) || (u[x1][y1] == 0)) return true;
	if (u[x0][y0] % 2 != u[x1][y1] % 2) return true;
	return false;
}

int main() {
	scanf("%d%d%d", &n, &a, &b);
	if (n > a * b) {
		puts("-1");
		return 0; 
	} else {
		vector< vector<int> > u(a, vector<int>(b));
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				int nom = i * b + j + 1;
				u[i][j] = nom;
			}
		}
		if (b % 2 == 0) {
			for (int i = 1; i < a; i += 2) {
				int tmp = u[i][0];
				for (int j = 0; j + 1 < b; j++) u[i][j] = u[i][j + 1];
				u[i][b - 1] = tmp;
			}
		}
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				printf("%d ", u[i][j] <= n ? u[i][j] : 0);
			}
			puts("");
		}
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				assert(ok(u, i, j, i - 1, j));
				assert(ok(u, i, j, i + 1, j));
				assert(ok(u, i, j, i, j - 1));
				assert(ok(u, i, j, i, j + 1));
			}
		}
	}
}