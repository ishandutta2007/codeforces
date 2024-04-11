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
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  const in inf=1e10;
  in mn=-inf;
  in mx=inf;
  in c,d;
  forn(zz,n){
    cin>>c>>d;
    if(d==2)
      mx=min(mx,1899LL);
    else
      mn=max(mn,1900LL);
    mn+=c;
    mx+=c;
  }
  if(mn>mx){
    cout<<"Impossible"<<endl;
    return 0;
  }
  if(mx>inf/10){
    cout<<"Infinity"<<endl;
    return 0;
  }
  cout<<mx<<endl;
  return 0;
}