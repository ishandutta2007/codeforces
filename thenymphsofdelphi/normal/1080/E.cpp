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

mt19937 rando(chrono::steady_clock::now().time_since_epoch().count());
int randt(int l, int r){ return rando() % (r - l + 1); }

// p[0][i]: half length of even pal substring around i, p[1][i]: half length(rounded donw) of odd pal substring
// O(n)
template<class Char_Type>
array<vector<int>, 2> manacher(const vector<Char_Type> &s){
    int n = (int)s.size();
    array<vector<int>, 2> p = {vector<int>(n + 1), vector<int>(n)};
    for(auto z = 0; z < 2; ++ z){
        for(auto i = 0, l = 0, r = 0; i < n; ++ i){
            int t = r - i + !z;
            if(i < r) p[z][i] = min(t, p[z][l + t]);
            int L = i - p[z][i], R = i + p[z][i] - !z;
            while(L >= 1 && R + 1 < n && s[L - 1] == s[R + 1]) ++ p[z][i], -- L, ++ R;
            if(R > r) l = L, r = R;
        }
    }
    return p;
}

const int N = 250 + 5;

int n, m;
char a[N][N];

int valchar[26];
int mask1[N];
vector <ll> mask2;
bool ispalin[N]; int lpalin[N], rpalin[N];
ll ans;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> m;
    For(i, 0, n){
        For(j, 0, m){
            cin >> a[i][j];
        }
    }
    For(i, 0, 26){
        valchar[i] = randt(0, (1 << 30));
    }
    mask2.resize(n);
    For(l, 0, m){
        For(i, 0, n){
            mask1[i] = mask2[i] = 0;
        }
        For(r, l, m){
            For(i, 0, n){
                mask1[i] ^= (1 << (a[i][r] - 'a'));
                if (__builtin_popcount(mask1[i]) <= 1){
                    ispalin[i] = 1;
                }
                else{
                    ispalin[i] = 0;
                }
                mask2[i] += valchar[a[i][r] - 'a'];
            }
            For(i, 0, n){
                if (ispalin[i]){
                    lpalin[i] = (i - 1 >= 0 and ispalin[i - 1] ? lpalin[i - 1] : i);
                }
            }
            FordE(i, n - 1, 0){
                if (ispalin[i]){
                    rpalin[i] = (i + 1 < n and ispalin[i + 1] ? rpalin[i + 1] : i);
                }
            }
            array <vi, 2> cac = manacher <ll> (mask2);
            assert(cac[0][0] == 0);
            For(i, 1, n){
                if (!ispalin[i] or !ispalin[i - 1]){
                    continue;
                }
                ans += min(cac[0][i], min(i - 1 - lpalin[i - 1] + 1, rpalin[i] - i + 1));
            }
            For(i, 0, n){
                if (!ispalin[i]){
                    continue;
                }
                ans += min(cac[1][i] + 1, min(i - lpalin[i] + 1, rpalin[i] - i + 1));
            }
        }
    }
    cout << ans << endl;
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