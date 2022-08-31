#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using uint = unsigned int;
using pcc = pair<char, char>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
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
const ll four[] = {0, 1, 0, -1, 0};
const ll eight[] = {0, 1, 1, 0, -1, -1, 1, -1, 0};
#define overload4(_1,_2,_3,_4,name,...) name
#define overload3(_1,_2,_3,name,...) name
#define rep1(n) for(ll i=0;i<n;++i)
#define rep2(i,n) for(ll i=0;i<n;++i)
#define rep3(i,a,b) for(ll i=a;i<b;++i)
#define rep4(i,a,b,c) for(ll i=a;i<b;i+=c)
#define rep(...) overload4(__VA_ARGS__,rep4,rep3,rep2,rep1)(__VA_ARGS__)
#define rrep1(n) for(ll i=(n)-1;i>=0;i--)
#define rrep2(i,n) for(ll i=(n)-1;i>=0;i--)
#define rrep3(i,a,b) for(ll i=(b)-1;i>=(a);i--)
#define rrep4(i,a,b,c) for(ll i=a+(b-a-1)/c*c;i>=a;i-=c)
#define rrep(...) overload4(__VA_ARGS__,rrep4,rrep3,rrep2,rrep1)(__VA_ARGS__)
#define each(i,a) for(auto&& i:a)
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
#define elif else if
#define unless(a) if(!(a))
#define mp make_pair
#define mt make_tuple
#define INT(...) int __VA_ARGS__;in(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__;in(__VA_ARGS__)
#define ULL(...) ull __VA_ARGS__;in(__VA_ARGS__)
#define STR(...) string __VA_ARGS__;in(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__;in(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__;in(__VA_ARGS__)
#define LD(...) ld __VA_ARGS__;in(__VA_ARGS__)
#define vec(type,name,...) vector<type> name(__VA_ARGS__)
#define VEC(type,name,size) vector<type> name(size);in(name)
#define vv(type,name,h,...) vector<vector<type>>name(h,vector<type>(__VA_ARGS__))
#define VV(type,name,h,w) vector<vector<type>>name(h,vector<type>(w));in(name)
#define vvv(type,name,h,w,...) vector<vector<vector<type>>>name(h,vector<vector<type>>(w,vector<type>(__VA_ARGS__)))
template<class T> auto max(const T& a){ return *max_element(all(a)); }
template<class T> auto min(const T& a){ return *min_element(all(a)); }
ll gcd(ll a, ll b){ while(b){ ll c = b; b = a % b; a = c; } return a; }
ll lcm(ll a, ll b){ if(!a || !b) return 0; return a * b / gcd(a, b); }
ll intpow(ll a, ll b){ ll ans = 1; while(b){ if(b & 1) ans *= a; a *= a; b /= 2; } return ans; }
ll modpow(ll a, ll b, ll p){ ll ans = 1; while(b){ if(b & 1) (ans *= a) %= p; (a *= a) %= p; b /= 2; } return ans; }
template<class T> bool chmin(T& a, const T& b){ if(a > b){ a = b; return 1; } return 0; }
template<class T> bool chmax(T& a, const T& b){ if(a < b){ a = b; return 1; } return 0; }
vector<pll> factor(ull x){ vector<pll> ans; for(ll i = 2; i * i <= x; i++) if(x % i == 0){ ans.push_back({i, 1}); while((x /= i) % i == 0) ans.back().second++; } if(x != 1) ans.push_back({x, 1}); return ans; }
vector<ll> divisor(ull x){ vector<ll> ans; for(ll i = 1; i * i <= x; i++) if(x % i == 0) ans.push_back(i); rrep(ans.size() - (ans.back() * ans.back() == x)) ans.push_back(x / ans[i]); return ans; }
template<class T> unordered_map<T, ll> press(vector<T>& a){ auto b = a; sort(all(b)); b.erase(unique(all(b)), b.end()); unordered_map<T,ll> ans; rep(b.size()) ans[b[i]] = i; each(i, a) i = ans[i]; return ans; }
template<class T> map<T, ll> press_map(vector<T>& a){ auto b = a; sort(all(b)); b.erase(unique(all(b)), b.end()); map<T,ll> ans; rep(b.size()) ans[b[i]] = i; each(i, a) i = ans[i]; return ans; }
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
void scan(vector<bool>& a){ for(unsigned i = 0; i < a.size(); i++) { int b; scan(b); a[i] = b; } }
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
void err(){ putchar('\n'); }
template<class T> void err(const T& t){ print(t); putchar('\n'); }
template<class Head, class... Tail> void err(const Head& head, const Tail&... tail){ print(head); putchar(' '); out(tail...); }
#else
template<class... T> void err(const T&...){}
#endif
int first(bool i = true){ return out(i?"first":"second"); }
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



