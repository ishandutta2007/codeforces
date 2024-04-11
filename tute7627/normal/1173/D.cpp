#include<bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long
#define ALL(a)  (a).begin(),(a).end()
#define ALLR(a)  (a).rbegin(),(a).rend()
#define spa << " " <<
#define MP make_pair
//ll MOD = 1e9+7;
ll MOD = 998244353;
ll INF = 1e18;
void chmin(ll &a,ll b){if(a>b)a=b;}
void chmax(ll &a,ll b){if(a<b)a=b;}
void pmod(ll &a,ll b){a=(a+b)%MOD;}
void qmod(ll &a,ll b){a=(a*b)%MOD;}
void ans1(bool x){if(x) cout<<"Yes"<<endl;else cout<<"No"<<endl;}
void ans2(bool x){if(x) cout<<"YES"<<endl;else cout<<"NO"<<endl;}
void ans3(bool x){if(x) cout<<"Yay!"<<endl;else cout<<":("<<endl;}
void ans(bool x, ll y, ll z){if(x)cout<<y<<endl;else cout<<z<<endl;}   
ll x=1;
vector<ll> y(250001);



vector<vector<ll>> a(250001);//()
vector<ll>t(250001);//
ll dfs(ll k){
  t[k]=1;
  ll ans=1;
  ll z=0;
  for(ll i=0;i<a[k].size();i++){
    if(t[a[k][i]]==0){
      qmod(ans,dfs(a[k][i]));
      z++; 
    }
  }
  if(k!=0){
  qmod(ans,y[z+1]);
  }
  else qmod(ans,y[z]);
  //cout<<ans<<endl;
  return ans;
}

int main(){
  ll i,j,o;
  ll result=INF,buf=0,buf1=0,buf2=0,buf3=0,buf4=0;
  bool judge = true;
  ll n; cin>>n;
  ll p,q;
  for(i=0;i<n-1;i++){
    cin>>p>>q;
    a[p-1].push_back(q-1);
    a[q-1].push_back(p-1);
  }
  for(i=1;i<=250000;i++){
  qmod(x,i);
  y[i]=x;
  }

  result=dfs(0);
  qmod(result,n);
  cout<<result<<endl;
  return 0;
}