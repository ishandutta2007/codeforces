#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector <vector <char> > wood(n, vector <char>(n));
	for (int i = 0; i < n; i++) {
		scanf("\n");
		for (int j = 0; j < n; j++) {
			scanf("%c", &wood[i][j]);
		}
	}
	bool good = false;
	for (int i = 0; i < n; i++) {
		bool ok = false;
		for (int j = 0; j < n; j++) {
			if (wood[i][j] != 'E') {
				ok = true;
			}
		}
		if (!ok) {
			good = true;
		}
	}
	for (int i = 0; i < n; i++) {
		bool ok = false;
		for (int j = 0; j < n; j++) {
			if (wood[j][i] != 'E') {
				ok = true;
			}
		}
		if (!ok && good) {
			printf("-1");
			return 0;
		}
	}
	vector <vector <bool> > used(n, vector <bool>(n));
	if (good) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (wood[j][i] != 'E') {
					printf("%d %d\n", j + 1, i + 1);
					break;
				}
			}
		}
	} else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (wood[i][j] != 'E') {
					printf("%d %d\n", i + 1, j + 1);
					break;
				}
			}
		}
	}
	return 0;
}