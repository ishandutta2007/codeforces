//#define _GLIBCXX_DEBUG

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define lfs cout<<fixed<<setprecision(10)
#define ALL(a)  (a).begin(),(a).end()
#define ALLR(a)  (a).rbegin(),(a).rend()
#define spa << " " <<
#define fi first
#define se second
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define EB emplace_back
#define rep(i,n,m) for(ll i = (n); i < (ll)(m); i++)
#define rrep(i,n,m) for(ll i = (ll)(m) - 1; i >= (ll)(n); i--)
using ll = long long;
using ld = long double;
const ll MOD1 = 1e9+7;
const ll MOD9 = 998244353;
const ll INF = 1e9;
using P = pair<ll, ll>;
template<typename T1, typename T2>
bool chmin(T1 &a,T2 b){if(a>b){a=b;return true;}else return false;}
template<typename T1, typename T2>
bool chmax(T1 &a,T2 b){if(a<b){a=b;return true;}else return false;}
ll median(ll a,ll b, ll c){return a+b+c-max({a,b,c})-min({a,b,c});}
void ans1(bool x){if(x) cout<<"Yes"<<endl;else cout<<"No"<<endl;}
void ans2(bool x){if(x) cout<<"YES"<<endl;else cout<<"NO"<<endl;}
void ans3(bool x){if(x) cout<<"Yay!"<<endl;else cout<<":("<<endl;}
template<typename T1,typename T2>
void ans(bool x,T1 y,T2 z){if(x)cout<<y<<endl;else cout<<z<<endl;}  
template<typename T>
void debug(vector<vector<T>>&v,ll h,ll w){for(ll i=0;i<h;i++)
{cout<<v[i][0];for(ll j=1;j<w;j++)cout spa v[i][j];cout<<endl;}};
void debug(vector<string>&v,ll h,ll w){for(ll i=0;i<h;i++)
{for(ll j=0;j<w;j++)cout<<v[i][j];cout<<endl;}};
template<typename T>
void debug(vector<T>&v,ll n){if(n!=0)cout<<v[0];
for(ll i=1;i<n;i++)cout spa v[i];cout<<endl;};
template<typename T>
vector<vector<T>>vec(ll x, ll y, T w){
  vector<vector<T>>v(x,vector<T>(y,w));return v;}
ll gcd(ll x,ll y){ll r;while(y!=0&&(r=x%y)!=0){x=y;y=r;}return y==0?x:y;}
vector<ll>dx={1,-1,0,0,1,1,-1,-1};
vector<ll>dy={0,0,1,-1,1,-1,1,-1};
template<typename T>
vector<T> make_v(size_t a,T b){return vector<T>(a,b);}
template<typename... Ts>
auto make_v(size_t a,Ts... ts){
  return vector<decltype(make_v(ts...))>(a,make_v(ts...));
}
template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2>&p){
  return os << p.first << " " << p.second;
}
//mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
template<class Key, class Value, class Hash>
struct hash_map {
  using size_type = std::size_t;
  using key_type = Key;
  using value_type = Value;
  using pair_type = std::pair<key_type, value_type>;

  enum class State: std::uint8_t {
    INACTIVE,
    ACTIVE,
    FILLED
  };

  Hash hashf;

  std::vector<State> st;
  std::vector<pair_type> bck;
  size_type mask;
  size_type prode;
  size_type sz;
  size_type min_elem;
  hash_map():
    mask(0), prode(-1), sz(0), min_elem(0) {
  }

  size_type find_empty(const key_type& key) {
    size_type h = hashf(key);
    for(size_type delta = 0;;delta++) {
      size_type i = (h + delta) & mask;
      if(st[i] != State::FILLED) {
        if(prode < delta) prode = delta;
        return i;
      }
    }
  }

  size_type find_filled(const key_type& key) {
    if(sz == 0) return size_type(-1);
    size_type h = hashf(key);
    for(size_type delta = 0; delta <= prode; delta++) {
      size_type i = (h + delta) & mask;
      if(st[i] == State::FILLED) {
        if(bck[i].first == key) {
          return i;
        }
      }
      else if(st[i] == State::INACTIVE) {
        return size_type(-1);
      }
    }
    return size_type(-1);
  }

  size_type find_or_allocate(const key_type& key) {
    size_type h = hashf(key);
    size_type hole = size_type(-1);
    size_type delta = 0;
    for(; delta <= prode; delta++) {
      size_type i = (h + delta) & mask;
      if(st[i] == State::FILLED) {
        if(bck[i].first == key) return i;
      }
      else if(st[i] == State::INACTIVE) return i;
      else {
        if(hole == size_type(-1)) {
          hole = i;
        }
      }
    }
    if(hole != size_type(-1)) return hole;
    for(; ; delta++) {
      size_type i = (h + delta) & mask;
      if(st[i] != State::FILLED) {
        prode = delta;
        return i;
      }
    }
  }

