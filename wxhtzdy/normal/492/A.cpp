#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;     
	int ans = 0, cnt = 0, res = 0;
	for (int i = 1; i <= n; i++) {
		cnt += i;
		res += cnt;
	 	if (res <= n) {
	 	  ans = i;
	 	}	else {
	 	 	break;
	 	}
	}
	cout << ans;
}