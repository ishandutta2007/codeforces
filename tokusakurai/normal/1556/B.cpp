#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define each(e, v) for(auto &e: v)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const int MOD = 1000000007;
//const int MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

struct io_setup{
    io_setup(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout << fixed << setprecision(15);
    }
} io_setup;

template<typename T>
struct Binary_Indexed_Tree{
    vector<T> bit;
    const int n;
    
    Binary_Indexed_Tree(const vector<T> &v) : n((int)v.size()){
        bit.resize(n+1);
        copy(begin(v), end(v), begin(bit)+1);
        for(int a = 2; a <= n; a <<= 1){
            for(int b = a; b <= n; b += a){
                bit[b] += bit[b-a/2];
            }
        }
    }

    Binary_Indexed_Tree(int n, const T &x) : n(n){
        bit.resize(n+1);
        vector<T> v(n, x);
        copy(begin(v), end(v), begin(bit)+1);
        for(int a = 2; a <= n; a <<= 1){
            for(int b = a; b <= n; b += a){
                bit[b] += bit[b-a/2];
            }
        }
    }
    
    void add(int i, const T &x){
        for(i++; i <= n; i += (i & -i)) bit[i] += x;
    }

    void change(int i, const T&x){
        add(i, x-query(i, i+1));
    }
    
    T sum(int i) const{
        T ret = 0;
        for(; i > 0; i -= (i & -i)) ret += bit[i];
        return ret;
    }
    
    T query(int l, int r) const{
        return sum(r) - sum(l);
    }

    T operator [] (int i) const {return query(i, i+1);}

    int lower_bound(T x) const{
        int ret = 0;
        for(int k = 31-__builtin_clz(n); k >= 0; k--){
            if(ret+(1<<k) <= n && bit[ret+(1<<k)] < x) x -= bit[ret += (1<<k)]; 
        }
        return ret;
    }

    int upper_bound(T x) const{
        int ret = 0;
        for(int k = 31-__builtin_clz(n); k >= 0; k--){
            if(ret+(1<<k) <= n && bit[ret+(1<<k)] <= x) x -= bit[ret += (1<<k)]; 
        }
        return ret;
    }
};

template<typename T>
long long inversion_number(vector<T> a){
    int n = a.size();
    vector<int> v(n);
    iota(begin(v), end(v), 0);
    sort(begin(v), end(v), [&](int i, int j){
        if(a[i] != a[j]) return a[i] < a[j];
        return i < j;
    });
    Binary_Indexed_Tree<int> bit(vector<int>(n, 0));
    long long ret = 0;
    for(int i = 0; i < n; i++){
        ret += bit.query(v[i]+1, n);
        bit.add(v[i], 1);
    }
    return ret;
}

long long inversion_number(vector<int> a, int m){
    int n = a.size();
    Binary_Indexed_Tree<int> bit(vector<int>(m, 0));
    long long ret = 0;
    for(int i = 0; i < n; i++){
        ret += bit.query(a[i]+1, m);
        bit.add(a[i], 1);
    }
    return ret;
}

int main(){
    int T; cin >> T;

    while(T--){
        int N; cin >> N;

        vector<int> a(N);
        rep(i, N) cin >> a[i];

        rep(i, N) a[i] &= 1;

        vector<int> id1, id2;
        rep(i, N){
            if(a[i] == 0) id2.eb(i);
            else id1.eb(i);
        }

        int n = sz(id1), m = sz(id2);
        if(abs(n-m) > 1){
            cout << "-1\n";
            continue;;
        }

        ll ans = INF;

        if(n >= m){
            vector<int> v;
            rep(i, N){
                if(i&1) v.eb(id2[i/2]);
                else v.eb(id1[i/2]);
            }
            chmin(ans, inversion_number(v));
        }
        if(n <= m){
            vector<int> v;
            rep(i, N){
                if(i&1) v.eb(id1[i/2]);
                else v.eb(id2[i/2]);
            }
            chmin(ans, inversion_number(v));
        }

        cout << ans << '\n';
    }
}