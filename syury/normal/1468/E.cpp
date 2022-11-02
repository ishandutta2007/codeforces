//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define pb push_back
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef pair<int, int> pii;


void solve(){
    int a[4], p[4] = {0, 1, 2, 3};
    for(int i = 0; i < 4; i++)
        cin >> a[i];
    int ans = 0;
    do{
        ans = max(ans, min(a[p[0]], a[p[2]]) * min(a[p[1]], a[p[3]]));
    }while(next_permutation(p + 0, p + 4));
    cout << ans << '\n';
}

signed main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--)
        solve();
    return 0;
}