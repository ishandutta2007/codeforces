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
  ll n;cin>>n;
  vector<ll>a(n);
  rep(i,0,n)cin>>a[i];
  string op;cin>>op;
  vector<bool>t(3);
  for(auto c:op){
    if(c=='+')t[0]=1;
    if(c=='-')t[1]=1;
    if(c=='*')t[2]=1;
  }
  string ret;
  if(t[0]&&t[2]){
    vector<ll>b;
    ll cnt=0;
    rep(i,0,n){
      if(a[i]==1){
        cnt++;
      }
      else{
        if(cnt>0)b.PB(-cnt);
        cnt=0;
        b.PB(a[i]);
      }
    }
    if(cnt>0)b.PB(-cnt);
    ll l=0;
    const ll inf=1e12;
    ll sz=b.size();
    vector<ll>dp(sz+1);
    vector<ll>from(sz+1);
    while(l<sz){
      ll r=l;
      ll mul=1;
      while(r<sz&&b[r]!=0){
        mul=min(inf,mul*max(1LL,b[r]));
        r++;
      }
      if(l==r){
        ret+="0+";
        l++;
        continue;
      }
      ll tr=r;
      if(b[l]<0){
        rep(i,0,abs(b[l])){
          ret+="1+";
        }
        l++;
      }
      if(r>0&&b[r-1]<0)r--;
      if(mul==inf){
        rep(i,l,r){
          if(b[i]>0)ret+=max(1LL,b[i])+'0';
          else{
            rep(j,0,abs(b[i]))ret+="1*";
            ret.pop_back();
          }
          if(i+1==r)ret+='+';
          else ret+='*';
        }
      }
      else{
        rep(i,l,r+1){
          dp[i]=0;
          from[i]=-1;
        }
        rep(i,l,r){
          ll mul=1;
          rep(j,i+1,r+1){
            mul*=max(1LL,b[j-1]);
            ll val=0;
            if(j==i+1)val=abs(b[i]);
            else val=mul;
            if(chmax(dp[j],dp[i]+val))from[j]=i;
          } 
        }
        //debug(dp,sz+1);
        //debug(from,sz+1);
        //cout<<l spa r<<endl;
        //return 0;
        vector<string>rev;
        ll now=r;
        while(now>l){
          assert(from[now]!=-1);
          if(from[now]+1==now){
            rrep(i,from[now],now){
              if(b[i]<0){
                rep(j,0,abs(b[i])){
                  //cout<<j<<endl;
                  rev.PB("1+");
                }
              }
              else rev.PB(string(1,'0'+b[i])+"+");
            }
          }
          else{
            ll start=rev.size();
            rrep(i,from[now],now){
              if(b[i]<0)rep(j,0,abs(b[i]))rev.PB("1*");
              else{
                rev.PB(string(1,'0'+b[i])+"*");
              }
            }
            //for(auto s:rev)cout<<s<<" ";cout<<endl;
            //cout<<start spa rev.size() spa rev[start].size()<<endl;
            rev[start].pop_back();
            rev[start]+='+';
          }
          now=from[now];
        }
        reverse(ALL(rev));
        for(auto add:rev)ret+=add;
      }
      if(r!=tr&&l!=tr){
        rep(i,0,abs(b[r])){
          ret+="1+";
        }
      }
      l=tr;
    }
    while(!isdigit(ret.back()))ret.pop_back();
  }
  else if(t[0]){
    rep(i,0,n){
      ret+=a[i]+'0';
      if(i<n-1)ret+='+';
    }
  }
  else if(t[2]){
    ll st=-1;
    rep(i,0,n){
      if(t[1]&&a[i]==0&&st==-1){
        st=i;
        if(i>0)ret+='-';
      }
      else if(i>0)ret+='*';
      ret+=a[i]+'0';
    }
  }
  else{
    rep(i,0,n){
      ret+=a[i]+'0';
      if(i<n-1)ret+='-';
    }
  }
  cout<<ret<<endl;
  return 0;
}