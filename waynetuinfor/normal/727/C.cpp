#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000 + 5;
int a[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    cout << "? 1 2" << endl;
    int a12; cin >> a12;
    cout << "? 1 3" << endl;
    int a13; cin >> a13;
    int x = a13 - a12;
    cout << "? 2 3" << endl;
    int y; cin >> y;
    a[3] = (x + y) / 2; a[2] = (y - x) / 2; a[1] = a12 - a[2];
    for (int i = 4; i <= n; ++i) {
        cout << "? 3 " << i << endl;
        int tmp; cin >> tmp;
        a[i] = tmp - a[3];
    }
    cout << "!";
    for (int i = 1; i <= n; ++i) cout << " " << a[i]; cout << endl;
    return 0;
}