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


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        string s, t; cin >> s >> t;
        string s1 = "?", t1 = "?";
        bool gag = 0;
        for(char c : s) if(c == 'B') gag = !gag;
        for(char c : t) if(c == 'B') gag = !gag;
        for(char c : s) if(c != 'B'){
            if(c == s1.back()) s1.pop_back();
            else s1.pb(c);
        }
        for(char c : t) if(c != 'B'){
            if(c == t1.back()) t1.pop_back();
            else t1.pb(c);
        }
        if(s1 == t1 && (!gag)) cout << "YES\n";
        else cout << "NO\n";
    }
}