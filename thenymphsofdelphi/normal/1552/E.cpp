#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (int i = l; i < r; i++)
#define ForE(i, l, r) for (int i = l; i <= r; i++)
#define FordE(i, l, r) for (int i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define bend(a) a.begin(), a.end()
#define isz(a) ((signed)a.size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

const int N = 1e2 + 5, M = 1e4 + 5;

int n, k;
int a[M];

int ctrb[N], b[N][N];
int c[M];

pii ans[N];
int sum[M];

bool verify(){
    ForE(i, 1, n){
        if (!ans[i].fi){
            return 0;
        }
    }
    map <int, int> mpp;
    ForE(i, 1, n){
        mpp[ans[i].fi]++;
        mpp[ans[i].se + 1]--;
    }
    int sum = 0;
    Fora(&elem, mpp){
        sum += elem.se;
        if (sum > (n + k - 2) / (k - 1)){
            return 0;
        }
    }
    return 1;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> k;
    ForE(i, 1, n * k){
        cin >> a[i];
    }

    int lim = (n + k - 1 - 1) / (k - 1);
    ForE(i, 1, n * k){
        b[a[i]][++ctrb[a[i]]] = i;
        c[i] = ctrb[a[i]];
    }
    ForE(i, 1, n * k){
        if (c[i] == 1 or ans[a[i]].fi){
            continue;
        }
        bool ck = 1;
        ForE(j, b[a[i]][c[i] - 1], b[a[i]][c[i]]){
            if (sum[j] == lim){
                ck = 0;
                break;
            }
        }
        if (ck){
            ans[a[i]] = {b[a[i]][c[i] - 1], b[a[i]][c[i]]};
            ForE(j, b[a[i]][c[i] - 1], b[a[i]][c[i]]){
                sum[j]++;
            }
        }
    }
    if (verify()){
        ForE(i, 1, n){
            cout << ans[i].fi << ' ' << ans[i].se << endl;
        } return 0;
    }
    cout << "CAC" << endl;
}

/*
==================================================+
INPUT                                             |
--------------------------------------------------+

--------------------------------------------------+
==================================================+
OUTPUT                                            |
--------------------------------------------------+

--------------------------------------------------+
==================================================+
*/