template<class T, class U>
struct LazySegmentTree{
    virtual T f(const T&, const T&) = 0;
    virtual void m(ll, T&, const U&) = 0;
    virtual void c(U&, const U&) = 0;
    ll size = 1, rank = 0;
    vector<T> data;
    vector<U> lazy;
    const T def_value;
    const U def_lazy;
    LazySegmentTree(ll n, const T& def_value, const U& def_lazy): def_value(def_value), def_lazy(def_lazy){
        while(size < n){
            size *= 2;
            rank++;
        }
        data.assign(size * 2, def_value);
        lazy.assign(size * 2, def_lazy);
    }
    LazySegmentTree(const vector<T>& v, const T& def_value, const U& def_lazy): def_value(def_value), def_lazy(def_lazy){
        while(size < v.size()){
            size *= 2;
            rank++;
        }
        data.assign(size * 2, def_value);
        lazy.assign(size * 2, def_lazy);
        for(ll i = 0; i < v.size(); i++) data[size + i] = v[i];
    }
    void push(ll at){
        if(!at) return;
        ll r = 31 - __builtin_clz(at);
        for(ll i = r; i > 0; i--){
            ll a = at >> i;
            if(lazy[a] != def_lazy){
                m(rank + i - r - 1, data[a * 2], lazy[a]);
                m(rank + i - r - 1, data[a * 2 + 1], lazy[a]);
                c(lazy[a * 2], lazy[a]);
                c(lazy[a * 2 + 1], lazy[a]);
                lazy[a] = def_lazy;
            }
        }
    }
    void update(ll at){
        while(at /= 2){
            data[at] = f(data[at * 2], data[at * 2 + 1]);
        }
    }
    T operator[](ll at){
        at += size;
        push(at);
        return data[at];
    }
    void set(ll at, const T& val){
        at += size;
        push(at);
        data[at] = val;
        update(at);
    }
    void range_query(ll l, ll r, const U& val){
        if(l >= r) return;
        l += size;
        r += size;
        ll L = 0, R = 0;
        [&L, &R, l, r]() mutable {
            for(; l < r; l /= 2, r /= 2){
                if(l & 1){
                    if(!L) L = l;
                    l++;
                }
                if(r & 1 && !R) R = r - 1;
            }
        }();
        push(L);
        push(R);
        for(ll rank = 0; l < r; l /= 2, r /= 2, rank++){
            if(l & 1){
                m(rank, data[l], val);
                c(lazy[l++], val);
            }
            if(r & 1){
                m(rank, data[--r], val);
                c(lazy[r], val);
            }
        }
        update(L);
        update(R);
    }
    T get(ll l, ll r){
        if(l >= r) return def_value;
        T L = def_value, R = def_value;
        l += size; r += size;
        push(l);
        push(r - 1);
        for(; l < r; l /= 2, r /= 2){
            if(l & 1) L = f(L, data[l++]);
            if(r & 1) R = f(data[--r], R);
        }
        return f(L, R);
    }
    void clear(){
        for(auto& i : data) i = def_value;
    }
};
template<class T>
struct RAQRSQ : LazySegmentTree<T, T>{
    using Base = LazySegmentTree<T, T>;
    T f(const T& a, const T& b){return a + b;}
    void m(ll rank, T& x, const T& val){x += val << rank;}
    void c(T& a, const T& b){a += b;}
    RAQRSQ(ll n, const T& def_value = T()) : Base(n, def_value, def_value){}
    RAQRSQ(const vector<T>& v, const T& def_value = T()) : Base(v, def_value, def_value){
        for(ll i = Base::size; --i;) Base::data[i] = f(Base::data[i * 2], Base::data[i * 2 + 1]);
    }
};
template<class T>
struct RUQRmQ : LazySegmentTree<T, T>{
    using Base = LazySegmentTree<T, T>;
    T f(const T& a, const T& b){return min(a, b);}
    void m(ll rank, T& x, const T& val){x = val;}
    void c(T& a, const T& b){a = b;}
    RUQRmQ(ll n, const T& def_value, const T& def_lazy = numeric_limits<T>::max()) : Base(n, def_value, def_lazy){}
    RUQRmQ(const vector<T>& v, const T& def_value, const T& def_lazy = numeric_limits<T>::max()) : Base(v, def_value, def_lazy){
        for(ll i = Base::size; --i;) Base::data[i] = f(Base::data[i * 2], Base::data[i * 2 + 1]);
    }
};
template<class T>
struct RUQRMQ : LazySegmentTree<T, T>{
    using Base = LazySegmentTree<T, T>;
    T f(const T& a, const T& b){return max(a, b);}
    void m(ll rank, T& x, const T& val){x = val;}
    void c(T& a, const T& b){a = b;}
    RUQRMQ(ll n, const T& def_value, const T& def_lazy = numeric_limits<T>::max()) : Base(n, def_value, def_lazy){}
    RUQRMQ(const vector<T>& v, const T& def_value, const T& def_lazy = numeric_limits<T>::max()) : Base(v, def_value, def_lazy){
        for(ll i = Base::size; --i;) Base::data[i] = f(Base::data[i * 2], Base::data[i * 2 + 1]);
    }
};
template<class T>
struct RAQRmQ : LazySegmentTree<T, T>{
    using Base = LazySegmentTree<T, T>;
    T f(const T& a, const T& b){return max(a, b);}
    void m(ll rank, T& x, const T& val){x += val;}
    void c(T& a, const T& b){a += b;}
    RAQRmQ(ll n, const T& def_value, const T& def_lazy = T()) : Base(n, def_value, def_lazy){}
    RAQRmQ(const vector<T>& v, const T& def_value, const T& def_lazy = T()) : Base(v, def_value, def_lazy){
        for(ll i = Base::size; --i;) Base::data[i] = f(Base::data[i * 2], Base::data[i * 2 + 1]);
    }
};
template<class T>
struct RUQRSQ : LazySegmentTree<T, T>{
    using Base = LazySegmentTree<T, T>;
    T f(const T& a, const T& b){return a + b;}
    void m(ll rank, T& x, const T& val){x = val << rank;}
    void c(T& a, const T& b){a = b;}
    RUQRSQ(ll n, const T& def_value = T(), const T& def_lazy = numeric_limits<T>::max()) : Base(n, def_value, def_lazy){}
    RUQRSQ(const vector<T>& v, const T& def_value = T(), const T& def_lazy = numeric_limits<T>::max()) : Base(v, def_value, def_lazy){
        for(ll i = Base::size; --i;) Base::data[i] = f(Base::data[i * 2], Base::data[i * 2 + 1]);
    }
};
signed main(){
    LL(n);
    using i4=array<ll,4>;
    VEC(i4,a,n);
    vec(ll,s,0);
    vec(ll,t,0);
    each(i,a){
        s.push_back(i[0]);
        s.push_back(i[1]);
        t.push_back(i[2]);
        t.push_back(i[3]);
    }
    auto ps=press(s),pt=press(t);
    each(i,a){
        i[0]=ps[i[0]];
        i[1]=ps[i[1]];
        i[2]=pt[i[2]];
        i[3]=pt[i[3]];
    }
    RAQRmQ<int>seg(max(ps.size(),pt.size()),0);
    vec(tuplis,q,0);
    rep(n){
        q.push_back({a[i][0],0,i});
        q.push_back({a[i][1],1,i});
    }
    sort(all(q));
    ll cnt=0;
    each(i,q){
        ll at=i[2];
        if(i[1]){
            seg.range_query(a[at][2],a[at][3]+1,-1);
            cnt--;
        }
        else{
            seg.range_query(a[at][2],a[at][3]+1,1);
            cnt++;
        }
        if(seg.get(0,seg.size)!=cnt)return NO();
    }
    q.clear();
    each(i,a){
        swap(i[0],i[2]);
        swap(i[1],i[3]);
    }
    rep(n){
        q.push_back({a[i][0],0,i});
        q.push_back({a[i][1],1,i});
    }
    sort(all(q));
    each(i,q){
        ll at=i[2];
        if(i[1]){
            seg.range_query(a[at][2],a[at][3]+1,-1);
            cnt--;
        }
        else{
            seg.range_query(a[at][2],a[at][3]+1,1);
            cnt++;
        }
        if(seg.get(0,seg.size)!=cnt)return NO();
    }
    YES();
}