#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        string s, c;
        cin >> s >> c;
        vector<vector<int>> abc(26);
        for (int i = s.size() - 1; i >= 0; i--) {
            abc[s[i] - 'A'].emplace_back(i);
        }
        bool bx = false;
        rep(i, 0, s.size()) {
            int x = s[i] - 'A';
            rep(j, 0, x) {
                if (!abc[j].empty())
                    if (abc[j][0] > i) {
                        swap(s[i], s[abc[j][0]]);
                        bx = true;
                        break;
                    }
            }
            if (bx)
                break;
        }

        if (s < c)
            cout << s << endl;
        else
            cout << "---" << endl;
    }

    return 0;
}