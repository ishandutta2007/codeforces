#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> op;

void solve(vector<int> &a, int n, int offset = 0) {
    for (int i = 0; i + 2 < n; i += 2) {
        op.push_back(i + offset);
    }
    for (int i = n - 5; i >= 0; i -= 2) {
        op.push_back(i + offset);
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        int tot = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            tot ^= a[i];
        }
        op.clear();
        if (tot != 0) {
            cout << "NO" << "\n";
            continue;
        }
        else if (n % 2) {
            solve(a, n);
        }
        else {
            int curr = 0;
            bool found = false;
            for (int i = 0; i < n - 1 and not found; i++) {
                curr ^= a[i];
                if (curr == 0 and i % 2 == 0) {
                    vector<int> x, y;
                    for (int j = 0; j <= i; j++) {
                        x.push_back(a[j]);
                    }
                    for (int j = i + 1; j < n; j++) {
                        y.push_back(a[j]);
                    }
                    solve(x, i + 1), solve(y, n - i - 1, i + 1);
                    found = true;
                }
            }
            if (!found) {
                cout << "NO" << "\n";
                continue;
            }

        }
        cout << "YES" << "\n";
        cout << op.size() << "\n";
        for (int x : op) {
            cout << x + 1 << " ";
        }
        cout << "\n";
    }
}