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

vector<int> p[2];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for1(i, 1, n){
        cin >> x; p[(x % 3) > 0].pb(i);
    }
    if(p[0].size() <= n / 2) cout << "0\n";
    else cout << "2\n";
    while(!p[1].empty()){
        p[0].pb(p[1].back());
        p[1].pop_back();
    }
    for1(i, 0, n / 2 - 1) a[p[0][i]] = 0;
    for1(i, 0, n / 2 - 1) a[p[0][i + n / 2]] = 1;
    for1(i, 1, n) cout << a[i];
}