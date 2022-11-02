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
typedef long double dbl;
typedef pair<int, int> pii;

void solve(){
    int n;
    string s;
    cin >> n >> s;
    vector<char> ok(n, 0);
    int cw = 0, ccw = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '-'){
            ++cw; ++ccw;
            int j = i == n - 1 ? 0 : (i + 1);
            ok[i] = ok[j] = 1;
        }
        else if(s[i] == '>'){
            ++cw;
        }
        else
            ++ccw;
    }
    if(cw == n || ccw == n)
        cout << n << '\n';
    else cout << count(all(ok), 1) << '\n';
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