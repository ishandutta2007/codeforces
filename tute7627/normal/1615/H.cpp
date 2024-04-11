//#define _GLIBCXX_DEBUG

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define lfs cout<<fixed<<setprecision(10)
#define ALL(a)  (a).begin(),(a).end()
#define ALLR(a)  (a).rbegin(),(a).rend()
#define UNIQUE(a) (a).erase(unique((a).begin(),(a).end()),(a).end())
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
template<typename T> using PQ = priority_queue<T>;
template<typename T> using QP = priority_queue<T,vector<T>,greater<T>>;
template<typename T1, typename T2>bool chmin(T1 &a,T2 b){if(a>b){a=b;return true;}else return false;}
template<typename T1, typename T2>bool chmax(T1 &a,T2 b){if(a<b){a=b;return true;}else return false;}
ll median(ll a,ll b, ll c){return a+b+c-max({a,b,c})-min({a,b,c});}
void ans1(bool x){if(x) cout<<"Yes"<<endl;else cout<<"No"<<endl;}
void ans2(bool x){if(x) cout<<"YES"<<endl;else cout<<"NO"<<endl;}
void ans3(bool x){if(x) cout<<"Yay!"<<endl;else cout<<":("<<endl;}
template<typename T1,typename T2>void ans(bool x,T1 y,T2 z){if(x)cout<<y<<endl;else cout<<z<<endl;}  
template<typename T1,typename T2,typename T3>void anss(T1 x,T2 y,T3 z){ans(x!=y,x,z);};  
template<typename T>void debug(const T &v,ll h,ll w,string sv=" "){for(ll i=0;i<h;i++){cout<<v[i][0];for(ll j=1;j<w;j++)cout<<sv<<v[i][j];cout<<endl;}};
template<typename T>void debug(const T &v,ll n,string sv=" "){if(n!=0)cout<<v[0];for(ll i=1;i<n;i++)cout<<sv<<v[i];cout<<endl;};
template<typename T>void debug(const vector<T>&v){debug(v,v.size());}
template<typename T>void debug(const vector<vector<T>>&v){for(auto &vv:v)debug(vv,vv.size());}
template<typename T>void debug(stack<T> st){while(!st.empty()){cout<<st.top()<<" ";st.pop();}cout<<endl;}
template<typename T>void debug(queue<T> st){while(!st.empty()){cout<<st.front()<<" ";st.pop();}cout<<endl;}
template<typename T>void debug(deque<T> st){while(!st.empty()){cout<<st.front()<<" ";st.pop_front();}cout<<endl;}
template<typename T>void debug(PQ<T> st){while(!st.empty()){cout<<st.top()<<" ";st.pop();}cout<<endl;}
template<typename T>void debug(QP<T> st){while(!st.empty()){cout<<st.top()<<" ";st.pop();}cout<<endl;}
template<typename T>void debug(const set<T>&v){for(auto z:v)cout<<z<<" ";cout<<endl;}
template<typename T>void debug(const multiset<T>&v){for(auto z:v)cout<<z<<" ";cout<<endl;}
template<typename T,size_t size>void debug(const array<T, size> &a){for(auto z:a)cout<<z<<" ";cout<<endl;}
template<typename T,typename V>void debug(const map<T,V>&v){for(auto z:v)cout<<"["<<z.first<<"]="<<z.second<<",";cout<<endl;}
template<typename T>vector<vector<T>>vec(ll x, ll y, T w){vector<vector<T>>v(x,vector<T>(y,w));return v;}
ll gcd(ll x,ll y){ll r;while(y!=0&&(r=x%y)!=0){x=y;y=r;}return y==0?x:y;}
vector<ll>dx={1,-1,0,0,1,1,-1,-1};vector<ll>dy={0,0,1,-1,1,-1,1,-1};
template<typename T>vector<T> make_v(size_t a,T b){return vector<T>(a,b);}
template<typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v(ts...))>(a,make_v(ts...));}
template<typename T1, typename T2>ostream &operator<<(ostream &os, const pair<T1, T2>&p){return os << p.first << " " << p.second;}
template<typename T>ostream &operator<<(ostream &os, const vector<T> &v){for(auto &z:v)os << z << " ";cout<<"|"; return os;}
template<typename T>void rearrange(vector<int>&ord, vector<T>&v){
  auto tmp = v;
  for(int i=0;i<tmp.size();i++)v[i] = tmp[ord[i]];
}
template<typename Head, typename... Tail>void rearrange(vector<int>&ord,Head&& head, Tail&&... tail){
  rearrange(ord, head);
  rearrange(ord, tail...);
}
template<typename T> vector<int> ascend(const vector<T>&v){
  vector<int>ord(v.size());iota(ord.begin(),ord.end(),0);
  sort(ord.begin(),ord.end(),[&](int i,int j){return v[i]<v[j];});
  return ord;
}
template<typename T> vector<int> descend(const vector<T>&v){
  vector<int>ord(v.size());iota(ord.begin(),ord.end(),0);
  sort(ord.begin(),ord.end(),[&](int i,int j){return v[i]>v[j];});
  return ord;
}
ll FLOOR(ll n,ll div){assert(div>0);return n>=0?n/div:(n-div+1)/div;}
ll CEIL(ll n,ll div){assert(div>0);return n>=0?(n+div-1)/div:n/div;}
ll digitsum(ll n){ll ret=0;while(n){ret+=n%10;n/=10;}return ret;}
ll modulo(ll n,ll d){return (n%d+d)%d;};
template<typename T>T min(const vector<T>&v){return *min_element(v.begin(),v.end());}
template<typename T>T max(const vector<T>&v){return *max_element(v.begin(),v.end());}
template<typename T>T acc(const vector<T>&v){return accumulate(v.begin(),v.end(),T(0));};
template<typename T>T reverse(const T &v){return T(v.rbegin(),v.rend());};
//mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
int popcount(ll x){return __builtin_popcountll(x);};
int poplow(ll x){return __builtin_ctzll(x);};
int pophigh(ll x){return 63 - __builtin_clzll(x);};
template<typename T>T poll(queue<T> &q){auto ret=q.front();q.pop();return ret;};
template<typename T>T poll(priority_queue<T> &q){auto ret=q.top();q.pop();return ret;};
template<typename T>T poll(QP<T> &q){auto ret=q.top();q.pop();return ret;};
template<typename T>T poll(stack<T> &s){auto ret=s.top();s.pop();return ret;};
ll MULT(ll x,ll y){if(LLONG_MAX/x<=y)return LLONG_MAX;return x*y;}
ll POW2(ll x, ll k){ll ret=1,mul=x;while(k){if(mul==LLONG_MAX)return LLONG_MAX;if(k&1)ret=MULT(ret,mul);mul=MULT(mul,mul);k>>=1;}return ret;}
ll POW(ll x, ll k){ll ret=1;for(int i=0;i<k;i++){if(LLONG_MAX/x<=ret)return LLONG_MAX;ret*=x;}return ret;}
template< typename T = int >
struct edge {
  int to;
  T cost;
  int id;
  edge():id(-1){};
  edge(int to, T cost = 1, int id = -1):to(to), cost(cost), id(id){}
  operator int() const { return to; }
};

