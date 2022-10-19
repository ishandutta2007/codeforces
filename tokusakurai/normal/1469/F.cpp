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
    
    Binary_Indexed_Tree(const vector<T> &v) : n(sz(v)){
        bit.resize(n+1);
        copy(all(v), bit.begin()+1);
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

    int upper_bound(T x) const {return lower_bound(x+1);}
};

int main(){
    int N; ll K;
    cin >> N >> K;
    vector<ll> L(N);
    rep(i, N) cin >> L[i];

    ll S = accumulate(all(L), 0LL)-2*N+1;
    if(S < K) {cout << "-1\n"; return 0;}

    sort(rall(L));
    rep(i, N) L[i]--;

    int l = 0, r = 1<<20; //(l, r]
    while(r-l > 1){
        int m = (l+r)/2;
        Binary_Indexed_Tree<ll> bit(vector<ll>(m+1, 0));
        bit.add(0, 1), bit.add(1, -1);
        bool flag = false;
        int ptr = 0;
        ll now = 1;

        rep(i, N){
            if(now >= K) {flag = true; break;}
            while(ptr <= m && bit.query(0, ptr+1) == 0) ptr++;
            if(ptr > m) break;

            now -= 1;
            bit.add(ptr, -1), bit.add(ptr+1, 1);

            int x = L[i]/2;
            int s = ptr+2, t = ptr+x+2;
            chmin(t, m+1);
            
            if(s < t) bit.add(s, 2), bit.add(t, -2), now += (t-s)*2;
            if(ptr+x+2 <= m && L[i]%2 == 1) bit.add(ptr+x+2, 1), bit.add(ptr+x+3, -1), now++;
        }

        if(now >= K) flag = true;

        if(flag) r = m;
        else l = m;
    }

    cout << r << '\n';
}