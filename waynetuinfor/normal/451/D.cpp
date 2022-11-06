#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int cnt[2][2];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s; 
    long long ans1 = 0, ans2 = 0;
    for (int i = 0; i < s.length(); ++i) {
        ++cnt[s[i] - 'a'][i & 1];
        ans1 += cnt[s[i] - 'a'][!(i & 1)]; ans2 += cnt[s[i] - 'a'][i & 1];
    } 
    cout << ans1 << ' ' << ans2 << endl;
    return 0;
}