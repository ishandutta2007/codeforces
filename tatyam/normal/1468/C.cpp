#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pll = pair<ll, ll>;
const ll INF = 0x1fffffffffffffff;
bool chmin(ll& a, ll b){ if(a > b){ a = b; return 1; } return 0; }
bool chmax(ll& a, ll b){ if(a < b){ a = b; return 1; } return 0; }


int main(){
    ll q;
    cin >> q;
    set<array<ll, 2>, greater<>> q1;
    queue<array<ll, 2>> q2;
    ll cnt = 0;
    while(q--){
        ll t;
        cin >> t;
        if(t == 1){
            ll x;
            cin >> x;
            q1.insert({x, ~cnt});
            q2.push({x, ~cnt});
            cnt++;
        }
        else if(t == 2){
            while(1){
                auto a = q2.front();
                q2.pop();
                if(!q1.count(a)) continue;
                q1.erase(a);
                cout << -a[1] << ' ';
                break;
            }
        }
        else{
            auto a = *q1.begin();
            q1.erase(q1.begin());
            cout << -a[1] << ' ';
        }
    }
    cout << endl;
}