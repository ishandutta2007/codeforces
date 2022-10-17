#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N, M; cin >> N >> M;
        vector<int> a(N);
        map<int, int> mp;
        mp[-1] = 1e9+1;
        for (int i = 0; i < N; ++i){
            cin >> a[i];
            if (a[i] < (--mp.end())->second){
                mp[i] = a[i];
            }
        }
        mp[N] = -1;
        while (M--){
            int i, d; cin >> i >> d;
            i--;
            a[i] -= d;
            d = a[i];
            while (mp.lower_bound(i)->second >= d){
                mp.erase(mp.lower_bound(i));
            }
            if ((--mp.upper_bound(i))->second > d){
                mp[i] = d;
            }
            // for (auto [a, b] : mp) cout << a << " " << b << '\n';
            cout << mp.size()-2 << " ";
        }
        cout << '\n';
    }
}