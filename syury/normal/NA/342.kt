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

int k;

void solve(){
    int n, m;
    cin >> n >> m;
    int d = min(n, m)/(k+1);
    if(min(n, m)%(k+1) == 0){
        cout << "+\n";
        return;
    }
    int bg = (k+1) * d;
    int par = ((n - bg) + (m - bg))%2;
    if(k == 1)d = 0;
    int ans = (par + 1 - d%2)%2;
    if(ans)cout << "-\n";
    else cout << "+\n";
}

signed main(){
//#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
//#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(6);
    int T = 1;
    cin >> T;
    cin >> k;
    while(T--)
        solve();
    return 0;
}