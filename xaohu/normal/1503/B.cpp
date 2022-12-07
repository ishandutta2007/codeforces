#include <bits/stdc++.h>

using namespace std;

int n, vis[100][100];

int main() {
	cin >> n;
	for (int i = 0; i < n * n; i++) {
		int e;
		cin >> e;
		e--;
		int x = -1, y, z;
		for (int a = 0; a < n; a++)
			for (int b = 0; b < n; b++)	
				if (!vis[a][b]) {
					if (x == -1) {
						x = a;
						y = b;
						z = 2;
					}
					if ((a + b) % 2 != e) {
						x = a; 
						y = b;
						z = (a + b) % 2;
					}
				}
		vis[x][y] = 1;
		cout << z + 1 << " " << x + 1 << " " << y + 1 << "\n";
	}
	return 0;
}