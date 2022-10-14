#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

vector<vector<int>> g(N);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    if (n == 3) {
        cout << 3 << '\n';
        cout << 1 << " " << 2 << '\n';
        cout << 2 << " " << 3 << '\n';
        cout << 3 << " " << 1 << '\n';
        return 0;
    }
    vector<int> prime(N, 1);
    prime[0] = prime[1] = 0;
    for (int i = 0; i < N; i++) {
        if (prime[i]) {
            for (int j = i + i; j < N; j += i) {
                prime[j] = 0;
            }
        }
    }
    for (int i = 0; i < n - 1; i++) {
        g[i].push_back(i + 1);
    }
    g[n - 1].push_back(0);
    int k = n, nxt = 0;
    while (!prime[k]) {
        g[nxt + n / 2].push_back(nxt);
        nxt++;
        k++;
    }
    cout << k << '\n';
    for (int i = 0; i < n; i++) {
        for (int c : g[i]) {
            cout << i + 1 << " " << c + 1 << '\n';
        }
    }
    return 0;
}