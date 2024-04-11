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
const in mdl=1000000007LL;
string s;
VVI nst,nsmup;
VVI alpos;
in n;
in st(in spos, in k);
in smup(in spos, in k){
  if(nsmup[spos][k]!=-1)return nsmup[spos][k];
  if(spos==n)return nsmup[spos][k]=0;
  return nsmup[spos][k]=(('z'-s[spos])*st(spos+1,k)+smup(spos+1,k))%mdl;
}
in st(in spos, in k){
  if(nst[spos][k]!=-1)return nst[spos][k];
  in tr=smup(spos,k);
  if(k==0)tr++;
  in j;
  forv(i,alpos[spos]){
    j=alpos[spos][i];
    if((j+1)*(n-spos-j)<=k){
      tr+=(s[spos+j]-'a')*st(spos+j+1,k-(j+1)*(n-spos-j));
    }
  }
  return nst[spos][k]=tr%mdl;
}
in k;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>k;
  nst.resize(n+1,VI(k+1,-1));
  nsmup=nst;
  nst[n][0]=1;
  for(in i=1;i<=k;i++)
    nst[n][i]=0;
  cin>>s;
  forv(i,s){
    s[i]=char(in('a')+in('z')-in(s[i]));
  }
  alpos.resize(n+1);
  forn(i,n){
    in cl=n-i;
    for(in j=0;j<cl;j++){
      if((j+1)*(cl-j)<=k)
	alpos[i].PB(j);
    }
  }
  cout<<st(0,k)<<endl;
  return 0;
}