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
template<typename T>void rearrange(vector<ll>&ord, vector<T>&v){
  auto tmp = v;
  for(int i=0;i<tmp.size();i++)v[i] = tmp[ord[i]];
}
template<typename Head, typename... Tail>void rearrange(vector<ll>&ord,Head&& head, Tail&&... tail){
  rearrange(ord, head);
  rearrange(ord, tail...);
}
//mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
int popcount(ll x){return __builtin_popcountll(x);};
int poplow(ll x){return __builtin_ctzll(x);};
int pophigh(ll x){return 63 - __builtin_clzll(x);};
void solve(){
  ll n,m;cin>>n>>m;
  vector<vector<int>>ng(n);
  rep(i,0,m){
    ll l,r;cin>>l>>r;
    l--;r--;
    ng[l].PB(r);
    ng[r].PB(l);
  }
  rep(i,0,n)sort(ALL(ng[i]));
  set<int>rem;
  rep(i,0,n)rem.insert(i);
  vector<vector<int>>g(n);
  vector<int>d(n);
  rep(i,0,n){
    if(!rem.count(i))continue;
    queue<int>que;
    que.push(i);
    rem.erase(i);
    while(!que.empty()){
      auto p=que.front();
      que.pop();
      for(auto itr=rem.begin();itr!=rem.end();){
        if(binary_search(ALL(ng[p]),*itr))itr++;
        else{
          g[p].PB(*itr);
          g[*itr].PB(p);
          d[*itr]++;
          d[p]++;
          que.push(*itr);
          itr=rem.erase(itr);
        }
      }
    }
  }
  //debug(d,n);
  queue<int>que;
  vector<int>p(n),q(n);
  int now=1;
  rep(i,0,n){
    if(d[i]==1)que.push(i);
    if(d[i]==0){
      p[i]=now,q[i]=now;
      now++;
    }
  }
  vector<vector<int>>v(n);
  while(!que.empty()){
    auto x=que.front();
    //cout<<x<<endl;
    que.pop();
    if(!v[x].empty()){
      for(auto to:g[x]){
        if(d[to]==1&&v[to].empty()){
          v[x].PB(to);
          d[to]=0;
        }
      }
      int sz=v[x].size();
      //cout<<x <<"+";debug(v[x],sz);
      rep(i,0,sz)p[v[x][i]]=now+i,q[v[x][i]]=now+i+1;
      p[x]=now+sz,q[x]=now;
      now+=sz+1;
    }
    else{
      if(d[x]==0)continue;
      for(auto to:g[x]){
        if(d[to]!=0){
          v[to].PB(x);
          break;
        }
      }
    }
    for(auto to:g[x]){
      d[to]--;
      if(d[to]==1)que.push(to);
    }
    d[x]=0;
  }
  debug(p,n);
  debug(q,n);
}
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll t;cin>>t;
  while(t--){
    solve();
  }
  return 0;
}