#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();
    s.push_back(s[0]);
    vector<vector<int>> a(10, vector<int>(10, -1));
    vector<int> b(10);
    rep(k, 0, n - 1) b[(s[k + 1] - s[k] + 10) % 10]++;

    rep(i, 0, 10) rep(j, i, 10) {
        int res = 0;
        rep(k, 0, 10) {
            if (b[k] == 0)
                continue;
            set<int> st;
            st.insert(i);
            st.insert(j);
            rep(l, 1, 12) {
                if (l == 11) {
                    res = -1;
                    break;
                }
                if (st.find(k) != st.end()) {
                    res += (l - 1) * b[k];
                    break;
                }
                vector<int> y;
                for (auto q : st) {
                    y.push_back((q + i) % 10);
                    y.push_back((q + j) % 10);
                }
                for (auto q : y)
                    st.insert(q);
            }
            if (res == -1)
                break;
        }
        a[i][j] = a[j][i] = res;
    }
    rep(i, 0, 10) rep(j, 0, 10) {
        cout << a[i][j] << ((j != 9) ? ' ' : '\n');
    }

    return 0;
}