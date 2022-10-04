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
template<typename T1,typename T2, typename T3>
pair<bool,pair<ld,ld>>quadratic_equation(T1 k1,T2 k2,T3 k3){
  ld a=k1,b=k2,c=k3;
  ld eps=1e-10;
  if(b*b-4*a*c<-eps)return make_pair(false,make_pair(-1,-1));
  ld add=b*b-4*a*c;
  if(add<0)add=0;
  return make_pair(true,make_pair((-b+sqrt(add))/(2*a),(-b-sqrt(add))/(2*a)));
}
bool solve(ll n,ll m,ll sx,ll sy,vector<ll>&cnt1,ll t){
  vector<ll>cnt2(t);
  rep(i,0,n)rep(j,0,m)cnt2[abs(i-sx)+abs(j-sy)]++;
  rep(i,0,t)if(cnt1[i]!=cnt2[i])return false;
  return true;
}

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll t;cin>>t;
  vector<ll>a(t);
  ll mx=0;
  vector<ll>cnt(t+2);
  ll k1=-1,k2=-1;
  rep(i,0,t){
    cin>>a[i];
    cnt[a[i]]++;
    chmax(mx,a[i]);
  }
  rep(i,1,t+2){
    if(cnt[i]!=i*4&&k1==-1){
      k1=i-1;
    }
    if(k1!=-1&&k2==-1&&cnt[i]!=i*4-(2*(i-k1)-1)){
      k2=i-1;
    }
  }
  if(k1==-1||k2==-1){
    cout<<-1<<endl;
    return 0;
  }
  if(t%(k1+k2+1)==0){
    ll h=k1+k2+1,w=t/(k1+k2+1);
    ll sy1=mx-k2,sy2=w-k2-1;
    if(sy1>=0&&sy2>=0){
      if(solve(h,w,k1,sy1,cnt,t)){
        cout<<h spa w<<endl;
        cout<<k1+1 spa sy1+1<<endl;
        return 0;
      }
      if(solve(h,w,k1,sy2,cnt,t)){
        cout<<h spa w<<endl;
        cout<<k1+1 spa sy2+1<<endl;
        return 0;
      }
    }
  }
  auto p=quadratic_equation(-1,mx+k2-k1,(k1+1)*(mx+k2+1)-t);
  //cout<<k1 spa k2 spa mx spa p.se.fi spa p.se.se<<endl;
  if(p.fi){
    ll dw1=round(p.se.fi),dw2=round(p.se.se);
    ll dr1=mx-dw1,dr2=mx-dw2;
    ll h1=dw1+k1+1,h2=dw2+k1+1;
    ll w1=dr1+k2+1,w2=dr2+k2+1;
    //cout<<h1 spa w1 spa dr1 spa dw1<<endl;
    if(dw1>=0&&dr1>=0&&h1*w1==t){
      if(solve(h1,w1,k1,k2,cnt,t)){
        cout<<h1 spa w1<<endl;
        cout<<k1+1 spa k2+1<<endl;
        return 0;
      }
      if(solve(h1,w1,k1,dr1,cnt,t)){
        cout<<h1 spa w1<<endl;
        cout<<k1+1 spa dr1+1<<endl;
        return 0;
      }
    }
    if(dw2>=0&&dr2>=0&&h2*w2==t){
      if(solve(h2,w2,k1,k2,cnt,t)){
        cout<<h2 spa w2<<endl;
        cout<<k1+1 spa k2+1<<endl;
        return 0;
      }
      if(solve(h2,w2,k1,dr2,cnt,t)){
        cout<<h2 spa w2<<endl;
        cout<<k1+1 spa dr2+1<<endl;
        return 0;
      }
    }
  }
  cout<<-1<<endl;
  return 0;
}