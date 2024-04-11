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
in n;
VI mar;
VI bsf;
in ab(in a){
  return a<0?-a:a;
}
in mnd(in df){
  bsf=VI(n,10000000LL);
  in tbst=10000000;
  forn(i,n){
    bsf[i]=i;
    forn(j,i){
      if((i-j)*df>=ab(mar[i]-mar[j])){
	bsf[i]=min(bsf[i],bsf[j]+i-j-1);
      }
    }
    tbst=min(tbst,bsf[i]+n-i-1);
  }
  return tbst;
}
in k;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>k;
  if(n==1){
    cout<<0<<endl;
    return 0;
  }
  mar.resize(n);
  forn(i,n)
    cin>>mar[i];
  in mn=-1;
  in mx=10000000000LL;
  in md;
  while(mx-mn>1){
    md=(mx+mn)/2;
    if(mnd(md)<=k)
      mx=md;
    else
      mn=md;
  }
  cout<<mx<<endl;
  return 0;
}