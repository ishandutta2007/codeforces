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

const int N = 4e5 + 5, M = 1e2 + 5;

int n;
int a[N];

int cnt[M];
int mxfreq;

int ans;
int b[N];

int pos[N];
int timeline[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i];
    }

    ForE(i, 1, n){
        cnt[a[i]]++;
    }
    {
        int mx = *max_element(cnt + 1, cnt + M), cntmx = 0;
        For(i, 1, M){
            if (cnt[i] == mx){
                cntmx++;
            }
        }
        if (cntmx > 1){
            cout << n << endl;
            return 0;
        }
        mxfreq = max_element(cnt + 1, cnt + M) - cnt;
    }

    For(i, 1, M){
        if (cnt[i] == 0 or i == mxfreq){
            continue;
        }
        int sum = 0;
        if (timeline[sum + n] != i){
            timeline[sum + n] = i;
            pos[sum + n] = n;
        }
        pos[sum + n] = 0;
        ForE(j, 1, n){
            int x = (a[j] == mxfreq ? 1 : (a[j] == i ? -1 : 0));
            sum += x;
            if (timeline[sum + n] != i){
                timeline[sum + n] = i;
                pos[sum + n] = n;
            }
            ans = max(ans, j - pos[sum + n]);
            pos[sum + n] = min(pos[sum + n], j);
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