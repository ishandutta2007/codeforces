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
in n,m,p;
in a[200009];
in b[200009];
map<in,in> mp;
in nms=1;
in avl[200009];
in bvl[200009];
in wrgs;
vector<in> chg;
void add(in x){
  chg.push_back(x);
  if(avl[x]==bvl[x])
    wrgs++;
  avl[x]++;
  if(avl[x]==bvl[x])
    wrgs--;
}
void rem(in x){
  if(avl[x]==bvl[x])
    wrgs++;
  avl[x]--;
  if(avl[x]==bvl[x])
    wrgs--;
}
int main(){
  cin>>n>>m>>p;
  for(in i=0;i<n;i++)
    cin>>a[i];
  for(in i=0;i<m+3;i++)
    bvl[i]=avl[i]=0;
  for(in i=0;i<m;i++){
    cin>>b[i];
    if(mp.find(b[i])==mp.end())
      mp[b[i]]=nms++;
    b[i]=mp[b[i]];
    bvl[b[i]]++;
  }
  for(in i=0;i<n;i++){
    if(mp.find(a[i])==mp.end())
      a[i]=0;
    else
      a[i]=mp[a[i]];
  }
  vector<in> sols;
  for(in i=0;i<p;i++){
    if(i+(m-1)*p>=n)
      continue;
    chg.resize(0);
    wrgs=nms-1;
    for(in j=0;j<m;j++){
      add(a[i+j*p]);
    }
    if(wrgs==0)
      sols.push_back(i);
    for(in j=1;i+(m-1+j)*p<n;j++){
      rem(a[i+(j-1)*p]);
      add(a[i+(m-1+j)*p]);
      if(wrgs==0)
	sols.push_back(i+j*p);
    }
    for(in i=0;i<chg.size();i++)
      avl[chg[i]]=0;
  }
  sort(sols.begin(),sols.end());
  cout<<sols.size()<<endl;
  for(in i=0;i<sols.size();i++)
    cout<<sols[i]+1<<" ";
  cout<<endl;
  return 0;
}