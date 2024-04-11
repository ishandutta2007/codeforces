#include <bits/stdc++.h>
using namespace std;

int x, y, p, q;
int bs(int, int);
bool check(int);

int main() {
    int t; cin >> t; while (t--) {
        cin >> x >> y >> p >> q;
        if (p == q && x < y) cout << "-1\n";
        else if (p == 0 && x > 0) cout << "-1\n";
        else {
            int d = 1, ans = 1e9;
            while (d <= 1e9) d <<= 1;
            while (d >>= 1) if (ans - d  >= 0) if (check(ans - d)) ans -= d;
            cout << (long long)ans * (long long)q - (long long)y << '\n';
        }
    }
    return 0;
}


bool check(int t) {
    if ((long long)t * (long long)q < (long long)y) return false;
    long long add = (long long)t * (long long)q - (long long)y, tar = (long long)t * (long long)p;
    if (tar - x < 0) return false;
    return tar - x <= add;
}