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

const int N = 1e5 + 5;

int n;
string s[3];
int cnt[3][2];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
int q; cin >> q; while (q--){
    cin >> n;
    cin >> s[0] >> s[1] >> s[2];
    memset(cnt, 0, sizeof(cnt));
    For(j, 0, 3){
        Fora(&v, s[j]){
            cnt[j][v - '0']++;
        }
    }
    bool ck = 0;
    For(j, 0, 3){
        For(k, 0, 3){
            if (j == k){
                continue;
            }
            if (cnt[j][0] >= n and cnt[k][0] >= n){
                vi cac[2];
                For(i, 0, 2 * n){
                    if (s[j][i] == '0'){
                        cac[0].push_back(i);
                        if (isz(cac[0]) == n){
                            break;
                        }
                    }
                }
                For(i, 0, 2 * n){
                    if (s[k][i] == '0'){
                        cac[1].push_back(i);
                        if (isz(cac[1]) == n){
                            break;
                        }
                    }
                }
                int l[2] = {0, 0};
                For(i, 0, n){
                    while (l[0] < cac[0][i]){
                        cout << s[j][l[0]];
                        l[0]++;
                    } l[0]++;
                    while (l[1] < cac[1][i]){
                        cout << s[k][l[1]];
                        l[1]++;
                    } l[1]++;
                    cout << '0';
                }
                while (l[0] < 2 * n){
                    cout << s[j][l[0]];
                    l[0]++;
                }
                while (l[1] < 2 * n){
                    cout << s[k][l[1]];
                    l[1]++;
                } l[1]++;
                ck = 1; break;
            }
            if (cnt[j][1] >= n and cnt[k][1] >= n){
                vi cac[2];
                For(i, 0, 2 * n){
                    if (s[j][i] == '1'){
                        cac[0].push_back(i);
                        if (isz(cac[0]) == n){
                            break;
                        }
                    }
                }
                For(i, 0, 2 * n){
                    if (s[k][i] == '1'){
                        cac[1].push_back(i);
                        if (isz(cac[1]) == n){
                            break;
                        }
                    }
                }
                int l[2] = {0, 0};
                For(i, 0, n){
                    while (l[0] < cac[0][i]){
                        cout << s[j][l[0]];
                        l[0]++;
                    } l[0]++;
                    while (l[1] < cac[1][i]){
                        cout << s[k][l[1]];
                        l[1]++;
                    } l[1]++;
                    cout << '1';
                }
                while (l[0] < 2 * n){
                    cout << s[j][l[0]];
                    l[0]++;
                }
                while (l[1] < 2 * n){
                    cout << s[k][l[1]];
                    l[1]++;
                } l[1]++;
                ck = 1; break;
            }
        }
        if (ck) break;
    }
    cout << endl;
    assert(ck);
}
}

/*
==================================+
INPUT:                            |
------------------------------    |

------------------------------    |

------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |

------------------------------    |
==================================+
*/