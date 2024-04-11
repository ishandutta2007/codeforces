#include <cstdio>
#include <queue>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <bitset>
#include <ctime>
#define LL long long
#define pii pair <int, int>
#define ULL unsigned long long
using namespace std;

const int N = 110;
LL a[N];

vector <int> l, r;

int main () {
//    freopen ("in.txt", "r", stdin);
    LL n, m;
    cin >> n >> m;
    a[1] = 1;
    for (int i = 2; i <= 50; i++) a[i] = a[i - 1] * 2;
    for (int i = 1; i <= n; i++) {
        if (m > a[n - i]) {
            m -= a[n - i];
            r.push_back (i);
        } else l.push_back (i);
    }
    for (int i = 0; i < (int)l.size (); i++) cout << l[i] << ' ';
    for (int i = (int)r.size () - 1; i >= 0; i--) cout << r[i] << ' ';
}