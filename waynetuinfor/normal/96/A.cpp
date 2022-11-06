#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    for (int i = 0; i < s.size(); ) {
        int j = i;
        while (j < s.size() && s[j] == s[i]) ++j;
        if (j - i >= 7) return 0 * puts("YES");
        i = j;
    }
    cout << "NO" << endl;
}