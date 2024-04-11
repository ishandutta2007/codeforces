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

const int N = 6e2 + 5;

int n;
pii a[N];

bool dp[N][N];
// whether we can create a correct parenthesis substring with len 2 * i, start from parenthesis j

string s;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i].fi >> a[i].se;
    }
    s.resize(2 * n + 1);
    ForE(j, 1, n){
        dp[1][j] = (a[j].fi <= 1 && 1 <= a[j].se);
    }
    ForE(i, 2, n){
        ForE(j, 1, n - i + 1){
            For(len, 1, i){
                if (a[j].fi <= (len << 1) - 1 && (len << 1) - 1 <= a[j].se &&
                    dp[len][j] && dp[i - len][j + len]){
                    dp[i][j] = 1;
                    break;
                }
            }
            if (dp[i][j]){
                continue;
            }
            if (a[j].fi <= (i << 1) - 1 && (i << 1) - 1 <= a[j].se && dp[i - 1][j + 1]){
                dp[i][j] = 1;
            }
        }
    }
    if (!dp[n][1]){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    queue <tuple <int, int, int>> qu;
    qu.push(make_tuple(n, 1, 1));
    while (!qu.empty()){
        tuple <int, int, int> t = qu.front(); qu.pop();
        int i = get<0>(t), j = get<1>(t), l = get<2>(t);
        if (i == 1){
            s[l] = '(';
            s[l + 1] = ')';
            continue;
        }
        bool ck = 0;
        For(len, 1, i){
            if (a[j].fi <= (len << 1) - 1 && (len << 1) - 1 <= a[j].se &&
                dp[len][j] && dp[i - len][j + len]){
                qu.push(make_tuple(len, j, l));
                qu.push(make_tuple(i - len, j + len, l + (len << 1)));
                ck = 1;
                break;
            }
        }
        if (!ck){
            s[l] = '(';
            s[l + (i << 1) - 1] = ')';
            qu.push(make_tuple(i - 1, j + 1, l + 1));
        }
    }
    s.erase(0, 1);
    cout << s;
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