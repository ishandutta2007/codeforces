#include <iostream>
#include <vector>
using namespace std;

long long quickpow(long long a, int ex) 
{
	long long res = 1;
	while (ex) {
		if (ex & 1) res *= a;
		a *= a;
		ex >>= 1;
	}
	return res;
}

void solve(long long k) 
{
	int i = 2;
	long long first = 11, cur = 1;
	long long next = 45;
	long long current_index = 1;
	while (current_index + next <= k) {
		current_index += next;
		next = (quickpow(10, i) - quickpow(10, i - 1)) * (first * 2 + i * (quickpow(10, i) - quickpow(10, i - 1) - 1)) / 2;
		cur = first;
		first = first + i * (quickpow(10, i) - quickpow(10, i - 1) - 1) + i + 1;
		++i;
	}
	--i;
	k -= current_index - 1;
	
	int l = 1, r = quickpow(10, i) - quickpow(10, i - 1);
	long long num_index = -1;
	while (l <= r) {
		long long m = (l + r) / 2;
		if (m * (cur * 2 + i * (m - 1)) / 2 >= k && (m - 1) * (cur * 2 + i * (m - 2)) / 2 < k) {
			num_index = m;
			break;
		}
		else if (m * (cur * 2 + i * (m - 1)) / 2 < k) l = m + 1;
		else r = m - 1;
	}
	
	k -= (long long)(num_index - 1) * (cur * 2 + i * (num_index - 2)) / 2;
	
	int j = 2;
	long long letter_pos = 1;
	long long next_letter = 9;
	while (letter_pos + next_letter * (j - 1) <= k) {
		letter_pos += next_letter * (j - 1);
		next_letter = quickpow(10, j) - quickpow(10, j - 1);
		++j;
	}
	--j;
	k -= letter_pos - 1;
	--k;
	long long num = quickpow(10, j - 1) + k / j;
	vector<int> digits;
	while (num) {
		digits.push_back(num % 10);
		num /= 10;
	}
	k %= j;
	cout << digits[digits.size() - k - 1] << '\n';
}

void test(long long k) 
{
	int j = 2;
	long long letter_pos = 1;
	long long next_letter = 9;
	while (letter_pos + next_letter * (j - 1) <= k) {
		letter_pos += next_letter * (j - 1);
		next_letter = quickpow(10, j) - quickpow(10, j - 1);
		++j;
	}
	--j;
	k -= letter_pos - 1;
	cout << '\n';
	cout << k << ' ' << letter_pos << ' ' << j << '\n';
	--k;
	long long num = quickpow(10, j - 1) + k / j;
	vector<int> digits;
	while (num) {
		digits.push_back(num % 10);
		num /= 10;
	}
	k %= j;
	cout << digits[digits.size() - k - 1] << '\n';
}

int main() 
{
	int t;
	cin >> t;
	
	long long k;
	while (t--) {
		cin >> k;
		solve(k);
	}
	
	return 0;
}