#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ALL(a)  (a).begin(),(a).end()
#define ALLR(a)  (a).rbegin(),(a).rend()
#define spa << " " <<
#define test cout<<"test"<<endl;
#define fi first
#define se second
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define rep(i,n,m) for(ll i = n; i < (ll)(m); i++)
#define rrep(i,n,m) for(ll i = m - 1; i >= (ll)(n); i--)
using ll = long long;
using ld = long double;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const ll INF = 1e18;
using P = pair<ll, ll>;
template<typename T>
void chmin(T &a,T b){if(a>b)a=b;}
template<typename T>
void chmax(T &a,T b){if(a<b)a=b;}
void pmod(ll &a,ll b){a=(a+b)%MOD;}
void pmod(ll &a,ll b,ll c){a=(b+c)%MOD;}
void qmod(ll &a,ll b){a=(a*b)%MOD;}
void qmod(ll &a,ll b,ll c){a=(b*c)%MOD;}
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

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(10);
  ll res=0,buf=0;
  bool judge = true;
  ll t;cin>>t;
  while(t--){
    ll k;cin>>k;
    string s,a,b;cin>>s>>a>>b;
    ll n=s.size();
    ll idx=n;
    vector<ll>ans(k,-1);
    set<ll>used;
    judge=true;
    bool judgebuf=false;
    rep(i,0,n){
      if(a[i]!=b[i]){
        idx=i;
        break;
      }
      if(ans[s[i]-'a']!=a[i]-'a'&&(ans[s[i]-'a']!=-1||used.count(a[i]-'a'))){
        judge=false;
        break;
      }
      ans[s[i]-'a']=a[i]-'a';
      used.insert(a[i]-'a');
      if(i==n-1)judgebuf=true;
    }
    //cout<<judgebuf<<endl;
    if(judge&&!judgebuf&&idx!=n){
      ll l=a[idx]-'a',r=b[idx]-'a';
      //cout<<l spa r<<endl;
      rep(i,l+1,r){
        //cout<<i<<endl;
        //cout<<ans[s[i]-'a'] spa !used.count(i)<<endl;
        if(ans[s[idx]-'a']==i||(ans[s[idx]-'a']==-1&&!used.count(i))){
          judgebuf=true;
          ans[s[idx]-'a']=i;
          //cout<<i<<endl;
          break;
        }
      }
    }
    //cout<<judgebuf<<endl;
    if(judge&&!judgebuf&&idx<n){
      auto tmp=ans;
      auto tmp_used=used;
      if(tmp[s[idx]-'a']!=a[idx]-'a'&&(tmp[s[idx]-'a']!=-1||tmp_used.count(a[idx]-'a')));
      else{
        //test;
        tmp[s[idx]-'a']=a[idx]-'a';
        tmp_used.insert(a[idx]-'a');
        if(idx==n-1){
          judgebuf=true;
          ans=tmp;
        }
        //cout<<idx<<endl;
        rep(i,idx+1,n){
          ll l=a[i]-'a',r=k;
          rep(j,l+1,r){
            if(tmp[s[i]-'a']==j||(tmp[s[i]-'a']==-1&&!tmp_used.count(j))){
            judgebuf=true;
            //cout<<i spa j spa tmp[s[i]-'a']<<endl;
            tmp[s[i]-'a']=j;
            ans=tmp;
            break;
            }
          }
          if(judgebuf)break;
          if(tmp[s[i]-'a']!=a[i]-'a'&&(tmp[s[i]-'a']!=-1||tmp_used.count(a[i]-'a')))break;
          tmp[s[i]-'a']=a[i]-'a';
          tmp_used.insert(a[i]-'a');
          if(i==n-1){
            //test;
            judgebuf=true;
            ans=tmp;
          }
      }
      }
    }
    //cout<<judgebuf<<endl;
    if(judge&&!judgebuf&&idx<n){
      auto tmp=ans;
      auto tmp_used=used;
      //cout<<tmp[s[idx]-'a'] spa b[idx]-'a' spa 
      if(tmp[s[idx]-'a']!=b[idx]-'a'&&(tmp[s[idx]-'a']!=-1||tmp_used.count(b[idx]-'a')));
      else{
      tmp[s[idx]-'a']=b[idx]-'a';
      tmp_used.insert(b[idx]-'a');
      if(idx==n-1){
          judgebuf=true;
          ans=tmp;
        }
      rep(i,idx+1,n){
        ll l=0,r=b[i]-'a';
        rep(j,l,r){
          if(tmp[s[i]-'a']==j||(tmp[s[i]-'a']==-1&&!tmp_used.count(j))){
          judgebuf=true;
          tmp[s[i]-'a']=j;
          ans=tmp;
          break;
          }
        }
        if(judgebuf)break;
        if(tmp[s[i]-'a']!=b[i]-'a'&&(tmp[s[i]-'a']!=-1||tmp_used.count(b[i]-'a')))break;
        tmp[s[i]-'a']=b[i]-'a';
        tmp_used.insert(b[i]-'a');
        if(i==n-1){
          judgebuf=true;
          ans=tmp;
        }
      }
      }
    }
    //debug(ans,k);
    if(judge&&judgebuf){
      cout<<"YES"<<endl;
      set<ll>st;
      //debug(ans,k);
      rep(i,0,k)st.insert(i);
      rep(i,0,k){
        if(ans[i]!=-1)st.erase(ans[i]);
      }
      rep(i,0,k){
        if(ans[i]!=-1){
          cout<<char(ans[i]+'a');
        }
        else{
          ans[i]=*st.begin();
          cout<<char(*st.begin()+'a');
          st.erase(st.begin());
        }
      }
      cout<<endl;
      /*rep(i,0,n){
        cout<<char(ans[s[i]-'a']+'a');
      }
      cout<<endl;*/
    }
    else cout<<"NO"<<endl;
  }
  return 0;
}