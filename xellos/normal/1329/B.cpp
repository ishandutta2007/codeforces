#include <iostream>
#include <vector>
using namespace std;

using cat = long long;

int main() {
	cin.sync_with_stdio(0);
	int T;
	cin >> T;
	while(T--) {
		cat D, mod;
		cin >> D >> mod;
		int B = 0; // max bit in D
		while((2<<B) <= D) B++;
		vector<cat> pw2(B+1, 1);
		for(int i = 1; i <= B; i++) pw2[i] = 2 * pw2[i-1];
		vector<cat> cnt(B+1, 0);
		for(int i = 0; i < B; i++) cnt[i] = pw2[i];
		cnt[B] = D-pw2[B]+1;
		cat ans = 0;
		for(int l = 1; l <= B+10; l++) {
			for(int i = 0; i <= B; i++) {
				ans += cnt[i];
				if(ans >= mod) ans -= mod;
			}
			vector<cat> cnt_nw(B+1, 0);
			cat sum = 0;
			for(int i = 0; i < B; i++) {
				cnt_nw[i] = sum * pw2[i] % mod;
				sum += cnt[i];
				if(sum >= mod) sum -= mod;
			}
			cnt_nw[B] = sum * (D-pw2[B]+1) % mod;
			cnt = cnt_nw;
		}
		cout << ans << "\n";
	}
}