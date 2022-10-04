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
template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2>&p){
  return os << p.first << " " << p.second;
}  
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n,k;cin>>n>>k;
  string s;cin>>s;
  ll cntl=0,mxl=-1,mxmove=0;
  vector<ll>idx;
  rep(i,0,n){
    if(s[i]=='L'){
      mxmove+=i-cntl;
      idx.PB(i);
      chmax(mxl,i-cntl);
      cntl++;
    }
  }
  //cout<<mxl spa mxmove<<endl;
  if(mxmove<k){
    cout<<-1<<endl;
    return 0;
  }
  vector<vector<ll>>ret(k);
  ll sz=idx.size();
  queue<P>que;
  rep(i,0,sz){
    if(idx[i]!=i&&(i==0||idx[i-1]!=idx[i]-1))que.emplace(i,-1);
  }
  //cout<<que.size()<<endl;
  rep(i,0,k){
    ll pre=-1;
    while(!que.empty()){
      auto q=que.front();
      //cout<<i spa q<<endl;
      if(q.se==i)break;
      que.pop();
      ret[i].PB(idx[q.fi]);
      idx[q.fi]--;
      if(idx[q.fi]!=q.fi&&(q.fi==0||idx[q.fi-1]!=idx[q.fi]-1)){
        que.emplace(q.fi,i);
        //cout<<"bool"<<idx[q.fi] spa q.fi spa i<<endl;
      }
      if(q.fi!=sz-1&&idx[q.fi]+2==idx[q.fi+1]){
        //cout<<"2bool"<<q.fi spa i<<endl;
        que.emplace(q.fi+1,i);
      }
      mxmove--;
      if(k-i-1==mxmove)break;
    }
    //cout<<que.size()<<endl;
    //ebug(idx,sz);
  }
  rep(i,0,sz)if(idx[i]!=i)judge=false;
  if(!judge){
    cout<<-1<<endl;
    return 0;
  }

  rep(i,0,k){
    cout<<ret[i].size();
    for(auto z:ret[i])cout<<" "<<z;
    cout<<endl;
  }
  return 0;
}