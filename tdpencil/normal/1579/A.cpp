#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define all(x) x.begin(),x.end()
#define trav(a, b) for(auto &a: b)
#define ct(a, b) count(all(a), b)
const ll mod = 1e9+7;

void solve() {
    int cnt[3]={};
    string s; cin >> s;
    for(char ch : s) ++cnt[ch - 'A'];
    if(cnt[0] + cnt[2] == cnt[1]) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;

    for(int num = 1; num <= T; num++) {
        solve();
    }
}