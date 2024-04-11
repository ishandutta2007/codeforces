#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int i, j, flag = 1, n;
	char s[111][111];
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> s[i];
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (s[i][j] == '.') {
				s[i][j] = '#';
				if (i + 2 >= n)
					flag = 0;
				else {
					if (s[i + 1][j] == '#')
						flag = 0;
					else
						s[i + 1][j] = '#';
					if (s[i + 2][j] == '#')
						flag = 0;
					else
						s[i + 2][j] = '#';
					if (j == 0 || j == n - 1)
						flag = 0;
					else {
						if (s[i + 1][j - 1] == '#')
							flag = 0;
						else
							s[i + 1][j - 1] = '#';
						if (s[i + 1][j + 1] == '#')
							flag = 0;
						else
							s[i + 1][j + 1] = '#';
					}
				}
			}
		}
	}
	if (flag == 1)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}