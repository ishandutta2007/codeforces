#include <bits/stdc++.h>
using namespace std;

const int N = (1 << 16) + 5;
int t, n, k, ans[N];

int main() {
	for(cin >> t; t --;) {
		scanf("%d%d", &n, &k);
		int up = 0;
		while((1 << up) != n) ++ up;
		
		for(int i = 0; i < n; ++ i) ans[i] = -1;
		
		if(n == 4 && k == 3) {
			puts("-1");
			continue;
		}
		
		if(k != n - 1) {
			ans[0] = n - 1 - k;
			ans[k] = n - 1;
		} else {
			ans[1] = 3;
			ans[n - 2] = n - 1;
			ans[0] = n - 1 - 3;
		}
		for(int i = 0; i < n; ++ i) {
			if(ans[i] != -1) ans[ans[i]] = i; 
		}
		for(int i = 0; i < n; ++ i) {
			if(ans[i] == -1) {
				ans[i] = n - 1 - i;
				ans[n - 1 - i] = i; 
			}
		}
		for(int i = 0; i < n; ++ i) if(i < ans[i]) {
			printf("%d %d\n", i, ans[i]);
		}
	}
}