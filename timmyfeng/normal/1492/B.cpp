#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<bool> used(n + 1);
        vector<int> deck(n);
        for (auto &i : deck) {
            cin >> i;
        }

        for (int i = n; i > 0; --i) {
            if (used[i]) {
                continue;
            }

            int j = deck.size() - 1;
            while (deck[j] != i) {
                --j;
            }

            for (int k = j; k < (int) deck.size(); ++k) {
                cout << deck[k] << " ";
                used[deck[k]] = true;
            }

            deck.erase(deck.begin() + j, deck.end());
        }

        cout << "\n";
    }
}