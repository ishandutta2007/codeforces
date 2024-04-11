//
// Created by yamunaku on 2020/05/12.
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
    CFS;
    int n;
    cin >> n;
    vi a(n);
    map<int, vector<int>> mp;
    rep(i, n){
        cin >> a[i];
        int tmp = a[i];
        for(int j = 2; j <= sqrt(tmp) + 1; j++){
            if(tmp % j == 0){
                int c = 0;
                while(tmp % j == 0){
                    tmp /= j;
                    c++;
                }
                mp[j].push_back(c);
            }
        }
        if(tmp > 1){
            mp[tmp].push_back(1);
        }
    }
    ll ans = 1;
    for(auto &p:mp){
        auto &v = p.second;
        if(v.size() <= n - 2) continue;
        if(v.size() == n - 1) v.push_back(0);
        sort(all(v));
        int mi = v[1];
        rep(i, mi) ans *= p.first;
    }
    cout << ans << endl;
    return 0;
}