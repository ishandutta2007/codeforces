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
in totsc=0;
in onsh=0;
in n,q;
VI mpof;
VI a;
VI ison;
in mx=500009;
VI sqfree;
VI coef;
VVI sqfrdvs,dvcoef;
in msc(in ta){
  in r=0;
  forv(i,sqfrdvs[ta]){
    r+=dvcoef[ta][i]*mpof[sqfrdvs[ta][i]];
  }
  return r;
}
void mkdv(in ta, in fc){
  forv(i,sqfrdvs[ta])
    mpof[sqfrdvs[ta][i]]+=fc;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>q;
  a.resize(n);
  ison.resize(n,0);
  mpof.resize(mx,0);
  sqfree.resize(mx,1);
  coef.resize(mx,-1);
  sqfrdvs.resize(mx);
  dvcoef=sqfrdvs;
  sqfree[0]=sqfree[1]=0;
  for(in i=2;i<mx;i++){
    if(i*i<mx)
      sqfree[i*i]=0;
    if(sz(sqfrdvs[i])==0){
      for(in j=i;j<mx;j+=i)
	coef[j]*=-1;
    }
    if(sqfree[i]){
      for(in j=i;j<mx;j+=i){
	sqfrdvs[j].PB(i);
	dvcoef[j].PB(coef[i]);
      }
    }
    else{
      for(in j=i;j<mx;j+=i)
	sqfree[j]=0;
    }
  }
  forn(i,n)
    cin>>a[i];
  in ta;
  forn(zz,q){
    cin>>ta;
    ta--;
    if(ison[ta]){
      onsh--;
      ison[ta]=0;
      mkdv(a[ta],-1);
      totsc-=(onsh-msc(a[ta]));
    }
    else{
      totsc+=(onsh-msc(a[ta]));
      onsh++;
      ison[ta]=1;
      mkdv(a[ta],1);
    }
    cout<<totsc<<"\n";
  }
  return 0;
}