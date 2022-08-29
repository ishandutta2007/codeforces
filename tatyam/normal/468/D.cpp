#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using uint = unsigned;
using pcc = pair<char, char>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;
using tuplis = array<ll, 3>;
template<class T> using pq = priority_queue<T, vector<T>, greater<T>>;
const ll LINF=0x1fffffffffffffff;
const ll MINF=0x7fffffffffff;
const int INF=0x3fffffff;
const int MOD=1000000007;
const int MODD=998244353;
const ld DINF=numeric_limits<ld>::infinity();
const ld EPS=1e-9;
const ld PI=3.1415926535897932;
const ll dx[] = {0, 1, 0, -1, 1, -1, 1, -1};
const ll dy[] = {1, 0, -1, 0, 1, 1, -1, -1};
#define overload4(_1,_2,_3,_4,name,...) name
#define overload3(_1,_2,_3,name,...) name
#define rep1(n) for(ll i=0;i<n;++i)
#define rep2(i,n) for(ll i=0;i<n;++i)
#define rep3(i,a,b) for(ll i=a;i<b;++i)
#define rep4(i,a,b,c) for(ll i=a;i<b;i+=c)
#define rep(...) overload4(__VA_ARGS__,rep4,rep3,rep2,rep1)(__VA_ARGS__)
#define rrep1(n) for(ll i=n;i--;)
#define rrep2(i,n) for(ll i=n;i--;)
#define rrep3(i,a,b) for(ll i=b;i-->(a);)
#define rrep4(i,a,b,c) for(ll i=(a)+((b)-(a)-1)/(c)*(c);i>=(a);i-=c)
#define rrep(...) overload4(__VA_ARGS__,rrep4,rrep3,rrep2,rrep1)(__VA_ARGS__)
#define each1(i,a) for(auto&&i:a)
#define each2(x,y,a) for(auto&&[x,y]:a)
#define each3(x,y,z,a) for(auto&&[x,y,z]:a)
#define each(...) overload4(__VA_ARGS__,each3,each2,each1)(__VA_ARGS__)
#define all1(i) begin(i),end(i)
#define all2(i,a) begin(i),begin(i)+a
#define all3(i,a,b) begin(i)+a,begin(i)+b
#define all(...) overload3(__VA_ARGS__,all3,all2,all1)(__VA_ARGS__)
#define rall1(i) (i).rbegin(),(i).rend()
#define rall2(i,k) (i).rbegin(),(i).rbegin()+k
#define rall3(i,a,b) (i).rbegin()+a,(i).rbegin()+b
#define rall(...) overload3(__VA_ARGS__,rall3,rall2,rall1)(__VA_ARGS__)
#define sum(...) accumulate(all(__VA_ARGS__),0LL)
#define dsum(...) accumulate(all(__VA_ARGS__),0.0L)
#define Msum(...) accumulate(all(__VA_ARGS__),0_M)
#define elif else if
#define unless(a) if(!(a))
#define INT(...) int __VA_ARGS__;in(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__;in(__VA_ARGS__)
#define ULL(...) ull __VA_ARGS__;in(__VA_ARGS__)
#define STR(...) string __VA_ARGS__;in(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__;in(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__;in(__VA_ARGS__)
#define LD(...) ld __VA_ARGS__;in(__VA_ARGS__)
#define Sort(a) sort(all(a))
#define Rev(a) reverse(all(a))
#define Uniq(a) sort(all(a));a.erase(unique(all(a)),end(a))
#define vec(type,name,...) vector<type>name(__VA_ARGS__)
#define VEC(type,name,size) vector<type>name(size);in(name)
#define vv(type,name,h,...) vector<vector<type>>name(h,vector<type>(__VA_ARGS__))
#define VV(type,name,h,w) vector<vector<type>>name(h,vector<type>(w));in(name)
#define vvv(type,name,h,w,...) vector<vector<vector<type>>>name(h,vector<vector<type>>(w,vector<type>(__VA_ARGS__)))
template<class T> auto min(const T& a){ return *min_element(all(a)); }
template<class T> auto max(const T& a){ return *max_element(all(a)); }
inline ll popcnt(ull a){ return __builtin_popcountll(a); }
ll gcd(ll a, ll b){ while(b){ ll c = b; b = a % b; a = c; } return a; }
ll lcm(ll a, ll b){ if(!a || !b) return 0; return a * b / gcd(a, b); }
ll intpow(ll a, ll b){ ll ans = 1; while(b){ if(b & 1) ans *= a; a *= a; b /= 2; } return ans; }
ll modpow(ll a, ll b, ll p){ ll ans = 1; while(b){ if(b & 1) (ans *= a) %= p; (a *= a) %= p; b /= 2; } return ans; }
template<class T> bool chmin(T& a, const T& b){ if(a > b){ a = b; return 1; } return 0; }
template<class T> bool chmax(T& a, const T& b){ if(a < b){ a = b; return 1; } return 0; }
template<class T, class U> bool chmin(T& a, const U& b){ if(a > T(b)){ a = b; return 1; } return 0; }
template<class T, class U> bool chmax(T& a, const U& b){ if(a < T(b)){ a = b; return 1; } return 0; }
vector<ll> iota(ll n, ll begin = 0){ vector<ll> a(n); iota(a.begin(), a.end(), begin); return a; }
vector<pll> factor(ull x){ vector<pll> ans; for(ull i = 2; i * i <= x; i++) if(x % i == 0){ ans.push_back({i, 1}); while((x /= i) % i == 0) ans.back().second++; } if(x != 1) ans.push_back({x, 1}); return ans; }
map<ll,ll> factor_map(ull x){ map<ll,ll> ans; for(ull i = 2; i * i <= x; i++) if(x % i == 0){ ans[i] = 1; while((x /= i) % i == 0) ans[i]++; } if(x != 1) ans[x] = 1; return ans; }
vector<ll> divisor(ull x){ vector<ll> ans; for(ull i = 1; i * i <= x; i++) if(x % i == 0) ans.push_back(i); rrep(ans.size() - (ans.back() * ans.back() == x)) ans.push_back(x / ans[i]); return ans; }
template<class T> unordered_map<T, ll> press(vector<T> a){ Uniq(a); unordered_map<T, ll> ans; rep(a.size()) ans[a[i]] = i; return ans; }
template<class T> map<T, ll> press_map(vector<T> a){ Uniq(a); map<T, ll> ans; rep(a.size()) ans[a[i]] = i; return ans; }
int scan(){ return getchar(); }
void scan(int& a){ scanf("%d", &a); }
void scan(unsigned& a){ scanf("%u", &a); }
void scan(long& a){ scanf("%ld", &a); }
void scan(long long& a){ scanf("%lld", &a); }
void scan(unsigned long long& a){ scanf("%llu", &a); }
void scan(char& a){ do{ a = getchar(); }while(a == ' ' || a == '\n'); }
void scan(float& a){ scanf("%f", &a); }
void scan(double& a){ scanf("%lf", &a); }
void scan(long double& a){ scanf("%Lf", &a); }
void scan(vector<bool>& a){ for(unsigned i = 0; i < a.size(); i++){ int b; scan(b); a[i] = b; } }
void scan(char a[]){ scanf("%s", a); }
void scan(string& a){ cin >> a; }
template<class T> void scan(vector<T>&);
template<class T, size_t size> void scan(array<T, size>&);
template<class T, class L> void scan(pair<T, L>&);
template<class T, size_t size> void scan(T(&)[size]);
template<class T> void scan(vector<T>& a){ for(auto&& i : a) scan(i); }
template<class T> void scan(deque<T>& a){ for(auto&& i : a) scan(i); }
template<class T, size_t size> void scan(array<T, size>& a){ for(auto&& i : a) scan(i); }
template<class T, class L> void scan(pair<T, L>& p){ scan(p.first); scan(p.second); }
template<class T, size_t size> void scan(T (&a)[size]){ for(auto&& i : a) scan(i); }
template<class T> void scan(T& a){ cin >> a; }
void in(){}
template <class Head, class... Tail> void in(Head& head, Tail&... tail){ scan(head); in(tail...); }
void print(){ putchar(' '); }
void print(bool a){ printf("%d", a); }
void print(int a){ printf("%d", a); }
void print(unsigned a){ printf("%u", a); }
void print(long a){ printf("%ld", a); }
void print(long long a){ printf("%lld", a); }
void print(unsigned long long a){ printf("%llu", a); }
void print(char a){ printf("%c", a); }
void print(char a[]){ printf("%s", a); }
void print(const char a[]){ printf("%s", a); }
void print(float a){ printf("%.15f", a); }
void print(double a){ printf("%.15f", a); }
void print(long double a){ printf("%.15Lf", a); }
void print(const string& a){ for(auto&& i : a) print(i); }
template<class T> void print(const complex<T>& a){ if(a.real() >= 0) print('+'); print(a.real()); if(a.imag() >= 0) print('+'); print(a.imag()); print('i'); }
template<class T> void print(const vector<T>&);
template<class T, size_t size> void print(const array<T, size>&);
template<class T, class L> void print(const pair<T, L>& p);
template<class T, size_t size> void print(const T (&)[size]);
template<class T> void print(const vector<T>& a){ if(a.empty()) return; print(a[0]); for(auto i = a.begin(); ++i != a.end(); ){ putchar(' '); print(*i); } }
template<class T> void print(const deque<T>& a){ if(a.empty()) return; print(a[0]); for(auto i = a.begin(); ++i != a.end(); ){ putchar(' '); print(*i); } }
template<class T, size_t size> void print(const array<T, size>& a){ print(a[0]); for(auto i = a.begin(); ++i != a.end(); ){ putchar(' '); print(*i); } }
template<class T, class L> void print(const pair<T, L>& p){ print(p.first); putchar(' '); print(p.second); }
template<class T, size_t size> void print(const T (&a)[size]){ print(a[0]); for(auto i = a; ++i != end(a); ){ putchar(' '); print(*i); } }
template<class T> void print(const T& a){ cout << a; }
int out(){ putchar('\n'); return 0; }
template<class T> int out(const T& t){ print(t); putchar('\n'); return 0; }
template<class Head, class... Tail> int out(const Head& head, const Tail&... tail){ print(head); putchar(' '); out(tail...); return 0; }
#ifdef DEBUG
inline ll __lg(ull x){ return 63 - __builtin_clzll(x); }
#define debug(...) { print(#__VA_ARGS__); print(":"); out(__VA_ARGS__); }
#else
#define debug(...) void(0)
#endif
int first(bool i = true){ return out(i?"first":"second"); }
int First(bool i = true){ return out(i?"First":"Second"); }
int yes(bool i = true){ return out(i?"yes":"no"); }
int Yes(bool i = true){ return out(i?"Yes":"No"); }
int No(){ return out("No"); }
int YES(bool i = true){ return out(i?"YES":"NO"); }
int NO(){ return out("NO"); }
int Yay(bool i = true){ return out(i?"Yay!":":("); }
int possible(bool i = true){ return out(i?"possible":"impossible"); }
int Possible(bool i = true){ return out(i?"Possible":"Impossible"); }
int POSSIBLE(bool i = true){ return out(i?"POSSIBLE":"IMPOSSIBLE"); }
void Case(ll i){ printf("Case #%lld: ", i); }


