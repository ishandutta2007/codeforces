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
in gcd(in a, in b){
  if(b==0)
    return a;
  return gcd(b,a%b);
}
in p2(in a){
  return 1LL<<a;
}
VI l,c;
in n;
VI fcs;
VI bst;
in sl;
void trp(in a, in tc){
  fcs.clear();
  for(in i=2;i*i<=a;++i){
    if(a%i==0){
      fcs.PB(i);
      while(a%i==0)
	a/=i;
    }
  }
  if(a!=1)
    fcs.PB(a);
  in t=sz(fcs);
  bst=VI(p2(t),1000000000LL);
  bst[p2(t)-1]=tc;
  forn(i,n){
    in cm=0;
    forv(j,fcs)
      if(l[i]%fcs[j]==0)
	cm|=p2(j);
    forv(j,bst)
      bst[j&cm]=min(bst[j&cm],bst[j]+c[i]);
  }
  sl=min(sl,bst[0]);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  l=c=VI(n);
  forn(i,n)
    cin>>l[i];
  forn(i,n)
    cin>>c[i];
  in g=l[0];
  for(in i=1;i<n;++i)
    g=gcd(g,l[i]);
  if(g!=1){
    cout<<-1<<endl;
    return 0;
  }
  sl=1000000000LL;
  forn(i,n){
    trp(l[i],c[i]);
  }
  cout<<sl<<endl;
  return 0;
}