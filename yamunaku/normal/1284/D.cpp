//
// Created by yamunaku on 2020/01/04.
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

struct StarrySkyTree{
private:
    int n;
    vector<ll> node, lazy;

public:
    StarrySkyTree(int sz){
        n = 1;
        while(n < sz) n *= 2;
        node.resize(2 * n - 1, 0);
        lazy.resize(2 * n - 1, 0);
        // for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        // for(int i=n-2; i>=0; i--) node[i] = node[i*2+1] + node[i*2+2];
    }

    void eval(int k, int l, int r){
        if(lazy[k] != 0){
            node[k] += lazy[k];
            if(r - l > 1){
                lazy[2 * k + 1] += lazy[k];
                lazy[2 * k + 2] += lazy[k];
            }
            lazy[k] = 0;
        }
    }

    void add(int a, int b, ll x, int k = 0, int l = 0, int r = -1){
        if(r < 0) r = n;
        eval(k, l, r);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b){
            lazy[k] += x;
            eval(k, l, r);
        }else{
            add(a, b, x, 2 * k + 1, l, (l + r) / 2);
            add(a, b, x, 2 * k + 2, (l + r) / 2, r);
            node[k] = max(node[2 * k + 1], node[2 * k + 2]);
        }
    }

    ll getmax(int a, int b, int k = 0, int l = 0, int r = -1){
        if(r < 0) r = n;
        if(b <= l || r <= a) return 0;
        eval(k, l, r);
        if(a <= l && r <= b) return node[k];
        ll vl = getmax(a, b, 2 * k + 1, l, (l + r) / 2);
        ll vr = getmax(a, b, 2 * k + 2, (l + r) / 2, r);
        return max(vl, vr);
    }
};


int main(){
    CFS;
    int n;
    cin >> n;
    map<int, int> mp;
    vi as(n), ae(n), bs(n), be(n);
    rep(i, n){
        cin >> as[i] >> ae[i] >> bs[i] >> be[i];
        ae[i]++, be[i]++;
        mp[as[i]] = mp[ae[i]] = mp[bs[i]] = mp[be[i]] = 0;
    }
    int sz = 0;
    for(auto &p:mp) p.second = sz++;
    vector<pair<int, int>> q1, q2;
    rep(i, n){
        as[i] = mp[as[i]];
        ae[i] = mp[ae[i]];
        bs[i] = mp[bs[i]];
        be[i] = mp[be[i]];
        q1.emplace_back(as[i], i + 1);
        q1.emplace_back(ae[i], -(i + 1));
        q2.emplace_back(bs[i], i + 1);
        q2.emplace_back(be[i], -(i + 1));
    }
    sort(all(q1));
    sort(all(q2));
    StarrySkyTree seg1(sz), seg2(sz);
    int c = 0;
    rep(i, 2 * n){
        if(q1[i].second > 0){
            q1[i].second--;
            seg1.add(bs[q1[i].second], be[q1[i].second], 1);
            c++;
        }else{
            q1[i].second = -q1[i].second - 1;
            seg1.add(bs[q1[i].second], be[q1[i].second], -1);
            c--;
        }
        if(i == 2 * n - 1){
            if(seg1.getmax(0, sz) < c){
                CNO;
                return 0;
            }
        }else if(q1[i].first < q1[i + 1].first){
            if(seg1.getmax(0, sz) < c){
                CNO;
                return 0;
            }
        }
    }
    rep(i, 2 * n){
        if(q2[i].second > 0){
            q2[i].second--;
            seg2.add(as[q2[i].second], ae[q2[i].second], 1);
            c++;
        }else{
            q2[i].second = -q2[i].second - 1;
            seg2.add(as[q2[i].second], ae[q2[i].second], -1);
            c--;
        }
        if(i == 2 * n - 1){
            if(seg2.getmax(0, sz) < c){
                CNO;
                return 0;
            }
        }else if(q2[i].first < q2[i + 1].first){
            if(seg2.getmax(0, sz) < c){
                CNO;
                return 0;
            }
        }
    }
    CYES;
    return 0;
}