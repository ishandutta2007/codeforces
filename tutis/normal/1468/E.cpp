#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef LOCAL
#define debug(...) {\
    std::cout << "[" << __FUNCTION__ << ":" << __LINE__ << "] " << #__VA_ARGS__ << " "  << __VA_ARGS__ << std::endl;\
    }
#else
#define debug(...)
#endif
/*input
4
1 2 3 4
5 5 5 5
3 1 4 1
100 20 20 100

*/
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;

	while (t--) {
		long long a, b, c, d;
		cin >> a >> b >> c >> d;
		long long ats = max(min(a, b) * min(c, d), min(a, c) * min(b, d));
		ats = max(ats, min(a, d) * min(b, c));
        cout << ats << "\n";
	}

}