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
in fc(const VVI& c, const in& x1, const in& y1, const in& x2, const in& y2){
  if(x2<x1 || y2<y1)
    return 0;
  in tc=c[x2][y2];
  if(x1>0)
    tc-=c[x1-1][y2];
  if(y1>0)
    tc-=c[x2][y1-1];
  if(x1>0 && y1>0)
    tc+=c[x1-1][y1-1];
  return tc;
}
vector<string> bd;
VVI ch,cv;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in h,w;
  cin>>h>>w;
  bd.resize(h);
  forn(i,h)
    cin>>bd[i];
  ch=VVI(h,VI(w-1,0));
  cv=VVI(h-1,VI(w,0));
  forn(i,h){
    forn(j,w-1){
      ch[i][j]=(bd[i][j]=='.' && bd[i][j+1]=='.');
      if(i>0)
	ch[i][j]+=ch[i-1][j];
      if(j>0)
	ch[i][j]+=ch[i][j-1];
      if(i>0 && j>0)
	ch[i][j]-=ch[i-1][j-1];
    }
  }
  forn(i,h-1){
    forn(j,w){
      cv[i][j]=(bd[i][j]=='.' && bd[i+1][j]=='.');
      if(i>0)
	cv[i][j]+=cv[i-1][j];
      if(j>0)
	cv[i][j]+=cv[i][j-1];
      if(i>0 && j>0)
	cv[i][j]-=cv[i-1][j-1];
    }
  }
  in q;
  cin>>q;
  in x1,x2,y1,y2;
  forn(i,q){
    cin>>x1>>y1>>x2>>y2;
    --x1;
    --y1;
    --x2;
    --y2;
    cout<<(fc(ch,x1,y1,x2,y2-1)+fc(cv,x1,y1,x2-1,y2))<<"\n";
  }
  return 0;
}