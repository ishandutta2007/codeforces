// 1178E
// sottosequenza palindroma lunga almeno floor(n / 2)

#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, k1, t, n, m, check1, a, b, l, r, f[100];
string s;
vector<char> res;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> s;
    n = s.size();
    l = 0;
    r = n - 2;

    while (l + 1 < r) {
        for (i = 97; i <= 99; i++) {
            f[i] = 0;
        }
        f[(int)s[l]]++;
        f[(int)s[l + 1]]++;
        f[(int)s[r]]++;
        f[(int)s[r + 1]]++;

        for (i = 97; i <= 99; i++) {
            if (f[i] >= 2) {
                res.push_back((char)i);
                break;
            }
        }

        l += 2;
        r -= 2;
    }

    for (auto u : res) {
        cout << u;
    }
    if (l - r != 2) {
        cout << s[l];
    }
    reverse(res.begin(), res.end());
    for (auto u : res) {
        cout << u;
    }

    return 0;
}