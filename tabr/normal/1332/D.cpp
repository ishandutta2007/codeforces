#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k;
    cin >> k;
    cout << "3 2\n";
    cout << (1 << 17) + k << " " << k << '\n';
    cout << (1 << 17) << " " << (1 << 17) + k << '\n';
    cout << "0 " << k << '\n';
    return 0;
}