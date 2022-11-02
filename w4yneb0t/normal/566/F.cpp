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
typedef int in;
typedef vector<in> VI;
typedef vector<VI> VVI;
const in mx=1000009LL;
in n;
VI aps;
VI bst;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  bst.resize(mx,0);
  aps.resize(mx,0);
  cin>>n;
  in tp;
  forn(i,n){
    cin>>tp;
    aps[tp]++;
  }
  in rs=0;
  for(in i=1;i<mx;i++){
    bst[i]+=aps[i];
    for(in j=i;j<mx;j+=i)
      bst[j]=max(bst[j],bst[i]);
    rs=max(rs,bst[i]);
  }
  cout<<rs<<"\n";
  return 0;
}