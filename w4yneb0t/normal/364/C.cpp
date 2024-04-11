#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<cassert>
using namespace std;
typedef long long in;
in pc;
in ps[8];
in cps[8]={2,3,5,7,11,13,17,19};
in k;
in lim;
in hwm[8];
struct nbr{
  vector<in> pw;
  vector<in> prod;
  in tpr;
  void ini(){
    pw.resize(pc);
    prod=pw;
    for(in i=0;i<pc;i++){
      pw[i]=0;
      prod[i]=1;
    }
    tpr=1;
  }
  void inc(in i){
    pw[i]++;
    prod[i]*=ps[i];
    tpr*=ps[i];
  }
  void des(in i){
    pw[i]=0;
    tpr/=prod[i];
    prod[i]=1;
  }
  nbr operator++(){
    in nx=pc-1;
    inc(nx);
    while(nx>0 && tpr>lim){
      des(nx);
      nx--;
      inc(nx);
    }
    if(tpr>lim)
      des(0);
    return *this;
  }
  bool operator<(const nbr cp)const{
    return tpr<cp.tpr;
  }
};
vector<nbr> tv;
set<nbr> vc;
void add(nbr a){
  vc.insert(a);
  for(in i=0;i<pc;i++)
    if(a.pw[i]>0)
      hwm[i]++;
}
void rem(nbr a){
  vc.erase(a);
  for(in i=0;i<pc;i++)
    if(a.pw[i]>0)
      hwm[i]--;
}
bool nog(nbr a, in s){
  return a.pw[s]==0;
}
int main(){
  cin>>k;
  lim=2*k*k;
  for(pc=2;true;pc++){
    if(pc>8)
      pc=2;
    tv.clear();
    vc.clear();
    for(in i=0;i<pc;i++){
      ps[i]=cps[i];
      hwm[i]=0;
    }
    nbr a;
    a.ini();
    nbr tp=a;
    do{
      ++a;
      tv.push_back(a);
    }while(tp<a);
    random_shuffle(tv.begin(),tv.end());
    in sof=0;
    for(in i=0;sof<k && i<tv.size();i++){
      bool bad=0;
      for(in j=pc-1;j>=0;j--){
	if(nog(tv[i],j) && hwm[j]*2<sof){
	  bad=1;
	  break;
	}
      }
      if(!bad){
	add(tv[i]);
	sof++;
      }
    }
    if(sof!=k)
      continue;
    for(set<nbr>::iterator it=vc.begin();it!=vc.end();++it)
      cout<<it->tpr<<" ";
    cout<<endl;
    return 0;
  }
  assert(0);
  return 0;
}