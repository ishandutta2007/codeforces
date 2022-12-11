#include <iostream>

using namespace std;

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	long long la, ra, ta, lb, rb, tb;
	cin >> la >> ra >> ta >> lb >> rb >> tb;
	if (lb - la < 0) {
		swap(la, lb);
		swap(ra, rb);
		swap(ta, tb);
	}
	long long g = gcd(ta, tb), c = lb - la;
	long long ans = min(ra - la + 1, rb - lb + 1); 
	if (c % g == 0) {
		cout << ans << endl;
		return 0;
	}
	long long t1 = ra - la + 1, t2 = rb - lb + 1;
	long long k = c / g;
	//cout << g << endl;
	long long d2 = c - k * g, d1 = (k + 1) * g - c;
	//cout << d2 << ' ' << d1 << endl;
	swap(d1, d2);
	long long ans1 = min(t2, t1 - d1);
	ans1 = max(ans1, 0ll);
	long long ans2 = min(t1, t2 - d2);
	ans2 = max(ans2, 0ll);
	cout << max(ans1, ans2) << endl;
	return 0;
}