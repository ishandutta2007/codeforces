#include <cstdio>
#include <queue>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#define LL long long
#define pii pair <int, int>
using namespace std;

const int N = 310, INF = 0x3f3f3f3f;
int a[N], c[N];

int gcd (int n, int m) {
    while (n && m) {
        if (n > m) n %= m; else m %= n;
    }
    return n + m;
}

map <int, int> mp[N];
map <int, int>::iterator it;

int main () {
//    freopen ("in.txt", "r", stdin);
    int n;
//    int cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &a[i]);
        int t = 1;
        for (int j = 2; j * j <= a[i]; j++) {
            if (a[i] % j == 0) {
                t *= j;
                while (a[i] % j == 0) a[i] /= j;
            }
        }
        if (a[i] != 1) t *= a[i];
        a[i] = t;
    }
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &c[i]);
    }
    mp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (it = mp[i - 1].begin(); it != mp[i - 1].end(); it++) {

            int d = (*it).first, p = (*it).second;
//            cout << d << ':' << p << ' ';
            if (mp[i].find(d) == mp[i].end()) mp[i][d] = p;
            else mp[i][d] = min (mp[i][d], p);
            int g = gcd (a[i], d);
            if (mp[i].find(g) == mp[i].end()) mp[i][g] = p + c[i];
            else mp[i][g] = min (mp[i][g], p + c[i]);
        }
//        cout << endl;
    }
    it = mp[n].begin();
    it++;
    if ((*it).first != 1) cout << -1;
    else cout << (*it).second;
}