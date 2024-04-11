#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll

const int mod = 998244353;
int mul(int a, int b) {
    return (a * 1ll * b) % mod;
}

const int N = (1 << 18) + 10;
int hs[4 * N], p_pow[N];

void calc_hashes(int v, int in_subtree, const string &s, int pos = 0) {
    if (in_subtree == 1) {
        hs[v] = 1 + (s[v - 1] == 'B');
        return;
    }
    calc_hashes(2 * v, (in_subtree - 1) / 2, s, pos + 1);
    calc_hashes(2 * v + 1, (in_subtree - 1) / 2, s, pos + 1 + (in_subtree - 1) / 2);
    int A = hs[2 * v], B = hs[2 * v + 1];
    if (A > B) {
        swap(A, B);
    }
    hs[v] = (1 + s[v - 1] == 'B') + p_pow[1] * A + p_pow[1 + (in_subtree - 1) / 2] * B;
}

int get_answer(int v, int in_subtree) {
    if (in_subtree == 1) {
        return 1;
    }
    int A = get_answer(2 * v, (in_subtree - 1) / 2),
            B = get_answer(2 * v + 1, (in_subtree - 1) / 2);
    if (hs[2 * v] == hs[2 * v + 1]) {
        return mul(A, B);
    } else {
        return mul(2, mul(A, B));
    }
}

const int P = 239017;

signed main() {
#ifdef PC
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    p_pow[0] = 1;
    for (int i = 1; i < N; i++) {
        p_pow[i] = p_pow[i - 1] * P;
    }
    int n;
    cin >> n;
    string s;
    cin >> s;
    calc_hashes(1, SZ(s), s);
    cout << get_answer(1, SZ(s)) << '\n';
}