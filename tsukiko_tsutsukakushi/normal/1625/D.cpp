/**
 *    author:  otera
 *    created: 12.01.2022 21:48:04 
**/
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using uint = unsigned;
#define repa(i, n) for(int i = 0; i < n; ++ i)
#define repb(i, a, b) for(int i = a; i < b; ++ i)
#define repc(i, a, b, c) for(int i = a; i < b; i += c)
#define overload4(a, b, c, d, e, ...) e
#define rep(...) overload4(__VA_ARGS__, repc, repb, repa)(__VA_ARGS__)
#define rep1a(i, n) for(int i = 0; i <= n; ++ i)
#define rep1b(i, a, b) for(int i = a; i <= b; ++ i)
#define rep1c(i, a, b, c) for(int i = a; i <= b; i += c)
#define rep1(...) overload4(__VA_ARGS__, rep1c, rep1b, rep1a)(__VA_ARGS__)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define per1(i,n) for(int i=n;i>=1;i--)
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
#define pb push_back
#define eb emplace_back
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x)))
#define Sort(a) sort(all(a))
#define Rev(a) reverse(all(a))
#define Uniq(a) sort(all(a));a.erase(unique(all(a)),end(a))
#define si(c) (int)(c).size()
inline ll popcnt(ull a){ return __builtin_popcountll(a); }
#define tpow(n) (1LL<<(n))
#define unless(A) if(!(A))
ll intpow(ll a, ll b){ ll ans = 1; while(b){ if(b & 1) ans *= a; a *= a; b /= 2; } return ans; }
ll intpow(ll a, ll b, ll m) {ll ans = 1; while(b){ if(b & 1) (ans *= a) %= m; (a *= a) %= m; b /= 2; } return ans; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
#define INT(...) int __VA_ARGS__;in(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__;in(__VA_ARGS__)
#define ULL(...) ull __VA_ARGS__;in(__VA_ARGS__)
#define STR(...) string __VA_ARGS__;in(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__;in(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__;in(__VA_ARGS__)
#define LD(...) ld __VA_ARGS__;in(__VA_ARGS__)
#define vec(type,name,...) vector<type>name(__VA_ARGS__)
#define VEC(type,name,size) vector<type>name(size);in(name)
#define vv(type,name,h,...) vector<vector<type>>name(h,vector<type>(__VA_ARGS__))
#define VV(type,name,h,w) vector<vector<type>>name(h,vector<type>(w));in(name)
#define vvv(type,name,h,w,...) vector<vector<vector<type>>>name(h,vector<vector<type>>(w,vector<type>(__VA_ARGS__)))
template <class T> using vc = vector<T>;
template <class T> using vvc = vector<vc<T>>;
template <class T> using vvvc = vector<vvc<T>>;
template <class T> using vvvvc = vector<vvvc<T>>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<class T> void scan(T& a){ cin >> a; }
template<class T> void scan(vector<T>& a){ for(auto&& i : a) scan(i); }
void in(){}
template <class Head, class... Tail> void in(Head& head, Tail&... tail){ scan(head); in(tail...); }
void print(){ cout << ' '; }
template<class T> void print(const T& a){ cout << a; }
template<class T> void print(const vector<T>& a){ if(a.empty()) return; print(a[0]); for(auto i = a.begin(); ++i != a.end(); ){ cout << ' '; print(*i); } }
int out(){ cout << '\n'; return 0; }
template<class T> int out(const T& t){ print(t); cout << '\n'; return 0; }
template<class Head, class... Tail> int out(const Head& head, const Tail&... tail){ print(head); cout << ' '; out(tail...); return 0; }
#define CHOOSE(a) CHOOSE2 a
#define CHOOSE2(a0,a1,a2,a3,a4,x,...) x
#define debug_1(x1) cout<<#x1<<": "<<x1<<endl
#define debug_2(x1,x2) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<endl
#define debug_3(x1,x2,x3) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<", "#x3<<": "<<x3<<endl
#define debug_4(x1,x2,x3,x4) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<", "#x3<<": "<<x3<<", "#x4<<": "<<x4<<endl
#define debug_5(x1,x2,x3,x4,x5) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<", "#x3<<": "<<x3<<", "#x4<<": "<<x4<<", "#x5<<": "<<x5<<endl
#ifdef DEBUG
#define debug(...) CHOOSE((__VA_ARGS__,debug_5,debug_4,debug_3,debug_2,debug_1,~))(__VA_ARGS__)
#define dump(...) { print(#__VA_ARGS__); print(":"); out(__VA_ARGS__); }
#else
#define debug(...)
#define dump(...)
#endif

template<typename T = unsigned int, int size = 30>
struct BinaryTrie{
  struct Node{
    Node* next[2];
    int num;
    Node():num(0), next{nullptr, nullptr}{};
  };
  T rev;
  Node* root;
  bitset<size>bit,bit2;
  BinaryTrie(){
    rev = 0;
    root = new Node();
  }
  void insert(T x, ll add = 1){
    Node* pos = root;
    bit = rev^x;
    for(int i=size-1;i>=0;i--){
      if(pos->next[bit[i]]==nullptr){
        pos->next[bit[i]] = new Node();
      }
      pos->num += add;
      pos = pos->next[bit[i]];
    }
    pos->num += add;
  }
  void erase(T x, ll add = 1){
    Node* pos = root;
    bit = rev^x;
    for(int i=size-1;i>=0;i--){
      pos->num -= add;
      pos = pos->next[bit[i]];
    }
    pos->num -= add;
  }
  void xor_all(T x){
    rev ^= x;
  }
  T max_element(){
    Node* pos = root;
    bit = ~rev;
    T val = 0;
    for(ll i=size-1;i>=0;i--){
      if(pos->next[bit[i]] != nullptr && pos->next[bit[i]]->num >= 1){
        pos = pos->next[bit[i]];
        val ^= T(1) << i;
      }
      else pos = pos->next[!bit[i]];
    }
    return val ^ rev;
  }
  T min_element(){
    Node* pos = root;
    bit = rev;
    T val = 0;
    for(ll i=size-1;i>=0;i--){
      if(pos->next[bit[i]] != nullptr && pos->next[bit[i]]->num >= 1){
        pos = pos->next[bit[i]];
        
      }
      else{
        pos = pos->next[!bit[i]];
        val ^= 1 << i;
      }
    }
    return val;
  }
  T kth_element(ll k){//k0-indexed
    Node* pos = root;
    bit = rev;
    T val = 0;
    for(ll i=size-1;i>=0;i--){
      if(pos->next[bit[i]] != nullptr && pos->next[bit[i]]->num > k){
        pos = pos->next[bit[i]];
      }
      else{
        if(pos->next[bit[i]] != nullptr)k -= pos->next[bit[i]]->num;
        val ^= T(1) << i;
        pos = pos->next[!bit[i]];
      }
    }
    return val ^ rev;
  }
  ll num_all(){
    return root->num;
  }
  ll count_lower(T x){ //xnum
    Node* pos = root;
    ll ret=0;
    bit = rev;
    bit2 = x;
    for(ll i=size-1;i>=0;i--){
      if(bit2[i]&&pos->next[bit[i]] != nullptr)ret += pos->next[bit[i]]->num;
      if(pos->next[bit2[i]^bit[i]] != nullptr)pos = pos->next[bit2[i]^bit[i]];
      else break;
    }
    return ret;
  }
  ll lower_bound(T x){ 
    ll idx = count_lower(x);
    if(idx == num_all())return -1;
    else return kth_element(idx);
  }
  ll upper_bound(T x){
    return lower_bound(x + 1);
  }
};

void solve() {
    INT(n, k);
    map<int, int> inv;
    VEC(int, a, n);
    if(k == 0) {
        vc<int> ids(n);
        iota(all(ids), 1);
        out(n);
        out(ids);
        return;
    }
    rep(i, n) inv[a[i]] = i;
    vc<int> ans;
    BinaryTrie<int, 30> bt;
    auto rec = [&](auto&&rec, int bit, vc<int> ids) -> void {
        int mask = (1<<bit);
        if(k & mask) {
            int sz = si(ids);
            bool ok = 0;
            rep(i, sz) {
                int x = a[ids[i]];
                bt.insert(x);
                bt.xor_all(x);
                int y = bt.max_element();
                debug(x, y, (x ^ y));
                if(!ok and (x ^ y) >= k) {
                    int id2 = inv[y];
                    ans.eb(ids[i]);
                    ans.eb(id2);
                    ok = 1;
                }
                bt.xor_all(x);
            }
            if(!ok) ans.eb(ids[0]);
            rep(i, sz) {
                int x = a[ids[i]];
                bt.erase(x);
            }
            return;
        } else {    
            vc<int> ones, zeros;
            int sz = si(ids);
            rep(i, sz) {
                int x = a[ids[i]];
                if(x & mask) ones.eb(ids[i]);
                else zeros.eb(ids[i]);
            }
            if(si(ones)) rec(rec, bit - 1, ones);
            if(si(zeros)) rec(rec, bit - 1, zeros);
        }
    };
    vc<int> ids(n);
    iota(all(ids), 0);
    rec(rec, 29, ids);
    int m = si(ans);
    if(m <= 1) {
        out(-1);
        return;
    }
    out(m);
    for(int &i: ans) ++ i;
    out(ans);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << fixed << setprecision(20);
    // INT(t); rep(i, t)solve();
    solve();
    return 0;
}