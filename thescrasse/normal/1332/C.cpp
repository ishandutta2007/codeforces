#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, k1, t, n, m, res, check1, a, b, toc, rt, cnt, v;
string s;
map<char, long long> f;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    for (i1 = 0; i1 < t; i1++) {
        cin >> n >> k;
        cin >> s;
        toc = k / 2;
        toc--;
        rt = n / k;
        res = 0;
        for (i = 0; i <= toc; i++) {
            cnt = 0;
            f.clear();
            for (j = 0; j < rt; j++) {
                v = i + k * j;
                f[s[v]]++;
                cnt = max(cnt, f[s[v]]);
                v = (k - i - 1) + k * j;
                f[s[v]]++;
                cnt = max(cnt, f[s[v]]);
            }
            // cout << cnt << endl;
            res += ((2 * rt) - cnt);
        }

        if (k % 2 == 1) {
            f.clear();
            cnt = 0;
            i = k / 2;
            for (j = 0; j < rt; j++) {
                v = i + k * j;
                f[s[v]]++;
                cnt = max(cnt, f[s[v]]);
            }
            // cout << cnt << endl;
            res += (rt - cnt);
        }
        cout << res << endl;
    }

    return 0;
}