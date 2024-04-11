//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define pb push_back
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef pair<int, int> pii;


void solve(){
    int n;
    cin >> n;
    map<pii, int> ziga;
    vector<pii> dir(n);
    for(int i = 0; i < n; i++){
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        dir[i] = {u - x, v - y};
        int g = dir[i].X == 0 || dir[i].Y == 0 ? abs(dir[i].X + dir[i].Y) : __gcd(abs(dir[i].X), abs(dir[i].Y));
        dir[i].X /= g;
        dir[i].Y /= g;
        pii neg = {-dir[i].X, -dir[i].Y};
        if(!ziga.count(neg))ziga[neg] = 1;
        else ++ziga[neg];
    }
    ll ans = 0;
    for(int i = 0; i < n; i++)
        if(ziga.count(dir[i]))ans += ziga[dir[i]];
    cout << ans/2 << '\n';
}

signed main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T=1;
    cin >> T;
    while(T--)
        solve();
    return 0;
}