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

const int N = 1e3 + 5e2 + 5, base = 1597, mod = 1000004869;

int n, m;
int a[N][N];
int b[N][N], sb[N][N];
int ha[N], hb[N];
map <int, vi> mpp;
int idx[N];
vpii ranges, tranges;
vi vans;

void checktrivial(){
    if (n == 1){
        cout << 0 << endl;
        exit(0);
    }
    if (m == 1){
        cout << 1 << endl << 1 << endl;
        exit(0);
    }
    bool ck = 1;
    ForE(i, 1, n){
        if (idx[i] != i){
            ck = 0;
        }
    }
    if (ck){
        cout << 0 << endl;
        exit(0);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);
    cin >> n >> m;
    ForE(i, 1, n){
        ForE(j, 1, m){
            cin >> a[i][j];
            ha[i] = ((ll)ha[i] * base + a[i][j]) % mod;
        }
        mpp[ha[i]].push_back(i);
    }
    Fora(&v, mpp){
        reverse(bend(v.se));
    }
    ForE(i, 1, n){
        ForE(j, 1, m){
            cin >> b[i][j];
            hb[i] = ((ll)hb[i] * base + b[i][j]) % mod;
        }
        if (!mpp.count(hb[i])){
            cout << -1 << endl;
            return 0;
        }
        idx[i] = mpp[hb[i]].back();
        mpp[hb[i]].pop_back();
        if (isz(mpp[hb[i]]) == 0){
            mpp.erase(hb[i]);
        }
    }
    checktrivial();
    ForE(j, 1, m){
        sb[1][j] = 1;
        ForE(i, 2, n){
            if (b[i][j] >= b[i - 1][j]){
                sb[i][j] = sb[i - 1][j] + 1;
            }
            else{
                sb[i][j] = 1;
            }
        }
    }
    ranges.emplace_back(1, n);
    while (1){
        bool ck = 0;
        ForE(j, 1, m){
            bool ck1 = 1, ck2 = 0;
            Fora(&range, ranges){
                if (sb[range.se][j] < range.se - range.fi + 1){
                    ck1 = 0;
                    break;
                }
                if (b[range.fi][j] != b[range.se][j]){
                    ck2 = 1;
                }
            }
            if (ck1 && ck2){
                ck = 1;
                vans.push_back(j);
                tranges.clear();
                Fora(&range, ranges){
                    int l = -1;
                    ForE(i, range.fi + 1, range.se){
                        if (b[i][j] == b[i - 1][j]){
                            if (l == -1){
                                l = i - 1;
                            }
                        }
                        else{
                            if (l != -1){
                                tranges.emplace_back(l, i - 1);
                                l = -1;
                            }
                        }
                    }
                    if (l != -1){
                        tranges.emplace_back(l, range.se);
                        l = -1;
                    }
                }
                ranges = tranges;
                if (isz(ranges) == 0){
                    reverse(bend(vans));
                    cout << isz(vans) << endl;
                    Fora(&v, vans){
                        cout << v << ' ';
                    } cout << endl;
                    return 0;
                }
            }
        }
        if (!ck){
            break;
        }
    }
    bool ck = 1;
    Fora(&range, ranges){
        ForE(i, range.fi + 1, range.se){
            if (idx[i] < idx[i - 1]){
                ck = 0;
                break;
            }
        }
    }
    if (ck){
        reverse(bend(vans));
        cout << isz(vans) << endl;
        Fora(&v, vans){
            cout << v << ' ';
        } cout << endl;
        return 0;
    }
    cout << -1 << endl;
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