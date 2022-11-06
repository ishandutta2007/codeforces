#include <bits/stdc++.h>
using namespace std;

const unsigned long long inf = 1e18 + 1;
vector<int> pr = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59 };
int n;
unsigned long long ans = inf;

void go(int cur, unsigned long long num, int fac) {
    if (fac == n && num < ans) { ans = num; return; }
    if (fac >= n) return;
    if (num > ans) return;
    for (int i = 1; ; ++i) {
        num *= (unsigned long long)pr[cur];
        if (num > ans) break;
        go(cur + 1, num, fac * (i + 1));
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    go(0, 1ull, 1);
    cout << ans << endl;
    return 0;
}