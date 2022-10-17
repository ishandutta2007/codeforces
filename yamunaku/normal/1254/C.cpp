//
// Created by yamunaku on 2019/11/19.
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

ll query(int t, int x, int y, int z){
    cout << t SP x + 1 SP y + 1 SP z + 1 << endl;
    ll ans;
    cin >> ans;
    return ans;
}

struct point{
    int id;
    ll s;
};

int main(){
    // CFS;
    int n;
    cin >> n;
    vector<point> a, b;
    repl(i, 2, n){
        if(query(2, 0, 1, i) < 0){
            a.push_back({i, query(1, 0, 1, i)});
        }else{
            b.push_back({i, query(1, 0, 1, i)});
        }
    }
    vector<point> a1, a2, b1, b2;
    ll mas = 0;
    int idxa = -1;
    for(auto &p:a){
        if(p.s > mas){
            idxa = p.id;
            mas = p.s;
        }
    }
    for(auto &p:a){
        if(p.id == idxa) continue;
        if(query(2, 0, idxa, p.id) < 0){
            a1.push_back({p.id, p.s});
        }else{
            a2.push_back({p.id, p.s});
        }
    }
    mas = 0;
    int idxb = -1;
    for(auto &p:b){
        if(p.s > mas){
            idxb = p.id;
            mas = p.s;
        }
    }
    for(auto &p:b){
        if(p.id == idxb) continue;
        if(query(2, 0, idxb, p.id) < 0){
            b1.push_back({p.id, p.s});
        }else{
            b2.push_back({p.id, p.s});
        }
    }
    vi ans;
    if(b.size()>0){
        sort(all(b2),[](point &l, point &r){
            return l.s < r.s;
        });
        for(auto &p:b2){
            ans.push_back(p.id+1);
        }
        ans.push_back(idxb+1);
        sort(all(b1),[](point &l, point &r){
            return l.s > r.s;
        });
        for(auto &p:b1){
            ans.push_back(p.id+1);
        }
    }
    ans.push_back(2);
    if(a.size()>0){
        sort(all(a2),[](point &l, point &r){
            return l.s < r.s;
        });
        for(auto &p:a2){
            ans.push_back(p.id+1);
        }
        ans.push_back(idxa+1);
        sort(all(a1),[](point &l, point &r){
            return l.s > r.s;
        });
        for(auto &p:a1){
            ans.push_back(p.id+1);
        }
    }
    ans.push_back(1);
    reverse(all(ans));
    cout << 0;
    for(auto x:ans){
        cout << " " << x;
    }
    cout << endl;
    return 0;
}