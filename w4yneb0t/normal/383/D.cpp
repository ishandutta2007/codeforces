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
#define fors(i,s) for(typeof((s).begin())::iterator i=(s).begin();i!=(s).end();++i)
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef long long in;
in n;
vector<in> a;
vector<vector<in> > waysa;
in ttp;
in dummy;
const in mdl=1000000007LL;
in& ways(in x, in ct){
  ttp=ct+10005;
  if(ttp<0 || ttp>=sz(waysa[x&1]))
    return dummy;
  return waysa[x&1][ct+10005];
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin>>n;
  a.resize(n);
  forn(i,n)
    cin>>a[i];
  waysa.resize(2,vector<in>(20009,0));
  ways(0,a[0])=1;
  ways(0,-a[0])=1;
  in totw=0;
  for(in i=1;i<n;i++){
    dummy=0;
    forv(j,waysa[i&1])
      waysa[i&1][j]=0;
    forv(j,waysa[!(i&1)])
      waysa[!(i&1)][j]%=mdl;
    ways(i,a[i])=1;
    ways(i,-a[i])=1;
    for(in j=-10002;j<=10002;j++){
      ways(i,j+a[i])+=ways(i-1,j);
      ways(i,j-a[i])+=ways(i-1,j);
    }
    totw+=ways(i,0);
  }
  cout<<totw%mdl<<endl;
  return 0;
}