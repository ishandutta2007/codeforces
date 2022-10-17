//
// Created by yamunaku on 2019/10/26.
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

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> mti;
typedef vector<ll> vl;
typedef vector<vector<ll>> mtl;

int main(){
    int n, k;
    cin >> n >> k;
    vl a(n);
    rep(i, n){
        cin >> a[i];
    }
    sort(all(a));
    map<ll, pair<ll, ll>> mp;
    rep(i, n){
        vector<pair<int, int>> p;
        ll tmp = a[i];
        repl(j, 2, sqrt(a[i] + 1)){
            if(a[i] % j == 0){
                int co = 0;
                while(a[i] % j == 0){
                    a[i] /= j;
                    co++;
                }
                if(co % k) p.emplace_back(j, co % k);
            }
        }
        if(a[i] > 1) p.emplace_back(a[i], 1);
        bool ok = true;
        ll tar = 1, now = 1;
        for(auto x:p){
            rep(j, x.second) now *= x.first;
            if((k - x.second) * log2(x.first) > log2(200000)){
                ok = false;
                break;
            }
            rep(j, k - x.second) tar *= x.first;
            if(tar > 100000){
                ok = false;
                break;
            }
        }
        if(ok){
            auto itr = mp.find(now);
            if(itr == mp.end()){
                mp[now] = {1, tar};
            }else{
                itr->second.first++;
            }
        }
    }
    ll ans = 0;
    for(auto &now:mp){
        if(now.second.second == now.first) ans += now.second.first * (now.second.first - 1) / 2;
        else{
            if(now.second.second < now.first){
                ans += now.second.first * mp[now.second.second].first;
            }
        }
    }
    cout << ans << endl;
    return 0;
}