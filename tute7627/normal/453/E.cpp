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

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  int n;cin>>n;
  int sz=sqrt(n);
  int num=(n+sz-1)/sz;
  vector<int>s(n),t(n),r(n);
  rep(i,0,n)cin>>s[i]>>t[i]>>r[i];
  struct Node{
    int l,r;
    ll add;
    vector<int>c;
    vector<ll>cm,cr;
    vector<int>tm,tr;
    vector<ll>now;
    Node()=default;
    void build(int nl,int nr,vector<int>&s,vector<int>&m,vector<int>&rr){
      l=nl,r=nr;
      c.assign(r-l,0);
      cm.assign(r-l+1,0);
      cr.assign(r-l+1,0);
      tm.assign(r-l,0);
      tr.assign(r-l,0);
      now.assign(r-l,0);
      int len=r-l;
      rep(i,0,r-l){
        tm[i]=m[i+l];
        tr[i]=rr[i+l];
        now[i]=s[i+l];
        if(rr[i+l]!=0)c[i]=(tm[i]+rr[i+l]-1)/rr[i+l];
        else c[i]=2e9;
      }
      vector<ll>ord(len);
      iota(ALL(ord),0);
      sort(ALL(ord),[&](int i,int j){return c[i]<c[j];});
      rearrange(ord,c);
      rep(i,0,len){
        cm[i+1]=cm[i]+m[ord[i]+l];
        cr[i+1]=cr[i]+rr[ord[i]+l];
      }
      add=0;

    }
    void upd(ll x){
      add+=x;
    }
    ll query(int nl,int nr){
      ll ret=0;
      //cout<<l spa nl spa r spa nr<<endl;
      if(l>=nl&&r<=nr){
        //cout<<nl spa nr spa now.empty()<<endl;
        if(now.empty()){
          int idx=upper_bound(ALL(c),add)-c.begin();
          //cout<<add spa idx<<endl;
          //debug(c,r-l);
          //debug(cm,r-l+1);
          //debug(cr,r-l+1);
          ret+=cm[idx];
          ret+=(cr.back()-cr[idx])*add;
          add=0;
        }
        else{
          //cout<<l spa r spa add spa add<<endl;
          rep(i,0,r-l){
            now[i]=min(now[i]+add*tr[i],(ll)tm[i]);
            ret+=now[i];
          }
          add=0;
          now.clear();
        }
      }
      else if(!(nr<=l||nl>=r)){
        if(now.empty())now.assign(r-l,0);
        //cout<<l spa r spa add spa add<<endl;
        rep(i,0,r-l){
          now[i]=min(now[i]+add*tr[i],(ll)tm[i]);
        }
        rep(i,max(0,nl-l),min(r,nr)-l){
          ret+=now[i];
          now[i]=0;
        }
        add=0;
      }
      return ret;
    }
  };
  vector<Node>v(num);
  rep(i,0,num){
    v[i].build(i*sz,min<ll>((i+1)*sz,n),s,t,r);
  }
  int q;cin>>q;
  int pre=0;
  while(q--){
    int ti,l,r;cin>>ti>>l>>r;l--;
    ll ret=0;
    rep(i,0,num){
      v[i].upd(ti-pre);
      //cout<<v[i].now.empty()<<endl;
      ll ar=v[i].query(l,r);;
      //cout<<v[i].l spa v[i].r spa ar<<endl;
      ret+=ar;
    }
    pre=ti;
    cout<<ret<<endl;
  }
  return 0;
}