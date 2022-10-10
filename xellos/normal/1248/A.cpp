#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int N[2];
		int cnt[2][2];
		for(int k = 0; k < 2; k++) {
			cin >> N[k];
			cnt[k][0] = cnt[k][1] = 0;
			for(int i = 0; i < N[k]; i++) {
				int a;
				cin >> a;
				cnt[k][a%2 != 0]++;
			}
		}
		cout << 1LL*cnt[0][0]*cnt[1][0] + 1LL*cnt[0][1]*cnt[1][1] << "\n";
	}
}