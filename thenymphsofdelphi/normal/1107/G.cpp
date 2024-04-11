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

const int N = 3e5 + 5, M = 20;

int n, k;
int d[N], c[N];
ll prefc[N];
ll rmqmin[M][N], rmqmax[M][N];

ll calmin(int l, int r){
    int z = __builtin_clz(r - l + 1) ^ 31;
    return min(rmqmin[z][l], rmqmin[z][r - (1 << z) + 1]);
}

ll calmax(int l, int r){
    int z = __builtin_clz(r - l + 1) ^ 31;
    return max(rmqmax[z][l], rmqmax[z][r - (1 << z) + 1]);
}

pii difs[N];
set <pii> sttranges;
ll ans;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    ForE(i, 1, n){
        cin >> d[i] >> c[i];
        c[i] = k - c[i];
        ans = max(ans, (ll)c[i]);
    }
    ForE(i, 1, n + 1){
        prefc[i] = prefc[i - 1] + c[i];
        rmqmin[0][i] = rmqmax[0][i] = prefc[i];
    }
    For(j, 1, M){
        ForE(i, 0, n + 1 - (1 << j) + 1){
            rmqmin[j][i] = min(rmqmin[j - 1][i], rmqmin[j - 1][i + (1 << (j - 1))]);
            rmqmax[j][i] = max(rmqmax[j - 1][i], rmqmax[j - 1][i + (1 << (j - 1))]);
        }
    }
    For(i, 1, n){
        difs[i] = make_pair(d[i + 1] - d[i], i);
    }
    sort(difs + 1, difs + n);
    ForE(i, 1, n){
        sttranges.insert(make_pair(i, i));
    }
    For(i, 1, n){
        int dif = difs[i].fi, idx = difs[i].se;
        auto itr = sttranges.lower_bound(make_pair(idx + 1, 0));
        int l2 = (*itr).fi, r2 = (*itr).se;
        itr--;
        int l1 = (*itr).fi, r1 = (*itr).se;
        ll tans = (ll)dif * -dif;
        tans += prefc[r1] - calmin(l1 - 1, r1 - 1);
        tans += calmax(l2, r2) - prefc[l2 - 1];
        ans = max(ans, tans);
        sttranges.erase(sttranges.find(make_pair(l1, r1)));
        sttranges.erase(sttranges.find(make_pair(l2, r2)));
        sttranges.insert(make_pair(l1, r2));
    }
    cout << ans << endl;
}