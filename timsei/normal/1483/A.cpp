#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int t, n, m, x, y, ans[N];

vector <int> f[N];

int main() {
	int t;
	for(cin >> t; t --;) {
		cin >> n >> m;
		for(int i = 1; i <= m; ++ i) f[i].clear();
		for(int i = 1; i <= n; ++ i) ans[i] = 0;
 		for(int i = 1; i <= m; ++ i) {
			scanf("%d", &x);
			for(int j = 0; j < x; ++ j) scanf("%d", &y), f[i].push_back(y);
			++ ans[f[i][0]];
		}
		int MX = 0;
		for(int i = 1; i <= n; ++ i) 
		if(ans[i] > (m + 1) / 2) {
			MX = i;
		}
		
		if(!MX) {
			puts("YES");
			for(int i = 1; i <= m; ++ i) printf("%d ", f[i][0]);
			puts("");
		}
		else {
			for(int i = 1; i <= m; ++ i) if(f[i].size() > 1)  {
				if(f[i][0] == MX) {
					-- ans[MX];
					swap(f[i][0], f[i][1]);
					if(ans[MX] <= (m + 1) / 2) break;
				}
			}
			if(ans[MX] > (m + 1) / 2) puts("NO");
			else {
				puts("YES");
				for(int i = 1; i <= m; ++ i) printf("%d ", f[i][0]);
				puts("");
			}
		}
	}
}