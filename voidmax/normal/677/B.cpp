#include <bits/stdc++.h>
#define For(i, a, b) for(int i = a; i < b; ++i)
#define Out(i, a, b) for(int i = a - 1; i >= b; --i)
#define pb push_back
#define point pair <int, int>
#define x first
#define y second
#define files(FileName) read(FileName); write(FileName)
#define read(FileName) freopen((FileName + ".in").c_str(), "r", stdin)
#define write(FileName) freopen((FileName + ".out").c_str(), "w", stdout)

using namespace std;

string FileName = "minsumdiff";

typedef long long base;

int n, h, k, a;
base ans, H;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> h >> k;
    For(i, 0, n) {
        cin >> a;
        if (H + a > h) {
            int eps = a - (h - H);
            if (H < eps) {
                ans += (H + k - 1) / k;
                H = 0;
            } else {
                ans += (eps + k - 1) / k;
                H -= (eps + k - 1) / k * k;
                if (H < 0) H = 0;
            }
        }
        H += a;
    }
    ans += (H + k - 1) / k;
    cout << ans << endl;
}