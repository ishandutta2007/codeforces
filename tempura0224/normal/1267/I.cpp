#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<utility>

using namespace std;

using ll = long long;
using P = pair<int, int>;
using LP = pair<ll, ll>;
const ll INF = (1e+18) + 100;
#define rep(i, n) for(int i=0;i<n;++i)
#define repl(i, l, n) for(int i=l;i<n;++i)
#define Rep(i, sta, n) for(int i=sta;i<n;i++)
#define stop char nyaa;cin>>nyaa;

using speP = pair<LP, ll>;

bool query(int x, int y){
    cout << "? " << x + 1 << " " << y + 1 << endl;
    char c;
    cin >> c;
    return c == '<';
}

void solve(){
    int n;
    cin >> n;

    vector<pair<int, int>> v;

    rep(i, n){
        if(query(i, n + i)){
            v.push_back({i, n + i});
        }else{
            v.push_back({n + i, i});
        }
    }

    vector<int> c(n, 0);
    rep(i, n){
        rep(j, i){
            if(query(v[i].first, v[j].first)){
                c[j]++;
            }else{
                c[i]++;
            }
        }
    }

    int k = 0;
    rep(i, n) if(c[i] == n - 1) k = i;

    vector<int> c2(n, 0);
    rep(i, n){
        rep(j, i){
            if(i == k || j == k) continue;
            if(query(v[i].second, v[j].second)){
                c2[j]++;
            }else{
                c2[i]++;
            }
        }
    }

    int l = 0;
    rep(i, n) if(c2[i] == n - 2) l = i;


    rep(i, n){
        if(i == k || i == l) continue;
        rep(j, n){
            query(v[i].second, v[j].first);
        }
    }
    cout << "!" << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    rep(i, t) solve();
    //stop
    return 0;
}