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
    cin >> n;
    vector<int> a(n);
    int la = -1;
    bool has2 = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i])la = i;
        if(a[i] == 2)has2 = 1;
    }
    if(la == -1){
        cout << "0\n";
        return;
    }
    vector<pii> ans;
    set<int> one, big;
    for(int i = n - 1; i >= 0; i--){
        if(a[i] == 1){
            one.insert(i);
            ans.emplace_back(n - i, i + 1);
        }
        else if(a[i] == 2){
            if(one.empty()){
                cout << "-1\n";
                return;
            }
            int j = *one.begin();
            one.erase(one.begin());
            ans.emplace_back(n - j, i + 1);
            big.insert(i);
        }
        else if(a[i] == 3){
            if(big.empty() && one.empty()){
                cout << "-1\n";
                return;
            }
            int j;
            if(!big.empty()){
                j = *big.begin();
                big.erase(big.begin());
            }
            else{
                j = *one.begin();
                one.erase(one.begin());
            }
            ans.emplace_back(n - i, i + 1);
            ans.emplace_back(n - i, j + 1);
            big.insert(i);
        }
    }
    cout << ans.size() << '\n';
    for(auto x: ans){
        cout << n + 1 - x.X << ' ' << x.Y << '\n';
    }
}

signed main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    while(T--)
        solve();
    return 0;
}