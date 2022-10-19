#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

char s[N];
int r[4], c[4];
int n, T, k;

map <int, int> Mx, My;

int main() {
	for(cin >> T; T --;) {
		int n;
		scanf("%d", &n);
		
		int t[2] = {0, 0};
		
		int rr = -1, cc = -1;
		
		Mx.clear(); My.clear();
		
		for(int i = 1; i <= 3; ++ i) {
			scanf("%d%d", &r[i], &c[i]);
			++ t[(r[i] + c[i]) & 1];
			++ Mx[r[i]];
			++ My[c[i]];

		}
		
		int e, d;
		for(auto x : Mx) if((x.second) == 2) e = (x.first);
		for(auto y : My) if((y.second) == 2) d = (y.first);
		
		if((e == 1 || e == n) && (d == 1 || d == n)) {
			rr = e, cc = d;
		}
		
		int x, y;
		scanf("%d%d", &x, &y);
		if(rr != -1) {
			if(x == rr || y == cc) {
				puts("YES");
			} else puts("NO");
			continue;
		}
		for(int i = 1; i <= 3; ++ i) {
			if(t[(r[i] + c[i]) & 1] == 1) {
				if((x % 2 == r[i] % 2) || (y % 2 == c[i] % 2)) {
					puts("YES");
				} else puts("NO");
			}
		}
	}
}