#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    set<long long> s;
    for (int i = 3; i < 28; i++) {
        cout << "? 2 " << i << endl;
        long long x;
        cin >> x;
        cout << "? " << i << " 2" << endl;
        long long y;
        cin >> y;
        if (x == -1) {
            cout << "! " << i - 1 << endl;
            return 0;
        }
        if (x != y) {
            cout << "! " << x + y << endl;
            return 0;
        }
        s.emplace(x + y);
    }
    cout << "! " << (*s.rbegin()) << endl;
    return 0;
}