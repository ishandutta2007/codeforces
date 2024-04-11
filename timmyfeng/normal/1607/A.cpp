#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while (n--) {
        string keyboard, word;
        cin >> keyboard >> word;

        vector<int> index(26);
        for (int i = 0; i < 26; ++i) {
            index[keyboard[i] - 'a'] = i;
        }

        int ans = 0;
        for (int i = 1; i < (int) word.size(); ++i) {
            ans += abs(index[word[i] - 'a'] - index[word[i - 1] - 'a']);
        }

        cout << ans << "\n";
    }
}