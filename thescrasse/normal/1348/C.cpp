#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define INF (ll)1e18

ll i, i1, j, k, k1, t, n, m, res, check1, check2, a, b, of[100010], l;
string s;
set<char> set1;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    while (t--) {
        cin >> n >> k >> s;
        sort(s.begin(), s.end());
        check1 = 0; check2 = 0;
        l = 0;
        for (i = 0; i < k; i++) {
            of[i] = 0;
        }
        set1.clear();
        for (i = 0; i < k; i++) {
            set1.insert(s[i]);
        }
        if (set1.size() > 1) {
            check1 = 1;
        }
        set1.clear();
        for (i = k; i < n; i++) {
            set1.insert(s[i]);
        }
        if (set1.size() > 1) {
            check2 = 1;
        }
        if (check1 == 0 && check2 == 0) {
            while (l < n) {
                for (i = l; i < min(l + k, n); i++) {
                    of[i] = i - l;
                }
                l += k;
            }
            for (i = 0; i < n; i++) {
                if (of[i] == 0) {
                    cout << s[i];
                }
            }
        } else {
            for (i = k; i < n; i++) {
                of[i] = 0;
            }
            if (check1 == 1) {
                cout << s[k - 1];
            } else {
                cout << s[0];
                for (i = k; i < n; i++) {
                    cout << s[i];
                }
            }
        }
        cout << endl;
    }

    return 0;
}