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

const int N = 2e5 + 5;

struct Query{
    ld x; int type;

    Query(ld x = 0, int type = 0): x(x), type(type){

    }
};

bool operator< (const Query& lhs, const Query& rhs){
    return lhs.x < rhs.x;
}

int sy, sl, sr;
int n;
pii fences[N];
int m;
pii points[N];

pair <ld, ld> pointsxaxis[N];
vector <Query> vquery;
map <ld, ld> mppval;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> sy >> sl >> sr;
    cin >> n;
    ForE(i, 1, n){
        cin >> fences[i].fi >> fences[i].se;
    }
    cin >> m;
    ForE(i, 1, m){
        cin >> points[i].fi >> points[i].se;
    }

    ForE(i, 1, n){
        vquery.emplace_back(fences[i].fi, 1);
        vquery.emplace_back(fences[i].se, -1);
    }
    ForE(i, 1, m){
        pointsxaxis[i].fi = points[i].fi + (ld)(sl - points[i].fi) * points[i].se / (points[i].se - sy);
        pointsxaxis[i].se = points[i].fi + (ld)(sr - points[i].fi) * points[i].se / (points[i].se - sy);
        vquery.emplace_back(pointsxaxis[i].fi, 0);
        vquery.emplace_back(pointsxaxis[i].se, 0);
    }
    sort(bend(vquery));
    ld sum = 0, pos = (ll)-1e18 - 7, delta = 0;
    Fora(&query, vquery){
        if (pos < query.x){
            sum += delta * (query.x - pos);
            pos = query.x;
        }
        if (query.type){
            delta += query.type;
        }
        else{
            mppval[query.x] = sum;
        }
    }
    cout << fixed << setprecision(6);
    ForE(i, 1, m){
        ld ans = mppval[pointsxaxis[i].se] - mppval[pointsxaxis[i].fi];
        ans *= (sr - sl) / (pointsxaxis[i].se - pointsxaxis[i].fi);
        cout << ans << endl;
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