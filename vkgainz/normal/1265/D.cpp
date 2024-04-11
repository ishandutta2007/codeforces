#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int, int> hs;
    cin >> hs[0] >> hs[1] >> hs[2] >> hs[3];
    int total = hs[0] + hs[1] + hs[2] + hs[3];
    for (int st = 0; st < 4; st++) if (hs[st]) {
        vector<int> res;
        auto ths = hs;
        ths[st]--;
        res.push_back(st);
        int last = st;
        for (int i = 0; i < total - 1; i++) {
            if (ths[last - 1]) {
                ths[last - 1]--;
                res.push_back(last - 1);
                last--;
            }
            else if (ths[last + 1]) {
                ths[last + 1]--;
                res.push_back(last + 1);
                last++;
            }
            else {
                break;
            }
        }
        if ((int) res.size() == total) {
            cout << "YES\n";
            for (int i = 0; i < (int) res.size(); i++) {
                cout << res[i] << " \n"[i == (int) res.size() - 1];
            }
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}