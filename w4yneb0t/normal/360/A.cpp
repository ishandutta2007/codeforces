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
VI ulm;
VI cbn;
in n,m;
const in inf=1000000000LL;
VI qt,ql,qr,qd;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  ulm.resize(n,inf);
  cbn.resize(n,0);
  in typ,l,r,d;
  forn(z,m){
    cin>>typ>>l>>r>>d;
    l--;
    r--;
    qt.PB(typ);
    ql.PB(l);
    qr.PB(r);
    qd.PB(d);
    if(typ==1){
      for(in i=l;i<=r;++i){
	cbn[i]+=d;
      }
    }
    else{
      for(in i=l;i<=r;++i){
	ulm[i]=min(ulm[i],d-cbn[i]);
      }
    }
  }
  forv(i,ulm)
    ulm[i]=max(-inf,ulm[i]);
  cbn=VI(n,0);
  bool ok=1;
  forv(i,qt){
    if(qt[i]==2){
      in mx=-3*inf;
      for(in j=ql[i];j<=qr[i];++j)
	mx=max(mx,ulm[j]+cbn[j]);
      if(mx!=qd[i])
	ok=0;
    }
    else{
      for(in j=ql[i];j<=qr[i];++j)
	cbn[j]+=qd[i];
    }
  }
  if(ok==0){
    cout<<"NO"<<endl;
    return 0;
  }
  cout<<"YES"<<endl;
  forv(i,ulm)
    cout<<ulm[i]<<" ";
  cout<<endl;
  return 0;
}