template<typename T>
using Graph = vector<vector<edge<T>>>;
template<typename T>
Graph<T>revgraph(const Graph<T> &g){
  Graph<T>ret(g.size());
  for(int i=0;i<g.size();i++){
    for(auto e:g[i]){
      int to = e.to;
      e.to = i;
      ret[to].push_back(e);
    }
  }
  return ret;
}
template<typename T>
Graph<T> readGraph(int n,int m,int indexed=1,bool directed=false,bool weighted=false){
  Graph<T> ret(n);
  for(int es = 0; es < m; es++){
    int u,v;
    T w=1;
    cin>>u>>v;u-=indexed,v-=indexed;
    if(weighted)cin>>w;
    ret[u].emplace_back(v,w,es);
    if(!directed)ret[v].emplace_back(u,w,es);
  }
  return ret;
}
template<typename T>
Graph<T> readParent(int n,int indexed=1,bool directed=true){
  Graph<T>ret(n);
  for(int i=1;i<n;i++){
    int p;cin>>p;
    p-=indexed;
    ret[p].emplace_back(i);
    if(!directed)ret[i].emplace_back(p);
  }
  return ret;
}
//BEGIN CUT HERE
// O(m^2 \log m \log U)
// U: maximum capacity
enum Objective{
  MINIMIZE = +1,
  MAXIMIZE = -1,
};
template<typename Flow, typename Cost,
         Objective objective = Objective::MINIMIZE>
struct MinCostFlow{
  template<typename T> inline void chmin(T &x,T y){x=min(x,y);}

  struct Edge{
    int src,dst;
    Flow flow,cap;
    Cost cost;
    int rev;
    Edge(int src,int dst,Flow cap,Cost cost,int rev):
      src(src),dst(dst),flow(0),cap(cap),cost(cost),rev(rev){}
    Flow residual_cap()const{return cap-flow;}
  };

  struct EdgePtr{
    int v,e;
    EdgePtr(int v,int e):v(v),e(e){}
  };

  int n;
  vector<vector<Edge>> G;
  vector<Flow> b;
  vector<Cost> p;

  MinCostFlow(int n):n(n),G(n),b(n,0){}

  EdgePtr add_edge(int src,int dst,Flow lower,Flow upper,Cost cost){
    int e=G[src].size();
    int r=(src==dst?e+1:G[dst].size());
    assert(lower<=upper);
    G[src].emplace_back(src,dst,+upper,+cost*objective,r);
    G[dst].emplace_back(dst,src,-lower,-cost*objective,e);
    return EdgePtr(src,e);
  }

  const Edge &get_edge(EdgePtr ep)const{return G[ep.v][ep.e];}

  void push(Edge &e,Flow amount){
    e.flow+=amount;
    G[e.dst][e.rev].flow-=amount;
  }

  void add_supply(int v,Flow amount){b[v]+=amount;}
  void add_demand(int v,Flow amount){b[v]-=amount;}

  Cost residual_cost(const Edge &e){
    return e.cost+p[e.src]-p[e.dst];
  }

