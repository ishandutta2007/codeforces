#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define INF (ll)1e18

ll i, i1, j, k, k1, t, n, m, res, check1, v[200010], a, b;
priority_queue<pair<ll, ll>> pq;

int main() {
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    while (t--) {
        cin >> n;
        pq.push({n, 0});

        for (i = 1; i <= n; i++) {
            a = pq.top().first; b = -pq.top().second; pq.pop();
            if (a % 2 == 1) {
                k = a / 2;
                v[b + k] = i;
                if (a != 1) {
                    pq.push({a / 2, -b});
                    pq.push({a / 2, -(b + k + 1)});
                }
            } else {
                k = a / 2;
                v[b + k - 1] = i;
                pq.push({a / 2 - 1, -b});
                pq.push({a / 2, -(b + k)});
            }
        }

        for (i = 0; i < n; i++) {
            cout << v[i] << ' ';
        }
        cout << endl;
    }

    return 0;
}