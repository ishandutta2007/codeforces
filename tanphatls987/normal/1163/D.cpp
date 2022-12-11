#include <bits/stdc++.h>

using namespace std;

const int M = 60;

int n[2];
int kmp[2][M][26];
string pat, s[2];

int f[1005][52][52];
bool vis[1005][52][52];


void prepare() {
    memset(kmp, -1, sizeof(kmp));
    cin >> pat >> s[0] >> s[1];
    

    for(int j = 0; j <= 1; j++) {
        n[j] = s[j].length();
        s[j] = s[j] + "@";

        for(int i = 0; i <= n[j]; i++) {
            for(int use = 0; use < 26; use++) {
                string res = s[j].substr(0, i) + char(use + 'a');
                kmp[j][i][use] = i + 1;
                while (s[j].substr(0, kmp[j][i][use]) != 
                    res.substr(i + 1 - kmp[j][i][use], kmp[j][i][use]))
                    kmp[j][i][use]--;
            }
        }
    }
}
const int inf = 1e6 + 10;
int DP(int pos, int pre0, int pre1) {
    if (pos == pat.length()) return 0;
    int &res = f[pos][pre0][pre1];
    if (vis[pos][pre0][pre1]) return res;
    
    vis[pos][pre0][pre1] = 1;

    int L = 0, R = 25;
    if (pat[pos] != '*') L = R = pat[pos] - 'a';

    res = -inf;
    for(int i = L; i <= R; i++) {
        int npre0 = kmp[0][pre0][i];
        int npre1 = kmp[1][pre1][i];
        res = max(res, DP(pos + 1, npre0, npre1) + (npre0 == n[0]) - (npre1 == n[1]));
    }
    return res;
}
int solve() {
    return DP(0, 0, 0);
}
int main() {
    prepare();
    cout << solve();
}