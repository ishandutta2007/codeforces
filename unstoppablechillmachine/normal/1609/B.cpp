#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    set<int> interesting;
    for (int i = 1; i + 1 < SZ(s); i++) {
        if (s[i - 1] == 'a' && s[i] == 'b' && s[i + 1] == 'c') {
            interesting.insert(i);
        }
    }
    for (int i = 0; i < q; i++) {
        int pos;
        char c;
        cin >> pos >> c;
        pos--;
        s[pos] = c;
        if (interesting.count(pos - 1)) {
            interesting.erase(pos - 1);
        }
        if (interesting.count(pos)) {
            interesting.erase(pos);
        }
        if (interesting.count(pos + 1)) {
            interesting.erase(pos + 1);
        }
        if (c == 'a' && pos + 2 < SZ(s) && s[pos + 1] == 'b' && s[pos + 2] == 'c') {
            interesting.insert(pos + 1);
        }
        if (c == 'b' && pos > 0 && pos + 1 < SZ(s) && s[pos - 1] == 'a' && s[pos + 1] == 'c') {
            interesting.insert(pos);
        }
        if (c == 'c' && pos - 2 >= 0 && s[pos - 2] == 'a' && s[pos - 1] == 'b') {
            interesting.insert(pos - 1);
        }
        cout << SZ(interesting) << '\n';
    }
}