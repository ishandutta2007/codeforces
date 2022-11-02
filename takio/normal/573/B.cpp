#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define xx first
#define yy second
using namespace std;

const int N = 100100;
int a[N], b[N];

int main () {
//    freopen ("in.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) scanf ("%d", &a[i]);
    priority_queue <pii, vector <pii>, greater <pii> > q;
    q.push (pii (0, 0));
    for (int i = 1; i <= n; i++) {
        q.push (pii (a[i] - i, i));
        pii t = q.top();
        b[i] = t.xx + i;
//        cout << i << ' ' << b[i] << ' ' <<  t.xx << ' ' << endl;
//        q.push (pii (a[i] + i, i));
    }
    while (!q.empty()) q.pop();
    q.push (pii (0, n + 1));
    int res = 0;
    for (int i = n; i >= 1; i--) {
        q.push (pii (a[i] - (n - i + 1), i));
        pii t = q.top();
        b[i] = min (t.xx + (n - i + 1), b[i]);
//        cout << i << ' ' << t.xx + (n - i + 1) << ' ' << t.xx << endl;
        res = max (res, b[i]);
//        q.push (pii (a[i] - i + n + 1, i));
    }
    cout << res << endl;
}