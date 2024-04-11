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

const int N = 1e6 + 5;

int n, k;
string s;

int sum, prefSumK[N], maxPrefSumK[N];
set <int> sttMax[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
int q; cin >> q; while (q--){
    cin >> n >> k;
    cin >> s; s = ' ' + s;
    sum = 0;
    For(i, 0, k){
        sttMax[i].clear();
        sttMax[i].insert(0);
    }
    ForE(i, 1, n){
        prefSumK[i] = (i > k ? prefSumK[i - k] : 0);
        maxPrefSumK[i] = (i > k ? maxPrefSumK[i - k] : 0);
        if (s[i] == '1'){
            prefSumK[i]++;
            sum++;
        }
        maxPrefSumK[i] = max(maxPrefSumK[i], prefSumK[i]);
    }
    // ForE(i, 1, n){
    //     cout << maxPrefSumK[i] << ' ';
    // } cout << endl;
    int ans = sum;
    ForE(i, 1, n){
        int endIdx = ((n - i) / k) * k + i;
        int tans = (sum - prefSumK[endIdx]) +
                   prefSumK[endIdx] - 2 * prefSumK[i] + (i + k - 1) / k +
                   *sttMax[i % k].begin();
        ans = min(ans, tans);
        // cout << i << ' ' << tans << ' ' << 2 * prefSumK[i] - (i + k - 1) / k << endl;
        sttMax[i % k].insert(2 * prefSumK[i] - (i + k - 1) / k);
    }
    cout << ans << endl;
}
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