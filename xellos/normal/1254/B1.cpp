#include <iostream>
#include <vector>
using namespace std;

using cat = long long;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	vector<int> A(N);
	int sum = 0;
	for(int i = 0; i < N; i++) {
		cin >> A[i];
		sum += A[i];
	}
	if(sum == 1) {
		cout << "-1\n";
		return 0;
	}
	cat ans = 0;
	vector<int> is_prime(sum+1, 1);
	for(int p = 2; p <= sum; p++) if(is_prime[p] && sum%p == 0) {
		for(int i = p; i <= sum; i += p) is_prime[i] = 0;
		cat cur = 0;
		for(int i = 0, l = i; i < sum/p; i++) for(int j = 0; j < p; j++) {
			while(A[l] == 0) l++;
			if(j < p-1-j) cur -= l;
			if(j > p-1-j) cur += l;
			l++;
		}
		ans = ans ? min(ans, cur) : cur;
	}
	cout << ans << "\n";
}