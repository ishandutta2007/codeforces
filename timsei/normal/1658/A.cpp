#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n, m, x, y, A[N];
char s[N];

void rmain() {
	scanf("%d", &n);
	scanf("%s", s + 1);
	int ans = 0;
	for(int i = 1; i < n; ++ i) if(s[i] == '0')  {
		if(s[i] == s[i + 1])
		ans += 2;
		else if(i < n - 1 && (s[i] == s[i + 2]))
		ans += 1;
	}
	cout << ans << endl;
}

int main() {
	int t;
	for(cin >> t; t --;) {
		rmain();
	}
}