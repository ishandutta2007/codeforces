#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define xx first
#define yy second
using namespace std;

int vis[6100];

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, a, res = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        while (vis[a]) a++, res++;
        vis[a] = 1;
    }
    cout << res << endl;
}