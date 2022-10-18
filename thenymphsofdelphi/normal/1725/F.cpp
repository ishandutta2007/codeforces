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
#define vi vector<int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define ld long double
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

vector<ii> ed;
int ans[32];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for1(i, 1, n){
        cin >> x >> y;
        ed.pb(ii(x, y));
    }
    for1(ds, 0, 29){
        int vl = (1 << ds);
        vector<ii> sep;
        int bonus = 0;
        for(ii pr : ed){
            ++pr.se;
            if(pr.se - pr.fi >= vl) ++bonus;
            else{
                pr.fi = pr.fi % vl;
                pr.se = pr.se % vl;
                if(pr.fi <= pr.se) sep.pb(pr);
                else{
                    sep.pb(ii(pr.fi, vl));
                    sep.pb(ii(0, pr.se));
                }
            }
        }
        int res = bonus;
        vector<ii> adl;
        for(ii pr : sep){
            adl.pb(ii(pr.fi, 1));
            adl.pb(ii(pr.se, -1));
        }
        sort(all(adl));
        for(ii pr : adl){
            res += pr.se;
            bonus = max(bonus, res);
        }
        ans[ds] = bonus;
    }
    int o; cin >> o; while(o--){
        cin >> x; int vl = 0;
        while((x & 1) == 0){
            x /= 2; ++vl;
        }
        cout << ans[vl] << endl;
    }
}