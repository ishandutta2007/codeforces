#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    vector<int> pre(m), suf(m);
    int j = 0;
    for(int i = 0; i < m; ++i) {
        while(s[j] != t[i]) ++j;
        pre[i] = j;
        ++j;
    }
    j = n - 1;
    for(int i = m - 1; i >= 0; --i) {
        while(s[j] != t[i]) --j;
        suf[i] = j;
        --j;
    }
    int ans = 0;
    for(int i = 0; i < m - 1; ++i) {
        ans = max(ans, suf[i+1] - pre[i]);
    }
    cout << ans << endl;
}