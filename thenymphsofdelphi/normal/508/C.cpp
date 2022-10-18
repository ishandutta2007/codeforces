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

const int N = 3e2 + 5;

int m, t, r;
int w[N];

bool ck[N * N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> m >> t >> r;
    ForE(i, 1, m){
        cin >> w[i];
    }
    if (t < r){
        cout << -1 << endl;
        return 0;
    }
    ForE(i, 1, m){
        int cnt = 0;
        For(j, w[i], w[i] + t){
            if (ck[j]){
                cnt++;
            }
        }
        if (cnt < r){
            cnt = r - cnt;
            FordE(j, w[i] + t - 1, i){
                if (!ck[j]){
                    ck[j] = 1;
                    cnt--;
                    if (!cnt){
                        break;
                    }
                }
            }
        }
    }
    int ans = 0;
    For(i, 0, N * N){
        if (ck[i]){
            ans++;
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