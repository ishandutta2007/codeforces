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
struct Lowlink{
  vector<vector<int>>G;
  int size;
  vector<int>ord,low,used;
  vector<int>articulation;
  vector<pair<int,int>>bridge;
  Lowlink(vector<vector<int>>&g):G(g){
    size = G.size();
    ord.assign(size,-1);
    low.assign(size,-1);
    used.assign(size,0);
    int tmp=0;
    for(int i=0;i<size;i++){
      if(!used[i]){
        dfs(i,tmp,-1);
      }
    }
  }
  void dfs(int k,int &num,int par){
    ord[k] = num;
    low[k] = num;
    num++;
    used[k] = 1;
    int cnt=0;
    bool is_articulation=false;
    bool multiple=false;
    for(int i=0;i<G[k].size();i++){
      if(!multiple&&par==G[k][i]){
        multiple=true;
        continue;
      }
      if(used[G[k][i]]){
        chmin(low[k],ord[G[k][i]]);
      }
      else{
        cnt++;
        dfs(G[k][i],num,k);
        chmin(low[k],low[G[k][i]]);
        if(ord[k]<low[G[k][i]])bridge.emplace_back(k,G[k][i]);
        if(ord[k]<=low[G[k][i]]&&par!=-1)is_articulation=true;
      }
    }
    if(par==-1&&cnt>=2)is_articulation=true;
    if(is_articulation)articulation.push_back(k);
    return; 
  }
  vector<int>index_tecc;//
  vector<vector<int>>edges_tecc;
  int TECC(){
    index_tecc.assign(G.size(),-1);
    int cnt=0;
    for(int i=0;i<size;i++){
      if(index_tecc[i]==-1)dfs_tecc(i,-1,cnt);
    }
    edges_tecc.assign(cnt+1,vector<int>());
    for(int i=0;i<bridge.size();i++){
      int u=index_tecc[bridge[i].fi],v=index_tecc[bridge[i].se];
      edges_tecc[u].push_back(v);
      edges_tecc[v].push_back(u);
    }
    return *max_element(index_tecc.begin(),index_tecc.end())+1;
  }
  void dfs_tecc(int k,int par,int &group){
    if(par==-1||ord[par]<low[k]){
      index_tecc[k] = group++;
    }
    else index_tecc[k] = index_tecc[par];
    for(int i=0;i<G[k].size();i++){
      if(index_tecc[G[k][i]]==-1)dfs_tecc(G[k][i],k,group);
    }
  }
  vector<vector<pair<int, int>>>bcc;
  stack<pair<int, int>>tmp;
  void BCC(){
    used.assign(G.size(), false);
    for(int i=0;i<G.size();i++){
      if(!used[i]){
        dfs_bcc(i, -1);
      }
    }
  }
  void dfs_bcc(int k, int par){
    used[k]=true;
    for(auto to:G[k]){
      if(to==par)continue;
      if(!used[to] | ord[to] < ord[k]){
        tmp.emplace(minmax(k, to));
      }
      if(!used[to]){
        dfs_bcc(to, k);
        if(low[to] >= ord[k]){
          bcc.emplace_back();
          while(1){
            auto e = tmp.top();
            bcc.back().emplace_back(e);
            tmp.pop();
            if(e.first == min(k, to) && e.second == max(k, to))break;
          }
        }
      }
    }
  }
  vector<vector<int>>bct_edges;
  vector<int>bct_index;
  vector<bool>art;
  void makeBCT(){
    assert(bcc.empty());
    BCC();
    art.assign(G.size(), false);
    bct_index.assign(G.size(), -1);
    for(auto v:articulation){
      bct_index[v] = bct_edges.size();
      bct_edges.emplace_back();
      art[v] = true;
    }
    vector<bool>check(G.size(),false);
    for(auto &ev:bcc){
      int idx = bct_edges.size();
      bct_edges.emplace_back();
      queue<int>rev;
      for(auto &e:ev){
        for(auto &v:{e.first, e.second}){
          if(art[v]&&!check[v]){
            rev.push(v);
            check[v] = true;
            bct_edges[idx].push_back(bct_index[v]);
            bct_edges[bct_index[v]].push_back(idx);
          }
          else if(!art[v]){
            bct_index[v] = idx;
          }
        }
      }
      while(!rev.empty()){
        check[rev.front()] = false;
        rev.pop();
      }
    }
  }
};

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n,m;cin>>n>>m;
  vector<vector<int>>g(n);
  vector<P>e;
  rep(i,0,m){
    ll u,v;cin>>u>>v;u--;v--;
    g[u].PB(v);
    g[v].PB(u);
    e.PB(minmax(u,v));
  }
  Lowlink low(g);
  low.makeBCT();
  /*debug(low.bct_index,n);
  for(auto g:low.bct_edges){
    for(auto to:g)cout<<to<<" ";cout<<endl;
  }*/
  /*for(auto z:low.bcc){
    for(auto zz:z)cout<<zz<<"|";
    cout<<endl;
  }*/
  auto bc=low.bcc;
  //cout<<low.bcc.size()<<endl;
  /*rep(i,0,bc.size()){
    cout<<i<<endl;
    for(auto z:bc[i])cout<<z<<endl;
  }*/
  ll sz=bc.size();
  vector<set<ll>>num(sz);
  vector<ll>lar(sz);
  set<P>st;
  rep(i,0,sz){
    for(auto z:bc[i]){
      num[i].insert(z.fi);
      num[i].insert(z.se);
    }
    if(bc[i].size()==num[i].size()){
      for(auto z:bc[i])st.insert(minmax(z.fi,z.se));
    }
  }
  vector<ll>ret;
  rep(i,0,m){
    if(st.count(e[i]))ret.PB(i+1);
  }
  cout<<ret.size()<<endl;
  debug(ret,ret.size());
  return 0;
}