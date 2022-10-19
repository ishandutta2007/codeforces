#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

char s[N];
int ct[256];

int n, T, k;

int main() {
	for(cin >> T; T --;) {
		scanf("%d%d", &n, &k);
		scanf("%s", s + 1);
		memset(ct, 0, sizeof(ct));
		for(int i = 1; i <= n; ++ i) ++ ct[s[i]];
		for(int i = 1; i <= k; ++ i) {
			bool ok = 1; int cnt = n / k;
			for(int j = 'a'; j <= 'z'; ++ j) {
				if(!ct[j] || cnt == 0) {
					printf("%c", j);
					break;
				} else {
					-- ct[j]; -- cnt;
				}
			}
		}
		puts("");
	}
}