#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

char w[101][101];
set<char> all;

int main () {
	int n, m;
	char c;
	scanf ("%d%d %c\n", &n, &m, &c);
	for (int i = 0; i < n; i++) gets (w[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (i + 1 < n && w[i][j] == c && w[i + 1][j] != '.' && w[i + 1][j] != c)
				all.insert (w[i + 1][j]);
			if (i + 1 < n && w[i + 1][j] == c && w[i][j] != '.' && w[i][j] != c)
				all.insert (w[i][j]);
			if (j + 1 < m && w[i][j] == c && w[i][j + 1] != '.' && w[i][j + 1] != c)
				all.insert (w[i][j + 1]);
			if (j + 1 < m && w[i][j + 1] == c && w[i][j] != '.' && w[i][j] != c)
				all.insert (w[i][j]);
		}
	printf ("%d\n", all.size ());
}