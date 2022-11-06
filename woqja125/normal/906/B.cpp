#include<cstdio>
#include<deque>
#include<algorithm>
#include<vector>
using namespace std;
int n, m;
int *a;
int get(int x, int y) {
	return x * m + y + 1;
}
int& A(int x, int y) {
	int l = x*m + y;
	return *(a + l);
}
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
vector<int> no[100];
void small() {
	a = new int[n*m];
	int succ = 0;
	for (int i = 1; i <= n*m; i++) a[i-1] = i;
	
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		int x = a[i*m + j];
		for (int d = 0; d < 4; d++) {
			int ii = i + dx[d];
			int jj = j + dy[d];
			if (ii < 0 || jj < 0 || ii >= n || jj >= m) continue;
			no[x].push_back(get(ii, jj));
		}
	}

	do {
		succ = 1;
		for (int i = 0; i < n && succ; i++) for (int j = 0; j < m && succ; j++) {
			for (int d = 0; d < 4; d++) {
				int ii = i + dx[d];
				int jj = j + dy[d];
				if (ii < 0 || jj < 0 || ii >= n || jj >= m) continue;
				for (int xx : no[A(i, j)]) {
					if (xx == A(ii, jj)) {
						succ = 0;
						break;
					}
				}
				if (!succ) break;
			}
		}
		if (succ) break;
	} while (next_permutation(a, a + n*m));
	if (!succ) {
		printf("NO\n");
		return;
	}
	printf("YES\n");
	for (int i = 0; i < n; i++, printf("\n")) for (int j = 0; j < m; j++) printf("%d ", a[i*m + j]);
}
int main() {
	scanf("%d%d", &n, &m);
	if (n <= 3 && m <= 3) {
		small();
		return 0;
	}


	a = new int[n*m];

	if (m >= 4) {
		for (int i = 0; i < n; i++) {
			int j = 0;
			if (i % 2 == 0) {
				for (int k = 1; k < m; k += 2) A(i, j++) = get(i, k);
				for (int k = 0; k < m; k += 2) A(i, j++) = get(i, k);
			}
			else {
				if (m != 4) {
					for (int k = 0; k < m; k += 2) A(i, j++) = get(i, k);
					for (int k = 1; k < m; k += 2) A(i, j++) = get(i, k);
				}
				else {
					j = m;
					for (int k = 1; k < m; k += 2) A(i, --j) = get(i, k);
					for (int k = 0; k < m; k += 2) A(i, --j) = get(i, k);
				}
			}
		}
	}
	else {
		for (int j = 0; j < m; j++) {
			int i = 0;
			if (j % 2 == 0) {
				for (int k = 1; k < n; k += 2) A(i++, j) = get(k, j);
				for (int k = 0; k < n; k += 2) A(i++, j) = get(k, j);
			}
			else {
				if (n != 4) {
					for (int k = 0; k < n; k += 2) A(i++, j) = get(k, j);
					for (int k = 1; k < n; k += 2) A(i++, j) = get(k, j);
				}
				else {
					i = n;
					for (int k = 1; k < n; k += 2) A(--i, j) = get(k, j);
					for (int k = 0; k < n; k += 2) A(--i, j) = get(k, j);
				}
			}
		}
	}

	printf("YES\n");
	for (int i = 0; i < n; i++, printf("\n")) for (int j = 0; j < m; j++) printf("%d ", a[i*m + j]);
	return 0;
}