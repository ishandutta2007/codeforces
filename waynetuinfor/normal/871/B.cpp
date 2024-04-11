#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000 + 100;
int x[maxn][maxn], p[maxn], tx[maxn];
int n;

int ask(int i, int j) {
    cout << "? " << i << ' ' << j << endl;
    int r; cin >> r; return r;
}

void answer(int k) {
    cout << "!" << endl;
    cout << k << endl;
    for (int i = 0; i < n; ++i) cout << p[i] << ' '; cout << endl;
    exit(0);
}

int main() {
    cin >> n; // pre(n);
    for (int i = 0; i < n; ++i) {
        int xo = ask(0, i);
        x[0][i] = xo;
    }
    for (int i = 1; i < n; ++i) {
        int xo = ask(i, i);
        for (int j = 0; j < n; ++j) {
            x[i][j] = xo ^ x[0][i] ^ x[0][j];
        }
    }
    int xn = 0;
    for (int i = 0; i < n; ++i) xn ^= i;
    if (n & 1) {
        for (int i = 0; i < n; ++i) {
            int xnow = 0;
            for (int j = 0; j < n; ++j) xnow ^= x[i][j];
            xnow ^= xn;
            p[i] = xnow;
        }
        answer(1);
        return 0;
    }
    for (int i = 0; i < n; ++i) tx[i] = (x[0][0] ^ x[i][0]); 
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        vector<int> tp(maxn);
        tp[0] = i;
        for (int j = 1; j < n; ++j) tp[j] = (tx[j] ^ tp[0]);
        bitset<maxn> v;
        bool good = true;
        vector<int> tb(maxn);
        for (int j = 0; j < n && good; ++j) {
            if (tp[j] >= n || tp[j] < 0) {
                good = false;
                break;
            }
            tb[tp[j]] = j;
        }
        for (int j = 0; j < n; ++j) {
            if ((tb[j] ^ tp[j]) != x[j][j]) good = false;
        }
        for (int j = 0; j < n && good; ++j) {
            if (tp[j] >= n || tp[j] < 0) {
                good = false;
                break;
            }
            if (v[tp[j]]) good = false;
            v[tp[j]] = true;
        }
        if (good) {
            ++ans;
            for (int j = 0; j < n; ++j) p[j] = tp[j];
        }
    }
    answer(ans);
    return 0;
}