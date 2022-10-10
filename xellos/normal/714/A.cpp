#include <iostream>
using namespace std;

using cat = long long;

int main() {
	cat l[2], r[2], k;
	cin >> l[0] >> r[0] >> l[1] >> r[1] >> k;
	cat lo = max(l[0], l[1]);
	cat ro = min(r[0], r[1]);
	if(ro < lo) cout << "0\n";
	else if(k < lo || k > ro) cout << ro-lo+1 << "\n";
	else cout << ro-lo << "\n";
}