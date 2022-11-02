#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cassert>
#define PB push_back
#define MP make_pair
#define sz(v) (in((v).size()))
#define forn(i,n) for(in i=0;i<(n);++i)
#define forv(i,v) forn(i,sz(v))
#define fors(i,s) for(auto i=(s).begin();i!=(s).end();++i)
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef long long in;
vector<vector<in> > dfs;
in n;
const in mdl=1000000007LL;
vector<in> fc,invfc;
in ncr(in a, in b){
  if(a<0 || a<b || b<0)
    return 0;
  return (((fc[a]*invfc[b])%mdl)*invfc[a-b])%mdl;
}
void mdf(in lv, in l, in r, in k){
  if(k==0){
    dfs[lv+1][l]++;
    dfs[lv+1][r+1]--;
    return;
  }
  mdf(lv+1,l,r,k-1);
  dfs[lv+1][r+1]-=ncr(r-l+k,k);
}
in pw(in a, in b){
  in r=1;
  for(in i=34;i>=0;i--){
    r*=r;
    r%=mdl;
    if((1LL<<i)&b){
      r*=a;
      r%=mdl;
    }
  }
  return r;
}
in inv(in a){
  return pw(a,mdl-2);
}
const in mk=104;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  in m;
  cin>>n>>m;
  dfs.resize(mk,vector<in>(n+mk,0));
  forn(i,n){
    cin>>dfs[0][i];
  }
  fc.resize(n+mk);
  invfc=fc;
  forn(i,n+mk){
    if(i==0)
      fc[i]=1;
    else
      fc[i]=(i*fc[i-1])%mdl;
    invfc[i]=inv(fc[i]);
  }
  in l,r,k;
  forn(i,m){
    cin>>l>>r>>k;
    l--;r--;
    mdf(0,l,r,k);
  }
  for(in j=mk-2;j>=0;j--){
    in cr=0;
    forv(i,dfs[j]){
      cr+=dfs[j+1][i];
      dfs[j][i]+=cr;
      dfs[j][i]%=mdl;
      cr%=mdl;
    }
  }
  forn(i,n)
    cout<<(dfs[0][i]+mdl)%mdl<<" ";
  cout<<endl;
  return 0;
}