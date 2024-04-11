#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N; cin >> N;
        vector<int> a(N), b(N);
        for (int i = 0; i < N; ++i){
            cin >> a[i];
        }
        for (int i = 0; i < N; ++i){
            cin >> b[i];
        }
        vector<int> mn(N), mx(N);
        for (int i = 0; i < N; ++i){
            mn[i] = *lower_bound(b.begin(), b.end(), a[i]) - a[i];
            cout << mn[i] << " ";
        }
        cout << '\n';
        map<int, int> mp;
        for (int x : b) mp[x]++;
        for (int i = N-1; i >= 0; --i){
            mx[i] = (--mp.end())->first - a[i];
            int val = mp.lower_bound(a[i])->first;
            mp[val]--;
            if (mp[val] == 0) mp.erase(val);
        }
        for (int i = 0; i < N; ++i){
            cout << mx[i] << " ";
        }
        cout << '\n';
    }
}