#include <bits/stdc++.h>
//#define int long long

using namespace std;

const int T = 18, N = 1 << 17;
int go[T][T];

int t[2 * N][T];

int code(int a, int b, int c) {
    return a * 6 + b * 2 + c;
}

void decode(int n, int &a, int &b, int &c) {
    c = n % 2;
    n /= 2;
    b = n % 3;
    n /= 3;
    a = n;
}

int get1(int a1, int b1, int c1, int a2, int b2, int c2) {
    if (a1 == 2 || a2 == 2 || (a1 >= 1 && b2 >= 1))
        return 2;
    if (a1 == 1 || a2 == 1)
        return 1;
    return 0;
}

int get2(int a1, int b1, int c1, int a2, int b2, int c2) {
    if (b1 == 2 || b2 == 2 || (b1 >= 1 && c2 >= 1))
        return 2;
    if (b1 == 1 || b2 == 1)
        return 1;
    return 0;
}

int get3(int a1, int b1, int c1, int a2, int b2, int c2) {
    if (c1 == 1 || c2 == 1)
        return 1;
    return 0;
}

void init_go() {
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < T; j++) {
            int a1, b1, c1, a2, b2, c2;
            decode(i, a1, b1, c1);
            decode(j, a2, b2, c2);
            int na = get1(a1, b1, c1, a2, b2, c2);
            int nb = get2(a1, b1, c1, a2, b2, c2);
            int nc = get3(a1, b1, c1, a2, b2, c2);
            if (a1 >= 2 && c2 >= 1) {
                go[i][j] = -1;
                continue;
            }
            if (a1 >= 1 && b2 >= 2) {
                go[i][j] = -1;
                continue;
            }
            /*if (code(na, nb, nc) == 17) {
                cout << a1 << ' ' << b1 << ' ' << c1 << ' ' << a2 << ' ' << b2 << ' ' << c2 << endl;
            }*/
            go[i][j] = code(na, nb, nc);
        }
    }
}

void relax(int pos) {
    for (int j = 0; j < T; j++)
        t[pos][j] = N;
    vector <pair <int, int>> gi, gj;
    for (int i = 0; i < T; i++) {
        if (t[2 * pos][i] < N)
            gi.push_back({i, t[2 * pos][i]});

        if (t[2 * pos + 1][i] < N)
            gj.push_back({i, t[2 * pos + 1][i]});
    }
    for (auto [i, c1] : gi) {
        for (auto [j, c2] : gj) {
            if (go[i][j] != -1) {
                t[pos][go[i][j]] = min(t[pos][go[i][j]], c1 + c2);
            }
        }
    }
}

void sset(int pos, char z) {
    for (int i = 0; i < T; i++)
        t[pos][i] = N;
    if (z == '?') {
        t[pos][0] = 0;
        return;
    }
    t[pos][code(1, 0, 0)] = 1;
    t[pos][code(0, 1, 0)] = 1;
    t[pos][code(0, 0, 1)] = 1;
    if (z == 'a') {
        t[pos][code(1, 0, 0)] = 0;
    }
    if (z == 'b') {
        t[pos][code(0, 1, 0)] = 0;
    }
    if (z == 'c') {
        t[pos][code(0, 0, 1)] = 0;
    }
}

void upd(int pos, char z) {
    pos += N - 1;
    sset(pos, z);
    while (pos > 1) {
        pos /= 2;
        relax(pos);
    }
}

signed main() {
    init_go();
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    for (int i = 1; i <= n; i++) {
        sset(N + i - 1, s[i - 1]);
    }
    for (int i = n + 1; i <= N; i++)
        sset(N + i - 1, '?');

    for (int i = N - 1; i >= 1; i--)
        relax(i);

    for (int i = 0; i < q; i++) {
        int pos;
        char n;
        cin >> pos >> n;
        upd(pos, n);
        int res = N;
        for (int j = 0; j < T; j++)
            res = min(res, t[1][j]);
        cout << res << "\n";
    }
}