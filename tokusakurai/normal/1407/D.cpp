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
 
struct Graph{
    vector<vector<int>> es;
    vector<int> d;
    const int n;
 
    Graph(int n) : n(n){
        es.resize(n);
        d.resize(n);
    }
 
    void add_edge(int from, int to, bool directed = false){
        es[from].pb(to);
        if(!directed) es[to].pb(from);
    }
 
    int bfs(int s, int t){
        fill(all(d), inf);
        d[s] = 0;
        queue<int> que;
        que.push(s);
        while(!que.empty()){
            int i = que.front(); que.pop();
            for(auto &e: es[i]){
                if(chmin(d[e], d[i]+1)) que.push(e);
            }
        }
        return d[t];
    }
};
 
template<typename Monoid>
struct Segment_Tree{
    using F = function<Monoid(Monoid, Monoid)>;
    int n;
    vector<Monoid> seg;
    const F f;
    const Monoid e1;
    
    Segment_Tree(const vector<Monoid> &v, const F &f, const Monoid &e1) : f(f), e1(e1){
        int m = sz(v);
        n = 1;
        while(n < m) n <<= 1;
        seg.assign(2*n, e1);
        copy(all(v), seg.begin()+n);
        for(int i = n-1; i > 0; i--) seg[i] = f(seg[2*i], seg[2*i+1]);
    }
    
    void change(int i, const Monoid &x){
        seg[i += n] = x;
        while(i >>= 1){
            seg[i] = f(seg[2*i], seg[2*i+1]);
        }
    }
 
    Monoid query(int l, int r) const{
        Monoid ret = e1;
        l += n, r += n;
        while(l < r){
            if(l&1) ret = f(ret, seg[l++]);
            if(r&1) ret = f(ret, seg[--r]);
            l >>= 1, r >>= 1;
        }
        return ret;
    }
 
    Monoid operator [] (int i) const {return seg[n+i];}
 
    template<typename C>
    int find_subtree(int i, const C &check, Monoid &M, bool type) const{
        while(i < n){
            Monoid nxt = type? f(seg[2*i+type], M) : f(M, seg[2*i+type]);
            if(check(nxt)) i = 2*i+type;
            else M = nxt, i = 2*i+(type^1);
        }
        return i-n;
    }
 
    template<typename C>
    int find_first(int l, const C &check) const{
        Monoid L = e1;
        int a = l+n, b = n+n;
        while(a < b){
            if(a&1){
                Monoid nxt = f(L, seg[a]);
                if(check(nxt)) return find_subtree(a, check, L, false);
                L = nxt, a++;
            }
            a >>= 1, b >>= 1;
        }
        return n;
    }
 
    template<typename C>
    int find_last(int r, const C &check) const{
        Monoid R = e1;
        int a = n, b = r+n;
        while(a < b){
            if(b&1 || a == 1){
                Monoid nxt = f(seg[--b], R);
                if(check(nxt)) return find_subtree(b, check, R, true);
                R = nxt;
            }
            a >>= 1, b >>= 1;
        }
        return -1;
    }
};
 
int main(){
    int N;
    cin >> N;
    Graph G(N);
    vector<int> v1(N), v2(N);
    int h[N];
    rep(i, N){
        cin >> h[i];
        v1[i] = h[i], v2[i] = -h[i];
    }
    auto f = [](int a, int b) {return min(a, b);};
    Segment_Tree<int> seg1(v1, f, inf), seg2(v2, f, inf);
    rep(i, N){
        auto c1 = [&](int a) {return a <= h[i];};
        auto c2 = [&](int a) {return a <= -h[i];};
        int l1 = seg1.find_last(i, c1), l2 = seg2.find_last(i, c2);
        if(l1 >= 0) G.add_edge(l1, i, true);
        if(l2 >= 0) G.add_edge(l2, i, true);
        int r1 = seg1.find_first(i+1, c1), r2 = seg2.find_first(i+1, c2);
        if(r1 < N) G.add_edge(i, r1, true);
        if(r2 < N) G.add_edge(i, r2, true);
    }
    cout << G.bfs(0, N-1) << endl;
}