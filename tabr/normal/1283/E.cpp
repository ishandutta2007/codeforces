#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n + 3);
    rep(i, 0, n) {
        int x;
        cin >> x;
        a[x]++;
    }
    int mn = 0, mx = 0;
    int cnt = 0, sum = 0;
    set<int> st;
    rep(i, 1, n + 2) {
        if (a[i]) {
            cnt++;
            sum += a[i];
        } else if (cnt) {
            mx += cnt;
            if (sum - cnt >= 2) {
                st.insert(i);
                st.insert(i - 1 - cnt);
            } else if (sum - cnt == 1) {
                if (st.find(i - 1 - cnt) != st.end())
                    st.insert(i);
                else
                    st.insert(i - 1 - cnt);
            }
            cnt = 0;
            sum = 0;
        }
    }
    mx += st.size();
    cnt = 0;
    rep(i, 1, n + 2) {
        if (a[i] > 0) {
            mn++;
            i += 2;
        }
    }
    cout << mn << ' ' << mx << endl;
    return 0;
}