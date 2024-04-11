#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

pii encrypt(vector<pii> v){
    sort(v.begin(), v.end());
    return {(ll)(v[0].first * 1e12 + v[1].first * 1e6 + v[2].first),
            (ll)(v[0].second * 1e12 + v[1].second * 1e6 + v[2].second)};
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N; cin >> N;
        int a, b, c, d, e, f;
        cin >> a >> b >> c >> d >> e >> f;
        vector<pii> v = {{a, b}, {c, d}, {e, f}};
        auto colour = [&](pii x){ return (x.first + x.second) % 2; };
        sort(v.begin(), v.end(), [&](pii x, pii y){
            return colour(x) < colour(y);
        });
        if (colour(v[0]) != colour(v[1])){
            reverse(v.begin(), v.end());
        }

        pii q;
        cin >> q.first >> q.second;
        if ((v[2].first == N || v[2].first == 1) && (v[2].second == N || v[2].second == 1)){
            cout << ((v[2].first == q.first || v[2].second == q.second) ? "YES" : "NO") << '\n';
            continue;
        }
        if (colour(v[0]) == colour(q)){
            cout << "YES" << '\n';
        }
        else{
            bool ans = ((v[2].second - q.second) % 2 == 0) && ((v[2].first - q.first) % 2 == 0);
            cout << (ans ? "YES" : "NO") << '\n';
        }
    }
}