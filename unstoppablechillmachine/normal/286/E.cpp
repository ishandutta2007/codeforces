#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()

const ld PI = acosl(-1);
typedef complex<ld> num;
const int L = 21;

vector<num> root[L + 5];

void init_fft() {
    int n = 1 << L;
    ld e = 2 * PI / n;
    root[L].resize(n);
    for (int i = 0; i < n; i++) {
        root[L][i] = polar(ld(1), e * i);
    }

    for (int k = L - 1; k >= 0; k--) {
        root[k].resize(1 << k);
        for (int i = 0; i < (1 << k); i++) {
            root[k][i] = root[k + 1][i * 2];
        }
    }
}

void fft_rec(num *a, int lg, bool inv) {
    if (lg == 0)
        return;

    int len = 1 << (lg - 1);
    fft_rec(a, lg - 1, inv);
    fft_rec(a + len, lg - 1, inv);

    for (int i = 0; i < len; i++) {
        num w = root[lg][i];
        if (inv) {
            w = conj(w);
        }
        num u = a[i];
        num v = a[i + len] * w;
        a[i] = u + v;
        a[i + len] = u - v;
    }
}

void fft(num *a, int lg, bool inv) {
    int n = 1 << lg;
    int j = 0, bit;
    for (int i = 1; i < n; i++) {
        for (bit = n >> 1; bit & j; bit >>= 1) {
            j ^= bit;
        }
        j ^= bit;
        if (i < j) {
            swap(a[i], a[j]);
        }
    }
    fft_rec(a, lg, inv);
    if (inv) {
        for (int i = 0; i < n; i++) {
            a[i] /= n;
        }
    }
}

num P[1 << L];

signed main() {
#ifdef PC
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    init_fft();
    int n, m;
    cin >> n >> m;
    int lg = 1;
    while ((1 << lg) < 2 * m) {
        lg++;
    }
    vector<int> items(n);
    vector<bool> have(m + 1);
    for (int i = 0; i < n; i++) {
        cin >> items[i];
        have[items[i]] = true;
        P[items[i]] = 1;
    }
    fft(P, lg, false);
    for (int i = 0; i < (1 << lg); i++) {
        P[i] *= P[i];
    }
    fft(P, lg, true);
    vector<int> take;
    bool ok = true;
    for (int i = 1; i <= m; i++) {
        if (floor(P[i].real() + 0.5) > 0) {
            if (!have[i]) {
                ok = false;
                break;
            }
        } else if (have[i]) {
            take.push_back(i);
        }
    }
    if (ok) {
        cout << "YES\n" << SZ(take) << '\n';
        for (auto x : take) {
            cout << x << ' ';
        }
        cout << '\n';
    } else {
        cout << "NO\n";
    }
}