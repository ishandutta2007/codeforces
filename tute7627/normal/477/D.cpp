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
template< int mod >
struct ModInt {
  int x;

  ModInt() : x(0) {}

  ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

  ModInt &operator+=(const ModInt &p) {
    if((x += p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator-=(const ModInt &p) {
    if((x += mod - p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator*=(const ModInt &p) {
    x = (int) (1LL * x * p.x % mod);
    return *this;
  }

  ModInt &operator/=(const ModInt &p) {
    *this *= p.inverse();
    return *this;
  }

  ModInt operator-() const { return ModInt(-x); }

  friend ModInt operator+(const ModInt& lhs, const ModInt& rhs) {
        return ModInt(lhs) += rhs;
  }
  friend ModInt operator-(const ModInt& lhs, const ModInt& rhs) {
        return ModInt(lhs) -= rhs;
  }
  friend ModInt operator*(const ModInt& lhs, const ModInt& rhs) {
        return ModInt(lhs) *= rhs;
  }
  friend ModInt operator/(const ModInt& lhs, const ModInt& rhs) {
        return ModInt(lhs) /= rhs;
  }

  bool operator==(const ModInt &p) const { return x == p.x; }

  bool operator!=(const ModInt &p) const { return x != p.x; }

  ModInt inverse() const {
    int a = x, b = mod, u = 1, v = 0, t;
    while(b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ModInt(u);
  }

  ModInt pow(int64_t n) const {
    ModInt ret(1), mul(x);
    while(n > 0) {
      if(n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  friend ostream &operator<<(ostream &os, const ModInt &p) {
    return os << p.x;
  }

  friend istream &operator>>(istream &is, ModInt &a) {
    int64_t t;
    is >> t;
    a = ModInt< mod >(t);
    return (is);
  }

  static int get_mod() { return mod; }
};
using modint = ModInt< MOD1 >;modint pow(ll n, ll x){return modint(n).pow(x);}modint pow(modint n, ll x){return n.pow(x);}
//using modint=ld;
struct SuffixArray{
  ll size;
  string str;
  vector<ll>data, rank;
  SuffixArray(string S):size(S.size()),str(S){
    str += '$';//-1,str[i]+input,,kind
    vector<ll>input(str.size());
    for(ll i=0;i<str.size();i++)input[i] = str[i];
    data = induced_sort(input, 200);
    data.erase(data.begin()); data.push_back(size);
    str.pop_back();
    rank.assign(size,0);
    for(ll i=0;i<size;i++){
      rank[data[i]] = i;
    }
  }
  vector<ll> induced_sort(vector<ll>t, ll kind){
    ll sz = t.size();
    vector<bool>ls(sz);//trueL,falseS
    for(ll i = sz-1;i>=0;i--){
      if(i==sz-1)ls[i] = false;
      else{
        if(t[i]!=t[i+1])ls[i] = (t[i] > t[i+1]);
        else ls[i] = ls[i+1];
      }
    }
    vector<ll>cnt(kind);
    for(ll i=0;i<sz;i++)cnt[t[i]]++;
    vector<P>lr(kind,MP(-1,-1));
    for(ll i=1;i<kind;i++){
      if(cnt[i]==0)lr[i] = lr[i-1];
      else lr[i] = make_pair(lr[i-1].se + 1, lr[i-1].se + cnt[i]);
    }
    vector<ll>lmsidx,ret(sz,-1);
    for(ll i=0;i<sz-1;i++){
      if(ls[i]&&!ls[i+1]){
        ret[lr[t[i+1]].fi+cnt[t[i+1]]-1]=i+1;
        cnt[t[i+1]]--;
        lmsidx.push_back(i+1);
      }
    }
    fill(ALL(cnt),0);
    for(ll i=0;i<sz;i++){
      if(ret[i]>=1&&ls[ret[i]-1]){
        ret[lr[t[ret[i]-1]].fi+cnt[t[ret[i]-1]]]=ret[i]-1;
        cnt[t[ret[i]-1]]++;
        if(i!=0&&!ls[ret[i]])ret[i]=-1;
      }
    }
    fill(ALL(cnt),0);
    for(ll i=sz-1;i>=1;i--){
      if(ret[i]>=1&&!ls[ret[i]-1]){
        ret[lr[t[ret[i]-1]].se-cnt[t[ret[i]-1]]]=ret[i]-1;
        cnt[t[ret[i]-1]]++;
      }
    }
    vector<ll>rev_lmsidx(sz,-1),lmsinput(lmsidx.size(),-1);
    for(ll i=0;i<lmsidx.size();i++)rev_lmsidx[lmsidx[i]] = i;
    ll kindnum=1; 
    lmsinput[rev_lmsidx[ret[0]]] = 1;
    vector<ll>comp(t.begin()+ret[0],t.end());
    for(ll i=1;i<sz;i++){
      if(ret[i]>=1&&ls[ret[i]-1]&&!ls[ret[i]]){
        vector<ll>tmp(t.begin()+ret[i],t.begin()+lmsidx[rev_lmsidx[ret[i]]+1]+1); 
        if(comp != tmp){
          kindnum++;
          comp = tmp;
        }
        lmsinput[rev_lmsidx[ret[i]]] = kindnum;
      }
    }
    vector<ll>output;
    if(kindnum==lmsidx.size()){
      output.assign(kindnum,-1);
      for(ll i=0;i<lmsinput.size();i++)output[lmsinput[i]-1]=i;
    }
    else output = induced_sort(lmsinput,kindnum+1);
    
    fill(ALL(cnt),0), fill(ALL(ret),-1);
    for(ll i=output.size()-1;i>=0;i--){
      ll tmp=lmsidx[output[i]];
      ret[lr[t[tmp]].se - cnt[t[tmp]]]=tmp;
      cnt[t[tmp]]++;
    }
    fill(ALL(cnt),0);
    for(ll i=0;i<sz;i++){
      if(ret[i]>=1&&ls[ret[i]-1]){
        ret[lr[t[ret[i]-1]].fi+cnt[t[ret[i]-1]]]=ret[i]-1;
        cnt[t[ret[i]-1]]++;
        if(i!=0&&!ls[ret[i]])ret[i]=-1;
      }
    }
    fill(ALL(cnt),0);
    for(ll i=sz-1;i>=1;i--){
      if(ret[i]>=1&&!ls[ret[i]-1]){
        ret[lr[t[ret[i]-1]].se-cnt[t[ret[i]-1]]]=ret[i]-1;
        cnt[t[ret[i]-1]]++;
      }
    }
    return ret;
  }
  ll operator[](ll x) const {
    return data[x];
  }
  ll lower_bound(string x){
    ll le=-1,ri=str.size();
    while(ri-le>=2){
      ll mid=(le+ri)/2;
      ll cnt=0;
      while(cnt<x.size()&&data[mid]+cnt<str.size()
        &&x[cnt]==str[data[mid]+cnt])cnt++;
      if(cnt==x.size())ri=mid;
      else if(data[mid]+cnt==str.size())le=mid;
      else if(x[cnt]<=str[data[mid]+cnt])ri=mid;
      else le=mid;
    }
    return ri;
  }
  ll upper_bound(string x){
    x.back()++;
    return lower_bound(x);
  }
  vector<ll> lcp(){
    vector<ll>ret(size);
    for(ll i=0,h=0;i<size;i++){
      if(rank[i]==0)continue;
      for(ll j=data[rank[i]-1];max(i,j)+h<size&&str[i+h]==str[j+h];h++);
      ret[rank[i]-1] = h;
      if(h>0) h--;
    }
    return ret;
  }
};
template<typename T, typename F>
struct DisjointSparseTable{
  int n;
  vector<vector<T>>data;
  const F func;
  DisjointSparseTable(vector<T>&v, const F &f):func(f),n(v.size()){
    int num=0;
    while((1<<num)<v.size())num++;
    data.assign(num+5,vector<T>(n+1, T()));
    if(n>=1)data[0][n-1]=v[n-1];
    for(int i=1;i<n;i++){
      int k = __builtin_ctz(i);
      data[k][i-1]=v[i-1];
      if(i!=n)data[k][i]=v[i];
      int l=i-(1<<k),r=min(n,i+(1<<k));
      for(int j=i-2;j>=l;j--)data[k][j]=func(v[j],data[k][j+1]);
      for(int j=i+1;j<r;j++)data[k][j]=func(data[k][j-1],v[j]);
    }
  }
  T query(int l,int r){//[l,r)
    r--;
    if(l==r)return data[0][l];
    ll k=31-__builtin_clz(l^r);
    return func(data[k][l],data[k][r]);
  }
};
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
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  string s;cin>>s;
  ll n=s.size();
  auto dp1=vec(n+1,n+1,INF);
  auto dp2=vec(n+1,n+1,modint(0));
  dp1[0][0]=0;
  dp2[0][0]=1;
  SuffixArray sa(s);
  auto lcp=sa.lcp();
  auto fmi=[&](ll i,ll j){return min(i,j);};
  DisjointSparseTable dst(lcp,fmi);
  //ij
  rep(i,0,n){
    rep(j,0,i+1){
      ll pre1=INF;
      modint pre2=0;
      for(ll o=j;o<=n;o+=i+1){
        auto exec=[&](){
          chmin(dp1[i+1][o],pre1);
          dp2[i+1][o]+=pre2;
          pre1=INF;
          pre2=0;
        };
        chmin(dp1[i+1][o],dp1[i][o]);
        dp2[i+1][o]+=dp2[i][o];
        if(o+i+1<=n&&s[o]=='1'){
          bool comp=false;
          if(o+(i+1)*2<=n){
            if(sa.rank[o]<sa.rank[o+i+1])comp=true;
            else if(dst.query(sa.rank[o+i+1],sa.rank[o])>=i+1)comp=true;
          }
          modint add=dp2[i+1][o];
          ll mi=dp1[i+1][o]+1;
          if(comp){
            dp2[i+1][o+i+1]+=add;
            chmin(dp1[i+1][o+i+1],mi);
            exec();
          }
          else{
            exec();
            pre1=mi;
            pre2=add;
          }
        }
        else exec();
      }
    }
  }
  cout<<dp2[n][n]<<endl;
  P ret(INF,INF);
  auto calc=[&](P x){
    ll last=convert(s.substr(n-x.fi));
    return x.se+last;
  };
  auto comp=[&](P x,P y){
    if(max(x.fi,y.fi)>=30)return min(x,y);
    else{
      //cout<<x spa y spa calc(x) spa calc(y)<<endl;
      if(calc(x)<calc(y))return x;
      else return y;
    }
  };
  //debug(dp1,n+1,n+1);cout<<endl;
  //debug(dp2,n+1,n+1);cout<<endl;
  rep(i,1,n+1)if(dp1[i][n]!=INF)ret=comp(ret,MP(i,dp1[i][n]));
  modint num=ret.se;
  modint tmp=1;
  //cout<<ret<<endl;
  rrep(i,n-ret.fi,n){
    if(s[i]=='1')num+=tmp;
    tmp*=2;
    //cout<<i spa tmp<<endl;
  }
  cout<<num<<endl;
  return 0;
}