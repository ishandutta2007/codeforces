#include <bits/stdc++.h>
using namespace std;

int md[7], c[10];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    vector<int> vec = { 1, 6, 8, 9 };
    memset(md, -1, sizeof(md));
    do {
        int k = 0;
        for (int i = 0, j = 1000; i < 4; ++i, j /= 10) k += vec[i] * j;
        if (md[k % 7] == -1) md[k % 7] = k;
    } while (next_permutation(vec.begin(), vec.end()));
    string s; cin >> s;
    for (int i = 0; i < s.length(); ++i) ++c[s[i] - '0'];
    --c[1]; --c[6]; --c[8]; --c[9];
    int cp = 0;
    for (int i = 1; i < 10; ++i) cp += c[i];
    if (cp == 0) {
        int c0 = c[0], p = 1;
        for (int i = 0; i < c0; ++i) p *= 10, p %= 7;
        vector<int> vec = { 1, 6, 8, 9 };
        do {
            int k = 0;
            for (int i = 0, j = 1000; i < 4; ++i, j /= 10) k += vec[i] * j;
            if ((k * p) % 7 == 0) {
                cout << k;
                for (int i = 0; i < c0; ++i) cout << 0;
                cout << endl;
                return 0;
            }
        } while (next_permutation(vec.begin(), vec.end()));
        cout << 0 << endl;
        return 0;
    }
    int k = 10000, now = 0;
    vector<int> ans;
    for (int i = 0; i < 10; ++i) {
        while (c[i]--) {
            now += i * k;
            now %= 7;
            k *= 10;
            k %= 7;
            ans.push_back(i);
        }
    }
    reverse(ans.begin(), ans.end());
    for (int i : ans) cout << i;
    cout << md[(-now + 7) % 7] << endl;
    return 0;
}