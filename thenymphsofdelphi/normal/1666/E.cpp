/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option

#include<bits/stdc++.h>
using namespace std;

#define all(flg) flg.begin(), flg.end()
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define eb emplace_back
#define ii pair<int, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

int len;
int optmin;
ii satr[maxN];
int ans[maxN];

bool solve(int le, int ri){
    int pl = 0, pr = 0;
    satr[0] = {0, 0};
    for1(i, 1, n){
        pl = max(pl + le, a[i]);
        pr = min(pr + ri, a[i + 1]);
        if(pr < pl) return 0;
        satr[i] = {pl, pr};
    }
    if(pr != a[n + 1]) return 0;
    int pinnate = len;
    for2(i, n, 1){
        int v2 = min(pinnate - le, satr[i - 1].se);
        ans[i] = v2; pinnate = v2;
    }
    return 1;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> len >> n;
    int ri = len / n;
    int le = 0;
    for1(i, 1, n) cin >> a[i];
    a[0] = 0;
    a[n + 1] = len;
    while(ri != le){
        // find stratisfied
        int mid = (le + ri + 1) / 2;
        if(!solve(mid, oo)) ri = mid - 1;
        else le = mid;
    }
    // le: optimal minimum;
    optmin = le;
    le = optmin; ri = len;
    while(le != ri){
        int mid = (le + ri) / 2;
        if(solve(optmin, mid)) ri = mid;
        else le = mid + 1;
    }
    solve(optmin, le);
    ans[n + 1] = len;
    for1(i, 1, n) cout << ans[i] << " " << ans[i + 1] << endl;
}