#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ALL(a)  (a).begin(),(a).end()
#define ALLR(a)  (a).rbegin(),(a).rend()
#define spa << " " <<
#define test cout<<"test"<<endl;
#define fi first
#define se second
#define MP make_pair
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
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  //cout<<fixed<<setprecision(10);
  ll res=0,buf=0;
  bool judge = true;
  ll n,k;cin>>k>>n;
  vector<string>s(k);
  rep(i,0,k)cin>>s[i];
  sort(ALL(s));
  if(k==1||s[0]==s.back()){
    swap(s[0][0],s[0][1]);
    cout<<s[0]<<endl;
    return 0;
  }
  swap(s[0],s[s.size()-1]);
  vector<ll>pos;
  rep(i,0,n){
    if(s[0][i]!=s[1][i])pos.PB(i);
  }
  vector<string>can;
  judge=false;
  if(pos.size()<=4){
    rep(i,0,pos.size()){
      rep(j,0,n){
        if(j!=pos[i]){
          auto tmp=s[0];
          swap(tmp[j],tmp[pos[i]]);
          can.PB(tmp);
          tmp=s[1];
          swap(tmp[j],tmp[pos[i]]);
          can.PB(tmp);
        }
      }
    }
    can.PB(s[0]);
    can.PB(s[1]);
  }
  else{
    cout<<-1<<endl;
    return 0;
  }
  string r;
  rep(i,0,can.size()){
    bool judgebuf=true;
    bool canchange=false;
    //cout<<can[i]<<endl;
    map<char,ll>ch;
    rep(j,0,n){
      ch[can[i][j]]++;
    }
    for(auto z:ch)if(z.se>=2)canchange=true;
    rep(j,0,k){
      vector<ll>c;
      rep(o,0,n){
        if(can[i][o]!=s[j][o]){
          c.PB(can[i][o]);
          c.PB(s[j][o]);
        }
      }
      if(c.size()>4||c.size()==2)judgebuf=false;
      if(c.size()==4){
        if(c[0]!=c[3]||c[1]!=c[2])judgebuf=false;
      }
      if(c.size()==0&&!canchange)judgebuf=false;
    }
    if(judgebuf){
      judge=true;
      r=can[i];
      break;
    }
  }
  ans(judge,r,-1);
  return 0;
}