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
ll max_ret=-INF;
void dfs(ll d,ll n1,ll n2,vector<vector<P>>&t1,vector<vector<P>>&t2,vector<bool>&used,ll now){
  if(d==0){
    chmax(max_ret,now);
  }
  else{
    if(n1>=1){
      ll cnt=0;
      for(auto v:t1[d-1]){
        if(!used[v.se]){
          cnt++;
          used[v.se]=true;
          dfs(d-1,n1-1,n2,t1,t2,used,now+v.fi);
          used[v.se]=false;
        }
        if(cnt>=n1)break;
      }      
    }
    if(n2>=1){
      ll cnt=0;
      for(auto v:t2[d-1]){
        if(!used[v.se]){
          cnt++;
          used[v.se]=true;
          dfs(d-1,n1,n2-1,t1,t2,used,now+v.fi);
          used[v.se]=false;
        }
        if(cnt>=n2)break; 
      }     
    }
  }
}
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n,p,k;cin>>n>>p>>k;
  vector<P>a(n);
  rep(i,0,n){
    cin>>a[i].fi;
    a[i].se=i;
  }
  sort(ALLR(a));
  vector<vector<ll>>s=vec(n,p,0LL);
  rep(i,0,n)rep(j,0,p)cin>>s[i][j];
  rep(i,0,p+1){
    ll sum=0;
    rep(j,0,k+i)sum+=a[j].fi;
    vector<vector<P>>t1(p);
    vector<vector<P>>t2(p);
    vector<bool>used(n);
    rep(j2,0,n)rep(o,0,p){
      ll j=a[j2].se;
      if(j2<k+i)t1[o].EB(s[j][o]-a[j2].fi,j);
      else t2[o].EB(s[j][o],j);
    }
    rep(o,0,p){
      sort(ALLR(t1[o]));
      sort(ALLR(t2[o]));
    }
    max_ret=-INF;
    dfs(p,i,p-i,t1,t2,used,0);
    //cout<<i spa sum spa max_ret<<endl; 
    chmax(res,sum+max_ret);
  }
  cout<<res<<endl;
  return 0;
}