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

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n,m;cin>>n>>m;
  auto v=vec(n,m,deque<char>());
  auto t=vec(n,m,string());
  rep(i,0,n)rep(j,0,m){
    string s;cin>>s;
    for(auto c:s)v[i][j].push_back(c);
  }
  rep(i,0,n)rep(j,0,m)cin>>t[i][j];
  ll cnt=0;
  stringstream ss;
  auto print=[&](){
    rep(i,0,n){
      rep(j,0,m){
        rep(o,0,v[i][j].size())cout<<v[i][j][o];
        //if(v[i][j].empty())cout<<"|";
        cout<<"|";
      }
      cout<<endl;
    }
    cout<<endl;
  };
  auto ope=[&](ll x1,ll y1,ll x2,ll y2){
    assert((x1==x2)^(y1==y2));
    //if(!((x1==x2)^(y1==y2)))cout<<"as" spa x1 spa y1 spa x2 spa y2<<endl;
    assert(!v[x1][y1].empty());
    auto c=v[x1][y1].back();
    v[x1][y1].pop_back();
    v[x2][y2].push_front(c);
    cnt++;
    ss<<x1+1 spa y1+1 spa x2+1 spa y2+1<<endl;
    //print();
  };
  for(auto [i,j]:{MP(0LL,0LL),MP(n-1,m-1)}){
    while(!v[i][j].empty()){
      ope(i,j,n-1,0);
    }
  }
  rep(i,1,n-1)rep(j,1,m-1){
    while(!v[i][j].empty()){
      if(v[i][j].back()=='0')ope(i,j,0,j);
      else ope(i,j,n-1,j);
    }
  }
  rep(i,1,n-1){
    while(!v[i][0].empty()){
      if(v[i][0].back()=='0')ope(i,0,0,0);
      else ope(i,0,n-1,0);
    }
  }
  //return 0;
  rep(i,1,n-1){
    while(!v[i][m-1].empty()){
      if(v[i][m-1].back()=='0')ope(i,m-1,0,m-1);
      else ope(i,m-1,n-1,m-1);
    }
  }
  //return 0;
  rep(j,1,m-1){
    while(!v[0][j].empty()){
      if(v[0][j].back()=='0')ope(0,j,0,0);
      else ope(0,j,0,m-1);
    }
  }
  //return 0;
  rep(j,1,m-1){
    while(!v[n-1][j].empty()){
     if(v[n-1][j].back()=='0')ope(n-1,j,n-1,0);
     else ope(n-1,j,n-1,m-1);
    }
  }
  //return 0;
  for(auto [i,j]:{MP(0LL,m-1),MP(n-1,0LL)}){
    while(!v[i][j].empty()){
      if(v[i][j].back()=='0')ope(i,j,0,0);
      else ope(i,j,n-1,m-1);
    }
  }
  //return 0;
  auto exec=[&](ll i,ll j){
    //cout<<i spa j spa t[i][j]<<endl;
    reverse(ALL(t[i][j]));
    for(auto c:t[i][j]){
      if(c=='0'){
        if(i==0&&j==0){
          ope(0,0,n-1,0);
          ope(n-1,0,0,0);
        }
        else if(j!=m-1){
          if(i!=0)ope(0,0,i,0);
          if(j!=0)ope(i,0,i,j);
        }
        else{
          if(j!=0)ope(0,0,0,j);
          if(i!=0)ope(0,j,i,j);
        }
      }
      else{
        if(i==n-1&&j==m-1){
          ope(n-1,m-1,n-1,0);
          ope(n-1,0,n-1,m-1);
        }
        else if(j!=0){
          if(i!=n-1)ope(n-1,m-1,i,m-1);
          if(j!=m-1)ope(i,m-1,i,j);
        }
        else{
          if(j!=m-1)ope(n-1,m-1,n-1,j);
          if(i!=n-1)ope(n-1,j,i,j);
        }
      }
    }
  };
  vector<P>p;
  exec(0,0);exec(n-1,m-1);
  rep(i,1,n-1)rep(j,1,m-1)exec(i,j);
  rep(i,0,n)rep(j,0,m)if((i==0)^(j==0)^(i==n-1)^(j==m-1))exec(i,j);
  exec(n-1,0);exec(0,m-1);
  cout<<cnt<<endl;
  cout<<ss.str();
  return 0;
}