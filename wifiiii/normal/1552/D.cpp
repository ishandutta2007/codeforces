#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int ok = 0;
        function<void(int,int,int)> dfs = [&](int p, int cur, int f) {
            if(p == n) {
                if(cur == 0 && f) ok = 1;
                return;
            }
            dfs(p + 1, cur + a[p], 1);
            dfs(p + 1, cur, f);
            dfs(p + 1, cur - a[p], 1);
        };
        dfs(0, 0, 0);
        cout << (ok ? "YES" : "NO") << endl;
    }
}