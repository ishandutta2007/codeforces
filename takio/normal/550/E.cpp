#include<cstdio>
#include<queue>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
#define LL long long
#define pii pair <int, int>
#define xx first
#define yy second
using namespace std;

const int N = 100100;

int a[N];

void o () { cout << "NO\n"; }
void y () { cout << "YES\n"; }

int main () {
//    freopen ("in.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &a[i]);
    }
    if (a[n] == 1) { o (); return 0; }
    if (n == 1) {
        if (a[1] == 1) o ();
        else {
            y ();
            cout << 0 << endl;
        }
        return 0;
    }
    if (n == 2) {
        if (a[1] == 1 && a[2] == 0) {
            y ();
            cout << "1->0" << endl;
        } else o ();
        return 0;
    }
    int cnt = 0, l1, l2, r1, r2;
    l1 = l2 = 1e9, r1 = r2 = 0;
    for (int i = n; i >= 1; i--) {
        if (a[i] == 0) cnt++;
        if (cnt == 2) {
            l2 = min (l2, i);
            r1 = r2 = max (r2, i);
        }
        if (cnt == 3) {
            l1 = i;
            break;
        }
    }
//    cout << l1 <<' ' << r1 <<' ' << l2 <<' ' << r2 <<endl;
    if (cnt == 0) o ();
    else if (cnt >= 1 && a[n - 1] == 1) {
        y ();
        for (int i = 1; i < n; i++) {
            printf ("%d->", a[i]);
        }
        cout << 0;
    } else if (cnt == 2) {
        o ();
    } else {
        y ();
        for (int i = 1; i < n; i++) {
            if (i == l1) cout << "(";
            if (i == l2) cout << "(";
            printf ("%d", a[i]);
            if (i == r1) cout << ")";
            if (i == r2) cout << ")";
            printf ("->");
        }
        cout << 0;
    }
}