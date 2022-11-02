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
    int c[3];
    int a[5];
    for(int i = 0; i < 3; i++)
        cin >> c[i];
    for(int i = 0; i < 5; i++)
        cin >> a[i];
    for(int i = 0; i < 3; i++){
        c[i] -= a[i];
        if(c[i] < 0){
            cout << "NO\n";
            return;
        }
    }
    a[3] -= min(a[3], c[0]);
    a[4] -= min(a[4], c[1]);
    if(a[3] + a[4] <= c[2])
        cout << "YES\n";
    else
        cout << "NO\n";
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