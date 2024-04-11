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
in fel[100009];
struct stp{
  in t,l,c;
};
map<in,stp> mp;
stp stps[100009];
in clt=0;
int main(){
  cin>>m;
  in lin=100005;
  forn(i,m){
    cin>>stps[i].t>>stps[i].l;
    if(stps[i].t==2)
      cin>>stps[i].c;
    mp[clt]=stps[i];
    in oclt=clt;
    if(clt<lin){
      if(stps[i].t==1){
	fel[clt]=stps[i].l;
	clt++;
      }
      else{
	for(in ct=0;clt<lin && ct<stps[i].c;ct++){
	  for(in lt=0;clt<lin && lt<stps[i].l;lt++){
	    fel[clt++]=fel[lt];
	  }
	}
	clt=oclt+stps[i].c*stps[i].l;
      }
    }
    else{
      if(stps[i].t==1)
	clt++;
      else
	clt=oclt+stps[i].c*stps[i].l;
    }
  }
  cin>>n;
  in q;
  stp tp;
  map<in,stp>::iterator it1,it2;
  forn(i,n){
    cin>>q;
    q--;
    if(mp.find(q)!=mp.end())
      it1=mp.find(q);
    else{
      mp[q]=stps[0];
      it2=mp.find(q);
      it1=it2;
      it1--;
      mp.erase(it2);
    }
    tp=it1->second;
    if(tp.t==1){
      cout<<tp.l<<" ";
      continue;
    }
    in dit=q-it1->first;
    cout<<fel[dit%tp.l]<<" ";
  }
  cout<<endl;
  return 0;
}