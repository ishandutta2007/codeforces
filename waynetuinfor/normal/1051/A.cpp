#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;
int lw[maxn], dg[maxn], up[maxn];

int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s; 
        int n = s.size();
        s = '.' + s;
        for (int i = 1; i <= n; ++i) {
            lw[i] = lw[i - 1], dg[i] = dg[i - 1], up[i] = up[i - 1];
            if (s[i] >= 'A' && s[i] <= 'Z') up[i]++;
            if (s[i] >= 'a' && s[i] <= 'z') lw[i]++;
            if (s[i] >= '0' && s[i] <= '9') dg[i]++;
        }
        if (up[n] > 0 && lw[n] > 0 && dg[n] > 0) {
            cout << s.substr(1, n) << endl;
            continue;
        }
        int ans = n + 1;
        string res = "";
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; ++j) {
                int a = lw[j] - lw[i - 1], b = dg[j] - dg[i - 1], c = up[j] - up[i - 1];
                int d = lw[n] - a, e = dg[n] - b, f = up[n] - c;
                int need = 0;
                if (d == 0) ++need;
                if (e == 0) ++need;
                if (f == 0) ++need;
                string k = s;
                int p = i;
                if (need <= j - i + 1) {
                    if (d == 0) k[p++] = 'a';
                    if (e == 0) k[p++] = '0';
                    if (f == 0) k[p++] = 'A';
                    if (j - i + 1 < ans) {
                        ans = j - i + 1;
                        res = k;
                    }
                } 
            }
        }
        cout << res.substr(1, n) << endl;
    }
}