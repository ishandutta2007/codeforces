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
VI v,l,r;
VI alv;
VI hasp;
in sm=0;
void ctfl(in u, in a, in b){
  if(b<=a)
    return;
  if(u==-2){
    sm+=b-a;
    return;
  }
  in c=lower_bound(alv.begin()+a,alv.begin()+b,v[u])-alv.begin();
  in d=upper_bound(alv.begin()+a,alv.begin()+b,v[u])-alv.begin();
  ctfl(l[u],a,c);
  ctfl(r[u],d,b);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  v=l=r=hasp=VI(n);
  forn(z,n){
    cin>>v[z]>>l[z]>>r[z];
    --l[z];
    --r[z];
    alv.PB(v[z]);
    if(l[z]!=-2)
      hasp[l[z]]=1;
    if(r[z]!=-2)
      hasp[r[z]]=1;
  }
  in rt=0;
  while(hasp[rt])
    ++rt;
  sort(all(alv));
  ctfl(rt,0,sz(alv));
  cout<<sm<<endl;
  return 0;
}