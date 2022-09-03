#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int n, m;
string s[10];
int p[10];

long long go (int i, int j, string ss) {
	if (i == n) {
		for (int k = 0; k < m; k++) {
			int l = 0;
			for (int i = 0; i < n; i++)
				l += int (s[k][i] == ss[i]);
			if (p[k] != l) return 0;
		}
		return 1;
	}
	long long tmp = go (i + 1, j, ss + char ('0' + '1' - s[0][i]));
	if (j < p[0]) tmp += go (i + 1, j + 1, ss + s[0][i]);
	return tmp;
}

int main () {
	cin >> n >> m;
	for (int i = 0; i < m; i++) cin >> s[i] >> p[i];
	cout << go (0, 0, "") << endl;
}