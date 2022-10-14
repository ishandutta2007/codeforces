#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
#define MOD 1000000007
typedef long long ll;
using namespace std;
ll n,m,k,x, rt[35], y, z, l, i, j, p;
ll a[100500];
ll used[100500], last_move;
vector<pii> f;
multiset<ll> g;
ll Abs(ll x) {
    return (x > 0 ? x : -x);
}
void process_my_move() {
    if (used[last_move] > 0) {
        cout << used[last_move] << endl;
        used[last_move] = used[used[last_move]] = -1;
        return;
    }
    f.clear();
    int mx = -1;
    int x;
    for (int j = 1; j <= 2 * n; j++) {
        if (used[j] != -1) {
            f.push_back(mp(a[j], j));
        }
        if (used[j] > 0) {
            if (a[j] - a[used[j]] > mx)
                mx = a[j] - a[used[j]], x = j;
        }
    }
    sort(f.begin(), f.end());
    reverse(f.begin(), f.end());
    if (f.size() == 1) {
        x = f[0].Y;
    } else {
        if (f[0].X - f[1].X > mx)
            x = f[0].Y;
    }
    cout << x << endl;
    used[x] = -1;
    fflush(stdout);
}

void process_enemy_move() {
    int x;
    cin >> x;
    last_move = x;
    if (used[x] > 0 && used[used[x]] > 0)
        return;
    used[x] = -1;
}
int main() {
     //freopen("input.txt","r",stdin);
    cin >> n >> m;
    for (int i = 1; i <= 2 * n; i++) {
        cin >> a[i];
    }
    for (int j = 0; j < m; j++) {
        cin >> x >> y;
        used[x] = y;
        used[y] = x;
    }
    ll t;
    cin >> t;

    last_move = 2 * n + 1;
    if (t == 1) {
        for (int i = 0; i < n; i++) {
            process_my_move();
            process_enemy_move();
        }
    } else {
        for (int i = 0; i < n; i++) {
            process_enemy_move();
            process_my_move();
        }
    }
    return 0;
}