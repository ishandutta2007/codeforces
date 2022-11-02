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
#define fors(i,s) for(typeof((s).begin()) i=(s).begin();i!=(s).end();++i)
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef long long in;
typedef vector<in> VI;
typedef vector<VI> VVI;
void pol(){
  cout<<"Polycarp"<<endl;
  exit(0);
}
void vas(){
  cout<<"Vasiliy"<<endl;
  exit(0);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in xp,yp,xv,yv;
  cin>>xp>>yp>>xv>>yv;
  while(1){
    if(xp<=xv && yp<=yv)
      pol();
    if(xp>=xv && yp>=yv)
      vas();
    if(yp<yv){
      swap(xp,yp);
      swap(xv,yv);
    }
    --yp;
    --xv;
    if(yv)
      --yv;
    if(xp==xv && yp==yv)
      pol();
  }
  return 0;
}