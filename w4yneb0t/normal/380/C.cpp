#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cassert>
#define PB push_back
#define sz(v) ((v).size())
#define forn(i,n) for(in i=0;i<(n);i++)
#define forv(i,v) forn(i,sz(v))
using namespace std;
typedef long long in;
in n,m;
string s;
vector<int> tps[1000009];
priority_queue<int> mcq;
struct qst{
  in a,b,id;
  bool operator<(const qst cp)const{
    return a<cp.a;
  };
};
in lct;
int crt[1000009];
in ans[100009];
qst qsts[100009];
void ad(int l){
  while(l<lct){
    crt[l]++;
    l=(l|(l+1));
  }
}
int sm(int l){
  int r=0;
  while(l>=0){
    r+=crt[l];
    l=(l&(l+1))-1;
  }
  return r;
}
int main(){
  cin>>s;
  cin>>m;
  n=s.length();
  lct=1000003;
  int mtt;
  forn(i,n){
    mtt=lct;
    if(s[i]=='('){
      mcq.push(i);
      tps[mtt].PB(i);
      continue;
    }
    if(mcq.empty()){
      tps[mtt].PB(i);
      continue;
    }
    mtt=mcq.top();
    tps[mtt].PB(i);
    mcq.pop();
  }
  forn(i,lct)
    crt[i]=0;
  forn(i,m){
    ans[i]=0;
  }
  forv(i,tps[lct])
    ad(tps[lct][i]);
  forn(i,m){
    cin>>qsts[i].a>>qsts[i].b;
    qsts[i].a--;
    qsts[i].b--;
    qsts[i].id=i;
  }
  in dsf=0;
  sort(qsts,qsts+m);
  forn(i,m){
    while(dsf<qsts[i].a){
      forv(j,tps[dsf])
	ad(tps[dsf][j]);
      dsf++;
    }
    ans[qsts[i].id]=(qsts[i].b-qsts[i].a+1-(sm(qsts[i].b)-sm(qsts[i].a-1)))*2;
  }
  forn(i,m)
    cout<<ans[i]<<endl;
  return 0;
}