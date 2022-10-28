#include <bits/stdc++.h>
using namespace std;

const int N = 1000000 + 1;
const int L = __lg(N) + 1;

int key[N], suffix[N], temp[N];
int balance[N], sparse[L][N];

int query(int a, int b) {
    int l = __lg(b - a + 1);
    return min(sparse[l][a], sparse[l][b - (1 << l) + 1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();

    for (int i = 0; i < n; ++i) {
        key[i] = s[i] - '(';
        suffix[i] = i;
    }

    for (int k = 0; k <= n; k = max(1, 2 * k)) {
        sort(suffix, suffix + n, [&](int a, int b) {
            if (key[a] == key[b]) {
                return key[(a + k) % n] < key[(b + k) % n];
            }
            return key[a] < key[b];
        });

        copy(key, key + n, temp);
        key[suffix[0]] = 0;
        int m = 0;

        for (int i = 1; i < n; ++i) {
            m += temp[suffix[i - 1]] < temp[suffix[i]] ||
                temp[(suffix[i - 1] + k) % n] < temp[(suffix[i] + k) % n];
            key[suffix[i]] = m;
        }
    }

    for (int i = 0; i < n; ++i) {
        balance[i + 1] = balance[i] + (s[i] == '(' ? 1 : -1);
    }

    for (int i = 0; i <= __lg(n + 1); ++i) {
        for (int j = 0; j + (1 << i) - 1 <= n; ++j) {
            if (i == 0) {
                sparse[i][j] = balance[j];
            } else {
                sparse[i][j] = min(sparse[i - 1][j], sparse[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    if (balance[n] == 0) {
        for (int i = 0; i < n; ++i) {
            int r = suffix[i];
            if (balance[r] == query(0, n)) {
                cout << s.substr(r) + s.substr(0, r) << "\n";
                exit(0);
            }
        }
    } else if (balance[n] > 0) {
        for (int i = 0; i < n; ++i) {
            int r = suffix[i];
            if (query(r, n) == balance[r] && query(0, r) >= balance[r] - balance[n]) {
                cout << s.substr(r) + s.substr(0, r) + string(balance[n], ')') << "\n";
                exit(0);
            }
        }
    } else {
        for (int i = 0; i < n; ++i) {
            int r = suffix[i];
            if (query(r, n) >= balance[n] + balance[r] && query(0, r) == balance[r]) {
                cout << string(-balance[n], '(') + s.substr(r) + s.substr(0, r) << "\n";
                exit(0);
            }
        }
    }
}