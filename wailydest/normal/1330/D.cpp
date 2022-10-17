#include <iostream>
#include <vector>
using namespace std;

int main() 
{
	int t;
	cin >> t;
	
	int d, m;
	while (t--) {
		cin >> d >> m;
		int m2p = 31 - __builtin_clz(d);
		vector<int> ssts(m2p + 1);
		for (int i = 0; i < m2p; ++i) {
			ssts[i] = 1 << i;
		}
		ssts[m2p] = d - (1 << m2p) + 1;
		long long ans = 1;
		for (int i = 1; i <= m2p; ++i) {
			ans += (ans * ssts[i] + ssts[i]) % m;
			ans %= m;
		}
		cout << ans % m << '\n';
	}
	return 0;
}