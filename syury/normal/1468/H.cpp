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
    int n, k, m;
    cin >> n >> k >> m;
    vector<char> del(n, 0);
    for(int i = 0; i < m; i++){
        int pos;
        cin >> pos;
        del[pos - 1] = 1;
    }
    if((n - m)%(k - 1)){
        cout << "NO\n";
        return;
    }
    int pref = 0;
    bool ok = 0;
    for(int i = 0; i < n; i++){
        if(!del[i])
            ++pref;
        else{
            int l = pref, r = n - m - pref;
            if(l >= (k-1)/2 && r >= (k-1)/2)
                ok = 1;
        }
    }
    if(ok)cout << "YES\n";
    else cout << "NO\n";
}

signed main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T=1;
    cin >> T;
    while(T--)
        solve();
    return 0;
}