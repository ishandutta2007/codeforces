#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int N, ans = 0;
		cin >> N;
		for(int d = 1; d <= 9; d++) {
			long long val = d;
			while(true) {
				if(val > N) break;
				ans++;
				val = 10 * val + d;
			}
		}
		cout << ans << "\n";
	}
}