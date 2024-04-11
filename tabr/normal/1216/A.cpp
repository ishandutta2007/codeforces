#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    string s;
    cin >> n >> s;
    int m = 0;
    rep(i, 0, n / 2) {
        string t = "";
        t += s[2 * i];
        t += s[2 * i + 1];
        if (t == "ab" || t == "ba")
            continue;
        else if (t == "aa") {
            s[2 * i] = 'b';
            m++;
        } else if (t == "bb") {
            s[2 * i] = 'a';
            m++;
        }
    }
    cout << m << endl;
    cout << s << endl;
    return 0;
}