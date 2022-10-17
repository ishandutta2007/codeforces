//
// Created by yamunaku on 2019/11/24.
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

struct que{
    int k;
    int pos;
    int id;
    int ans = -1;
};

struct SegmentTree{

    inline void updatef(pair<int, int> &x, pair<int, int> y){
        x = y;
    }

    inline pair<int, int> mergef(pair<int, int> &x, pair<int, int> &y){
        return {x.first + y.first, -1};
    }

    int n;
    vector<pair<int, int>> node;

    SegmentTree(int sz){
        n = 1;
        while(n < sz) n <<= 1;
        node.resize(2 * n - 1, {0, -1});
    }

    void update(int k, int x){
        k += n - 1;
        updatef(node[k], {1, x});
        while(k){
            k = (k - 1) / 2;
            node[k] = mergef(node[2 * k + 1], node[2 * k + 2]);
        }
    }

    int get(int x, int k = 0){
        if(k >= n - 1) return node[k].second;
        if(x <= node[2 * k + 1].first){
            return get(x, 2 * k + 1);
        }else{
            return get(x - node[2 * k + 1].first, 2 * k + 2);
        }
    }
};

int main(){
     CFS;
    int n;
    cin >> n;
    vi a(n);
    vector<pair<int, int>> v(n);
    rep(i, n){
        cin >> a[i];
        v[i] = {-a[i], i};
    }
    sort(all(v));
    int q;
    cin >> q;
    vector<que> query(q);
    rep(i, q){
        cin >> query[i].k >> query[i].pos;
        query[i].id = i;
        query[i].ans = -1;
    }
    sort(all(query), [](que &l, que &r){
        return l.k < r.k;
    });
    int now = 0;
    SegmentTree seg(n);
    rep(i, q){
        while(now < query[i].k){
            seg.update(v[now].second, -v[now].first);
            now++;
        }
        query[i].ans = seg.get(query[i].pos);
    }
    sort(all(query), [](que &l, que &r){
        return l.id < r.id;
    });
    rep(i, q){
        cout << query[i].ans << endl;
    }
    return 0;
}