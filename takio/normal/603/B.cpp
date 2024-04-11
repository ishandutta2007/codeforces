#include <bits/stdc++.h>
#define LL long long
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
#define pii pair <LL, int>
#define xx first
#define yy second
using namespace std;

const int N = 1001000;

int nx[N], vis[N], d[N], cnt[N], all[N];
vector <int> g;

int main () {
//    freopen ("in.txt", "r", stdin);
    int p, k;
    cin >> p >> k;
    if (k == 0) {
        LL res = 1;
        for (int i = 0; i < p - 1; i++) {
            (res *= p) %= (int) (1e9 + 7);
        }
        cout << res << endl;
        return 0;
    }
    for (int i = 0; i < p; i++) if (!vis[i]) {
        int tmp = i, c = 0;
        g.push_back (i);
        vis[tmp] = 1;
        do {
            tmp = 1LL * tmp * k % p;
            c++;
        } while (tmp != i);
        do {
            tmp = 1LL * tmp * k % p;
            d[tmp] = c;
            vis[tmp] = 1;
        } while (tmp != i);
    }
    for (int i = 0; i < p; i++) {
//        cout << d[i] << ' ' ; cout <<endl;
        cnt[d[i]]++;
    }
    for (int i = 1; i <= p; i++) {
        for (int j = i; j <= p; j += i) {
            all[j] += cnt[i];
        }
    }
    LL res = 1;
    for (int i = 0; i < g.size(); i++) {
//        cout << g[i] << ' ' << d[g[i]] << ' ' << all[d[g[i]]] << endl;
        (res *= all[d[g[i]]]) %= (int)(1e9 + 7);
    }
    cout << res << endl;
}