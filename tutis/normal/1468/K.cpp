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
L
RUUDL
LLUU
DDDUUUUU

*/
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;

	while (t--) {
		string a;
		cin >> a;
		set<pair<int, int>> apl;
		{
			int x = 0, y = 0;

			for (auto &&c : a) {
				if (c == 'L') {
					x--;
				}
				else if (c == 'R') {
					x++;
				}
				else if (c == 'D') {
					y--;
				}
				else if (c == 'U') {
					y++;
				}
				else {
					abort();
				}

				apl.insert({x, y});
			}

			apl.erase({0, 0});
		}
		int kx = 0, ky = 0;

		for (auto &&[bx, by] : apl) {
			int x = 0, y = 0;

			for (auto &&c : a) {
				int nx = x, ny = y;

				if (c == 'L') {
					nx--;
				}
				else if (c == 'R') {
					nx++;
				}
				else if (c == 'D') {
					ny--;
				}
				else if (c == 'U') {
					ny++;
				}
				else {
					abort();
				}

				if (nx == bx and ny == by) {
					nx = x;
					ny = y;
				}
				else {
					x = nx;
					y = ny;
				}
			}

            if(x == 0 and y == 0){
                kx = bx;
                ky = by;
            }
		}
        cout << kx << " " << ky << "\n";
	}

}