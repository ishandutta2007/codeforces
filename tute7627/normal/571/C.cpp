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
struct UnionFind {
  vector<ll> data;
  ll num;
  UnionFind(ll size) : data(size, -1) ,num(size){ }
  bool unite(ll x, ll y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
	  num--;
    }
    return x != y;
  }
  bool find(ll x, ll y) {
    return root(x) == root(y);
  }
  ll root(ll x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  ll size(ll x) {
    return -data[root(x)];
  }
};
struct edge {
  ll to,id;
  edge(ll to,ll id):to(to),id(id){};
};
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n,m;cin>>n>>m;
  vector<vector<ll>>p(m);
  rep(i,0,n){
    ll k;cin>>k;
    rep(j,0,k){
      ll v;cin>>v;
      if(v<0)p[abs(v)-1].PB(-(i+1));
      else p[abs(v)-1].PB(i+1);
    }
  }
  vector<vector<edge>>g(n);
  vector<bool>t(n);
  string ret(m,'?');
  vector<ll>deg(n);
  rep(i,0,m){
    if(p[i].size()==0)continue;
    if(p[i].size()==1||abs(p[i][0])==abs(p[i][1])){
      ll to=abs(p[i][0])-1;
      if(p[i][0]<0)ret[i]='0';
      else ret[i]='1';
      t[to]=true;
    }
    else if(p[i][0]*p[i][1]<0){
      ll a=abs(p[i][0])-1;
      ll b=abs(p[i][1])-1;
      g[a].EB(b,i);
      g[b].EB(a,i);
      deg[a]++;
      deg[b]++;
    }
    else{
      ll to1=abs(p[i][0])-1;
      ll to2=abs(p[i][1])-1;
      if(p[i][0]<0)ret[i]='0';
      else ret[i]='1';
      t[to1]=true;
      t[to2]=true;
    }
  }
  queue<ll>que;
  set<ll>rem;
  rep(i,0,n){
    if(deg[i]<=1)que.push(i);
    rem.insert(i);
  }
  while(1){
    if(rem.empty())break;
    if(que.empty()){
      que.push(*rem.begin());
    }
    auto idx=que.front();
    que.pop();
    if(!rem.count(idx))continue;
    rem.erase(idx);
    if(!t[idx]){
      P mx(-1,-1);
      for(auto e:g[idx]){
        if(ret[e.id]!='?')continue;
        chmax(mx,MP(deg[e.to],e.id));
      }
      if(mx.fi<0){
        judge=false;
        break;
      }
      ll k=0;
      ll other=-1;
      for(auto z:p[mx.se]){
        if(abs(z)-1==idx){
          k=z;
        }
        else other=abs(z)-1;
      }
      //assert(k!=0);
      if(k<0)ret[mx.se]='0';
      else ret[mx.se]='1';
      if(other!=-1){
        deg[other]--;
        if(deg[other]<=1&&rem.count(other))que.push(other);
      }
    }
  }
  rep(i,0,m)if(ret[i]=='?')ret[i]='1';
  ans2(judge);
  if(judge)cout<<ret<<endl;
  return 0;
}