#include <bits/stdc++.h>

using namespace std;

int t;
string a, b;

int main() {
	cin >> t;
	while (t--) {
		cin >> a >> b;
		int n = a.size(), m = b.size();
		int ans = 0;
		for (int x = 0; x < n; x++)	
			for (int y = x; y < n; y++)
				for (int z = 0; z < m; z++)
					for (int w = z; w < m; w++) 
						if (a.substr(x, y - x + 1) == b.substr(z, w - z + 1))
							ans = max(ans, y - x + 1);
		cout << n + m - ans - ans << "\n";
	}
	return 0;					
}