// http://codeforces.com/contest/713/problem/C
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, a[N];

long long solve() {
    priority_queue <int> opt;
    opt.push(a[1]);

    long long ans = 0;
    for(int i = 2; i <= n; i++){
        if (opt.top() <= a[i]) {
            opt.push(a[i]);
        } else {
            opt.push(a[i]);
            opt.push(a[i]);
            ans += abs(a[i] - opt.top());
            opt.pop();
        }
        //cout << i << " " << a[i] << " " << lastopt << " " << ans << '\n';
    }
    return ans;
}
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] -= i;
    }
    //for(int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];
    cout << solve();
}