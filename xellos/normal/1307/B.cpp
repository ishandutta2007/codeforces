#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

using cat = long long;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		int N, X, ans = 1100000000;
		cin >> N >> X;
		for(int i = 0, a; i < N; i++) {
			cin >> a;
			if(a <= X) ans = min(ans, (X+a-1)/a);
			else ans = min(ans, 2);
		}
		cout << ans << "\n";
	}
}