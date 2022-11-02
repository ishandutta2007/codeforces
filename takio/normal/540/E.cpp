#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define xx first
#define yy second
using namespace std;

const int N = 400100;

map <int, int> mp, mp2;
map <int, int> :: iterator it, it2;

pii a[N];
int b[N];
LL t[N];

int f (int x) { return x & -x; }

void add (int x, int y) {
    for (int i = x; i < N; i += f (i)) {
        t[i] += y;
    }
}

LL sum (int x) {
    LL res = 0;
    for (int i = x; i >= 1; i -= f (i)) {
        res += t[i];
    }
    return res;
}

//int jug () {
//    if (it == mp.begin()) return 1;
//    it2 = it;
//    it2--;
//    return (*it2).xx + 1 != (*it).xx;
//}

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, u, v;
    cin >> n;
    for (int i = 1; i <= n; i++) {
//        cout << i << endl;
        scanf ("%d%d", &u, &v);
        if (!mp[u]) mp[u] = u;
        if (!mp[v]) mp[v] = v;
        int tmp = mp[u];
        mp[u] = mp[v];
        mp[v] = tmp;
    }
    int pre = 1, an = 0;
    for (it = mp.begin (); it != mp.end(); it++) {
        int x = (*it).xx, y = (*it).yy;
//        cout << "x y " <<x << ' ' << y << endl;
        if (x != 1 && x - pre - 1) {
            a[++an] = pii (x - 1, x - pre - 1);
//            cout << x - 1 << ' ' << x - pre - 1 << endl;
            b[an] = x - 1;
        }
        a[++an] = pii (y, 1);
//        cout << y << ' ' << 1 << endl;
        b[an] = y;
        pre = x;
    }
    sort (b + 1, b + 1 + an);
    int bn = unique (b + 1, b + 1 + an) - b - 1;
//    for (int i = 1; i<= bn; i++) {
//        cout << b[i] << ' ';
//    } cout << endl;
    for (int i = 1; i <= bn; i++) {
        mp2[b[i]] = i;
//        cout << a[i].xx << ' ' << a[i].yy << endl;
    }
    for (int i = 1; i <= an; i++) {
        a[i].xx = mp2[a[i].xx];
    }
    LL res = 0, all = 0;
    for (int i = 1; i <= an; i++) {
//        cout << a[i].xx << ' ' << all << endl;
        res += 1LL * (all - sum (a[i].xx)) * a[i].yy;
        add (a[i].xx, a[i].yy);
        all += a[i].yy;
    }
    cout << res << endl;
}