//
// Created by yamunaku on 2020/02/24.
//

#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define repl(i, l, r) for(int i = (l); i < (r); i++)
#define per(i, n) for(int i = ((n)-1); i >= 0; i--)
#define perl(i, l, r) for(int i = ((r)-1); i >= (l); i--)
#define all(x) (x).begin(),(x).end()
#define MOD9 998244353
#define MOD1 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000
#define SP <<" "<<
#define CYES cout<<"Yes"<<endl
#define CNO cout<<"No"<<endl
#define CFS cin.tie(0);ios::sync_with_stdio(false)
#define CST(x) cout<<fixed<<setprecision(x)

using ll = long long;
using ld = long double;
using vi = vector<int>;
using mti = vector<vector<int>>;
using vl = vector<ll>;
using mtl = vector<vector<ll>>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
template<typename T>
using heap = priority_queue<T, vector<T>, function<bool(const T, const T)>>;

int main(){
    //CFS;
    int n;
    cin >> n;
    vector<pair<int, int>> p(n);
    rep(i, n){
        cin >> p[i].first;
    }
    rep(i,n) cin >> p[i].second;
    sort(all(p));
    heap<int> q([](const int l, const int r){
        return l < r;
    });
    int now = 0;
    ll ans = 0;
    ll sum = 0;
    rep(i, n){
        int k = p[i].first - now;
        rep(_, k){
            if(q.empty()) break;
            sum -= q.top();
            ans += sum;
            q.pop();
        }
        q.push(p[i].second);
        sum += p[i].second;
        now = p[i].first;
    }
    while(!q.empty()){
        sum -= q.top();
        ans += sum;
        q.pop();
    }
    cout << ans << endl;
    return 0;
}