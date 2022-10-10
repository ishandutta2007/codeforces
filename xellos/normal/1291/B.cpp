#include <iostream>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		bool ans = true;
		for(int i = 0, cur = 0, up = 1, a; i < N; i++) {
			cin >> a;
			if(up && a >= i) {
				cur = a;
				continue;
			}
			up = 0;
			if(cur == 0) ans = false;
			cur = min(a, cur-1);
		}
		cout << (ans ? "Yes\n" : "No\n");
	}
}