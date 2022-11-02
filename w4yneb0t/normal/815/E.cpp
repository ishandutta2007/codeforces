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
typedef vector<in> VI;
typedef vector<VI> VVI;
map<pair<in,in>, in> ct;
in nmv(in n, in md){
  if(ct.count(MP(n,md)))
    return ct[MP(n,md)];
  if(n==0)
    return ct[MP(n,md)]=0;
  in mdl=(n-1)/2;
  if(mdl+1<md)
    return ct[MP(n,md)]=0;
  return ct[MP(n,md)]=1+nmv(mdl,md)+nmv(n-1-mdl,md);
}
void movin(in n, in md, in fst, in k){
  in mdl=(n-1)/2;
  if(k==1){
    cout<<mdl+fst<<endl;
    exit(0);
  }
  if(1+nmv(mdl,md)+nmv(n-1-mdl,md+1)>=k)
    movin(mdl,md,fst,k-1-nmv(n-1-mdl,md+1));
  else
    movin(n-1-mdl,md,fst+mdl+1,k-1-nmv(mdl,md));
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,k;
  cin>>n>>k;
  if(k==1){
    cout<<1<<endl;
    return 0;
  }
  if(k==2){
    cout<<n<<endl;
    return 0;
  }
  k-=2;
  in mn=1;
  in mx=n;
  in md;
  while(mx-mn>1){
    md=(mx+mn)/2;
    if(nmv(n-2,md)>=k)
      mn=md;
    else
      mx=md;
  }
  movin(n-2,mn,2,k);
  return 0;
}