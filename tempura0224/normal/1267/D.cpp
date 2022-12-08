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

void solve(){
    int n;
    cin >> n;
    vector<int> goal(n, 0), mask(n, 0);
    rep(i, n){
        int k;
        rep(j, 3){
            cin >> k;
            goal[i] |= (k << j);
        }
    }
    rep(i, n){
        int k;
        rep(j, 3){
            cin >> k;
            mask[i] |= (k << j);
        }
    }
    vector<vector<int>> get(8);
    queue<int> q;
    get[7].push_back(0);
    q.push(7);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        rep(i, n){
            if(goal[i] == x){
                if(get[mask[i] & x].size() == 0){
                    get[mask[i] & x].push_back(i);
                    q.push(mask[i] & x);
                }
            }
        }
        if(get[0b011].size() == 0 && get[0b001].size() > 0 && get[0b010].size() > 0){
            get[0b011].push_back(get[0b001][0]);
            get[0b011].push_back(get[0b010][0]);
            q.push(0b011);
        }
        if(get[0b101].size() == 0 && get[0b001].size() > 0 && get[0b100].size() > 0){
            get[0b101].push_back(get[0b001][0]);
            get[0b101].push_back(get[0b100][0]);
            q.push(0b101);
        }
        if(get[0b110].size() == 0 && get[0b100].size() > 0 && get[0b010].size() > 0){
            get[0b110].push_back(get[0b100][0]);
            get[0b110].push_back(get[0b010][0]);
            q.push(0b110);
        }
    }
    rep(i, n){
        if(goal[i] == 0) continue;
        if(get[goal[i]].size() == 0){
            cout << "Impossible" << endl;
            return;
        }
    }
    vector<int> used(n, false);
    repl(i, 1, 8){
        for(auto &x:get[i]){
            used[x] = true;
        }
    }
    vector<pair<int, int>> ans;
    repl(i, 1, n){
        if(goal[i] == 0) continue;
        for(auto &x: get[goal[i]]) ans.push_back({x, i});
        if(!used[i]){
            get[goal[i]] = {i};
        }
    }
    cout << "Possible" << endl;
    rep(i, n){
        cout << (used[i] ? 1 : 0);
        if(i < n - 1) cout << " ";
        else cout << endl;
    }
    cout << ans.size() << endl;
    for(auto &p:ans){
        cout << p.first + 1 << " " << p.second + 1 << endl;
    }

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    //stop
    return 0;
}