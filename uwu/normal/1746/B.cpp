#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N; cin >> N;
        vector<int> zero, one;
        for (int i = 0; i < N; ++i){
            int x; cin >> x;
            if (x == 0) zero.push_back(i);
            else one.push_back(i);
        }
        reverse(one.begin(), one.end());
        int ans = 0;
        while (!zero.empty() && !one.empty() && zero.back() > one.back()){
            ans++;
            zero.pop_back();
            one.pop_back();
        }
        cout << ans << '\n';
    }
}