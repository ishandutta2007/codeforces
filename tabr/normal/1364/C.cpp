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
    vector<int> a(n), b(n);
    set<int> st;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        st.emplace(a[i]);
    }
    int c = 0;
    if (a[0] > 1) {
        cout << -1 << '\n';
    }
    if (a[0] == 1) {
        b[0] = 0;
        c = 1;
        while (st.count(c)) {
            c++;
        }
    } else {
        c = 1;
        while (st.count(c)) {
            c++;
        }
        b[0] = c;
        c++;
        while (st.count(c)) {
            c++;
        }
    }
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) {
            b[i] = a[i - 1];
            if (a[i] > c) {
                cout << -1 << '\n';
                return 0;
            }
        } else {
            b[i] = c;
            c++;
            while (st.count(c)) {
                c++;
            }
        }
    }
    for (int i : b) {
        cout << i << " ";
    }
    cout << '\n';
    return 0;
}