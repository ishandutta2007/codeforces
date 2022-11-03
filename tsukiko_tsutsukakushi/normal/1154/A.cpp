#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long long ll;

#define FOR(i, s, e) for (int (i) = (s); (i) < (e); (i)++)

int main() {
    int x[4];
    int k = 0;
    FOR(i, 0, 4) {
        cin >> x[i];
        k = max(k, x[i]);
    }
    int a[4];
    FOR(i, 0, 4) {
        a[i] = k - x[i];
        if( a[i] > 0) cout << a[i] << " ";
    }
}