struct WeightedEdge{
    ll to, cost;
    WeightedEdge(){}
    WeightedEdge(ll to, ll cost): to(to), cost(cost){}
    operator ll() const { return to; }
};
struct WeightedGraph{
    using E = WeightedEdge;
    vector<vector<E>> g;
    WeightedGraph(){}
    WeightedGraph(ll n): g(n){}
    vector<E>& operator[](ll at){ return g[at]; }
    operator vector<vector<E>>&(){ return g; }
    auto begin(){ return g.begin(); }
    auto end(){ return g.end(); }
    auto begin() const { return g.cbegin(); }
    auto end() const { return g.cend(); }
    ll size() const { return g.size(); }
    void resize(ll n){ g.resize(n); }
    const vector<E>& operator[](ll at) const { return g[at]; }
    operator const vector<vector<E>>&() const { return g; }
    void add_edge(ll a, ll b, ll cost){
        g[a].emplace_back(b, cost);
        g[b].emplace_back(a, cost);
    }
    void add_directed_edge(ll from, ll to, ll cost){
        g[from].emplace_back(to, cost);
    }
    template<ll start_index = 1> void input_graph(ll m){
        while(m--){
            ll a, b, c;
            scanf("%lld%lld%lld", &a, &b, &c);
            a -= start_index;
            b -= start_index;
            g[a].emplace_back(b, c);
            g[b].emplace_back(a, c);
        }
    }
    template<ll start_index = 1> void input_directed_graph(ll m){
        while(m--){
            ll a, b, c;
            scanf("%lld%lld%lld", &a, &b, &c);
            a -= start_index;
            b -= start_index;
            g[a].emplace_back(b, c);
        }
    }
    template<ll start_index = 1> void input_tree(ll n = -1){ if(n == -1) n = g.size(); input_graph<start_index>(n - 1); }
};
template<class T>
struct SegmentTree{
    virtual T f(const T&, const T&) const = 0;
    const T def_value;
    ll size = 1, rank = 0, expected_size;
    vector<T> data;
    SegmentTree(ll n, const T& def_value): def_value(def_value), expected_size(n){
        while(size < expected_size){
            size *= 2;
            rank++;
        }
        data.assign(size * 2, def_value);
    }
    SegmentTree(const vector<T>& v, const T& def_value): def_value(def_value), expected_size(v.size()){
        while(size < expected_size){
            size *= 2;
            rank++;
        }
        data.assign(size * 2, def_value);
        for(ll i = 0; i < v.size(); i++) data[size + i] = v[i];
        // for(ll i = Base::size; --i;) Base::data[i] = f(Base::data[i * 2], Base::data[i * 2 + 1]);
    }
    T operator[](ll at) const {
        return data[size + at];
    }
    void update(ll at){
        while(at /= 2) data[at] = f(data[at * 2], data[at * 2 + 1]);
    }
    void set(ll at, const T& val){
        at += size;
        data[at] = val;
        update(at);
    }
    void add(ll at, const T& val){
        at += size;
        data[at] += val;
        update(at);
    }
    T get(ll l, ll r) const {
        T L = def_value, R = def_value;
        l += size; r += size;
        for(; l < r; l /= 2, r /= 2){
            if(l & 1) L = f(L, data[l++]);
            if(r & 1) R = f(data[--r], R);
        }
        return f(L, R);
    }
    template<class F> ll find_last(const F& check, ll l = 0) const { // max x  s.t. check(get(l, x)) == true
        if(l == expected_size) return expected_size;
        ll height = 0, at = l + size;
        T val = def_value;
        for(; height <= rank; height++) if(at >> height & 1){
            T val2 = f(val, data[at >> height]);
            if(check(val2)){
                at += 1 << height;
                if(at == size * 2) return expected_size;
                val = val2;
            }
            else break;
        }
        for(; height--; ){
            T val2 = f(val, data[at >> height]);
            if(check(val2)){
                at += 1 << height;
                if(at == size * 2) return expected_size;
                val = val2;
            }
        }
        return min(at - size, expected_size);
    }
    template<class F> ll find_first(const F& check, ll r) const { // min x  s.t. check(get(x, r)) == true
        if(!r) return 0;
        ll height = 0, at = r + size;
        T val = def_value;
        for(; height <= rank; height++) if(at >> height & 1){
            T val2 = f(val, data[at >> height ^ 1]);
            if(check(val2)){
                at -= 1 << height;
                if(at == size) return 0;
                val = val2;
            }
            else break;
        }
        for(; height--; ){
            T val2 = f(val, data[(at >> height) - 1]);
            if(check(val2)){
                at -= 1 << height;
                if(at == size) return 0;
                val = val2;
            }
        }
        return at - size;
    }
    void clear(){
        for(auto& i : data) i = def_value;
    }
};
struct RmQ : SegmentTree<array<pll, 2>>{
    using T = array<pll, 2>;
    using Base = SegmentTree<T>;
    T f(const T& a, const T& b) const {
        T ans = a;
        for(pll x : b){
            if(ans[0].second != x.second && ans[1] > x){
                ans[1] = x;
                if(ans[0].first > ans[1].first) swap(ans[0], ans[1]);
            }
            else if(ans[0].second == x.second && ans[0] > x){
                ans[0] = x;
            }
        }
        return ans;
    }
    RmQ(ll n, const T& def_value = {pll{LINF,LINF},{LINF,LINF}}) : Base(n, def_value){}
    RmQ(const vector<T>& v, const T& def_value) : Base(v, def_value){
        for(ll i = Base::size; --i;) Base::data[i] = f(Base::data[i * 2], Base::data[i * 2 + 1]);
    }
    void set2(ll at, ll color){
        Base::set(at, {pll{at, color}, pll{LINF, LINF}});
    }
};
struct RMQ : SegmentTree<ll>{
    using T = ll;
    using Base = SegmentTree<T>;
    T f(const T& a, const T& b) const {return max(a, b);}
    RMQ(ll n, const T& def_value = 0) : Base(n, def_value){}
    RMQ(const vector<T>& v, const T& def_value) : Base(v, def_value){
        for(ll i = Base::size; --i;) Base::data[i] = f(Base::data[i * 2], Base::data[i * 2 + 1]);
    }
};
struct RSQ : SegmentTree<ll>{
    using T = ll;
    using Base = SegmentTree<T>;
    T f(const T& a, const T& b) const {return a + b;}
    RSQ(ll n, const T& def_value = 0) : Base(n, def_value){}
};
struct HLDecomposition{
    ll n;
    const WeightedGraph& g;
    vector<ll> index, invex, light_root, heavy_root, siz;
    HLDecomposition(const WeightedGraph& g, ll root = 0): n(g.size()), g(g), index(n), invex(n), light_root(n), heavy_root(n), siz(n, 1){
        dfs(-1, root);
        n = 0;
        dfs2(-1, root, -1, 0);
        vector<ll> siz2(n);
        for(ll i = 0; i < n; i++) siz2[index[i]] = siz[i];
        swap(siz, siz2);
    }
    void dfs(ll from, ll at){
        for(auto& i : g[at]) if(i != from){
            dfs(at, i);
            siz[at] += siz[i];
        }
    }
    void dfs2(ll from, ll at, ll light, ll heavy){
        invex[n] = at;
        light_root[n] = light;
        heavy_root[n] = heavy;
        index[at] = n++;
        ll max = -1, maxdex = -1;
        for(auto& i : g[at]) if(i != from && chmax(max, siz[i])) maxdex = i;
        if(maxdex == -1) return;
        dfs2(at, maxdex, light, heavy);
        for(auto& i : g[at]) if(i != from && i != maxdex) dfs2(at, i, index[at], n);
    }
    ll lca(ll a, ll b){
        a = index[a]; b = index[b];
        while(true){
            if(a > b) swap(a, b);
            if(heavy_root[a] == heavy_root[b]) return invex[a];
            b = light_root[b];
        }
    }
    template<class T> void path_node(ll a, ll b, const T& f){
        a = index[a]; b = index[b];
        while(true){
            if(a > b) swap(a, b);
            if(heavy_root[a] == heavy_root[b]){
                f(a, b + 1);
                return;
            }
            f(heavy_root[b], b + 1);
            b = light_root[b];
        }
    }
    template<class T> void path_edge(ll a, ll b, const T& f){
        a = index[a]; b = index[b];
        while(true){
            if(a > b) swap(a, b);
            if(heavy_root[a] == heavy_root[b]){
                if(a != b) f(a, b);
                return;
            }
            f(heavy_root[b] - 1, b);
            b = light_root[b];
        }
    }
    template<class T> void subtree_node(ll a, const T& f){
        a = index[a];
        f(a, a + siz[a]);
    }
    template<class T> void subtree_edge(ll a, const T& f){
        a = index[a];
        f(a, a + siz[a] - 1);
    }
};
int main(){
    LL(n);
    if(n==1){
        out(0);
        return out(1);
    }
    WeightedGraph g(n);
    g.input_tree();
    auto answer=[&](vector<ll>ans){
        HLDecomposition hld(g);
        RSQ seg(n);
        rep(at,n)each(i,g[at])if(at<i)hld.path_edge(at,i,[&](ll x,ll y){seg.set(x,i.cost);});
        ll cost=0;
        rep(n)hld.path_edge(i,ans[i],[&](ll x,ll y){cost+=seg.get(x,y);});
        out(cost);
        each(i,ans)i++;
        out(ans);
        exit(0);
    };
    vec(ll,siz,n,1);
    auto dfs = [&](ll from, ll at, auto dfs) -> void {
        each(i, g[at]) if(i != from){
            dfs(at, i, dfs);
            siz[at] += siz[i];
        }
    };
    dfs(-1, 0, dfs);
    ll min=LINF,cen=-1;
    rep(n)if(siz[i]*2>=n&&chmin(min,siz[i]))cen=i;
    if(siz[cen]*2==n){
        vec(bool,lu,n);
        auto dfs = [&](ll from, ll at, auto dfs) -> void {
            if(siz[at] * 2 > n) return;
            lu[at] = 1;
            each(i, g[at]) if(i != from) dfs(at, i, dfs);
        };
        dfs(-1, cen, dfs);
        vector<ll>a,b,ans(n);
        rep(n)(lu[i]?a:b).push_back(i);
        rep(n/2){
            ans[a[i]]=b[i];
            ans[b[i]]=a[i];
        }
        answer(ans);
    }
    siz.assign(n,1);
    each(i,g[cen])dfs(cen,i,dfs);
    vec(ll,color,n,-1);
    ll m=g[cen].size();
    RmQ idx(n);
    RMQ siz_seg(m);
    rep(m){
        siz_seg.set(i,siz[g[cen][i]]*2);
        auto dfs = [&](ll from, ll at, auto dfs) -> void {
            color[at]=i;
            idx.set2(at,color[at]);
            each(i, g[at]) if(i != from){
                dfs(at, i, dfs);
            }
        };
        dfs(cen,g[cen][i],dfs);
    }
    idx.set2(cen,m);
    vec(ll,ans,n,-1);
    ll rest=n;
    rep(n){
        if(siz_seg.data[1]==rest){
            auto p=siz_seg.data.begin()+siz_seg.size;
            const ll max_color=max_element(p,p+siz_seg.size)-p;
            vector<ll>a1,b1,a2,b2;
            vec(bool,used,n);
            rep(n){
                if(ans[i]==-1)(color[i]==max_color?a1:b1).push_back(i);
                else used[ans[i]]=1;
            }
            rep(n)if(!used[i])(color[i]==max_color?b2:a2).push_back(i);
            rep(a1.size())ans[a1[i]]=a2[i];
            rep(b1.size())ans[b1[i]]=b2[i];
            answer(ans);
        }
        ll c=color[i];
        ll j=(idx.data[1][0].second!=c?idx.data[1][0].first:idx.data[1][1].first);
        ans[i]=j;
        idx.set(j,{pll{LINF,LINF},{LINF,LINF}});
        if(~color[i])siz_seg.add(color[i],-1);
        if(~color[j])siz_seg.add(color[j],-1);
        rest--;
    }
    answer(ans);
}