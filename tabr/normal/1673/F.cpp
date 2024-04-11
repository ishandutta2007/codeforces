#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> a(31);
    vector<int> b(31);
    int aa = 0;
    int bb = 0;
    for (int i = 0; i < 31; i++) {
        int k = __builtin_ctz(i + 1);
        a[i] = 1 << (2 * k);
        b[i] = 1 << (2 * k + 1);
        aa |= a[i];
        bb |= b[i];
    }
    debug(a);
    debug(b);
    debug(accumulate(a.begin(), a.end(), 0) + accumulate(b.begin(), b.end(), 0) <= 48000 / 32);
    vector<map<int, int>> x(32);
    for (int i = 0; i < 32; i++) {
        set<int> st;
        for (int j = 0; j < 32; j++) {
            int k = i;
            int d = 0;
            while (k > j) {
                k--;
                d ^= a[k];
            }
            while (k < j) {
                d ^= a[k];
                k++;
            }
            st.emplace(d);
            x[i][d] = j;
        }
        assert(st.size() == 32);
    }
    vector<map<int, int>> y(32);
    for (int i = 0; i < 32; i++) {
        set<int> st;
        for (int j = 0; j < 32; j++) {
            int k = i;
            int d = 0;
            while (k > j) {
                k--;
                d ^= b[k];
            }
            while (k < j) {
                d ^= b[k];
                k++;
            }
            st.emplace(d);
            y[i][d] = j;
        }
        assert(st.size() == 32);
    }
    int n, k;
    cin >> n >> k;
    int px = 0, py = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            cout << a[j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n; j++) {
            cout << b[i] << " ";
        }
        cout << endl;
    }
    while (k--) {
        int d;
        cin >> d;
        int da = d & aa;
        int db = d & bb;
        px = y[px][db];
        py = x[py][da];
        cout << px + 1 << " " << py + 1 << endl;
    }
    return 0;
}