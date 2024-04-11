#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    const int N = 1000;
    vector<string> ans(N + 1);
    string s; int x = 0;
    for(int i = 0; i <= N; ++i) {
        if(i & 1) s += '1', x += 1;
        else s += '2', x += 2;
        if(x <= N && ans[x].empty()) ans[x] = s;
    }
    s.clear(); x = 0;
    for(int i = 0; i <= N; ++i) {
        if(i % 2 == 0) s += '1', x += 1;
        else s += '2', x += 2;
        if(x <= N && ans[x].empty()) ans[x] = s;
    }
    while(t--) {
        int n;
        cin >> n;
        cout << ans[n] << '\n';
    }
}