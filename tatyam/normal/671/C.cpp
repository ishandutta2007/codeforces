#pragma GCC optimize("fast-math")
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
#define overload5(a,b,c,d,e,name,...) name
#define overload4(a,b,c,d,name,...) name
#define overload3(a,b,c,name,...) name
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
#define each4(w,x,y,z,a) for(auto&&[w,x,y,z]:a)
#define each(...) overload5(__VA_ARGS__,each4,each3,each2,each1)(__VA_ARGS__)
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
#define Msum(...) accumulate(all(__VA_ARGS__),Modint{0})
#define elif else if
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
#define vv(type,name,h,...) vector name(h,vector<type>(__VA_ARGS__))
#define VV(type,name,h,w) vector name(h,vector<type>(w));in(name)
#define vvv(type,name,h,w,...) vector name(h,vector(w,vector<type>(__VA_ARGS__)))
template<class T> auto min(const T& a){ return *min_element(all(a)); }
template<class T> auto max(const T& a){ return *max_element(all(a)); }
template<class T, class U> auto count(const T& a, const U& b){ return count(all(a), b); }
template<class T, class U> auto count_if(const T& a, U b){ return count_if(all(a), b); }
template<class T, class U> T filter(T a, U b){ a.erase(remove_if(all(a), not_fn(b)), a.end()); return a; }
inline ll popcnt(ull a){ return __builtin_popcountll(a); }
ll intpow(ll a, ll b){ ll ans = 1; while(b){ if(b & 1) ans *= a; a *= a; b /= 2; } return ans; }
ll modpow(ll a, ll b, ll p){ ll ans = 1; while(b){ if(b & 1) (ans *= a) %= p; (a *= a) %= p; b /= 2; } return ans; }
template<class T> bool chmin(T& a, const T& b){ if(a > b){ a = b; return 1; } return 0; }
template<class T> bool chmax(T& a, const T& b){ if(a < b){ a = b; return 1; } return 0; }
template<class T, class U> bool chmin(T& a, const U& b){ if(a > T(b)){ a = b; return 1; } return 0; }
template<class T, class U> bool chmax(T& a, const U& b){ if(a < T(b)){ a = b; return 1; } return 0; }
vector<ll> iota(ll n, ll begin = 0){ vector<ll> a(n); iota(a.begin(), a.end(), begin); return a; }
vector<pll> factor(ull x){ vector<pll> ans; for(ull i = 2; i * i <= x; i++) if(x % i == 0){ ans.push_back({i, 1}); while((x /= i) % i == 0) ans.back().second++; } if(x != 1) ans.push_back({x, 1}); return ans; }
vector<ll> divisor(ull x){ vector<ll> ans; for(ull i = 1; i * i <= x; i++) if(x % i == 0) ans.push_back(i); rrep(ans.size() - (ans.back() * ans.back() == x)) ans.push_back(x / ans[i]); return ans; }
template<class T> unordered_map<T, ll> press(vector<T> a){ Uniq(a); unordered_map<T, ll> ans; rep(a.size()) ans[a[i]] = i; return ans; }
template<class T> auto run_press(const T& a){ vector<pair<decay_t<decltype(a[0])>, ll>> ans; each(x, a){ if(ans.empty() || ans.back().first != x) ans.emplace_back(x, 1); else ans.back().second++; } return ans; }
template<class... Ts> void in(Ts&... t);
[[maybe_unused]] void print(){}
template<class T, class... Ts> void print(const T& t, const Ts&... ts);
template<class... Ts> void out(const Ts&... ts){ print(ts...); cout << '\n'; }
namespace IO{
#define VOID(a) decltype(void(a))
struct setting{
    setting(){
        cin.tie(nullptr); ios::sync_with_stdio(false);
        fixed(cout); cout.precision(12);
    }
} setting;
template<int I> struct P : P<I-1>{};
template<> struct P<0>{};
template<class T> void i(T& t){ i(t, P<3>{}); }
void i(vector<bool>::reference t, P<3>){ int a; i(a); t = a; }
template<class T> auto i(T& t, P<2>) -> VOID(cin >> t){ cin >> t; }
template<class T> auto i(T& t, P<1>) -> VOID(begin(t)){ for(auto&& x : t) i(x); }
template<class T, size_t... idx> void ituple(T& t, index_sequence<idx...>){
    in(get<idx>(t)...);
}
template<class T> auto i(T& t, P<0>) -> VOID(tuple_size<T>{}){
    ituple(t, make_index_sequence<tuple_size<T>::value>{});
}
template<class T> void o(const T& t){ o(t, P<4>{}); }
template<size_t N> void o(const char (&t)[N], P<4>){ cout << t; }
template<class T, size_t N> void o(const T (&t)[N], P<3>){
    o(t[0]); for(size_t i = 1; i < N; i++){ o(' '); o(t[i]); }
}
template<class T> auto o(const T& t, P<2>) -> VOID(cout << t){ cout << t; }
template<class T> auto o(const T& t, P<1>) -> VOID(begin(t)){ bool first = 1; for(auto&& x : t) { if(first) first = 0; else o(' '); o(x); } }
template<class T, size_t... idx> void otuple(const T& t, index_sequence<idx...>){
    print(get<idx>(t)...);
}
template<class T> auto o(T& t, P<0>) -> VOID(tuple_size<T>{}){
    otuple(t, make_index_sequence<tuple_size<T>::value>{});
}
#undef VOID
}
#define unpack(a) (void)initializer_list<int>{(a, 0)...}
template<class... Ts> void in(Ts&... t){ unpack(IO::i(t)); }
template<class T, class... Ts> void print(const T& t, const Ts&... ts){
    IO::o(t); unpack(IO::o((cout << ' ', ts)));
}
#undef unpack
#ifdef DEBUG
inline ll __lg(ull x){ return 63 - __builtin_clzll(x); }
#define debug(...) { print(#__VA_ARGS__); print(":"); out(__VA_ARGS__); }
#else
#define debug(...) void(0)
#endif
void first(bool i = true){ return out(i?"first":"second"); }
void First(bool i = true){ return out(i?"First":"Second"); }
void Yes(bool i = true){ return out(i?"Yes":"No"); }
void No(){ return out("No"); }
void YES(bool i = true){ return out(i?"YES":"NO"); }
void NO(){ return out("NO"); }
void Yay(bool i = true){ return out(i?"Yay!":":("); }
void possible(bool i = true){ return out(i?"possible":"impossible"); }
void Possible(bool i = true){ return out(i?"Possible":"Impossible"); }
void POSSIBLE(bool i = true){ return out(i?"POSSIBLE":"IMPOSSIBLE"); }
void Case(ll i){ printf("Case #%lld: ", i); }


