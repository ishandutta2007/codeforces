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
typedef int in;
typedef vector<in> VI;
typedef vector<VI> VVI;
struct rul{
  in a,b,c,usd;
};
in n;
queue<in> avb;
VI isk;
VVI crs;
VI cfl;
vector<rul> ruls;
VI tm;
void lkat(in id){
  if(ruls[id].usd)return;
  in a=ruls[id].a;
  in b=ruls[id].b;
  in c=ruls[id].c;
  tm[a]=cfl[a];
  tm[b]=cfl[b];
  tm[c]=cfl[c];
  tm[a]--;
  tm[b]++;
  tm[c]++;
  bool isok=1;
  if(tm[b]>9 || tm[c]>9)
    isok=0;
  if(isok)
    avb.push(id);
  isk[id]=isok;
}
void tfr(rul cc){
  cfl[cc.a]--;
  cfl[cc.b]++;
  cfl[cc.c]++;
  forv(i,crs[cc.a])
    lkat(crs[cc.a][i]);
  forv(i,crs[cc.b])
    lkat(crs[cc.b][i]);
  forv(i,crs[cc.c])
    lkat(crs[cc.c][i]);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  crs.resize(n);
  cfl.resize(n,4);
  ruls.resize(n*4);
  tm.resize(4*n+9);
  isk.resize(4*n+9,1);
  forn(i,n*4){
    ruls[i].usd=0;
    cin>>ruls[i].a>>ruls[i].b>>ruls[i].c;
    ruls[i].a--;
    ruls[i].b--;
    ruls[i].c--;
    crs[ruls[i].a].PB(i);
    crs[ruls[i].b].PB(i);
    crs[ruls[i].c].PB(i);
    avb.push(i);
  }
  cout<<"YES\n";
  in zz=1;
  while(!avb.empty()){
    in cc=avb.front();avb.pop();
    if(ruls[cc].usd)isk[cc]=0;
    if(!isk[cc])continue;
    cout<<(cc+1)<<(zz++==4*n?"\n":" ");
    ruls[cc].usd=1;
    tfr(ruls[cc]);
  }
  return 0;
}