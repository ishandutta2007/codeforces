#include <bits/stdc++.h>
using namespace std;

int n, q, b, r, c;
bool mz[2][100002];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	while (q--) {
        cin >> r >> c;
        r--;
        if (!mz[r][c]) {
            b += (mz[r==0][c] == 1) + (mz[r==0][c-1] == 1) + (mz[r==0][c+1] == 1);
            mz[r][c] = 1;
        }
        else {
            b -= (mz[r==0][c] == 1) + (mz[r==0][c-1] == 1) + (mz[r==0][c+1] == 1);
            mz[r][c] = 0;
        }
        if (b) cout << "No\n";
        else cout << "Yes\n";
    }
}