#include "bits/stdc++.h"

using namespace std;

#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    queue<pair<int, int>> q[2];

    for (int x = 1; x <= n; ++x) {
        for (int y = 1; y <= n; ++y) {
            q[(x + y) % 2].emplace(x, y);
        }
    }

    while (not empty(q[0]) && not empty(q[1])) {
        int c;
        cin >> c;

        if (c == 1) {
            auto [x, y] = q[0].front();
            q[0].pop();
            cout << "3 " << x << " " << y << endl;
        }
        else {
            auto [x, y] = q[1].front();
            q[1].pop();
            cout << "1 " << x << " " << y << endl;
        } 
    }

    int d[2] = { 3, 1 };
    for (int t = 0; t < 2; ++t) {
        while (not empty(q[t])) {
            int c;
            cin >> c;

            auto [x, y] = q[t].front();
            q[t].pop();

            if (c != 2) {
                cout << "2 " << x << " " << y << endl;
            }
            else {
                cout << d[t] << " "  << x << " " << y << endl;
            }
        }
    }


    exit(0);
}