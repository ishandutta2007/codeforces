#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }
    int ans = n;
    set<int> s, t;
    rep(i, 0, n) {
        if (s.find(a[i]) != s.end())
            break;
        s.insert(a[i]);
        int j = n - 1;
        t = s;
        while (t.find(a[j]) == t.end()) {
            t.insert(a[j]);
            j--;
        }
        ans = min(ans, j - i);
    }
    t.clear();
    int j = n - 1;
    while (t.find(a[j]) == t.end()) {
        t.insert(a[j]);
        j--;
        if (j == -1)
            break;
    }
    ans = min(ans, j + 1);
    cout << ans << endl;

    return 0;
}