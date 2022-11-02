#include <bits/stdc++.h>
#define LL long long
#define pii pair <LL, LL>
#define xx first
#define yy second
using namespace std;

const int N = 1010, mod = 1013;
int a[N];

struct hashmap {
    int key[N];
    int val[N], head[mod], nx[N], tot;
    void init () {
        memset (head, -1, sizeof head);
        tot = 0;
    }
    void ins (int x, int y) {
        int h = (x % mod + mod) % mod;
        for (int i = head[h]; ~i; i = nx[i]) {
            if (key[i] == x) {
                val[i] += y;
                return;
            }
        }
        key[tot] = x;
        val[tot] = y;
        nx[tot] = head[h];
        head[h] = tot++;
    }
    int qry (int x) {
        int h = (x % mod + mod) % mod;
        for (int i = head[h]; ~i; i = nx[i]) {
            if (key[i] == x) return val[i];
        }
        return 0;
    }
} mp;


int main () {
//    for (int i = 1; i <= mod; i++) if (mod % i == 0) cout << i;
//    freopen ("in.txt", "r", stdin);
    int n;
    cin >> n;
    mp.init ();
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &a[i]);
        mp.ins(a[i], 1);
    }
    vector <int> r;
    int res = mp.qry (0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) if (i != j) {
            if (a[i] == 0 && a[j] == 0) continue;
            int mx = 2, x = a[i], y = a[j];
            r.clear();
            mp.ins(x, -1);
            mp.ins(y, -1);
            r.push_back (x);
            r.push_back (y);
            while (mp.qry (x + y)) {
                int t = y;
                y = x + y;
                x = t;
                r.push_back (y);
                mp.ins(y, -1);
                mx++;
            }
            res = max (mx, res);
            for (int i = 0; i < r.size(); i++) mp.ins(r[i], 1);
        }
    }
    cout << res << endl;
}