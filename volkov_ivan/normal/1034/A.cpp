#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

const int MAX_N = 3e5 + 7;
long long arr[MAX_N];
vector <int> p;
unordered_map <int, int> cnt;
vector <int> all;

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

void f(int n, int d) {
	int i = 0;
	//cout << p[0] << endl;
	while (i < p.size() && p[i] * p[i] <= d) {
		//cout << i << ' ' << p[i] << ' ' << d << endl;
		if (d % p[i] == 0) {
			all[i]++;
			while (d % p[i] == 0) d /= p[i];
		}
		i++;
	}
	if (d < 4000) {
		for (int i = 0; i < p.size(); i++) {
			if (p[i] == d) {
				all[i]++;
				return;
			}
		}
	}
	if (d != 1) cnt[d]++;
}

bool is_prime(int n) {
	int i = 2;
	while (i * i <= n) {
		if (n % i == 0) return 0;
		i++;
	}
	return 1;
}

int main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);	
	for (int i = 2; i < 4000; i++) if (is_prime(i)) p.push_back(i);
	all.resize(p.size());
	for (int &elem : all) elem = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	long long d = arr[0];
	for (int i = 1; i < n; i++) d = gcd(d, arr[i]);
	for (int i = 0; i < n; i++) arr[i] = arr[i] / d;
	int ans = 0;
	for (int i = 0; i < n; i++) f(n, arr[i]);
	for (int i = 0; i < (int) all.size(); i++) ans = max(ans, all[i]);
	for (pair <int, int> elem : cnt) ans = max(ans, elem.second);
	//cout << ans << endl;
	if (ans == 0) cout << -1 << endl;
	else cout << n - ans << endl;
	return 0;
}