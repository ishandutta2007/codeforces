#include <iostream>
#include <algorithm>
#include <vector>
#define int long long

using namespace std;

int n, l, x, y;
vector <int> lineal;
vector <int> arrx;
vector <int> arry;
bool fx, fy, all;

bool find_in_(vector <int> &a, int b) {
    int L = -1, R = a.size();
    while (R - L > 1) {
        int M = (L + R) / 2;
        if (a[M] < b) {
            L = M;
        }
        else {
            R = M;
        }
    }
    if (R == a.size() || a[R] != b) {
        return false;
    }
    return true;
}

main() {
    cin >> n >> l >> x >> y;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        lineal.push_back(k);
        if (k - x >= 0) {
            arrx.push_back(k - x);
        }
        if (k + x <= l) {
            arrx.push_back(k + x);
        }
        if (k - y >= 0) {
            arry.push_back(k - y);
        }
        if (k + y <= l) {
            arry.push_back(k + y);
        }
    }
    sort(lineal.begin(), lineal.end());
    sort(arrx.begin(), arrx.end());
    sort(arry.begin(), arry.end());
    for (int i = 0; i < arrx.size(); ++i) {
        if (find_in_(lineal, arrx[i])) {
            fx = true;
            break;
        }
    }
    for (int i = 0; i < arry.size(); ++i) {
        if (find_in_(lineal, arry[i])) {
            fy = true;
            break;
        }
    }
    if (!fx && !fy) {
        for (int i = 0; i < arrx.size(); ++i) {
            if (find_in_(arry, arrx[i])) {
                all = true;
                cout << 1 << endl << arrx[i];
                break;
            }
        }
        if (!all) {
            cout << 2 << endl << arrx[0] << ' ' << arry[0];
        }
    }
    else if (!fx) {
        cout << 1 << endl << arrx[0];
    }
    else if (!fy) {
        cout << 1 << endl << arry[0];
    }
    else {
        cout << 0;
    }
}