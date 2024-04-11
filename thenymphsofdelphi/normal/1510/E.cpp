#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// #define endl '\n'
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

const int N = 36 + 5;
const ld eps = 1e-9, eps2 = 1e-7;

int n;
ld Cx, Cy;

// bracket sequences
struct info1{
    string s;
    ld cx, cy, a, vx, vy;
    // vx = 
    
    info1(): cx(0), cy(0), a(0), vx(0), vy(0){
        
    }

    info1(ld vx, ld vy): cx(0), cy(0), a(0), vx(vx), vy(vy){

    }

    void cal(){
        vx = cx * a - Cx * a;
        vy = cy * a - Cy * a;
    }
};

bool cmp1(const info1& lhs, const info1& rhs){
    if (lhs.vx != rhs.vx){
        return lhs.vx < rhs.vx;
    }
    return lhs.vy < rhs.vy;
}

bool cmp2(const info1& lhs, const info1& rhs){
    if (lhs.vy != rhs.vy){
        return lhs.vy < rhs.vy;
    }
    return lhs.vx < rhs.vx;
}

char c[N];
vector <info1> prefbrackets[N], suffbrackets[N];

void bt(int u){
    if (u == n / 2 + 1){
        bool ck; int prefsum;
        ck = 1; prefsum = 0;
        ForE(i, 1, n / 2){
            prefsum += (c[i] == '(' ? 1 : -1);
            if (prefsum < 0){
                ck = 0;
            }
        }
        if (ck){
            prefbrackets[prefsum].emplace_back();
            int tsum = 0;
            ForE(i, 1, n / 2){
                prefbrackets[prefsum].back().s += c[i];
                if (c[i] == '('){
                    prefbrackets[prefsum].back().cx += (ld)(i * (6 * tsum + 3) - 3 * tsum - 1) / 6;
                    prefbrackets[prefsum].back().cy += (ld)tsum * tsum / 2 + (ld)(3 * tsum + 1) / 6;
                    prefbrackets[prefsum].back().a += tsum + 0.5;
                    tsum++;
                }
                else{
                    prefbrackets[prefsum].back().cx += (ld)(i * (6 * tsum - 3) - 3 * tsum + 1) / 6;
                    prefbrackets[prefsum].back().cy += (ld)tsum * tsum / 2 - (ld)(3 * tsum - 1) / 6;
                    prefbrackets[prefsum].back().a += tsum - 0.5;
                    tsum--;
                }
            }
            prefbrackets[prefsum].back().cx /= prefbrackets[prefsum].back().a;
            prefbrackets[prefsum].back().cy /= prefbrackets[prefsum].back().a;
            prefbrackets[prefsum].back().cal();
        }
        ck = 1;
        prefsum = 0;
        FordE(i, n / 2, 1){
            prefsum += (c[i] == ')' ? 1 : -1);
            if (prefsum < 0){
                ck = 0;
            }
        }
        if (ck){
            suffbrackets[prefsum].emplace_back();
            int tsum = prefsum;
            ForE(i, 1, n / 2){
                suffbrackets[prefsum].back().s += c[i];
                if (c[i] == '('){
                    suffbrackets[prefsum].back().cx += (ld)(i * (6 * tsum + 3) - 3 * tsum - 1) / 6;
                    suffbrackets[prefsum].back().cy += (ld)tsum * tsum / 2 + (ld)(3 * tsum + 1) / 6;
                    suffbrackets[prefsum].back().a += tsum + 0.5;
                    tsum++;
                }
                else{
                    suffbrackets[prefsum].back().cx += (ld)(i * (6 * tsum - 3) - 3 * tsum + 1) / 6;
                    suffbrackets[prefsum].back().cy += (ld)tsum * tsum / 2 - (ld)(3 * tsum - 1) / 6;
                    suffbrackets[prefsum].back().a += tsum - 0.5;
                    tsum--;
                }
            }
            suffbrackets[prefsum].back().cx /= suffbrackets[prefsum].back().a;
            suffbrackets[prefsum].back().cy /= suffbrackets[prefsum].back().a;
            suffbrackets[prefsum].back().cx += n / 2;
            suffbrackets[prefsum].back().cal();
        }
        return;
    }
    c[u] = '(';
    bt(u + 1);
    c[u] = ')';
    bt(u + 1);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> Cx >> Cy;
    bt(1);
    // cout << fixed << setprecision(6);
    // ForE(i, 0, n){
    //     cout << i << endl;
    //     cout << "PREFBRACKETS" << endl;
    //     Fora(&info, prefbrackets[i]){
    //         cout << info.s << ' ' << info.cx << ' ' << info.cy << ' ' << info.a << endl;
    //     }
    //     cout << "SUFFBRACKETS" << endl;
    //     Fora(&info, suffbrackets[i]){
    //         cout << info.s << ' ' << info.cx << ' ' << info.cy << ' ' << info.a << endl;
    //     }
    // }
    ForE(i, 0, n){
        sort(bend(prefbrackets[i]), cmp1);
        sort(bend(suffbrackets[i]), cmp1);
    }
    ForE(i, 0, n){
        Fora(&info, prefbrackets[i]){
            int idx = lower_bound(bend(suffbrackets[i]), info1(-info.vx - eps2, -info.vy - eps2), cmp1) - suffbrackets[i].begin();
            if (idx == isz(suffbrackets[i])){
                continue;
            }
            if (abs(info.vx + suffbrackets[i][idx].vx) <= eps2 and abs(info.vy + suffbrackets[i][idx].vy) <= eps2){
                cout << info.s << suffbrackets[i][idx].s << endl;
                return 0;
            }
        }
        Fora(&info, suffbrackets[i]){
            int idx = lower_bound(bend(prefbrackets[i]), info1(-info.vx - eps2, -info.vy - eps2), cmp1) - prefbrackets[i].begin();
            if (idx == isz(prefbrackets[i])){
                continue;
            }
            if (abs(info.vx + prefbrackets[i][idx].vx) <= eps2 and abs(info.vy + prefbrackets[i][idx].vy) <= eps2){
                cout << prefbrackets[i][idx].s << info.s << endl;
                return 0;
            }
        }
    }
    ForE(i, 0, n){
        sort(bend(prefbrackets[i]), cmp2);
        sort(bend(suffbrackets[i]), cmp2);
    }
    ForE(i, 0, n){
        Fora(&info, prefbrackets[i]){
            int idx = lower_bound(bend(suffbrackets[i]), info1(-info.vx - eps2, -info.vy - eps2), cmp2) - suffbrackets[i].begin();
            if (idx == isz(suffbrackets[i])){
                continue;
            }
            if (abs(info.vx + suffbrackets[i][idx].vx) <= eps2 and abs(info.vy + suffbrackets[i][idx].vy) <= eps2){
                cout << info.s << suffbrackets[i][idx].s << endl;
                return 0;
            }
        }
        Fora(&info, suffbrackets[i]){
            int idx = lower_bound(bend(prefbrackets[i]), info1(-info.vx - eps2, -info.vy - eps2), cmp2) - prefbrackets[i].begin();
            if (idx == isz(prefbrackets[i])){
                continue;
            }
            if (abs(info.vx + prefbrackets[i][idx].vx) <= eps2 and abs(info.vy + prefbrackets[i][idx].vy) <= eps2){
                cout << prefbrackets[i][idx].s << info.s << endl;
                return 0;
            }
        }
    }
    return -1;
}

/*
==================================+
INPUT:                            |
------------------------------    |
6 3.4 0.6
------------------------------    |

------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
()(())
------------------------------    |

------------------------------    |
==================================+
*/