#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long in;
in n,m;
in ac[30];
in bc[30];
in sz=50;
in inf=10000000000000LL;
struct pth{
  vector<vector<in> > t;
  void ini(){
    t.resize(sz,vector<in>(sz,inf));
  }
  pth operator+(const pth cp)const{
    pth ret;
    ret.ini();
    for(in i=0;i<sz;i++){
      for(in j=0;j<sz;j++){
        for(in k=0;k<sz;k++){
          if(t[i][k]+cp.t[k][j]<ret.t[i][j])
            ret.t[i][j]=t[i][k]+cp.t[k][j];
        }
      }
    }
    return ret;
  }
};
pth mpt;
pth pw[25];
pth tot;
int main(){
  cin>>n>>m;
  for(in i=0;i<n;i++){
    cin>>ac[i];
  }
  for(in i=0;i<n;i++){
    cin>>bc[i];
  }
  in cc;
  in dp;
  in as;
  mpt.ini();
  for(in msk=0;msk<(1LL<<n);msk++){
    cc=0;
    as=0;
    dp=0;
    for(in i=0;i<n;i++){
      as+=((msk&(1LL<<i))!=0)*2-1;
      if(as<dp)
        dp=as;
      cc+=((msk&(1LL<<i))!=0)*ac[i]+((msk&(1LL<<i))==0)*bc[i];
    }
    for(in i=-dp;i<sz && i+as<sz;i++){
      if(cc<mpt.t[i][i+as])
        mpt.t[i][i+as]=cc;
    }
  }
  pw[0]=mpt;
  for(in i=1;i<25;i++){
    pw[i]=pw[i-1]+pw[i-1];
  }
  bool st=false;
  tot.ini();
  for(in i=0;i<25;i++){
    if(m&(1LL<<i)){
      if(st)
        tot=tot+pw[i];
      else
        tot=pw[i];
      st=true;
    }
  }
  cout<<tot.t[0][0]<<endl;
  return 0;
}