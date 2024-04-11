#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int k = 1;
    while ((n + k) / (k + 1) + 1 <= (n + k - 1) / k) {
        k++;
    }
    int x = n + 1 - k - (n + k - 1) / k;
    vector<int> on(n), need(n, 1);
    for (int i = 0; i < n; i++) {
        if (i % k == 0) {
            need[i] = 0;
        }
    }
    while (accumulate(on.begin(), on.end(), 0) < x) {
        vector<int> a;
        for (int i = 0; i < n; i++) {
            if (on[i] == 0 && need[i] == 1) {
                a.emplace_back(i + 1);
            }
        }
        cout << a.size() << " ";
        for (int i : a) {
            cout << i << " ";
        }
        cout << endl;
        int c;
        cin >> c;
        c--;
        on = need;
        for (int i = 0; i < a.size(); i++) {
            on[(c + i) % n] = 0;
        }
    }
    cout << 0 << '\n';
    return 0;
}