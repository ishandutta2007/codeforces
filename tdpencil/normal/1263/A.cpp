#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

int main() {
    int t;
    cin >> t;
    forn(tt, t) {   
        int a[3];
        cin >> a[0] >> a[1] >> a[2];
        sort(a, a + 3);
        if (a[2] <= a[0] + a[1])
            cout << (a[0] + a[1] + a[2]) / 2 << endl;
        else
            cout << a[0] + a[1] << endl;
    }
}