  void reserve(int next_cnt) {
    size_type required_cnt = next_cnt + (next_cnt >> 1) + 1;
    if(required_cnt > bck.size()) {
      next_cnt = 4;
      while(next_cnt < required_cnt) next_cnt <<= 1;
    }
    else if(next_cnt <= bck.size() / 4) {
      next_cnt = std::max(4, (int)bck.size() / 2);
    }
    else {
      return;
    }
    std::vector<State> old_st(next_cnt, State::INACTIVE);
    std::vector<pair_type> old_bck(next_cnt);

    std::swap(old_st, st);
    std::swap(old_bck, bck);
    mask = next_cnt - 1;
    sz = 0;
    prode = 0;
    min_elem = next_cnt - 1;


    for(size_type pos = 0; pos < old_bck.size(); pos++) {
      if(old_st[pos] == State::FILLED) {
        size_type i = find_empty(old_bck[pos].first);
        st[i] = State::FILLED;
        bck[i] = std::move(old_bck[pos]);
        min_elem = std::min(min_elem, i);
        sz += 1;
      }
    }
  }

  void insert(const key_type& key, const value_type& val) {
    reserve(sz + 1);
    size_type i = find_or_allocate(key);
    if(st[i] != State::FILLED) {
      st[i] = State::FILLED;
      bck[i] = pair_type(key, val);
      min_elem = std::min(min_elem, i);
      sz++;
    }
    else {
      bck[i] = pair_type(key, val);
    }
  }

  bool erase(const key_type& key) {
    size_type i = find_filled(key);
    if(i == size_type(-1)) {
      return false;
    }
    else {
      st[i] = State::ACTIVE;
      bck[i].~pair_type();
      sz--;
      return true;
    }
  }

  pair_type* get(const key_type& key) {
    size_type i = find_filled(key);
    if(i == size_type(-1)) {
      return nullptr;
    }
    else {
      return &bck[i];
    }
  }

  pair_type* get_or_insert(const key_type& key, const value_type val) {
    reserve(sz + 1);
    size_type i = find_or_allocate(key);
    if(st[i] != State::FILLED) {
      st[i] = State::FILLED;
      bck[i] = pair_type(key, val);
      min_elem = std::min(min_elem, i);
      sz++;
    }
    return &bck[i];
  }

  pair_type get_and_erase(const key_type& key) {
    size_type i = find_filled(key);
    st[i] = State::ACTIVE;
    pair_type p = std::move(bck[i]);
    sz--;
    return p;
  }


  template<class Func>
  void search_all(Func func) {
    for(size_type i = min_elem; i < bck.size(); i++) {
      if(st[i] == State::FILLED) {
        min_elem = i;
        size_type res = func(bck[i]);
        if(res & 0b10) {
          st[i] = State::ACTIVE;
          bck[i].~pair_type();
          sz--;
        }
        if(res & 0b01) {
           return;
        }
      }
    }
  }

  size_type size() const { return sz; }
};


struct Hashu32 {
  std::uint32_t operator()(std::uint32_t key) {
    int c2=0x27d4eb2d; // a prime or an odd constant
    key = (key ^ 61) ^ (key >> 16);
    key = key + (key << 3);
    key = key ^ (key >> 4);
    key = key * c2;
    key = key ^ (key >> 15);
    return key;
  }
};

struct Hashu64 {
  std::size_t operator()(std::uint64_t key) {
    key = (~key) + (key << 18); // key = (key << 18) - key - 1;
    key = key ^ (key >> 31);
    key = key * 21; // key = (key + (key << 2)) + (key << 4);
    key = key ^ (key >> 11);
    key = key + (key << 6);
    key = key ^ (key >> 22);
    return (int) key;
  }

};
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  bool judge = true;
  int n;cin>>n;
  vector<int>a(n);
  rep(i,0,n)cin>>a[i];
  hash_map<int, int, Hashu32> mp;
  auto fh=[&](int l,int r,int k,int t){
    return (t^(k<<1)^(r<<7)^(l<<19));
  };
  vector<int>b(n+1);
  rep(i,0,n)b[i+1]=b[i]+a[i];
  auto dfs=[&](auto &&f,int l,int r,int t,int k)->int{
    if(l+r>n){
      //cout<<l spa r spa k spa t<<endl;
      return INF;
    }
    int h=fh(l,r,k,t);
    auto p=mp.get(h);
    if(p!=nullptr)return p->second;
    int val;
    if(t==0){
      val=-INF;
      int tmp=f(f,l+k,r,t^1,k);
      if(tmp!=INF)chmax(val,tmp+b[l+k]-b[l]);
      //if(k==2)cout<<l spa k spa tmp spa +b[l+k]-b[l]<<endl;
      tmp=f(f,l+k+1,r,t^1,k+1);
      //if(l==0&&r==0)cout<<l spa k spa tmp spa b[l+k+1]-b[l]<<endl;
      if(tmp!=INF)chmax(val,tmp+b[l+k+1]-b[l]);
      if(val==-INF)val=0;
    }
    else{
      val=INF;
      int tmp=f(f,l,r+k,t^1,k);
      if(tmp!=INF)chmin(val,tmp-(b[n-r]-b[n-(r+k)]));
      //if(k==2)cout<<l spa r spa tmp<<endl;
      tmp=f(f,l,r+k+1,t^1,k+1);
      //if(k==2)cout<<l spa r spa tmp<<endl;
      if(tmp!=INF)chmin(val,tmp-(b[n-r]-b[n-(r+k+1)]));
      if(val==INF)val=0;
    }
    //cout<<l spa r spa k spa t spa val<<endl;
    mp.insert(h,val);
    return val;
  };
  cout<<dfs(dfs,0,0,0,1)<<endl;
  return 0;
}