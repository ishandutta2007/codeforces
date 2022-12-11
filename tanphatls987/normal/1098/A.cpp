#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
const int inf = 1e9 + 10;
int n, pa[N], a[N];
int ans[N];
vector<int> v[N];
int main() {
    cin >> n;
    for(int i = 2; i <= n; i++) { 
        cin >> pa[i];
        v[pa[i]].push_back(i);
    }

    for(int i = 1; i <= n; i++) cin >> a[i];

    ans[1] = a[1];
    for(int i = 2; i <= n; i++) {
        if (a[i] == -1) {
            if (v[i].empty()) ans[i] = 0;
            else {
                ans[i] = inf;
                for(auto j : v[i])
                    ans[i] = min(ans[i], a[j] - a[pa[i]]);
            }
            if (ans[i] < 0) {
                cout << "-1";
                return 0;
            }
            a[i] = a[pa[i]] + ans[i];
        } else {
            ans[i] = a[i] - a[pa[i]];
        }
    }
    long long sum = 0;
    for(int i = 1; i <= n; i++) sum += ans[i];
    cout << sum;
}