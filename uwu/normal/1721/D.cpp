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
        map<int, int> mp;
        int ans = 0;
        for (int l = 29; l >= 0; --l){
            mp.clear();
            for (int x : a){
                x &= (1<<30) - (1<<l);
                mp[x]++;
            }
            for (int x : b){
                x &= (1<<30) - (1<<l);
                x ^= (1<<l);
                mp[x]--;
            }
            bool flag = 1;
            for (auto [x, y] : mp){
                flag &= y == 0;
            }
            if (flag){
                ans += (1<<l);
                for (int &x : a) x ^= (1<<l);
            }
            else{
                for (int &x : a) x |= (1<<l);
                for (int &x : b) x |= (1<<l);
            }
        }
        cout << ans << '\n';
    }
}