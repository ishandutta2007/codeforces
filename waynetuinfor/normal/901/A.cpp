#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int a[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int h; cin >> h;
    int n = 0;
    for (int i = 0; i <= h; ++i) cin >> a[i], n += a[i];
    bool amb = false;
    int pos = -1;
    for (int i = 1; i <= h; ++i) {
        if (a[i] > 1 && a[i - 1] > 1) amb = true, pos = i;
    }
    if (!amb) return cout << "perfect" << endl, 0;
    cout << "ambiguous" << endl;
    int prv = 0, now = 1;
    for (int i = 0; i <= h; ++i) {
        for (int j = 0; j < a[i]; ++j) {
            cout << prv << ' ';
            ++now;
        }
        prv = now - 1;
    }
    cout << endl;
    prv = 0; now = 1;
    for (int i = 0; i < pos; ++i) {
        for (int j = 0; j < a[i]; ++j) {
            cout << prv << ' ';
            ++now;
        }
        prv = now - 1;
    }
    cout << prv - 1 << ' ';
    ++now;
    for (int i = 0; i < a[pos] - 1; ++i) cout << prv << ' ', ++now;
    prv = now - 1;
    for (int i = pos + 1; i <= h; ++i) {
        for (int j = 0; j < a[i]; ++j) {
            cout << prv << ' ';
            ++now;
        }
        prv = now - 1;
    }
    cout << endl;
}