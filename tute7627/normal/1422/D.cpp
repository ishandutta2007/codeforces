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
struct edge {
  ll to,cost;
  edge(ll x,ll y):to(x),cost(y){};
};
ll MAX_V = 4e5 + 5;
vector<ll> dist(MAX_V);
void dijkstra(ll s,vector<vector<edge>>&g) {
    priority_queue<P, vector<P>, greater<P> > que;
    fill(dist.begin(),dist.begin()+g.size(), INF);
    dist[s] = 0;
    que.emplace(0, s);
    while (!que.empty()) {
        P p = que.top();
        que.pop();
        ll v = p.second;
        if (dist[v] < p.first) continue;
        for(auto e:g[v]) {
            if (dist[e.to] > dist[v] + e.cost) {
                dist[e.to] = dist[v] + e.cost;
                que.emplace(dist[e.to], e.to);
            }
        }
    }
}
template<typename T>
map<T,ll> compress(vector<T> &v){
  sort(ALL(v));
  v.erase(unique(ALL(v)),v.end());
  map<T, ll> ret;
  for(ll i=0;i<(ll)v.size();i++)
    ret[v[i]]=i;
  return ret;
}
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n,m;cin>>n>>m;
  ll sx,sy,fx,fy;cin>>sx>>sy>>fx>>fy;
  vector<ll>x(m),y(m);
  rep(i,0,m)cin>>x[i]>>y[i];
  auto vx=x,vy=y;
  auto mx=compress(vx),my=compress(vy);
  ll szx=mx.size(),szy=my.size();
  //debug(vx,szx);
  //debug(vy,szy);
  vector<vector<edge>>g(m+szx+szy+2);
  ll S=g.size()-2,T=g.size()-1;
  rep(i,0,szx-1){
    g[m+i].EB(m+i+1,vx[i+1]-vx[i]);
    g[m+i+1].EB(m+i,vx[i+1]-vx[i]);
  }
  rep(i,0,szy-1){
    g[m+szx+i].EB(m+szx+i+1,vy[i+1]-vy[i]);
    g[m+szx+i+1].EB(m+szx+i,vy[i+1]-vy[i]);
  }
  rep(i,0,m){
    ll ax=mx[x[i]]+m;
    ll ay=my[y[i]]+m+szx;
    g[i].EB(ax,0);
    g[ax].EB(i,0);
    g[i].EB(ay,0);
    g[ay].EB(i,0);
  }
  rep(i,0,szx){
    g[S].EB(i+m,abs(sx-vx[i]));
    //g[i+m].EB(T,abs(fx-vx[i]));
  }
  rep(i,0,szy){
    g[S].EB(i+m+szx,abs(sy-vy[i]));
    //g[i+m+szx].EB(T,abs(fy-vy[i]));
  }
  //g[S].EB(T,abs(sx-fx)+abs(sy-fy));
  ll ret=abs(sx-fx)+abs(sy-fy);
  dijkstra(S,g);
  //debug(dist,g.size());
  rep(i,0,m)chmin(ret,dist[i]+abs(fx-x[i])+abs(fy-y[i]));
  cout<<ret<<endl;
  return 0;
}