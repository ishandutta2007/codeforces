#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (int i = l; i < r; i++)
#define ForE(i, l, r) for (int i = l; i <= r; i++)
#define FordE(i, l, r) for (int i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define bend(a) a.begin(), a.end()
#define isz(a) ((signed)a.size())

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <pii> vpii;
typedef vector <vi> vvi;

const int N = 1e2 + 5;

struct Move{
    int i, x, y;

    Move(int i = 0, int x = 0, int y = 0): i(i), x(x), y(y){

    }
};

pii& operator+= (pii& lhs, const pii& rhs){
    lhs.fi += rhs.fi; lhs.se += rhs.se;
    return lhs;
}

pii operator+ (const pii& lhs, const pii& rhs){
    pii ans = lhs; ans += rhs;
    return ans;
}

int n, k;
int a[5][N];

pii park[N], car[N];
vector <Move> vmove;
pii dir[4] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

pii par[5][N]; bool ck[5][N];

bool valid(const pii& lhs){
    return 2 <= lhs.fi and lhs.fi <= 3 and 1 <= lhs.se and lhs.se <= n;
}

void move(int i, int x, int y){
    assert(abs(car[i].fi - x) + abs(car[i].se - y) == 1);
    assert(!a[x][y]);
    vmove.emplace_back(i, x, y);
    swap(a[car[i].fi][car[i].se], a[x][y]);
    car[i] = make_pair(x, y);
}

void movepath(pii s, pii e, pii o){ // start, end, obstacle
    assert(!a[s.fi][s.se]);
    memset(ck, 0, sizeof(ck));
    queue <pii> qu; qu.push(e); ck[e.fi][e.se] = 1;
    while (!qu.empty()){
        pii u = qu.front(); qu.pop();
        if (u == s){
            break;
        }
        For(d, 0, 4){
            pii v = u + dir[d];
            if (valid(v) and v != o and !ck[v.fi][v.se]){
                par[v.fi][v.se] = u; ck[v.fi][v.se] = 1; qu.push(v);
            }
        }
    }
    assert(ck[s.fi][s.se]);
    while (s != e){
        pii p = par[s.fi][s.se];
        if (a[p.fi][p.se]){
            move(a[p.fi][p.se], s.fi, s.se);
        }
        s = p;
    }
}

signed main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> k;
    ForE(x, 1, 4){
        ForE(y, 1, n){
            cin >> a[x][y];
            if (a[x][y]){
                if (x == 1 or x == 4){
                    park[a[x][y]] = make_pair(x, y);
                    a[x][y] = 0;
                }
                else{
                    car[a[x][y]] = make_pair(x, y);
                }
            }
        }
    }
    ForE(i, 1, k){
        if (abs(park[i].fi - car[i].fi) + abs(park[i].se - car[i].se) == 1){
            move(i, park[i].fi, park[i].se);
        }
    }
    pii hole = make_pair(0, 0);
    ForE(x, 2, 3){
        ForE(y, 1, n){
            if (!a[x][y]){
                hole = make_pair(x, y);
            }
        }
    }
    if (hole == make_pair(0, 0)){
        cout << -1 << endl;
        return 0;
    }
    ForE(i, 1, k){
        if (park[i] == car[i]){
            continue;
        }
        while (car[i].se < park[i].se){
            movepath(hole, make_pair(car[i].fi, car[i].se + 1), car[i]);
            hole = make_pair(car[i].fi, car[i].se + 1);
            move(i, hole.fi, hole.se);
            hole.se--;
        }
        while (park[i].se < car[i].se){
            movepath(hole, make_pair(car[i].fi, car[i].se - 1), car[i]);
            hole = make_pair(car[i].fi, car[i].se - 1);
            move(i, hole.fi, hole.se);
            hole.se++;
        }
        if (park[i].fi == 1 and car[i].fi == 3){
            movepath(hole, make_pair(car[i].fi - 1, car[i].se), car[i]);
            hole = make_pair(car[i].fi - 1, car[i].se);
            move(i, hole.fi, hole.se);
            hole.fi++;
        }
        if (park[i].fi == 4 and car[i].fi == 2){
            movepath(hole, make_pair(car[i].fi + 1, car[i].se), car[i]);
            hole = make_pair(car[i].fi + 1, car[i].se);
            move(i, hole.fi, hole.se);
            hole.fi--;
        }
        move(i, park[i].fi, park[i].se);
    }
    cout << isz(vmove) << endl;
    Fora(&cac, vmove){
        cout << cac.i << ' ' << cac.x << ' ' << cac.y << endl;
    }
}

/*
==================================================+
INPUT:                                            |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
OUTPUT:                                           |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
*/