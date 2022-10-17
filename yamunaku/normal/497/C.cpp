//
// Created by yamunaku on 2019/08/13.
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

struct aaa{
    int l;
    int r;
    int type;
    int k;
    int id;
};

int main(){
    CFS;
    vector<aaa> v;
    int n;
    cin >> n;
    int l, r;
    rep(i, n){
        cin >> l >> r;
        v.push_back({l, r, 1, 0, i});
    }
    int m;
    cin >> m;
    int k;
    rep(i, m){
        cin >> l >> r >> k;
        v.push_back({l, r, 0, k, i});
    }
    sort(all(v), [](aaa &l, aaa &r){
        return l.l == r.l ? l.type < r.type : l.l < r.l;
    });
    multimap<int, pair<int, int>> mp;
    vector<int> ans(n);
    rep(i, n + m){
        if(v[i].type == 0){
            mp.insert({v[i].r, {v[i].k, v[i].id}});
        }else{
            auto itr = mp.lower_bound(v[i].r);
            while(1){
                if(itr == mp.end()){
                    cout << "NO" << endl;
                    return 0;
                }
                if(itr->second.first > 0) break;
                itr = mp.erase(itr);
            }
            itr->second.first--;
            ans[v[i].id] = itr->second.second;
        }
    }
    cout << "YES" << endl;
    rep(i, n){
        cout << ans[i]+1 << " ";
    }
    cout << endl;
    return 0;
}