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
    vector<int> money;
    set<int> ord;
    set<pii, greater<pii> > big;
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        int t;
        cin >> t;
        if(t == 1){
            int mn;
            cin >> mn;
            int id = money.size();
            money.push_back(mn);
            ord.insert(id);
            big.emplace(money[id], -id);
        }
        else if(t == 2){
            int id = *ord.begin();
            ord.erase(ord.begin());
            big.erase(make_pair(money[id], -id));
            cout << id + 1 << ' ';
        }
        else{
            int id = -big.begin()->Y;
            big.erase(big.begin());
            ord.erase(id);
            cout << id + 1 << ' ';
        }
    }
}

signed main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T=1;
    //cin >> T;
    while(T--)
        solve();
    return 0;
}