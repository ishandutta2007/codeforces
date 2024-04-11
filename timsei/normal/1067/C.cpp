#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int n;

int main() {
	cin >> n;
	int now = 0;
	for(int i = 1; i <= n; ++ i) {
		if(i + (i / 2) > n) {
			now = i - 1;
			break;
		}
	}
	if((n * n) / 10 <= n) {
		for(int i = 1; i <= n; ++ i
		) printf("%d %d\n", rand(), rand());
		return 0;
	}
	for(int i = 1; i <= now; ++ i) cout << 1 <<" " << i << endl, -- n;
	for(int i = 2; i <= now; i += 2) cout << 4 <<" " << i << endl, -- n;
	for(int i = 1; i <= now; i += 2) {
		if(n) cout << 4 <<" " << i << endl, -- n;
	}
}