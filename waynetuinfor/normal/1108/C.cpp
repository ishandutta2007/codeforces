#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    vector<int> v = {0, 1, 2};
    int ans = 1e9;
    string sans = "";
    do {
        string t = "";
        for (int i = 0; i < n; ++i) {
            if (i % 3 == v[0]) t += 'R';
            if (i % 3 == v[1]) t += 'G';
            if (i % 3 == v[2]) t += 'B';
        }
        int dist = 0;
        for (int i = 0; i < n; ++i)
            dist += s[i] != t[i];
        if (dist < ans) {
            ans = dist;
            sans = t;
        }
    } while (next_permutation(v.begin(), v.end()));
    cout << ans << endl;
    cout << sans << endl;
}