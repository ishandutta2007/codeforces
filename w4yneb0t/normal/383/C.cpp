#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<cassert>
#define PB push_back
#define MP make_pair
#define sz(v) (in((v).size()))
#define forn(i,n) for(in i=0;i<(n);++i)
#define forv(i,v) forn(i,sz(v))
#define fors(i,s) for(typeof((s).begin())::iterator i=(s).begin();i!=(s).end();++i)
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef long long in;
in n,m;
vector<vector<in> > cd;
vector<in> pr;
vector<in> ent;
vector<in> ext;
vector<in> fwt;
void adfw(in l, in a){
  while(l<sz(fwt)){
    fwt[l]+=a;
    l|=(l+1);
  }
}
in smfw(in l){
  in r=0;
  while(l>=0){
    r+=fwt[l];
    l&=(l+1);
    --l;
  }
  return r;
}
void adtr(in x, in a){
  adfw(ent[x],a);
  adfw(ext[x],-a);
}
in smtr(in x){
  return smfw(ent[x]);
}
vector<vector<in> > egs;
vector<in> sval,ht;
queue<in> q;
stack<in> stk;
vector<in> ssf;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin>>n>>m;
  sval.resize(n);
  forn(i,n)
    cin>>sval[i];
  egs.resize(n);
  in ta,tb;
  forn(i,n-1){
    cin>>ta>>tb;
    ta--;
    tb--;
    egs[ta].PB(tb);
    egs[tb].PB(ta);
  }
  cd.resize(n);
  pr.resize(n,0);
  ht.resize(n,-1);
  ht[0]=0;
  q.push(0);
  while(!q.empty()){
    ta=q.front();
    if(ht[ta])
      sval[ta]*=-1;
    q.pop();
    forv(i,egs[ta]){
      tb=egs[ta][i];
      if(ht[tb]!=-1)
	continue;
      ht[tb]=!ht[ta];
      pr[tb]=ta;
      cd[ta].PB(tb);
      q.push(tb);
    }
  }
  ssf.resize(n,0);
  ent.resize(n);
  ext.resize(n);
  ent[0]=0;
  stk.push(0);
  in tim=1;
  while(!stk.empty()){
    ta=stk.top();
    if(ssf[ta]==sz(cd[ta])){
      ext[ta]=tim++;
      stk.pop();
    }
    else{
      tb=cd[ta][ssf[ta]++];
      ent[tb]=tim++;
      stk.push(tb);
    }
  }
  fwt.resize(tim,0);
  in typ,x,v;
  forn(i,m){
    cin>>typ>>x;
    x--;
    if(typ==1){
      cin>>v;
      if(ht[x])
	v*=-1;
      adtr(x,v);
    }
    else{
      v=smtr(x);
      v+=sval[x];
      if(ht[x])
	v*=-1;
      cout<<v<<"\n";
    }
  }
  return 0;
}