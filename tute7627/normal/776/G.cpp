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
#define rrep(i,n,m) for(ll i = (m) - 1; i >= (ll)(n); i--)
using ll = long long;
using ld = long double;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const ll INF = 1e18;
using P = pair<ll, ll>;
template<typename T>
bool chmin(T &a,T b){if(a>b){a=b;return true;}else return false;}
template<typename T>
bool chmax(T &a,T b){if(a<b){a=b;return true;}else return false;}
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
  ll res=0,buf=0;
  bool judge = true;
  auto dic=vec(1<<16,16,0LL);
  rep(i,0,1<<16){
    bitset<16> k=i;
    ll mx=-1;
    ll tmp=i;
    while(tmp){
      chmax(mx,tmp%16);
      tmp/=16;
    }
    rep(j,0,mx+1)if(k[mx])dic[i][j]++;
    rep(j,mx+1,16)if(k[j])dic[i][j]++;
    if(i!=0)rep(j,0,16)dic[i][j]+=dic[i-1][j];
  }
  map<char,ll>mp;
  rep(i,0,10)mp[i+'0']=i;
  rep(i,'a','g')mp[i]=i-'a'+10;
  //debug(dic,1<<6,16);
  auto solve=[&](string s){
    ll n=s.size();
    if(n==1&&s.back()=='0')return 0LL;
    auto dp=make_v(n,16,2,0LL);
    dp[0][0][0]=1;
    rep(i,0,n-3){
      rep(j,0,16){
        rep(o,0,16){
          dp[i+1][max(o,j)][1]+=dp[i][j][1];
          if(mp[s[i]]>o)dp[i+1][max(o,j)][1]+=dp[i][j][0];
          if(mp[s[i]]==o)dp[i+1][max(o,j)][0]+=dp[i][j][0];
        }
      }
    }
    ll ret=0;
    ll tmp;
    if(n>=4)tmp=stoll(s.substr(n-4,4),nullptr,16LL);
    else tmp=stoll(s,nullptr,16LL);
    rep(i,0,16){
      ret+=dic[(1<<16)-1][i]*dp[max(0LL,n-4)][i][1];
      ret+=dic[tmp][i]*dp[max(0LL,n-4)][i][0];
    }
    return ret;
  };
  ll q;cin>>q;
  while(q--){
    string l,r;cin>>l>>r;
    ll n=solve(r);
    ll tmp=stoll(l,nullptr,16);
    if(tmp>=1){
      tmp--;
      stringstream ss;
      ss<<hex<<tmp;
      auto str=ss.str();
      ll m=solve(str);
      n-=m;
    }
    cout<<dec<<n<<endl;
  }
  return 0;
}