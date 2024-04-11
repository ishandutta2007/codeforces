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
template<typename T>void rearrange(vector<ll>&ord, vector<T>&v){
  auto tmp = v;
  for(int i=0;i<tmp.size();i++)v[i] = tmp[ord[i]];
}
template<typename Head, typename... Tail>void rearrange(vector<ll>&ord,Head&& head, Tail&&... tail){
  rearrange(ord, head);
  rearrange(ord, tail...);
}
//mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
int popcount(ll x){return __builtin_popcountll(x);};
int poplow(ll x){return __builtin_ctzll(x);};
int pophigh(ll x){return 63 - __builtin_clzll(x);};
string convert(ll n,ll bit){
  string ret(bit,'0');
  for(ll i=0;i<bit;i++)if(n&1LL<<bit-1-i)ret[i]='1';
  return ret;
}
string convert(ll n){
  ll bit=0;
  while(n>=1<<bit)bit++;
  return convert(n,max(1LL,bit));
}
ll convert(string s){
  ll ret=0;
  ll n=s.size();
  for(ll i=0;i<n;i++)if(s[i]=='1')ret|=1LL<<n-i-1;
  return ret;
}
vector<ll> convert_base(ll n,ll m,ll base){
	vector<ll>ret(m,0);
	for(ll i=0;i<m;i++){
		ret[i]=n%base;
		n/=base;
	}
	return ret;
}
ll convert_base(vector<ll>v,ll base){
  ll tmp=1,ret=0;
  for(ll i=0;i<v.size();i++){
    ret+=v[i]*tmp;
    tmp*=base;
  }
  return ret;
}
vector<ll>tsort(vector<vector<ll>>&g){
  ll n = g.size();
  vector<ll>ret(n),ret2(n);
  vector<ll>v(n);
  for(ll i=0;i<n;i++)for(ll j=0;j<g[i].size();j++)v[g[i][j]]++;
  stack<ll>st;
  for(ll i=0;i<n;i++)if(v[i]==0)st.push(i);
  for(ll i=0;i<n;i++){
    if(st.empty())return vector<ll>();//
    ll x=st.top();
    st.pop();
    ret[x]=i;
    ret2[i]=x;
    for(ll j=0;j<g[x].size();j++){
      v[g[x][j]]--;
      if(v[g[x][j]]==0)st.push(g[x][j]);
    }
  }
  //ret:ret2:
  return ret2;
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
  ll n,m,k;cin>>n>>m>>k;
  vector<string>s(n),t(m);
  vector<ll>mt(m);
  rep(i,0,n)cin>>s[i];
  auto str=s;
  auto mp=compress(str);
  rep(i,0,m)cin>>t[i]>>mt[i],mt[i]--;
  ll sz=mp.size();
  vector<vector<ll>>g(sz);
  vector<ll>mi(sz,-1);
  rep(i,0,m){
    auto valt=mp[s[mt[i]]];
    rep(j,0,k)if(s[mt[i]][j]!=t[i][j]&&s[mt[i]][j]!='_')judge=false;
    rep(j,0,1<<k){
      string to=t[i];
      rep(o,0,k)if(j&1<<o)to[o]='_';
      if(mp.count(to)){
        auto val=mp[to];
        if(val!=valt)g[valt].PB(val);
      }
    }
    if(mi[valt]!=-1&&mi[valt]!=mt[i])judge=false;
    mi[valt]=mt[i];
  }
  //cout<<judge<<endl;
  auto v=tsort(g);
  if(v.empty()||!judge)cout<<"NO"<<endl;
  else{
    cout<<"YES"<<endl;
    vector<bool>used(n);
    vector<ll>ret;
    for(auto z:v){
      if(mi[z]!=-1){
        //cout<<mi[z]<<endl;
        ret.PB(mi[z]+1);
        used[mi[z]]=true;
      }
    }
    rep(i,0,n){
      if(!used[i]){
        ret.PB(i+1);
        //cout<<i<<endl;
      }
    }
    debug(ret,n);
  }
  return 0;
}