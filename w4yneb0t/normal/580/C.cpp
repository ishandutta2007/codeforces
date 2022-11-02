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
VI cct;
VVI egs;
in tct(in u, in pr, in d, in sf){
  if(cct[u])
    sf++;
  else
    sf=0;
  if(sf>d)
    return 0;
  if(pr!=-1 && sz(egs[u])==1)
    return 1;
  in s=0;
  in tt;
  forv(i,egs[u]){
    tt=egs[u][i];
    if(tt==pr)continue;
    s+=tct(tt,u,d,sf);
  }
  return s;
}
in n;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in d;
  cin>>n>>d;
  cct=VI(n);
  forn(i,n)
    cin>>cct[i];
  egs.resize(n);
  in ta,tb;
  forn(i,n-1){
    cin>>ta>>tb;
    ta--;
    tb--;
    egs[ta].PB(tb);
    egs[tb].PB(ta);
  }
  cout<<tct(0,-1,d,0)<<endl;
  return 0;
}