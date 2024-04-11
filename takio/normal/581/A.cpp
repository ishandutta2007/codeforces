#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define xx first
#define yy second

using namespace std;

const int N = 100100;

int a[N];

int main () {
//    freopen ("in.txt", "r", stdin);
    int a, b;
    cin >> a >> b;
    int t = min (a, b);
    a -= t, b -= t;
    cout <<t << ' ' << max (a, b) / 2 << endl;
}