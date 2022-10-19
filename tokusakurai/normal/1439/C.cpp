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
struct Node{
    int l, r;
    vector<T> v, s;
    T base;

    Node(int l, int r, const vector<T> &v) : l(l), r(r), v(v), base(-INF){
        s.resize(r-l+1);
        recalc();
    }

    void recalc(){
        s[r-l] = 0;
        rep3(i, r-l-1, 0) s[i] = s[i+1]+v[i];
    }

    T get(int i){
        return base == -INF? v[i] : base;
    }

    void update(){
        rep(i, r-l) v[i] = get(i);
        base = -INF;
    }

    void rmq(int R, const T &x){
        if(R <= l) return;
        R -= l, chmin(R, r-l);
        if(get(R-1) >= x) return;
        if(R == r-l){
            if(x >= get(0)) {base = x; return;}
            update();
            rep(i, R) chmax(v[i], x);
            recalc();
            return;
        }
        update();
        rep(i, R) chmax(v[i], x);
        recalc();
    }

    T rsq(int L){
        if(L >= r) return 0;
        L -= l, chmax(L, 0);
        return base == -INF? s[L] : base*(r-l-L); 
    }
};

template<typename T>
struct Data{
    int n, m;
    vector<Node<T>> nodes;
    vector<T> s;

    Data(int n, const vector<T> &v) : n(n){
        m = 0;
        while(m*m < n) m++;
        rep(i, m){
            int l = min(n, m*i), r = min(n, m*(i+1));
            nodes.eb(l, r, vector<T>(begin(v)+l, begin(v)+r));
        }
        s.resize(m+1), rmq(n, 0);
    }

    void rmq(int R, const T &x){
        each(e, nodes) e.rmq(R, x);
        s[m] = 0;
        rep3(i, m-1, 0) s[i] = s[i+1]+nodes[i].rsq(0);
    }

    T rsq(int L){
        int k = L/m+1;
        return s[k]+nodes[k-1].rsq(L);
    }

    T get(int i){
        return nodes[i/m].get(i%m);
    }
};

int main(){
    int N, Q;
    cin >> N >> Q;
    vector<ll> a(N);
    rep(i, N) cin >> a[i];
    Data<ll> D(N, a);
    while(Q--){
        int q, x; ll y; cin >> q >> x >> y;
        if(q == 1){
            D.rmq(x, y);
            //rep(i, N) cout << D.rsq(i) << ' '; cout << '\n';
        }
        else{
            x--;
            int ans = 0;
            while(x < N){
                int l = x-1, r = N; //(l,r]
                while(r-l > 1){
                    int m = (l+r)/2;
                    (D.get(m) <= y? r : l) = m;
                }
                if(r == N) break;
                x = r;
                ll S = D.rsq(x);
                l = x+1, r = N+1; //[l,r)
                while(r-l > 1){
                    int m = (l+r)/2;
                    (D.rsq(m) >= S-y? l : r) = m;
                }
                ans += l-x, x = l, y -= S-D.rsq(l);
            }
            cout << ans << '\n';
        }
    }
}