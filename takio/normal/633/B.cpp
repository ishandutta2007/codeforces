#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define xx first
#define yy second
using namespace std;

const int N = 100100, mod = 1e9 + 7;

int cal (int x) {
    int r = 0;
    while (x) {
        x /= 5;
        r += x;
    }
    return r;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    int n;
    cin >> n;
    vector <int> r;
//    if ()
    for (int i = 1; ; i++) {
        int t = cal (i);
        if (t > n) break;
        if (t == n) r.push_back (i);
    }
    cout << r.size() << endl;
    for (int i = 0; i < r.size(); i++) printf ("%d ", r[i]);
}