const ll MAX=2e5;
template<class T>
struct SegmentTreeBeats{
    struct Beats{
        T first_max, second_max;
        ll cnt;
        Beats(const T& a, const T& b = def_beats, ll c = 1): first_max(a), second_max(b), cnt(c){}
        Beats operator+(const Beats& a) const {
            if(c(first_max, a.first_max)) return {a.first_max, max(first_max, a.second_max, c), a.cnt};
            else if(c(a.first_max, first_max)) return {first_max, max(second_max, a.first_max, c), cnt};
            return {first_max, max(second_max, a.second_max, c), cnt + a.cnt};
        }
    };
    inline T f(const T& a, const T& b) const { return a + b; }
    inline void m(T& data, Beats& beats, const T& val){
        data += beats.cnt * (val - beats.first_max);
        beats.first_max = val;
    }
    static inline bool c(const T& a, const T& b);
    static const T def_value, def_beats, identity;
    ll size = 1, rank = 0;
    vector<T> data, lazy;
    vector<Beats> beats;
    SegmentTreeBeats(ll n){
        while(size < n){
            size *= 2;
            rank++;
        }
        data.assign(size * 2, def_value);
        lazy.assign(size * 2, def_value);
        beats.assign(size * 2, def_value);
        for(ll i = size; --i; ) beats[i] = beats[i * 2] + beats[i * 2 + 1];
    }
    SegmentTreeBeats(const vector<T>& v){
        while(size < v.size()){
            size *= 2;
            rank++;
        }
        data.assign(size * 2, def_value);
        lazy.assign(size * 2, def_value);
        beats.assign(size * 2, def_beats);
        for(ll i = 0; i < v.size(); i++){
            data[size + i] = v[i];
            beats[size + i] = v[i];
        }
        for(ll i = size; --i; ){
            data[i] = f(data[i * 2], data[i * 2 + 1]);
            beats[i] = beats[i * 2] + beats[i * 2 + 1];
        }
    }
    inline void _push(ll at){
        if(lazy[at] != def_value){
            if(c(lazy[at], beats[at * 2].first_max)){
                m(data[at * 2], beats[at * 2], lazy[at]);
                lazy[at * 2] = min(lazy[at], lazy[at * 2], c);
            }
            if(c(lazy[at], beats[at * 2 + 1].first_max)){
                m(data[at * 2 + 1], beats[at * 2 + 1], lazy[at]);
                lazy[at * 2 + 1] = min(lazy[at], lazy[at * 2 + 1], c);
            }
            lazy[at] = def_value;
        }
    }
    inline void push(ll at){
        if(!at) return;
        for(ll i = 32 - __builtin_clz(at); --i; ) _push(at >> i);
    }
    inline void _update(ll at){
        data[at] = f(data[at * 2], data[at * 2 + 1]);
        beats[at] = beats[at * 2] + beats[at * 2 + 1];
    }
    inline void update(ll at){
        while(at /= 2) _update(at);
    }
    inline T operator[](ll at){
        at += size;
        push(at);
        return data[at];
    }
    inline void set(ll at, const T& val){
        at += size;
        push(at);
        data[at] = val;
        beats[at] = val;
        update(at);
    }
    inline void chmin(ll l, ll r, const T& val){
        l += size;
        r += size;
        ll at = 1, rnk = rank;
        while(at){
            if(l < (at + 1) << rnk && at << rnk < r && c(val, beats[at].first_max)){
                if(at < size) _push(at);
                if(l <= at << rnk && (at + 1) << rnk <= r && c(beats[at].second_max, val) && c(val, beats[at].first_max)){
                    m(data[at], beats[at], val);
                    lazy[at] = val;
                }
                else{
                    at *= 2;
                    rnk--;
                    continue;
                }
            }
            while(at & 1){
                at /= 2;
                rnk++;
                _update(at);
            }
            if(!at) return;
            at++;
        }
    }
    T get_f(ll l, ll r){
        if(l >= r) return identity;
        T L = identity, R = identity;
        l += size; r += size;
        push(l);
        push(r - 1);
        for(; l < r; l /= 2, r /= 2){
            if(l & 1) L = f(L, data[l++]);
            if(r & 1) R = f(data[--r], R);
        }
        return f(L, R);
    }
    T get_max(ll l, ll r){
        if(l >= r) return def_beats;
        T L = def_beats, R = def_beats;
        l += size; r += size;
        push(l);
        push(r - 1);
        for(; l < r; l /= 2, r /= 2){
            if(l & 1) L = max(L, beats[l++].first_max, c);
            if(r & 1) R = max(beats[--r].first_max, R, c);
        }
        return max(L, R, c);
    }
};
template<class T> const T SegmentTreeBeats<T>::def_value = 0;
template<class T> const T SegmentTreeBeats<T>::def_beats = numeric_limits<T>::min();
template<class T> const T SegmentTreeBeats<T>::identity = 0;
template<class T> bool SegmentTreeBeats<T>::c(const T& a, const T& b){ return a < b; }
ll solve(){
    LL(n);
    VEC(ll,a,n);
    vector divisor_idx(MAX+1,vector<ll>{});
    rep(n)each(d,divisor(a[i]))divisor_idx[d].push_back(i);
    vector<tuplis>query;
    rep(v,MAX+1)if(divisor_idx[v].size()>=2){
        auto&idx=divisor_idx[v];
        query.push_back({0,idx.rbegin()[1]-1,v});
        query.push_back({idx[0]+1,idx.back()-1,v});
        query.push_back({idx[1]+1,n-1,v});
    }
    Sort(query);
    Rev(query);
    ll ans=0;
    SegmentTreeBeats<ll> seg(n);
    rep(l,n){
        while(query.size()&&query.back()[0]==l){
            auto[l,r,v]=query.back();
            query.pop_back();
            if(l>r)continue;
            seg.chmin(0,r+1,-v);
        }
        ans-=seg.get_f(l,n);
    }
    return ans;
}
int main(){
    out(solve());
}