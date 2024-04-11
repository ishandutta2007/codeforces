#include <iostream>
#include <set>
using namespace std;

int main() 
{
	multiset<int> p;
	int a1, a2, k1, k2, n;
	cin >> a1 >> a2 >> k1 >> k2 >> n;
	
	int n_res = a1 * (k1 - 1) + a2 * (k2 - 1);
	n -= n_res;
	if (n <= 0) cout << 0 << ' ';
	else {
		cout << n << ' ';
	}
	n += n_res;
	
	n_res = k1 < k2 ? k1 * a1 : k2 * a2;
	if (n_res >= n) cout << n / min(k1, k2);
	else {
		cout << (k1 < k2 ? a1 : a2) + (n - n_res) / max(k1, k2);
	}
	return 0;
}