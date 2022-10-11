#include <iostream>
#include <string>
#include <cstring>

typedef long long ll;

const ll MOD = 1e9 + 7;
const int ms = 707;

std::string str;
int ten[ms];
int sum[ms];
int memo[ms][ms][10];
//[on][middle][number] left is implicit. O(n^2)

int dp(int on, int middle, int number) {
	if(on == 0) {
		if(middle == 0) {
			return 0;
		} else {
			return (ll)number * sum[middle - 1] % MOD;
		}
	}
	int &ans = memo[on][middle][number];
	if(ans != -1) {
		return ans;
	}
	ans = ((ll)number * dp(on - 1, middle, number) +
		   (ll)(9LL - number) * 10LL * dp(on - 1, middle, number) + 
		   (ll)dp(on - 1, middle + 1, number)) % MOD;
	//std::cout << "dp(" << on << ", " << middle << ", " << number << ") got " << ans << "\n";
	return ans;
}

int freq[10];

int main() {
	ten[0] = sum[0] = 1;
	for(int i = 1; i < ms; i++) {
		ten[i] = (ll) ten[i - 1] * 10 % MOD;
		sum[i] = (sum[i - 1] + ten[i]) % MOD;
	}
	memset(memo, -1, sizeof memo);
	std::cin >> str;
	ll ans = 0;
	for(int i = 0; i < str.size(); i++) {
		for(int j = 0; j < str[i] - '0'; j++) {
			//right -= freq[j];
			//ans = (ans + (ll) ten[right] * dp(str.size() - i - 1, freq[j] + 1, j)) % MOD;
			//std::cout << j << ": calling for (" << str.size() - i - 1 << ", " << freq[j] + 1 << ", " << j << ")\n";
			freq[j]++;
			int right = i + 1 - freq[0];
			for(int k = 1; k < 10; k++) {
				right -= freq[k];
				ans = (ans + (ll) ten[right] * dp(str.size() - i - 1, freq[k], k)) % MOD;
				//std::cout << right << ", (" << j << ", " << k << "): calling for (" << str.size() - i - 1 << ", " << freq[k] << ", " << k << ") got " << (ll)ten[right] * dp(str.size() - i - 1, freq[k], k) << "\n";
			}
			freq[j]--;
		}
		freq[str[i] - '0']++;
	}
	ll cur = 0;
	for(int j = 1; j < 10; j++) {
		while(freq[j]--) {
			cur = (cur * 10 + j) % MOD;
		}
	}
	//std::cout << "cur is " << cur << '\n';
	std::cout << (ans + cur) % MOD << '\n';
}