  vector<int> excess_vs,deficit_vs;
  void saturate_negative(const Flow delta){
    for(auto &es:G){
      for(auto &e:es){
        Flow cap=e.residual_cap();
        cap-=cap%delta;
        if(cap<0 or residual_cost(e)<0){
          push(e,cap);
          b[e.src]-=cap;
          b[e.dst]+=cap;
        }
      }
    }

    excess_vs.clear();
    deficit_vs.clear();
    for(int v=0;v<n;v++){
      if(b[v]>0) excess_vs.emplace_back(v);
      if(b[v]<0) deficit_vs.emplace_back(v);
    }
  }

  const Cost unreachable = std::numeric_limits<Cost>::max();
  Cost farthest;
  vector<Cost> dist;
  vector<Edge*> parent;

  struct P{
    Cost first;
    int second;
    P(Cost first,int second):first(first),second(second){}
    bool operator<(const P o)const{return first>o.first;}
  };

  priority_queue<P> pq;

  template<typename Predicate>
  void eliminate(vector<int> &vs,Predicate predicate){
    vs.erase(remove_if(begin(vs),end(vs),predicate),end(vs));
  }

  bool dual(const Flow delta){
    eliminate(excess_vs, [&](int v){return b[v]<+delta;});
    eliminate(deficit_vs,[&](int v){return b[v]>-delta;});

    dist.assign(n,unreachable);
    for(int v:excess_vs) pq.emplace(dist[v]=0,v);

    parent.assign(n,nullptr);
    auto emplace=[&](Edge& e){
      if(e.residual_cap()<delta) return;
      Cost nxt=dist[e.src]+residual_cost(e);
      if(nxt>=dist[e.dst]) return;
      pq.emplace(dist[e.dst]=nxt,e.dst);
      parent[e.dst]=&e;
    };

    farthest=0;
    int deficit_count=0;
    while(!pq.empty()){
      Cost d=pq.top().first;
      int v=pq.top().second;
      pq.pop();
      if(dist[v]<d) continue;
      farthest=d;

      if(b[v]<=-delta) deficit_count++;
      if(deficit_count>=(int)deficit_vs.size()) break;

      for(auto &e:G[v]) emplace(e);
    }
    pq=decltype(pq)();

    for(int v=0;v<n;v++)
      p[v]+=min(dist[v],farthest);

    return deficit_count>0;
  }

  void primal(const Flow delta){
    for(int t:deficit_vs){
      if(dist[t]>farthest) continue;
      Flow f=-b[t];
      int v;
      for(v=t;parent[v];v=parent[v]->src)
        chmin(f,parent[v]->residual_cap());
      chmin(f,b[v]);

      f-=f%delta;
      if(f<=0) continue;

      for(v=t;parent[v];){
        auto &e=*parent[v];
        push(e,f);
        int u=parent[v]->src;
        if(e.residual_cap()<=0) parent[v]=nullptr;
        v=u;
      }
      b[t]+=f;
      b[v]-=f;
    }
  }

  template<Flow SCALING_FACTOR=2>
  bool build(){
    p.resize(n);
    Flow max_flow=1;
    for(auto t:b) max_flow=max({max_flow,t,-t});
    for(auto &es:G)
      for(auto &e:es)
        max_flow=max({max_flow,e.residual_cap(),-e.residual_cap()});

    Flow delta=1;
    while(delta<max_flow) delta*=SCALING_FACTOR;
    for(;delta;delta/=SCALING_FACTOR){
      saturate_negative(delta);
      while(dual(delta)) primal(delta);
    }

    return excess_vs.empty() and deficit_vs.empty();
  }

  template<typename T=Cost>
  T get_cost(){
    T res=0;
    for(auto &es:G)
      for(auto &e:es)
        res+=T(e.flow)*T(e.cost)/T(objective);
    return res/T(2);
  }
  template<typename T=Cost> T get_gain(){return get_cost();}

  vector<Cost> get_potential(){
    fill(p.begin(),p.end(),0);
    for(int i=0;i<n;i++)
      for(auto &es:G)
        for(auto &e:es)
          if(e.residual_cap()>0)
            chmin(p[e.dst],p[e.src]+e.cost);
    return p;
  }
};

template<typename Flow, typename Cost>
using MaxGainFlow = MinCostFlow<Flow, Cost, Objective::MAXIMIZE>;
//END CUT HERE
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
	ll n,m;cin>>n>>m;
	vector<ll>a(n);
	rep(i,0,n)cin>>a[i];
	MinCostFlow<ll,ll>mcf(n+1);
	rep(i,0,n){
		mcf.add_edge(n,i,0,1,a[i]);
		mcf.add_edge(i,n,0,1,-a[i]);
	}
	ll inf=10000;
	rep(i,0,m){
		ll u,v;cin>>u>>v;u--;v--;
		mcf.add_edge(v,u,0,inf,0);
	}
	assert(mcf.build());
	auto p=mcf.get_potential();
	//cout<<mcf.get_cost()<<endl;
	vector<ll>ret(n);
	rep(i,0,n)ret[i]=(p[i]-p[n]);
	debug(ret);
  return 0;
}