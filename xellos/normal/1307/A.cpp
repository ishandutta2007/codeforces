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
		int N, D, ans = 0;
		cin >> N >> D;
		for(int i = 0; i < N; i++) {
			int a;
			cin >> a;
			while(D >= i && a) a--, ans++, D -= i;
		}
		cout << ans << "\n";
	}
}