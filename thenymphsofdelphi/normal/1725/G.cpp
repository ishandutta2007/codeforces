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

int ans[] = {0, 3, 5, 7, 8, 9, 11, 12};

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    // 3, 5, 7, 9, 11, ...
    // 8, 12, 16, ...
    cin >> n;
    if(n <= 7) cout << ans[n] << endl;
    else{
        n += 1;
        n += 1;
        int jp = n / 3; n %= 3;
        if(n == 0){
            n = 3; --jp;
        }
        int jim = jp * 4;
        if(n == 1) cout << jim + 1;
        if(n == 2) cout << jim + 3;
        if(n == 3) cout << jim + 4;

    }
}