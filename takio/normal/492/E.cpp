#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

const int N = 1000100;
int pos[N], cnt[N], mx = 0, res;

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, m, dx, dy;
    cin >> n >> m >> dx >> dy;
    int nx = 0, ny = 0;
    for (int i = 1; i <= n; i++) {
        pos[nx] = ny;
//        cout << nx << ' ' << ny << endl;
        (nx += dx) %= n;
        (ny += dy) %= n;
    }
    int x, y;
    while (m--) {
        scanf ("%d%d", &x, &y);
        int t = (y - pos[x] + n) % n;
//        cout <<x << ' ' <<y << ' ' << t << endl;
        if (++cnt[t] > mx) res = t, mx = cnt[t];
    }
    cout << 0 << ' ' << res;
}