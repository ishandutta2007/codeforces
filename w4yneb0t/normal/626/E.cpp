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
in bstup=0;
in bstdn=1;
in bstmid=0;
in bstk=0;
VI mar;
VI smup;
in n;
void proc(in mide){
  in midval=mar[mide];
  in mn=0;
  in mx=min(mide,n-1-mide)+1;
  in md;
  in avtop,avbot;
  in sugtop;
  in sugbot=2;
  while(mx-mn>1){
    md=(mn+mx)/2-1;
    avbot=2*md+1;
    avtop=smup[md]+smup[mide+md+1]-smup[mide];
    sugtop=mar[md]+mar[mide+md+1];
    if(sugtop*avbot>avtop*sugbot)
      mx=md+1;
    else
      mn=md+1;
  }
  md=mn;
  avbot=2*md+1;
  avtop=smup[md]+smup[mide+md+1]-smup[mide];
  avtop-=avbot*midval;
  if(avtop*bstdn<avbot*bstup){
    bstdn=avbot;
    bstup=avtop;
    bstmid=mide;
    bstk=md;
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  mar.resize(n);
  const in lrg=1000002;
  forn(i,n){
    cin>>mar[i];
    mar[i]=lrg-mar[i];
  }
  sort(all(mar));
  smup.resize(n+1);
  smup[0]=0;
  forn(i,n)
    smup[i+1]=smup[i]+mar[i];
  forn(i,n)
    proc(i);
  cout<<(2*bstk+1)<<"\n";
  forn(i,bstk)
    cout<<lrg-mar[i]<<" ";
  cout<<lrg-mar[bstmid];
  forn(i,bstk)
    cout<<" "<<lrg-mar[bstmid+i+1];
  cout<<"\n";
  return 0;
}