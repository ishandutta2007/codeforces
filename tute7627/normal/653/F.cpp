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
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n;cin>>n;
  string s;cin>>s;
  vector<ll>a(n+1);
  rep(i,0,n){
    a[i+1]=a[i]+(s[i]=='(')*2-1;
  }
  map<ll,vector<ll>>mp;
  rep(i,0,n+1){
    mp[a[i]].PB(i);
  }
  SuffixArray sa(s);
  auto lcp=sa.lcp();
  auto &rank=sa.rank;
  set<ll>st;
  st.insert(n+1);
  for(auto &z:mp){
    auto &v=z.se;
    rep(i,0,v.size()){
      if(v[i]==n){
        st.insert(v[i]);
        continue;
      }
      //cout<<z.fi spa i spa res<<endl;
      ll lim=*st.lower_bound(v[i]);
      ll back=v[i];
      if(rank[v[i]]!=0)back+=lcp[rank[v[i]]-1];
      //cout<<lim spa back<<endl;
      ll idxr=lower_bound(ALL(v),lim)-v.begin()-i-1;
      ll idxl=upper_bound(ALL(v),back)-v.begin()-i-1;
      res+=max(0LL,idxr-idxl);
      st.insert(v[i]);
    }
  }
  cout<<res<<endl;
  return 0;
}