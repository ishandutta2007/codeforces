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
using ll = int;
using ld = long double;
const ll MOD1 = 1e9+7;
const ll MOD9 = 998244353;
const ll INF = 1e9;
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
ostream &operator<<(ostream &os, pair<T1, T2>&p){
  return os << p.first << " " << p.second;
}  

string convert(ll n,ll bit){
  string ret(bit,'0');
  for(ll i=0;i<bit;i++)if(n&1LL<<bit-1-i)ret[i]='1';
  return ret;
}
string convert(ll n){
  ll bit=0;
  while(n>=1<<bit)bit++;
  return convert(n,max(1,bit));
}
ll convert(string s){
  ll ret=0;
  ll n=s.size();
  for(ll i=0;i<n;i++)if(s[i]=='1')ret|=1<<n-i-1;
  return ret;
}
template<long long iden, long long size>
struct Trie{
  struct Node{
    vector<ll>next;
    ll mi;
    Node():mi(INF){
       next.assign(size,-1);
    }
  };
  vector<Node>data;
  Trie(){
    data.emplace_back();
  }
  void add(const string &s, ll val,ll id){
    ll pos=0;
    for(ll i=0;i<s.size();i++){
      ll c = s[i] - iden;
      if(data[pos].next[c]==-1){
        data[pos].next[c]=data.size();
        data.emplace_back();
      }
      chmin(data[pos].mi,val);
      pos = data[pos].next[c];
    }
    chmin(data[pos].mi,val);
  }
  void search(const string &s){
    ll pos=0;
    for(ll i=0;i<s.size();i++){
      ll c = s[i] - iden;
      if(data[pos].next[c]==-1)break;
      pos = data[pos].next[c];
    }
  }
  vector<ll>v;
  void dfs(ll pos, ll d,ll lim,string &comp,ll &ret){
    if(d==18)return;
    ll next0=data[pos].next[0];
    ll next1=data[pos].next[1];
    if(comp[d]=='0'){
      if(next1!=-1&&data[next1].mi<=lim){
        ret|=1<<17-d;
        dfs(next1,d+1,lim,comp,ret);
      }
      else if(next0!=-1&&data[next0].mi<=lim)dfs(next0,d+1,lim,comp,ret);
    }
    else if(comp[d]=='1'){
      if(next0!=-1&&data[next0].mi<=lim){
        dfs(next0,d+1,lim,comp,ret);
      }
      else if(next1!=-1&&data[next1].mi<=lim){
        ret|=1<<17-d;
        dfs(next1,d+1,lim,comp,ret);
      }
    }
  }
};
using trie = Trie<'0',2>;
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll q;cin>>q;
  vector<trie>tri(100005);
  const ll len=18;
  while(q--){
    ll t;cin>>t;
    if(t==1){
      ll u;cin>>u;
      string input=convert(u,len);
      for(ll j=1;j*j<=u;j++){
        if(u%j==0){
          tri[j].add(input,u,0);
          if(u/j!=j)tri[u/j].add(input,u,0);
        }
      }
    }
    else{
      ll x,k,s;cin>>x>>k>>s;
      if(x%k!=0){
        cout<<-1<<endl;
        continue;
      }
      ll ret=0;
      string input=convert(x,len);
      tri[k].dfs(0,0,s-x,input,ret);
      ans(ret==0,-1,ret);
    }
  }
  return 0;
}