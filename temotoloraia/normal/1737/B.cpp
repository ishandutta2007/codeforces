#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define ll long long
#define F first
#define S second
using namespace std;

const int N = 1000005, MOD = 1e9 + 7;

int cnt (int M){
    if (M <= 0)
        return 0;
    int x = sqrt (M);
    int ans = x + x-1 + x-1;
    if (x*(x+1) <= M)
        ans++;
    if (x*(x+2) <= M)
        ans++;
    return ans;
}

void solve () {
    int l, r;
    cin >> l >> r;
    cout << cnt(r) - cnt (l-1) << endl;
}

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    int T=1;
    cin >> T;
    for (int i = 1; i <= T; i++){
        solve();
    }
    return 0;
}