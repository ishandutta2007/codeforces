#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int A[N], B[4], n, ok[N];

char s[N];

int main() {
	int T;
	for(cin >> T; T --;) {
		scanf("%d", &n);
		scanf("%s", s + 1);
		for(int i = 1; i <= n; ++ i) ok[i] = 1;
		for(int i = 1; i <= n; ++ i) if(s[i] == '0') ok[i] = 0;
		
		bool bef = 0;
		
		long long ans = 0;
		
		for(int i = 1; i <= n; ++ i) {
			for(int j = i; j <= n; j += i) {
				if(s[j] == '1') {
					break;
				} else {
					if(!ok[j]) {
						ans += i; ok[j] = 1;
					}
				}
			}
		}
		printf("%lld\n", ans);
	}
}