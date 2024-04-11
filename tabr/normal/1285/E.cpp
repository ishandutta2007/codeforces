#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
//#include "library/debug.cpp"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<tuple<int, int, int>> p;
        rep(i, 0, n) {
            int l, r;
            cin >> l >> r;
            p.emplace_back(l, 1, i);
            p.emplace_back(r + 1, 0, i);
        }
        sort(p.begin(), p.end());
        int x = 0;
        vector<int> y(n);
        set<int> st;
        for (auto z : p) {
            if (get<1>(z) == 0) {
                st.erase(get<2>(z));
                if (st.size() == 1 && y[*st.begin()] % 2 == 0) {
                    y[*st.begin()]++;
                }
            } else {
                if (st.size() == 1 && y[*st.begin()] % 2 == 1) {
                    y[*st.begin()]++;
                }
                st.insert(get<2>(z));
            }
            if (st.empty()) x++;
        }
        if (x == n)
            cout << n - 1 << endl;
        else
            cout << x + *max_element(y.begin(), y.end()) / 2 << endl;
    }
    return 0;
}