#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (auto i = (l); i < (r); i++)
#define ForE(i, l, r) for (auto i = (l); i <= (r); i++)
#define FordE(i, l, r) for (auto i = (l); i >= (r); i--)
#define Fora(v, a) for (auto v: (a))
#define bend(a) (a).begin(), (a).end()
#define isz(a) ((signed)(a).size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

const int N = 5e3 + 5, M = 1e3 + 5;

int n, m;
map <string, int> mppvar;
string s[N];
pii a[N]; int b[N];

int val[N][2];

void solve(const auto &cmp){
    For(j, 0, m){
        int cnt[2] = {0, 0};
        val[0][0] = 0; val[0][1] = 1;
        ForE(i, 1, n){
            if (b[i] == 0){
                val[i][0] = val[i][1] = s[i][j] - '0';
            }
            else{
                if (b[i] == 1){
                    val[i][0] = val[a[i].fi][0] & val[a[i].se][0];
                    val[i][1] = val[a[i].fi][1] & val[a[i].se][1];
                }
                else if (b[i] == 2){
                    val[i][0] = val[a[i].fi][0] | val[a[i].se][0];
                    val[i][1] = val[a[i].fi][1] | val[a[i].se][1];
                }
                else{
                    val[i][0] = val[a[i].fi][0] ^ val[a[i].se][0];
                    val[i][1] = val[a[i].fi][1] ^ val[a[i].se][1];
                }
            }
            cnt[0] += val[i][0]; cnt[1] += val[i][1];
        }
        if (cmp(cnt[1], cnt[0])){
            cout << 1;
        }
        else{
            cout << 0;
        }
    } cout << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> m;
    mppvar["?"] = 0;
    ForE(i, 1, n){
        string svar; cin >> svar; mppvar[svar] = i;
        cin >> svar >> svar;
        if (isdigit(svar[0])){
            s[i] = svar;
        }
        else{
            a[i].fi = mppvar[svar];
            cin >> svar;
            if (svar == "AND"){
                b[i] = 1;
            }
            else if (svar == "OR"){
                b[i] = 2;
            }
            else{
                b[i] = 3;
            }
            cin >> svar;
            a[i].se = mppvar[svar];
        }
    }
    solve([&](int x, int y){ return x < y; });
    solve([&](int x, int y){ return x > y; });
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