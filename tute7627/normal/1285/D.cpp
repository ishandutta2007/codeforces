#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define lfs cout<<fixed<<setprecision(10)
#define ALL(a)  (a).begin(),(a).end()
#define ALLR(a)  (a).rbegin(),(a).rend()
#define spa << " " <<
#define test cout<<"test"<<endl;
#define fi first
#define se second
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define EB emplace_back
#define rep(i,n,m) for(ll i = (n); i < (ll)(m); i++)
#define rrep(i,n,m) for(ll i = (m) - 1; i >= (ll)(n); i--)
using ll = long long;
using ld = long double;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const ll INF = 1e18;
using P = pair<ll, ll>;
template<typename T>
void chmin(T &a,T b){if(a>b)a=b;}
template<typename T>
void chmax(T &a,T b){if(a<b)a=b;}
void pmod(ll &a,ll b){a=(a+b)%MOD;}
void pmod(ll &a,ll b,ll c){a=(b+c)%MOD;}
void qmod(ll &a,ll b){a=(a*b)%MOD;}
void qmod(ll &a,ll b,ll c){a=(b*c)%MOD;}
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
vector<ll>dx={1,0,-1,0,1,1,-1,-1};
vector<ll>dy={0,1,0,-1,1,-1,1,-1};
template<typename T>
vector<T> make_v(size_t a,T b){return vector<T>(a,b);}
template<typename... Ts>
auto make_v(size_t a,Ts... ts){
  return vector<decltype(make_v(ts...))>(a,make_v(ts...));
}
ostream &operator<<(ostream &os, pair<ll, ll>&p){
  return os << p.first << " " << p.second;
}  
template<long long iden, long long size>
struct Trie{
  struct Node{
    vector<ll>next,idx;
    ll num;
    Node():num(0){
       next.assign(size,-1);
    }
  };
  vector<Node>data;
  Trie(){
    data.emplace_back();
  }
  void add(const string &s, ll id){
    ll pos=0;
    for(ll i=0;i<s.size();i++){
      ll c = s[i] - iden;
      if(data[pos].next[c]==-1){
        data[pos].next[c]=data.size();
        data.emplace_back();
      }
      data[pos].num++;
      pos = data[pos].next[c];
    }
    data[pos].num++;
    data[pos].idx.push_back(id);
  }
  void search(const string &s){
    ll pos=0;
    for(ll i=0;i<s.size();i++){
      ll c = s[i] - iden;
      if(data[pos].next[c]==-1)break;
      pos = data[pos].next[c];
    }
  }
  vector<ll>v;
  ll dfs(ll pos, ll d){
    ll mi=INF;
    for(ll i=0;i<size;i++){
      if(data[pos].next[i]!=-1){
        auto t=dfs(data[pos].next[i], d+1);
        chmin(mi,t);
      }
    }
    if(mi==INF)return 0;
    else if(data[pos].next[0]==-1||data[pos].next[1]==-1){
        return mi;
    }
    else{
      return mi+(1<<29-d);
    }
  }
};
using trie = Trie<'0',2>;
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n;cin>>n;
  vector<ll>a(n);
  trie tri;
  rep(i,0,n){
    cin>>a[i];
    string s;
    rep(j,0,30){
      if(a[i]&(1<<29-j))s.PB('1');
      else s.PB('0');
    }
    //cout<<s<<endl;
    tri.add(s,i);
  }
  auto t=tri.dfs(0,0);
  cout<<t<<endl;
  return 0;
}