#include <iostream>
#include <cmath>
#include <map>
#include <string>

using namespace std;
using ll = long long;

map<char, int> dx = {{'U', 0}, {'D', 0}, {'L', -1}, {'R', 1}};
map<char, int> dy = {{'U', 1}, {'D', -1}, {'L', 0}, {'R', 0}};

int main() {
    ll sx, sy, gx, gy, N;
    cin >> sx >> sy >> gx >> gy >> N;
    string S;
    cin >> S;

    ll wx[N], wy[N];
    wx[0] = 0, wy[0] = 0;

    for (int i = 1; i <= N; ++i) {
        wx[i] = wx[i - 1] + dx[S[i - 1]];
        wy[i] = wy[i - 1] + dy[S[i - 1]];
    }

    ll t;
    {
        ll ok = 1e12, ng = 0;
        while (ok - ng > 1) {
            ll mid = (ok + ng) / 2;
            ll d = abs(gx - (sx + wx[N] * mid)) + abs(gy - (sy + wy[N] * mid));

            if (d <= mid * N) {
                ok = mid;
            } else {
                ng = mid;
            }
        }

        t = ok;
    }

    if (t == 1e12) {
        cout << "-1" << endl;
        return 0;
    }

    --t;
    sx += wx[N] * t;
    sy += wy[N] * t;

    for (int i = 0; i <= N; ++i) {
        ll d = abs(gx - (sx + wx[i])) + abs(gy - (sy + wy[i]));
        if (d <= N * t + i) {
            cout << N * t + i << endl;
            return 0;
        }
    }

    terminate();
    return 0;
}