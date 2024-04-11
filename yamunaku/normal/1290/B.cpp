//
// Created by yamunaku on 2020/02/02.
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

struct SegmentTree{
    int ide = 0;

    inline void updatef(int &x, int y){
        x = y;
    }

    inline int queryf(int x, int y){
        return x | y;
    }

    int n;
    vector<int> node;

    SegmentTree(int sz){
        n = 1;
        while(n < sz) n <<= 1;
        node.resize(2 * n - 1, ide);
    }

    void update(int k, int x){
        k += n - 1;
        updatef(node[k], x);
        while(k){
            k = (k - 1) / 2;
            node[k] = queryf(node[2 * k + 1], node[2 * k + 2]);
        }
    }

    int get(int a, int b, int k = 0, int l = 0, int r = -1){
        if(r < 0)r = n;
        if(r <= a || b <= l) return ide;
        if(a <= l && r <= b) return node[k];
        int xl = get(a, b, 2 * k + 1, l, (l + r) / 2);
        int xr = get(a, b, 2 * k + 2, (l + r) / 2, r);
        return queryf(xl, xr);
    }
};

int main(){
    CFS;
    string s;
    cin >> s;
    int n = s.size();
    SegmentTree seg(n);
    rep(i, n){
        seg.update(i, 1 << ((int) (s[i] - 'a')));
    }
    int q;
    cin >> q;
    rep(_, q){
        int l, r;
        cin >> l >> r;
        l--;
        int x = seg.get(l, r);
        int c = 0;
        while(x){
            if(x & 1) c++;
            x >>= 1;
        }
        if(c > 2){
            CYES;
        }else{
            if(r - l == 1) CYES;
            else if(s[l] != s[r - 1]) CYES;
            else CNO;
        }
    }
    return 0;
}