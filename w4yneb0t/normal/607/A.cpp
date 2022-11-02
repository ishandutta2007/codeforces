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
vector<pair<in,in> > bc;
VI sv;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  bc.resize(n);
  forn(i,n)
    cin>>bc[i].first>>bc[i].second;
  sort(all(bc));
  sv.resize(n,0);
  in bst=0;
  forn(i,n){
    in mn=-1;
    in mx=i;
    in md;
    while(mx-mn>1){
      md=(mx+mn)/2;
      if(bc[md].first>=bc[i].first-bc[i].second)
	mx=md;
      else
	mn=md;
    }
    if(mn==-1)
      sv[i]=1;
    else
      sv[i]=1+sv[mn];
    bst=max(bst,sv[i]);
  }
  cout<<n-bst<<endl;
  return 0;
}