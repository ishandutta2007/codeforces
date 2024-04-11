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
using ll = int;
using ld = long double;
const ll MOD1 = 1e9+7;
const ll MOD9 = 998244353;
const ll INF = 1e9;
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
int popcount(ll x){return __builtin_popcountll(x);};
int poplow(ll x){return __builtin_ctzll(x);};
int pophigh(ll x){return 63 - __builtin_clzll(x);};
string convert(ll n,ll bit){
  string ret(bit,'0');
  for(ll i=0;i<bit;i++)if(n&1LL<<bit-1-i)ret[i]='1';
  return ret;
}
/*string convert(ll n){
  ll bit=0;
  while(n>=1<<bit)bit++;
  return convert(n,max(1LL,bit));
}*/
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
template<ll base, ll sz>
struct Bits{
  vector<ll>data;
  ll value;
  Bits(){data.assign(sz,0);};
  Bits(ll k):value(k){
    data.assign(sz,0);
    build(k);
  }
  void build(ll k){
    for(ll i=0;i<sz;i++){
      data[i] = k % base;
      k /= base;
    }
  }
  Bits &operator=(const ll k){
    fill(ALL(this->data),0);
    this->build(k);
  } 
  ll &operator[](const ll k){
    return this->data.at(k);
  }
  static ll pow(ll k){
    ll ret=1;
    while(k--)ret *= base;
    return ret;
  }
  void print(){
    for(ll i=sz-1;i>=0;i--){
      if(i!=sz-1)cout<<" ";
      cout<<data[i];
    }
    cout<<endl;
  }
};
using bits = Bits<3,12>;
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  int w,n,m;cin>>w>>n>>m;
  int lim=bits::pow(w);
  vector<int>cnt(lim);
  vector<int>a(n);
  vector<int>th(w+1,1);
  rep(i,0,w)th[i+1]=th[i]*3;
  rep(i,0,n){
    cin>>a[i];
    auto tmp=convert_base(a[i],w,2);
    cnt[convert_base(tmp,3)]++;
  }
  rep(i,0,w){
    rep(j,0,lim){
      bits x=j;
      if(x[i]!=2)cnt[j+th[i]*(2-x[i])]+=cnt[j];
    }
  }
  //debug(cnt,lim);
  rep(i,0,m){
    string s;cin>>s;
    long long ret=0;
    auto v=vec(w,2,0);
    rep(i,0,w){
      if(s[w-i-1]=='A')v[i]={th[i]*2,0};
      if(s[w-i-1]=='O')v[i]={0,-1};
      if(s[w-i-1]=='X')v[i]={0,th[i]};
      if(s[w-i-1]=='a')v[i]={-1,th[i]};
      if(s[w-i-1]=='o')v[i]={th[i],th[i]*2};
      if(s[w-i-1]=='x')v[i]={th[i],0};
    }
    auto dfs=[&](auto &&f,ll p,ll q,ll d)->void{
      if(d==w){
        //bits tp=p,tq=q;
        //cout<<p spa q spa cnt[p] spa cnt[q]<<endl;
        //tp.print();tq.print();
        ret+=cnt[p]*cnt[q];
        return;
      }
      rep(i,0,2){
        if(v[d][i]!=-1)f(f,p,q+v[d][i],d+1);
        p+=th[d];
      }
    };
    dfs(dfs,0,0,0);
    cout<<ret<<endl;
  }
  return 0;
}