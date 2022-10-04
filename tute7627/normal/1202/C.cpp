#include<bits/stdc++.h>
using namespace std;

#define ALL(a)  (a).begin(),(a).end()
#define ALLR(a)  (a).rbegin(),(a).rend()
#define spa << " " <<
#define test cout<<"test"<<endl;
#define fi first
#define se second
#define rep(i,n,m) for(ll i = n; i < (ll)(m); i++)
#define rrep(i,n,m) for(ll i = n - 1; i >= (ll)(m); i--)
typedef long long ll;
typedef long double ld;
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
void debug(vector<vector<ll>>v,ll h,ll w){for(ll i=0;i<h;i++)
{cout<<v[i][0];for(ll j=1;j<w;j++)cout spa v[i][j];cout<<endl;}};
void debug(vector<string>v,ll h,ll w){for(ll i=0;i<h;i++)
{for(ll j=0;j<w;j++)cout<<v[i][j];cout<<endl;}};
void debug(vector<ll>v,ll n){cout<<v[0];
for(ll i=1;i<n;i++)cout spa v[i];cout<<endl;};
vector<vector<ll>>vec(ll x, ll y, ll w){
  vector<vector<ll>>v(x,vector<ll>(y,w));return v;}
ll gcd(ll x,ll y){ll r;while((r=x%y)!=0){x=y;y=r;}return y;}
//m.emplace(x,0).fi->se++;

int main(){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  ll res=0,res1=INF,res2=-INF,buf=0;
  bool judge = true;
  ll t;cin>>t;
  vector<string>s(t);
  rep(i,0,t)cin>>s[i];
  rep(i,0,t){
    ll n=s[i].size();
    ll bufx=0;
    ll bufy=0;
    ll maxx=0,minx=0,maxy=0,miny=0;
    ll wpl=0,wpr=0,spl=0,spr=0,apl=0,apr=0,dpl=0,dpr=0;
    rep(j,0,n){
      switch(s[i][j]){
        case 'W':bufy++;
        if(bufy>=maxy)wpr=j;
        if(bufy>maxy){chmax(maxy,bufy);wpl=j;}
        break;
        case 'S':bufy--;
        if(bufy<=miny)spr=j;
        if(bufy<miny){chmin(miny,bufy);spl=j;}
        break;
        case 'A':bufx--;
        if(bufx<=minx)apr=j;
        if(bufx<minx){chmin(minx,bufx);apl=j;}
        break;
        case 'D':bufx++;
        if(bufx>=maxx)dpr=j;
        if(bufx>maxx){chmax(maxx,bufx);dpl=j;}
        break;
      }
      
    }
    ll ret=max(1LL,(maxy-miny+1))*max(1LL,(maxx-minx+1));
    //cout<<ret spa maxx spa minx spa maxy spa miny<<endl;
    if(apl>dpr)chmin(ret,max(1LL,(maxy-miny+1))*max(2LL,(maxx-minx)));
    if(dpl>apr)chmin(ret,max(1LL,(maxy-miny+1))*max(2LL,(maxx-minx)));
    if(spl>wpr)chmin(ret,max(2LL,(maxy-miny))*max(1LL,(maxx-minx+1)));
    if(wpl>spr)chmin(ret,max(2LL,(maxy-miny))*max(1LL,(maxx-minx+1)));
    cout<<ret<<endl;
  }

  return 0;
}