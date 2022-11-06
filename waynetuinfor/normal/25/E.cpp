#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, mod = 479001599, p = 173;
int hs[3][maxn], pp[maxn];
string s[3];

inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
inline int mul(int a, int b) { return a * 1ll * b % mod; }

void init() {
    pp[0] = 1;
    for (int i = 1; i < maxn; ++i) pp[i] = mul(pp[i - 1], p);
    for (int i = 0; i < 3; ++i) {
        hs[i][0] = s[i][0];
        for (size_t j = 1; j < s[i].size(); ++j) hs[i][j] = add(s[i][j], mul(hs[i][j - 1], p));
    }
}

int get(int i, int l, int r) {
    if (l == 0) return hs[i][r];
    return sub(hs[i][r], mul(pp[r - l + 1], hs[i][l - 1]));
}

bool overlap(int a, int b) {
    if (s[a].size() > s[b].size()) swap(a, b);
    for (size_t i = 0; i < s[b].size(); ++i) {
        if (i + s[a].size() > s[b].size()) continue;
        if (get(a, 0, s[a].size() - 1) == get(b, i, i + s[a].size() - 1)) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    for (int i = 0; i < 3; ++i) cin >> s[i];
    init();
    vector<int> ord;
    bitset<3> ins; ins.set();
    for (int i = 0; i < 3; ++i) {
        for (int j = i + 1; j < 3; ++j) {
            if (overlap(i, j)) ins[(s[i].size() <= s[j].size() ? i : j)] = false;
        }
    }
    for (int i = 0; i < 3; ++i) if (ins[i]) ord.push_back(i);
    int ans = 3 * maxn;
    do {
        int now = (int)s[ord[0]].size(); 
        for (int i = 1; i < ord.size(); ++i) {
            int mat = 0;
            for (int l = 1; l <= min(s[ord[i - 1]].size(), s[ord[i]].size()); ++l) {
                if (get(ord[i - 1], s[ord[i - 1]].size() - l, s[ord[i - 1]].size() - 1) == get(ord[i], 0, l - 1)) mat = l;
            } 
            now += s[ord[i]].size() - mat;
        }
        ans = min(ans, now);
    } while (next_permutation(ord.begin(), ord.end()));
    cout << ans << endl;
    return 0;
}