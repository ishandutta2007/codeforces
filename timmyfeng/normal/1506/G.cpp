#include <bits/stdc++.h>
using namespace std;

const int ALPHA_SIZE = 26;

int first[ALPHA_SIZE], last[ALPHA_SIZE];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        string ans;
        while (!s.empty()) {
            fill(first, first + ALPHA_SIZE, s.size());
            fill(last, last + ALPHA_SIZE, s.size());

            for (int i = 0; i < (int) s.size(); ++i) {
                int c = s[i] - 'a';
                first[c] = min(first[c], i);
                last[c] = i;
            }

            for (int i = ALPHA_SIZE - 1; i >= 0; --i) {
                if (first[i] <= *min_element(last, last + ALPHA_SIZE)) {
                    ans.push_back('a' + i);
                    break;
                }
            }

            string new_s;
            bool ok = false;
            for (auto c : s) {
                if (c == ans.back()) {
                    ok = true;
                } else if (ok) {
                    new_s.push_back(c);
                }
            }
            s.swap(new_s);
        }

        cout << ans << "\n";
    }
}