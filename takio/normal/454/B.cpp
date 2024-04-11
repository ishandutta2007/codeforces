#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int  main () {
    int n, a, t, mn = 1e9, flag = 0, f;
    cin >> n;
    cin >> a;
    t = f = a;
//    cout << n << endl;
    for (int i = 2; i <= n; i++)
    {
        scanf ("%d", &a);
        if (a >= t){
            t = a;
            continue;
        }
        if (flag == 0) {
            flag = 1;
            mn = min(mn, n - i + 1);
        }
        else {
            cout << -1;
            return 0;
        }
        t = a;
//        cout << t << endl;
    }
//    cout << f << ' ' << t << endl;
    if (flag == 0) cout << 0;
    else if (t > f) cout << -1;
    else cout << mn;
}