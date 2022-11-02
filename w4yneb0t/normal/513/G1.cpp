#include<iomanip>
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
vector<vector<map<pair<in,in>,double> > > tran;
in n,k;
in flp(in i, in j, in x){
  if(x<i || x>j)return x;
  return i+(j-x);
}
double ipb;
void genm(in lf, in rt){
  in nul,nur;
  forn(j,n){
    forn(i,j+1){
      nul=flp(i,j,lf);
      nur=flp(i,j,rt);
      tran[lf][rt][MP(nul,nur)]+=ipb;
    }
  }
}
vector<vector<vector<double> > > ctg;
double crg(in i, in j, in k){
  if(ctg[i][j][k]>-0.5)
    return ctg[i][j][k];
  if(k==0){
    if(i<j)
      return ctg[i][j][k]=0;
    else
      return ctg[i][j][k]=1;
  }
  double &tu=ctg[i][j][k];
  tu=0;
  in fct=0;
  if(i>j){
    fct=1;
    swap(i,j);
  }
  for(map<pair<in,in>,double>::iterator it=tran[i][j].begin();it!=tran[i][j].end();++it){
    tu+=it->second*crg(it->first.first,it->first.second,k-1);
  }
  if(fct)
    tu=1-tu;
  return tu;
}
vector<in> spm;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin>>n>>k;
  ctg.resize(n,vector<vector<double> >(n,vector<double>(k+1,-1)));
  ipb=1/double(n*(n+1)/2);
  spm.resize(n);
  forn(i,n)
    cin>>spm[i];
  tran.resize(n,vector<map<pair<in,in>,double> >(n));
  forn(i,n){
    forn(j,i){
      genm(j,i);
    }
  }
  double tot=0;
  forn(i,n){
    forn(j,i){
      if(spm[i]<spm[j])
	tot+=crg(i,j,k);
      else
	tot+=crg(j,i,k);
    }
  }
  cout<<setprecision(15)<<tot<<endl;
  return 0;
}