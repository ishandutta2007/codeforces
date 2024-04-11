#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            int x;
            cin >> x;
            --x;
            a[i][x] += 1;
        }
    }
    auto finish = [&]() -> int {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(a[i][j] != 1) return i;
            }
        }
        return -1;
    };
    vector<vector<int>> ans;
    int p = -1;
    while((p = finish()) != -1) {
        vector<int> g(n, -1);
        for(int i = p, j = 0; j < n; ++j, i = (i + 1) % n) {
            g[i] = g[(i + n - 1) % n];
            for(int k = 0; k < n; ++k) {
                if(a[i][k] > 1) {
                    g[i] = k;
                    break;
                }
            }
            assert(g[i] != -1);
        }
        ans.push_back(g);
        for(int i = 0; i < n; ++i) {
            --a[i][g[i]];
            ++a[i][g[(i + n - 1) % n]];
        }
    }
    for(int r = 0; r < n * (n - 1) / 2; ++r) {
        vector<int> g(n, -1);
        for(int j = 1; j < n; ++j) {
            if(a[0][j]) {
                g[0] = j;
                break;
            }
        }
        for(int j = 1; j < n; ++j) {
            g[j] = (g[0] + j) % n;
        }
        ans.push_back(g);
        for(int i = 0; i < n; ++i) {
            --a[i][g[i]];
            ++a[i][g[(i + n - 1) % n]];
        }
    }
    cout << ans.size() << '\n';
    for(auto b : ans) {
        for(int i : b) {
            cout << i + 1 << ' ';
        }
        cout << '\n';
    }
}