#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int T, n;
char s[N];

int main() {
	for(cin >> T; T --;) {
		scanf("%s", s + 1);
		n = strlen(s + 1);
		int ok = 1;
		for(int i = 1; i <= n; ++ i) {
			ok += (s[i] == 'E');
		}
		if(ok == n) puts("NO");
		else puts("YES");
	}
}