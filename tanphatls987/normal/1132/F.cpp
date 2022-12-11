#include <bits/stdc++.h>

using namespace std;

const int N = 5e2 + 10;
const int inf = 1e9 + 10;
const int alp = 26;

int f[N][N];
string s;

int DP(int L, int R) {
    if (L >= R) return 0;
    int &res = f[L][R];
    if (res != -1) return res;

    if (s[L] == s[R]) {
        res = DP(L + 1, R - 1) + 1;
        for(int i = L + 1; i < R; i++) if (s[i] == s[L]) {
            res = min(res, DP(L + 1, i - 1) + 1 + DP(i, R));
            res = min(res, DP(L, i) + 1 + DP(i + 1, R - 1));
        }
        return res;
    }
    res = inf;
    for(int i = L; i <= R; i++) {
        if (s[i] == s[L]) {
            res = min(res, DP(L, i) + 1 + DP(i + 1, R));
        }
        if (s[i] == s[R]) {
            res = min(res, DP(L, i - 1) + 1 + DP(i, R));
        }
    }
    return res;

}
void prepare() {
    int n;
    cin >> n >> s;
    string tmp;
    tmp.push_back(s[0]);
    for(auto ch : s) if (ch != tmp.back()) tmp.push_back(ch);
    s = tmp;
}
int main() {
    prepare();
    memset(f, -1, sizeof(f));
    cout << DP(0, s.length() - 1) + 1;
}