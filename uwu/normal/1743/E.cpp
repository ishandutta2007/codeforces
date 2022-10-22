#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using ll = long long;
 
int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll p1, t1, p2, t2;
    cin >> p1 >> t1 >> p2 >> t2;
    ll h, s; cin >> h >> s;
    if (t1 > t2) swap(p1, p2), swap(t1, t2);
 
    vector<__gnu_pbds::gp_hash_table<ll, ll>> mp(h+1);
    auto solve = [&](auto self, ll h, ll c1) -> ll{
        if (h <= 0) return 0;
        if (mp[h].find(c1) != mp[h].end()) return mp[h][c1];
        ll &ans = mp[h][c1];
        ans = 1e18;
        ans = min(ans, (h+(p1-s)-1) / (p1-s) * t1 - c1);
        ans = min(ans, (h+(p2-s)-1) / (p2-s) * t2);
        // sync cannons, two cases
        // 1 waits for 2
        ll shots1 = (t2+c1)/t1 - 1;
        ll nh = h - (shots1 * (p1-s)) - (p1+p2-s);
        ans = min(ans, self(self, nh, 0) + t2);
 
        // 2 waits for 1
        ll t = ((t2+c1+t1-1)/t1) * t1;
        shots1 = t/t1 - 1;
        nh = h - (shots1 * (p1-s)) - (p1+p2-s);
        ans = min(ans, self(self, nh, 0) + t - c1);
 
        // not synced, skip to cannon 2 fires once
        shots1 = (t2+c1)/t1;
        ll nc1 = (t2+c1)%t1;
        nh = h - (shots1 * (p1-s)) - (p2-s);
        ans = min(ans, self(self, nh, nc1) + t2);
 
        return ans;
    };
    cout << solve(solve, h, 0) << '\n';
}

/*
27
9 18    4
13      2
27      5
11
22
24

9 18 27 36 45 54 63
13 26 39 52 65

*/