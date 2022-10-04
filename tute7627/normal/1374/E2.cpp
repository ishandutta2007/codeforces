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

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  vector<vector<ll>>v(4);
  vector<vector<P>>p(4);
  ll n,m,k;cin>>n>>m>>k;
  rep(i,0,n){
    ll t,a,b;cin>>t>>a>>b;
    a*=2;
    v[a^b].PB(t);
    p[a^b].EB(t,i);
  }
  rep(i,0,4)sort(ALL(v[i]));
  vector<ll>sz(4);
  rep(i,0,4)sz[i]=v[i].size();
  vector<vector<ll>>cum(4);
  rep(i,0,4){
    cum[i].assign(sz[i]+1,0);
    rep(j,0,sz[i])cum[i][j+1]=cum[i][j]+v[i][j];
  }
  P mx(INF,INF);
  priority_queue<ll>q1;
  priority_queue<ll,vector<ll>,greater<ll>>q2;
  ll sum=0;
  rep(i,0,sz[0])q2.push(v[0][i]);//,sum+=v[0][i];
  rep(i,k,sz[1])q2.push(v[1][i]);//,sum+=v[1][i];
  rep(i,k,sz[2])q2.push(v[2][i]);//,sum+=v[2][i];
  //debug(sz,4);
  rep(i,0,sz[3]+1){
    //cout<<i spa k-i spa sz[1] spa sz[2]<<endl;
    //cout<<i spa q1.size() spa q2.size()<<endl;
    if(sz[2]<k-i||sz[1]<k-i){
      if(k-i>=1){
      rep(j,1,3){
        //cout<<sz[j] spa k-i-1<<endl; 
        if(sz[j]>k-i-1){
          ll add=v[j][k-i-1];
          if(!q1.empty()&&add<q1.top()){
            sum+=add;
            q1.push(add);
          }
          else q2.push(add);
        }
      }
      }
      continue;
    }
    ll tmp=cum[3][i]+cum[2][max(0LL,k-i)]+cum[1][max(0LL,k-i)];
    ll rem=m-(i+max(0LL,k-i)*2);
    //cout<<i spa rem spa tmp spa q1.size() spa q2.size()<<endl;
    if(rem>=0){
      while(!q2.empty()&&q1.size()<rem){
        q1.push(q2.top());sum+=q2.top();q2.pop();
      }
      while(!q1.empty()&&q1.size()>rem){
        q2.push(q1.top());sum-=q1.top();q1.pop();
      }
      if(q1.size()==rem)chmin(mx,MP(sum+tmp,i));
    }
    if(k-i>=1){
      rep(j,1,3){
        //cout<<sz[j] spa k-i-1<<endl; 
        if(sz[j]>k-i-1){
          ll add=v[j][k-i-1];
          if(!q1.empty()&&add<q1.top()){
            sum+=add;
            q1.push(add);
          }
          else q2.push(add);
        }
      }
    }
  }
  if(mx.fi==INF){
    cout<<-1<<endl;
    return 0;
  }
  rep(i,0,4)sort(ALL(p[i]));
  vector<ll>ret;
  vector<P>cand;
  rep(i,0,4){
    rep(j,0,sz[i]){
      if((i==3&&j<mx.se)||((i==1||i==2)&&j<k-mx.se))ret.PB(p[i][j].se+1);
      else cand.EB(p[i][j]);
    }
  }
  sort(ALL(cand));
  for(auto c:cand){
    if(ret.size()<m)ret.PB(c.se+1);
  }
  cout<<mx.fi<<endl;
  debug(ret,m);
  return 0;
}