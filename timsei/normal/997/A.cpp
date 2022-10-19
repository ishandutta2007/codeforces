#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;

int n, m, x, y, cnt[2];

char s[N];

int main() {
	cin >> n >> x >> y;
	long long ans = 0;
	scanf("%s", s + 1);
	
	for(int i = 1; i <= n; ++ i) {
		if(i != 1 && s[i] == s[i - 1]) continue;
		else {
			++ cnt[s[i] - '0'];
		}
	}
	if(!cnt[0]) cout << 0 << endl;
	else cout << y + 1LL * min(x, y) * (cnt[0] - 1) << endl;
}