#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    vector<bitset<100>> vec;
    int ans = 0;
    for (int i = 1; i <= N; ++i){
        bitset<100> bs;
        for (int j = 0; j < N; ++j){
            char c; cin >> c;
            bs[j] = c == '1';
        }
        if (!bs[0]) bs.flip();
        vec.push_back(bs);
        int cur = 0;
        for (auto other : vec){
            if (bs == other) cur++;
        }
        ans = max(ans, cur);
    }
    cout << ans << '\n';
}