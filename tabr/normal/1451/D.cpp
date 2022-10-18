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
    int tt;
    cin >> tt;
    while (tt--) {
        long long d, k;
        cin >> d >> k;
        long long t = d * d / (k * k);
        long long i = (long long)sqrt(t / 2) + 10;
        while (i * i * 2 > t) {
            i--;
        }
        if ((i + 1) * (i + 1) + i * i <= t) {
            cout << "Ashish" << '\n';
        } else {
            cout << "Utkarsh" << '\n';
        }
    }
    return 0;
}