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
const ll INF = 1e18;
using P = pair<ll, ll>;
template<typename T1, typename T2>bool chmin(T1 &a,T2 b){if(a>b){a=b;return true;}else return false;}
template<typename T1, typename T2>bool chmax(T1 &a,T2 b){if(a<b){a=b;return true;}else return false;}
ll median(ll a,ll b, ll c){return a+b+c-max({a,b,c})-min({a,b,c});}
void ans1(bool x){if(x) cout<<"Yes"<<endl;else cout<<"No"<<endl;}
void ans2(bool x){if(x) cout<<"YES"<<endl;else cout<<"NO"<<endl;}
void ans3(bool x){if(x) cout<<"Yay!"<<endl;else cout<<":("<<endl;}
template<typename T1,typename T2>void ans(bool x,T1 y,T2 z){if(x)cout<<y<<endl;else cout<<z<<endl;}  
template<typename T>void debug(vector<vector<T>>&v,ll h,ll w){for(ll i=0;i<h;i++){cout<<v[i][0];for(ll j=1;j<w;j++)cout spa v[i][j];cout<<endl;}};
void debug(vector<string>&v,ll h,ll w){for(ll i=0;i<h;i++){for(ll j=0;j<w;j++)cout<<v[i][j];cout<<endl;}};
template<typename T>void debug(vector<T>&v,ll n){if(n!=0)cout<<v[0];for(ll i=1;i<n;i++)cout spa v[i];cout<<endl;};
template<typename T>vector<vector<T>>vec(ll x, ll y, T w){vector<vector<T>>v(x,vector<T>(y,w));return v;}
ll gcd(ll x,ll y){ll r;while(y!=0&&(r=x%y)!=0){x=y;y=r;}return y==0?x:y;}
vector<ll>dx={1,-1,0,0,1,1,-1,-1};vector<ll>dy={0,0,1,-1,1,-1,1,-1};
template<typename T>vector<T> make_v(size_t a,T b){return vector<T>(a,b);}
template<typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v(ts...))>(a,make_v(ts...));}
template<typename T1, typename T2>ostream &operator<<(ostream &os, const pair<T1, T2>&p){return os << p.first << " " << p.second;}
template<typename T>ostream &operator<<(ostream &os, const vector<T> &v){for(auto &z:v)os << z << " ";cout<<"|"; return os;}
//mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
template<typename T = unsigned int, int size = 30>
struct BinaryTrie{
  struct Node{
    Node* next[2];
    ll num;
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
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n;cin>>n;
  vector<ll>a(n);
  rep(i,0,n)cin>>a[i];
  BinaryTrie tri;
  vector<ll>p(n);
  rep(i,0,n){
    cin>>p[i];
    tri.insert(p[i]);
  }
  vector<ll>ret;
  rep(i,0,n){
    tri.xor_all(a[i]);
    ll k=tri.min_element();
    ret.PB(k);
    tri.erase(k);
    tri.xor_all(a[i]);
  }
  debug(ret,n);
  return 0;
}