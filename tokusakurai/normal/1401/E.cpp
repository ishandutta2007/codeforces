#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1000000007;
//const ll MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const double pi = acos(-1.0);
const double EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

template<typename T>
struct Binary_Indexed_Tree{
    vector<T> bit;
    
    Binary_Indexed_Tree(int N){
        bit.assign(N+1, 0);
    }
    
    void add(int i, const T &x){
        for(i++; i < sz(bit); i += (i & -i)) bit[i] += x;
    }
    
    T sum(int i){
        T ret = 0;
        for(; i > 0; i -= (i & -i)) ret += bit[i];
        return ret;
    }
    
    T query(int l, int r){
        return sum(r) - sum(l);
    }
    
    void clear(){
        fill(bit.begin(), bit.end(), 0);
    }
};

int main(){
    int N, M;
    cin >> N >> M;
    int MAX = 1000000;
    int y[N], lx[N], rx[N], x[M], ly[M], ry[M];
    vector<int> stx[MAX+1], enx[MAX+1], idy[MAX+1];
    rep(i, N){
        cin >> y[i] >> lx[i] >> rx[i];
        stx[lx[i]].pb(i), enx[rx[i]].pb(i);
    }
    rep(i, M){
        cin >> x[i] >> ly[i] >> ry[i];
        idy[x[i]].pb(i);
    }

    Binary_Indexed_Tree<int> bit(MAX+1);
    ll ans = 1;
    rep(i, MAX+1){
        for(auto &e: stx[i]){
            if(lx[e] == 0 && rx[e] == MAX) ans++;
            bit.add(y[e], 1);
        }
        for(auto &e: idy[i]){
            if(ly[e] == 0 && ry[e] == MAX) ans++;
            ans += bit.query(ly[e], ry[e]+1);
        }
        for(auto &e: enx[i]){
            bit.add(y[e], -1);
        }
    }
    cout << ans << endl;
}