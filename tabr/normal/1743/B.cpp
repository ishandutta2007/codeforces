#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()

template<class T>
using vec = vector<T>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vec<int> a(n - 1);
        iota(all(a), 1);
        a.emplace_back(0);
        reverse(all(a));
        rep(i, n) {
            cout << a[i] + 1 << " \n"[i == n - 1];
        }
    }
    return 0;
}