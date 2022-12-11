#include <bits/stdc++.h>
#define int long long
 
using namespace std;

 
vector <int> z;
const int N = 5e3 + 7, M1 = 1e9 + 7, M2 = 1e9 + 9, b1 = 127, b2 = 239;
int maxi1[N], maxi2[N], maxx[N];
pair <int, int> h1[N], h2[N];
pair <int, int> poww[N];
string best;

int mod(int x, int m) {
    x %= m;
    if (x < 0) x += m;
    return x;
}

pair <int, int> get_h(int l, int r) {
    int res1 = mod(h1[r].first - h1[l - 1].first * poww[r - l + 1].first, M1);
    int res2 = mod(h1[r].second - h1[l - 1].second * poww[r - l + 1].second, M2);
    return {res1, res2};
}

pair <int, int> get_h2(int l, int r) {
    int res1 = mod(h2[r].first - h2[l - 1].first * poww[r - l + 1].first, M1);
    int res2 = mod(h2[r].second - h2[l - 1].second * poww[r - l + 1].second, M2);
    return {res1, res2};
}

void solve(string s) {
    int n = s.length();
    string t = s;
    int ser = (n + 1) / 2;
    int len = 0;
    while (len != n && s[len] == s[n - len - 1]) {
        len++;
    }
    if (len == n) {
        best = s;
        return;
    }
    if (2 * len > (int) best.size()) {
        best = "";
        for (int i = 0; i < len; i++) best += s[i];
        for (int i = len - 1; i >= 0; i--) best += s[i];
        //cout << "! " << best << endl;
    }
    //cout << 43 << endl;
    for (int i = 0; i < ser; i++) {
        maxi1[i] = -1;
        int l = i, r = i;
        while (l >= 0 && r < n && s[l] == s[r]) {
            l--;
            r++;
            maxi1[i] += 2;
            if (l < len) {
                int curlen = maxi1[i] + 2 * (l + 1);
                //cout << i << ' ' << maxi1[i] << ' ' << ' ' << curlen << endl;
                if (curlen > (int) best.size()) {
                    best = "";
                    for (int j = 0; j < r; j++) {
                        best += s[j];
                    }
                    for (int j = l; j >= 0; j--) {
                        best += s[j];
                    }
                }
            }
        }
    }
    //cout << 65 << endl;
    if (n % 2 == 1) ser--;
    for (int i = 0; i < ser; i++) {
        maxi2[i] = 0;
        int l = i, r = i + 1;
        while (l >= 0 && r < n && s[l] == s[r]) {
            l--;
            r++;
            maxi2[i] += 2;
            if (l < len) {
                int curlen = maxi2[i] + 2 * (l + 1);
                //cout << "!! " << i << ' ' << maxi2[i] << ' ' << ' ' << curlen << endl;
                if (curlen > (int) best.size()) {
                    //cout << i << endl;
                    best = "";
                    for (int j = 0; j < r; j++) {
                        best += s[j];
                    }
                    for (int j = l; j >= 0; j--) {
                        best += s[j];
                    }
                }
            }
        }
    }
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        string s;
        cin >> s;
        best = s[0];
        solve(s);
        reverse(s.begin(), s.end());
        solve(s);
        cout << best << endl;
    }
    return 0;
}