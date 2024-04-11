#include <bits/stdc++.h>
using namespace std;

int palindrome_index(vector<int> a) {
    int n = a.size();
    for (int i = 0; i < n; ++i) {
        if (a[i] != a[n - 1 - i]) {
            return i;
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (auto &i : a) {
            cin >> i;
        }

        int i = palindrome_index(a);
        int j = n - 1 - i;

        if (i == -1) {
            cout << "YES\n";
            continue;
        }

        vector<int> a1 = a;
        a1.erase(remove(a1.begin(), a1.end(), a[i]), a1.end());

        vector<int> a2 = a;
        a2.erase(remove(a2.begin(), a2.end(), a[j]), a2.end());

        if (palindrome_index(a1) == -1 || palindrome_index(a2) == -1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}