#include <bits/stdc++.h>

using namespace std;

int P[1005], V[1005];

int find(int x) {
    if (P[x]) return P[x] = find(P[x]);
    return x;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        memset(P, 0, sizeof(P));
        memset(V, 0, sizeof(V));
        vector<pair<int, int>> D;
        for (int i = 1; i <= n; ++i) {
            int d;
            cin >> d;
            D.emplace_back(d, i);
        }
        sort(D.rbegin(), D.rend());
        for (auto [d, i] : D) {
            if (V[i]) continue;
            V[i] = true;
            while (d--) {
                cout << "? " << i << endl;
                int x;
                cin >> x;
                if (V[x]) {
                    P[i] = x;
                    break;
                }
                else {
                    P[x] = i;
                    V[x] = true;
                }
            }
        }
        cout << "! ";
        for (int i = 1; i <= n; ++i) {
            cout << find(i) << " ";
        }
        cout << endl;
    }
    return 0;
}