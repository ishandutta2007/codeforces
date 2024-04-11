#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 100010;
struct data {
    char s[55], t[55];
//    int tn;
}d2[N], d[N];

//bool cmp (data a, data b) {
//    return a.tn < b.tn;
//}

char p[55];

int main () {
    int n;
//    freopen ("in.txt", "r", stdin);
    while (cin >> n) {
        for (int i = 1; i <= n; i++) {
            scanf ("%s%s", d2[i].s, d2[i].t);
            if (strcmp(d2[i].s, d2[i].t) > 0) {
                strcpy (p, d2[i].s);
                strcpy (d2[i].s, d2[i].t);
                strcpy (d2[i].t, p);
            }
        }
        int tn;
        for (int i = 1; i <= n; i++) {
            scanf ("%d", &tn);
            d[i] = d2[tn];
        }
//        sort (d + 1, d + 1 + n, cmp);
//        for (int i = 1; i <= n; i++) {
//            cout << d2[i].s << ' ' << d2[i].t << endl;
//        }
        strcpy (p, d[1].s);
        for (int i = 2; i <= n; i++) {
            if (strcmp (d[i].s, p) > 0) strcpy (p, d[i].s);
            else if (strcmp (d[i].t, p) > 0) strcpy (p, d[i].t);
            else {
                cout << "NO";
                return 0;
            }
        }
        cout << "YES";
    }
}