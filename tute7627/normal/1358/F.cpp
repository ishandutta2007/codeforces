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
void print(ll x){
  if(x==0)cout<<"IMPOSSIBLE"<<endl;
  if(x==1)cout<<"SMALL"<<endl;
  if(x==2)cout<<"BIG"<<endl;
}
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n;cin>>n;
  vector<ll>a(n),b(n);
  rep(i,0,n)cin>>a[i];
  rep(i,0,n)cin>>b[i];

  if(n==1){
    if(a==b){
      print(1);
      cout<<0<<endl;
    }
    else print(0);
    return 0;
  }
  if(n==2){
    vector<pair<char,ll>>ret;
    ll cnt=0;
    while(1){
      if(b[0]==b[1]||b[0]==0)break;
      else if(b[0]>b[1]){
        swap(b[0],b[1]);
        ret.EB('R',1);
      }
      else if(a[0]==b[0]||a[1]==b[0]){
        if(b[0]==min(a[0],a[1])){
          ll num=(b[1]-max(a[0],a[1]))/b[0];
          ret.EB('P',num);
          b[1]-=num*b[0];
          cnt+=num;
        }
        else{
          ll num=b[1]/b[0];
          ret.EB('P',num);
          cnt+=num;
          b[1]%=b[0];
        }
        if(a!=b){
          swap(b[0],b[1]);
          ret.EB('R',1);
        }
        break;
      }
      else{
        ll num=b[1]/b[0];
        ret.EB('P',num);
        cnt+=num;
        b[1]%=b[0];
      }
    }
    //debug(a,n);debug(b,n);
    if(a!=b){
      print(0);
      return 0;
    }
    if(cnt<=200000){
      print(1);
      string s;
      for(auto z:ret)s+=string(z.se,z.fi);
      reverse(ALL(s));
      cout<<s.size()<<endl;
      cout<<s<<endl;
    }
    else{
      print(2);
      cout<<cnt<<endl;
    }
    return 0;
  }
  string ret;
  ll cnt=0;
  while(judge){
    if(a==b)break;
    auto tmp=b;
    reverse(ALL(tmp));
    if(tmp==a){
      ret+='R';
      reverse(ALL(b));
      break;
    }
    if(b[0]>b[n-1]){
      reverse(ALL(b));
      ret+='R';
    }
    else{
      ll now=0;
      rrep(i,1,n){
        b[i]-=b[i-1];
        if(b[i]<=0)judge=false;
      }
      ret+='P';
      cnt++;
    }
  }
  if(a==b){
    if(cnt>200000){
      print(2);
      cout<<cnt<<endl;
      return 0;
    }
    print(1);
    cout<<ret.size()<<endl;
    reverse(ALL(ret));
    cout<<ret<<endl;
  }
  else{
    print(0);
  }
  return 0;
}