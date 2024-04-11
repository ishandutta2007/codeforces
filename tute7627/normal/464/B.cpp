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
  auto v=vec(8,3,0LL);
  rep(i,0,8)rep(j,0,3)cin>>v[i][j];
  vector<ll>p(8,0);
  rep(i,4,8)p[i]=1;
  vector<vector<ll>>tp;
  {
    vector<ll>tmp(3);
    iota(ALL(tmp),0);
    do{
      tp.PB(tmp);
    }while(next_permutation(ALL(tmp)));
  }
  auto calc=[&](vector<vector<ll>>v){
    for(auto &z:v)sort(ALL(z));
    sort(ALL(v));
    return v;
  };
  auto jud=calc(v);
  ll cnt=0;
  do{
    vector<ll>q;
    rep(i,0,8)if(p[i])q.PB(i);
    rep(tt,0,4){
      if(tt>0)swap(q[0],q[tt]);
      rep(i,0,216){
        vector<ll>vd(3);
        ll buf=i;
        rep(j,0,3){
          vd[j]=buf%6;
          buf/=6;
        }
        auto vt=vec(3,3,0LL);
        bool sw=true;
        rep(j,0,3)rep(o,0,3){
          vt[j][o]=v[q[j+1]][tp[vd[j]][o]]-v[q[0]][o];
        }
        rep(j,0,3){
          rep(o,j+1,3){
            if(vt[j][0]*vt[o][0]+vt[j][1]*vt[o][1]+vt[j][2]*vt[o][2]!=0)sw=false;
          }
        }
        vector<vector<ll>>tmp(8,v[q[0]]);
        rep(j,0,1<<3){
          rep(o,0,3){
            if(j&1<<o)rep(k,0,3)tmp[j][k]+=vt[o][k];
          }
        }
        sort(ALL(tmp));
        tmp.erase(unique(ALL(tmp)),tmp.end());
        if(tmp.size()<8)sw=false;
        if(jud!=calc(tmp))sw=false;
        if(!sw)continue;
        cout<<"YES"<<endl;
        map<vector<ll>,vector<ll>>mp;
        rep(j,0,8){
          sort(ALL(v[j]));
          mp[v[j]].PB(j);
        }
        auto ret=vec(8,3,0LL);
        rep(j,0,8){
          auto tmp2=tmp[j];
          sort(ALL(tmp2));
          ll idx=mp[tmp2].back();
          mp[tmp2].pop_back();
          ret[idx]=tmp[j];
        }
        debug(ret,8,3);
        return 0; 
      }
    }
    cnt++;
  }while(next_permutation(ALL(p)));
  //cout<<cnt<<endl;
  cout<<"NO"<<endl;
  return 0;
}