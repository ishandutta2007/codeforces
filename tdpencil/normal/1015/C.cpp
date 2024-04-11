#include <bits/stdc++.h>
int main() {
    using namespace std;
    ios_base::sync_with_stdio(false); cin.tie(0);
    typedef long long ll; 
    ll N, M;
    cin >> N >> M;

    vector<array<long long, 2>> songs(N);
    ll lim=0;
    for(int i=0; i < N; i++) {
        cin >> songs[i][0] >> songs[i][1];
        assert(songs[i][0] > songs[i][1]);
        lim += songs[i][1];
    }
    if(lim > M) {
        cout << -1 << "\n";
        return 0;
    }
    auto cmp = [&](const auto a, const auto b) {
        return a[0] -a[1] > b[0] - b[1];
    };
    function<void(vector<array<ll, 2>>)> dbg = [&](vector<array<ll, 2>> a) {
        for(auto &e: a)
            cout << "First: " << e[0] << " " << "Second: " << e[1] << "\n";
    } ;
    sort(songs.begin(), songs.end(), cmp);
    reverse(songs.begin(), songs.end());
    ll cur =0;
    ll ans=N;
//    dbg(songs);
    for(int i=0; i < N; i++) {
        if(lim + (songs[i][0] - songs[i][1]) <= M) {
            --ans;
            lim += (songs[i][0] - songs[i][1]);
        }
    }

    

    cout << ans << "\n";
}