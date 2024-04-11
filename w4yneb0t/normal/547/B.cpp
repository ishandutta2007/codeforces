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
struct br{
  in pos,a;
  bool operator<(const br cp)const{
    if(a!=cp.a)
      return a>cp.a;
    return pos<cp.pos;
  }
};
VI mar;
vector<br> brs;
in n;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  brs.resize(n);
  mar.resize(n+2,0);
  forn(i,n){
    brs[i].pos=i+1;
    cin>>brs[i].a;
  }
  sort(all(brs));
  in nxg=1;
  forv(i,brs){
    in cc=brs[i].pos;
    in tsz=1;
    tsz+=mar[cc-1];
    tsz+=mar[cc+1];
    while(nxg<=tsz){
      cout<<brs[i].a<<" ";
      ++nxg;
    }
    mar[cc-mar[cc-1]]=tsz;
    mar[cc+mar[cc+1]]=tsz;
  }
  cout<<"\n";
  return 0;
}