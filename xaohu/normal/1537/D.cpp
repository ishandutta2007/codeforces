#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; a <= i; i--)
using namespace std;

//~ int dp[200111];

int main() {
	//~ rep(i, 2, 200) {
		//~ rep(j, 2, i - 1)
			//~ if (i % j == 0 && dp[i - j] == 0)
				//~ dp[i] = 1;
		//~ cout << i << " " << dp[i] << endl;
		//~ if (i % 2 == 1)
			//~ assert(dp[i] == 0);
		//~ if (i % 2 == 0 && dp[i] == 0)
			//~ cout << i << endl;
	//~ }
	int T; cin >> T;
	while (T--) {
		int n;
		cin >> n;
		if (n & 1) 
			cout << "Bob\n";
		else {
			int cnt = 0;
			while (n % 2 == 0) {
				cnt++;
				n /= 2;
			}
			if (n == 1 && cnt % 2) 
				cout << "Bob\n";
			else 
				cout << "Alice\n";
		}
	}
	return 0;
}