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
string s,t;
VI wys;
VI psm;
VI lps;
VI pfar(string s){  //test with aaaa
  in n=sz(s);
  VI rt(n+1,0);
  rt[0]=-1;
  rt[1]=0;
  for(in i=2;i<=n;i++){
    rt[i]=rt[i-1];
    while(rt[i]!=-1 && s[rt[i]]!=s[i-1])
      rt[i]=rt[rt[i]];
    rt[i]++;
  }
  return rt;
}
VI tar;
VI wsm;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>s>>t;
  tar=pfar(t);
  in n=sz(s);
  wsm=psm=wys=VI(n+1,0);
  in lst=-1;
  in nxt=0;
  in tsm=0;
  forn(i,n){
    while(nxt!=-1 && t[nxt]!=s[i]){
      nxt=tar[nxt];
    }
    ++nxt;
    if(nxt==sz(t)){
      lst=i-sz(t)+1;
      nxt=tar[nxt];
    }
    wys[i+1]+=lst+1;
    if(lst!=-1)
      wys[i+1]+=lst*psm[lst]-wsm[lst];
    wys[i+1]%=mdl;
    if(wys[i+1]<0)
      wys[i+1]+=mdl;
    psm[i+1]+=wys[i+1]+psm[i];
    psm[i+1]%=mdl;
    wsm[i+1]=(wsm[i]+wys[i+1]*i)%mdl;
    tsm+=wys[i+1];
  }
  cout<<tsm%mdl<<endl;
  return 0;
}
/*
2
012
12

12222
2


 */