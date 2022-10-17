#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        map<char, int> cnt;
        char a;
        cin >> a; cnt[a]++;
        cin >> a; cnt[a]++;
        cin >> a; cnt[a]++;
        cin >> a; cnt[a]++;
        vector<int> v;
        for (auto [a, b] : cnt) v.push_back(b);
        sort(v.begin(), v.end());
        v.pop_back();
        int ans = 0;
        for (int x : v) ans += (x+1)/2;
        cout << ans << '\n';
    }
}