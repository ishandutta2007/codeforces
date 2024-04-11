#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N, M; cin >> N >> M;
        vector<pair<ll, int>> v;
        for (int i = 1; i <= N; ++i){
            ll cur = 0;
            for (int j = 1; j <= M; ++j){
                ll a; cin >> a;
                cur += a * j;
            }
            v.push_back({cur, i});
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        cout << v[0].second << " " << v[0].first - v[1].first << '\n';
    }
}